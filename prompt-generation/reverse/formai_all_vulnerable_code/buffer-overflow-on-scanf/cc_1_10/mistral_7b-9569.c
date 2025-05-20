//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} Candidate;

void print_menu() {
    printf("\n-----------------------------------------\n");
    printf("| Electronic Voting System Menu          |\n");
    printf("-----------------------------------------\n");
    printf("| 1. Register Candidate                 |\n");
    printf("| 2. Cast Vote                         |\n");
    printf("| 3. Display Vote Count                |\n");
    printf("| 4. Exit                              |\n");
    printf("-----------------------------------------\n");
}

int main() {
    Candidate candidates[MAX_CANDIDATES];
    int num_candidates = 0;
    int choice;
    char name[MAX_NAME_LENGTH];

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_candidates >= MAX_CANDIDATES) {
                    printf("Maximum number of candidates reached.\n");
                    break;
                }
                printf("Enter candidate name: ");
                scanf("%s", name);
                strcpy(candidates[num_candidates].name, name);
                candidates[num_candidates].votes = 0;
                num_candidates++;
                break;

            case 2:
                if (num_candidates == 0) {
                    printf("No candidates registered.\n");
                    break;
                }
                printf("Enter candidate number: ");
                int candidate_num;
                scanf("%d", &candidate_num);
                if (candidate_num >= 0 && candidate_num < num_candidates) {
                    candidates[candidate_num].votes++;
                    printf("Vote cast for %s\n", candidates[candidate_num].name);
                } else {
                    printf("Invalid candidate number.\n");
                }
                break;

            case 3:
                if (num_candidates == 0) {
                    printf("No candidates registered.\n");
                    break;
                }
                printf("\nCandidate Name\tVotes\n");
                for (int i = 0; i < num_candidates; i++) {
                    printf("%s\t\t%d\n", candidates[i].name, candidates[i].votes);
                }
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}