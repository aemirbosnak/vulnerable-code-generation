//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

typedef struct {
    char name[50];
    int age;
    char address[100];
    char occupation[50];
} Voter;

typedef struct {
    char name[50];
    int votes;
} Candidate;

void add_candidate(Candidate candidates[], int* num_candidates) {
    if (*num_candidates == MAX_CANDIDATES) {
        printf("Cannot add more candidates!\n");
        return;
    }

    printf("Enter candidate name: ");
    scanf("%s", candidates[*num_candidates].name);
    candidates[*num_candidates].votes = 0;

    (*num_candidates)++;
}

void add_voter(Voter voters[], int* num_voters) {
    if (*num_voters == MAX_VOTERS) {
        printf("Cannot add more voters!\n");
        return;
    }

    printf("Enter voter name: ");
    scanf("%s", voters[*num_voters].name);

    printf("Enter voter age: ");
    scanf("%d", &voters[*num_voters].age);

    printf("Enter voter address: ");
    scanf("%s", voters[*num_voters].address);

    printf("Enter voter occupation: ");
    scanf("%s", voters[*num_voters].occupation);

    (*num_voters)++;
}

int main() {
    Candidate candidates[MAX_CANDIDATES];
    int num_candidates = 0;

    Voter voters[MAX_VOTERS];
    int num_voters = 0;

    int option;

    do {
        printf("\n\nElectronic Voting System\n");
        printf("1. Add candidate\n");
        printf("2. Add voter\n");
        printf("3. View candidates\n");
        printf("4. Vote\n");
        printf("5. Results\n");
        printf("6. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                add_candidate(candidates, &num_candidates);
                break;
            case 2:
                add_voter(voters, &num_voters);
                break;
            case 3:
                if (num_candidates == 0) {
                    printf("No candidates added yet!\n");
                    break;
                }

                printf("Candidates:\n");
                for (int i = 0; i < num_candidates; i++) {
                    printf("%s\n", candidates[i].name);
                }

                break;
            case 4:
                if (num_voters == 0) {
                    printf("No voters added yet!\n");
                    break;
                }

                printf("Enter voter name: ");
                char name[50];
                scanf("%s", name);

                int found_voter = 0;
                int index_voter = -1;

                for (int i = 0; i < num_voters; i++) {
                    if (strcmp(voters[i].name, name) == 0) {
                        found_voter = 1;
                        index_voter = i;
                        break;
                    }
                }

                if (!found_voter) {
                    printf("Voter not found!\n");
                    break;
                }

                if (voters[index_voter].age < 18) {
                    printf("Voter is under 18 years of age!\n");
                    break;
                }

                printf("Enter candidate name: ");
                char candidate_name[50];
                scanf("%s", candidate_name);

                int found_candidate = 0;
                int index_candidate = -1;

                for (int i = 0; i < num_candidates; i++) {
                    if (strcmp(candidates[i].name, candidate_name) == 0) {
                        found_candidate = 1;
                        index_candidate = i;
                        break;
                    }
                }

                if (!found_candidate) {
                    printf("Candidate not found!\n");
                    break;
                }

                candidates[index_candidate].votes++;

                printf("Vote successful!\n");

                break;
            case 5:
                if (num_candidates == 0) {
                    printf("No candidates added yet!\n");
                    break;
                }

                int total_votes = 0;
                for (int i = 0; i < num_candidates; i++) {
                    total_votes += candidates[i].votes;
                }

                printf("Results:\n");
                for (int i = 0; i < num_candidates; i++) {
                    printf("%s: %d votes (%.2f %%)\n", candidates[i].name, candidates[i].votes, (float)candidates[i].votes / total_votes * 100);
                }

                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option!\n");
                break;
        }
    } while (option != 6);

    return 0;
}