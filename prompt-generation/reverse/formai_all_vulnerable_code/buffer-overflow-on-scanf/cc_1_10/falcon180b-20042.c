//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 1000

typedef struct {
    char name[50];
    int votes;
} candidate_t;

candidate_t candidates[MAX_CANDIDATES];

void add_candidate(char* name) {
    int i;
    for(i=0; i<MAX_CANDIDATES; i++) {
        if(candidates[i].name[0] == '\0') {
            strcpy(candidates[i].name, name);
            break;
        }
    }
}

void vote(int voter_id, char* candidate_name) {
    int i;
    for(i=0; i<MAX_CANDIDATES; i++) {
        if(strcmp(candidates[i].name, candidate_name) == 0) {
            candidates[i].votes++;
            break;
        }
    }
}

void display_results() {
    int i;
    printf("\nResults:\n");
    for(i=0; i<MAX_CANDIDATES; i++) {
        if(candidates[i].name[0]!= '\0') {
            printf("%d. %s - %d votes\n", i+1, candidates[i].name, candidates[i].votes);
        }
    }
}

int main() {
    int choice, voter_id, candidate_id;
    char candidate_name[50];
    bool quit = false;

    system("clear");

    printf("\nWelcome to the Electronic Voting System!\n");
    printf("----------------------------------------\n");

    while(!quit) {
        printf("\nPlease choose an option:\n");
        printf("1. Add a candidate\n");
        printf("2. Vote\n");
        printf("3. Display results\n");
        printf("4. Quit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the name of the candidate: ");
                scanf("%s", candidate_name);
                add_candidate(candidate_name);
                break;
            case 2:
                printf("Enter your voter ID: ");
                scanf("%d", &voter_id);
                printf("Enter the name of the candidate you want to vote for: ");
                scanf("%s", candidate_name);
                vote(voter_id, candidate_name);
                break;
            case 3:
                display_results();
                break;
            case 4:
                quit = true;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}