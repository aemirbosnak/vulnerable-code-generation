//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_CANDIDATES 50
#define MAX_VOTERS 1000

/* Structures for candidates and voters */
typedef struct candidate {
    char name[50];
    int num_votes;
} candidate_t;

typedef struct voter {
    char name[50];
    bool voted;
} voter_t;

/* Global variables */
candidate_t candidates[MAX_CANDIDATES];
voter_t voters[MAX_VOTERS];
int num_candidates, num_voters;

/* Function prototypes */
void *voter_thread(void *arg);
void add_candidate(char *name);
void display_results();

/* Main function */
int main() {
    char candidate_name[50];
    int num_threads, i;
    pthread_t threads[MAX_VOTERS];

    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    printf("\nEnter the names of the candidates:\n");
    for (i = 0; i < num_candidates; i++) {
        scanf("%s", candidate_name);
        add_candidate(candidate_name);
    }

    printf("\nEnter the number of voters: ");
    scanf("%d", &num_voters);

    printf("\nEnter the names of the voters:\n");
    for (i = 0; i < num_voters; i++) {
        scanf("%s", voters[i].name);
        voters[i].voted = false;
    }

    /* Create threads for voters */
    for (i = 0; i < num_voters; i++) {
        pthread_create(&threads[i], NULL, voter_thread, (void *) i);
    }

    /* Wait for threads to complete */
    for (i = 0; i < num_voters; i++) {
        pthread_join(threads[i], NULL);
    }

    /* Display the results */
    display_results();

    return 0;
}

/* Function to add a candidate to the system */
void add_candidate(char *name) {
    static int i = 0;  // To keep track of the number of candidates
    strcpy(candidates[i].name, name);
    candidates[i].num_votes = 0;
    i++;
}

/* Thread function which allows a voter to cast a vote */
void *voter_thread(void *arg) {
    int *id = (int *) arg;
    int i;
    bool valid_vote = false;

    do {
        /* Display the list of candidates */
        printf("\nCast your vote, %s:\n", voters[*id].name);
        for (i = 0; i < num_candidates; i++) {
            printf("%d. %s\n", i+1, candidates[i].name);
        }

        /* Allow the voter to cast a vote */
        int choice;
        scanf("%d", &choice);

        /* Mark the voter as having voted */
        if (choice >= 1 && choice <= num_candidates) {
            valid_vote = true;
            voters[*id].voted = true;

            /* Increment the number of votes for the chosen candidate */
            candidates[choice-1].num_votes++;
            printf("\nThank you, %s, for casting your vote!\n", voters[*id].name);
        } else {
            printf("\nInvalid choice. Please try again.\n");
        }
    } while (!valid_vote);

    pthread_exit(NULL);
}

/* Function to display the results of the election */
void display_results() {
    int i, max_votes = 0, max_index = 0;

    printf("\nElection Results:\n");
    for (i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].num_votes);
        
        /* Check for maximum number of votes */
        if (candidates[i].num_votes > max_votes) {
            max_votes = candidates[i].num_votes;
            max_index = i;
        }
    }

    /* Display the winning candidate */
    printf("\nThe winner of the election is: %s!\n", candidates[max_index].name);
}