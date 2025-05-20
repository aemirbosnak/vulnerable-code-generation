//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: authentic
#include <stdio.h>
#include <string.h>
#define MAX_CANDIDATES 10
#define MAX_NAME_LEN 50
typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    int votes;
} Candidate;
Candidate candidates[MAX_CANDIDATES];
int main() {
    int choice, candidate_id, i;
    char name[MAX_NAME_LEN];
    int num_candidates = 0;
    while (1) {
        printf("\n------------------ Electronic Voting System -----------------\n");
        printf("\n1. Register Candidate\n");
        printf("2. Cast Vote\n");
        printf("3. View Vote Count\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (num_candidates >= MAX_CANDIDATES) {
                    printf("\nMaximum number of candidates reached.\n");
                    break;
                }
                printf("\nEnter Candidate ID: ");
                scanf("%d", &candidates[num_candidates].id);
                printf("Enter Candidate Name: ");
                fgets(name, sizeof(name), stdin);
                strtok(name, "\n");
                strcpy(candidates[num_candidates].name, name);
                candidates[num_candidates].votes = 0;
                num_candidates++;
                break;
            case 2:
                printf("\nEnter Candidate ID to Cast Vote: ");
                scanf("%d", &candidate_id);
                for (i = 0; i < num_candidates; i++) {
                    if (candidates[i].id == candidate_id) {
                        candidates[i].votes++;
                        break;
                    }
                }
                if (i == num_candidates) {
                    printf("\nInvalid Candidate ID.\n");
                }
                break;
            case 3:
                printf("\nVote Count:\n");
                for (i = 0; i < num_candidates; i++) {
                    printf("\nID: %d, Name: %s, Votes: %d", candidates[i].id, candidates[i].name, candidates[i].votes);
                }
                break;
            case 4:
                printf("\nExiting the System.\n");
                exit(0);
            default:
                printf("\nInvalid Choice.\n");
        }
    }
    return 0;
}