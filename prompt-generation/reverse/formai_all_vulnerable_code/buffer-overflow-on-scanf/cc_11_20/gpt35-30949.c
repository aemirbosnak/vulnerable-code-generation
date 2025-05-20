//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: automated
#include <stdio.h>
#include <stdlib.h>

struct candidate {
    char name[50];
    int votes;
};

struct voter {
    int id;
    int voted;
};

int main() {
    int num_candidates, num_voters;
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    struct candidate candidates[num_candidates];

    for (int i = 0; i < num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    printf("\n");

    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    struct voter voters[num_voters];

    for (int i = 0; i < num_voters; i++) {
        voters[i].id = i+1;
        voters[i].voted = 0;
    }

    printf("\n");

    int choice;
    while (1) {
        printf("Menu\n");
        printf("1. Cast Vote\n");
        printf("2. Check Results\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter your voter ID: ");
                int voter_id;
                scanf("%d", &voter_id);

                if (voter_id < 1 || voter_id > num_voters) {
                    printf("Invalid Voter ID!\n");
                    break;
                }

                if (voters[voter_id-1].voted) {
                    printf("You have already voted!\n");
                    break;
                }

                printf("Choose your candidate:\n");
                for (int i = 0; i < num_candidates; i++) {
                    printf("%d. %s\n", i+1, candidates[i].name);
                }

                int candidate_choice;
                scanf("%d", &candidate_choice);

                if (candidate_choice < 1 || candidate_choice > num_candidates) {
                    printf("Invalid Candidate Choice!\n");
                    break;
                }

                candidates[candidate_choice-1].votes++;
                voters[voter_id-1].voted = 1;

                printf("Your vote has been cast!\n");
                break;
            
            case 2:
                printf("Results\n");
                for (int i = 0; i < num_candidates; i++) {
                    printf("%s - %d votes\n", candidates[i].name, candidates[i].votes);
                }
                break;

            case 3:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}