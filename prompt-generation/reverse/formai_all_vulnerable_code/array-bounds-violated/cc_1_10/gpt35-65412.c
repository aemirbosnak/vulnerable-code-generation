//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

struct candidate {
    char name[MAX_NAME_LEN];
    int votes;
};

struct voter {
    char name[MAX_NAME_LEN];
    int voted_for;
};

struct election {
    struct candidate candidates[MAX_CANDIDATES];
    struct voter voters[MAX_VOTERS];
    int num_candidates;
    int num_voters;
};

// function to display menu and get user's choice
int menu() {
    int choice;
    printf("\nElectronic Voting System:\n");
    printf("1. Add Candidate\n");
    printf("2. Add Voter\n");
    printf("3. Show Candidates\n");
    printf("4. Vote Counting\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// function to add candidate to the election
void add_candidate(struct election *e) {
    if (e->num_candidates == MAX_CANDIDATES) {
        printf("Sorry, maximum number of candidates reached.");
        return;
    }
    struct candidate c;
    printf("Enter candidate name: ");
    fflush(stdin); // clear the input buffer
    fgets(c.name, MAX_NAME_LEN, stdin); // read candidate name
    c.name[strlen(c.name)-1] = '\0'; // remove newline character from string
    c.votes = 0; // initialize vote count
    e->candidates[e->num_candidates] = c;
    e->num_candidates++;
    printf("Candidate added successfully!\n");
}

// function to add voter to the election
void add_voter(struct election *e) {
    if (e->num_voters == MAX_VOTERS) {
        printf("Sorry, maximum number of voters reached.");
        return;
    }
    struct voter v;
    printf("Enter voter name: ");
    fflush(stdin); // clear the input buffer
    fgets(v.name, MAX_NAME_LEN, stdin); // read voter name
    v.name[strlen(v.name)-1] = '\0'; // remove newline character from string
    
    // check if voter has already voted
    for (int i = 0; i < e->num_voters; i++) {
        if (strcmp(e->voters[i].name, v.name) == 0) {
            printf("Sorry, you have already voted!");
            return;
        }
    }
    
    // display candidates and get the choice
    printf("Candidates:\n");
    for (int i = 0; i < e->num_candidates; i++) {
        printf("%d. %s\n", i+1, e->candidates[i].name);
    }
    printf("Enter your choice: ");
    scanf("%d", &v.voted_for);
    if (v.voted_for < 1 || v.voted_for > e->num_candidates) {
        printf("Invalid choice!");
        return;
    }
    e->voters[e->num_voters] = v;
    e->num_voters++;
    e->candidates[v.voted_for-1].votes++; // update vote count for the chosen candidate
    printf("Thank you for voting!\n");
}

// function to display the list of candidates
void show_candidates(struct election *e) {
    printf("Candidates:\n");
    for (int i = 0; i < e->num_candidates; i++) {
        printf("%s - %d votes\n", e->candidates[i].name, e->candidates[i].votes);
    }
}

// function to count votes and declare winner
void count_votes(struct election *e) {
    int max_votes = 0, winner = 0;
    for (int i = 0; i < e->num_candidates; i++) {
        if (e->candidates[i].votes > max_votes) {
            max_votes = e->candidates[i].votes;
            winner = i;
        }
    }
    printf("Winner: %s with %d votes.\n", e->candidates[winner].name, max_votes);
}

int main() {
    struct election e;
    e.num_candidates = 0;
    e.num_voters = 0;
    int choice;
    do {
        choice = menu();
        switch (choice) {
            case 1:
                add_candidate(&e);
                break;
            case 2:
                add_voter(&e);
                break;
            case 3:
                show_candidates(&e);
                break;
            case 4:
                count_votes(&e);
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);
    return 0;
}