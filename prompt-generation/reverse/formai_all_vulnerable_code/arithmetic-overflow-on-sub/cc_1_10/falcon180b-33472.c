//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[50];
    int votes;
} candidate;

void add_candidate(candidate* candidates, int num_candidates, char* name) {
    for (int i = 0; i < num_candidates; i++) {
        if (strcmp(candidates[i].name, name) == 0) {
            printf("Candidate already exists.\n");
            return;
        }
    }
    strcpy(candidates[num_candidates].name, name);
    candidates[num_candidates].votes = 0;
    num_candidates++;
}

void display_candidates(candidate* candidates, int num_candidates) {
    printf("List of Candidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i+1, candidates[i].name);
    }
}

int main() {
    srand(time(NULL));
    candidate* candidates = (candidate*) malloc(10 * sizeof(candidate));
    int num_candidates = 0;
    char choice;
    do {
        printf("Enter 'a' to add a candidate, 'd' to display candidates, 'v' to vote or 'e' to exit.\n");
        scanf("%c", &choice);
        switch (choice) {
            case 'a': {
                char name[50];
                printf("Enter the name of the candidate:\n");
                scanf("%s", name);
                add_candidate(candidates, num_candidates, name);
                break;
            }
            case 'd': {
                display_candidates(candidates, num_candidates);
                break;
            }
            case 'v': {
                int candidate_index;
                printf("Enter the index of the candidate you want to vote for:\n");
                scanf("%d", &candidate_index);
                candidates[candidate_index-1].votes++;
                break;
            }
            case 'e': {
                free(candidates);
                exit(0);
            }
            default: {
                printf("Invalid choice.\n");
            }
        }
    } while (choice!= 'e');
    return 0;
}