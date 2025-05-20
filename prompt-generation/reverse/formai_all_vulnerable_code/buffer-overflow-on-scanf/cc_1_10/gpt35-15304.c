//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 10

typedef struct {
    char name[20];
    int votes;
} candidate;

typedef struct {
    int id;
    char name[30];
    int voted;
} voter;

candidate candidates[MAX_CANDIDATES];
voter voters[MAX_VOTERS];
int num_candidates, num_voters;

void print_candidates() {
    printf("List of Candidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i+1, candidates[i].name);
    }
}

void add_candidate() {
    if (num_candidates == MAX_CANDIDATES) {
        printf("Error: Maximum candidate limit reached.\n");
        return;
    }

    printf("Enter candidate name: ");
    scanf("%s", candidates[num_candidates].name);
    candidates[num_candidates].votes = 0;
    num_candidates++;
}

void delete_candidate() {
    if (num_candidates == 0) {
        printf("Error: No candidates to delete.\n");
        return;
    }

    print_candidates();
    printf("Enter candidate number to delete: ");
    int choice;
    scanf("%d", &choice);

    if (choice < 1 || choice > num_candidates) {
        printf("Error: Invalid choice.\n");
        return;
    }

    for (int i = choice - 1; i < num_candidates - 1; i++) {
        candidates[i] = candidates[i+1];
    }

    num_candidates--;
    printf("Candidate deleted.\n");
}

void print_voters() {
    printf("List of Voters:\n");
    for (int i = 0; i < num_voters; i++) {
        printf("%d. %s\n", voters[i].id, voters[i].name);
    }
}

void add_voter() {
    if (num_voters == MAX_VOTERS) {
        printf("Error: Maximum voter limit reached.\n");
        return;
    }

    printf("Enter voter name: ");
    scanf("%s", voters[num_voters].name);
    voters[num_voters].id = num_voters + 1;
    voters[num_voters].voted = 0;
    num_voters++;
}

void delete_voter() {
    if (num_voters == 0) {
        printf("Error: No voters to delete.\n");
        return;
    }

    print_voters();
    printf("Enter voter ID to delete: ");
    int choice;
    scanf("%d", &choice);

    if (choice < 1 || choice > num_voters) {
        printf("Error: Invalid choice.\n");
        return;
    }

    for (int i = choice - 1; i < num_voters - 1; i++) {
        voters[i] = voters[i+1];
    }

    num_voters--;
    printf("Voter deleted.\n");
}

void cast_vote() {
    if (num_voters == 0) {
        printf("Error: No voters registered.\n");
        return;
    }

    printf("Enter voter ID: ");
    int voter_id;
    scanf("%d", &voter_id);

    for (int i = 0; i < num_voters; i++) {
        if (voters[i].id == voter_id) {
            if (voters[i].voted) {
                printf("Error: This voter has already voted.\n");
                return;
            }

            print_candidates();
            printf("Enter candidate number to vote for: ");
            int candidate_number;
            scanf("%d", &candidate_number);

            if (candidate_number < 1 || candidate_number > num_candidates) {
                printf("Error: Invalid choice.\n");
                return;
            }

            candidates[candidate_number - 1].votes++;
            voters[i].voted = 1;
            printf("Vote cast.\n");
            return;
        }
    }

    printf("Error: Voter not found.\n");
}

void print_results() {
    if (num_candidates == 0) {
        printf("No candidates to display.\n");
        return;
    }

    printf("%-20s %s\n", "Candidate Name", "Votes");
    for (int i = 0; i < num_candidates; i++) {
        printf("%-20s %d\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int choice;

    do {
        printf("\n");
        printf("Electronic Voting System\n");
        printf("=========================\n");
        printf("1. Add Candidate\n");
        printf("2. Delete Candidate\n");
        printf("3. Add Voter\n");
        printf("4. Delete Voter\n");
        printf("5. Cast Vote\n");
        printf("6. Print Results\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_candidate();
                break;
            case 2:
                delete_candidate();
                break;
            case 3:
                add_voter();
                break;
            case 4:
                delete_voter();
                break;
            case 5:
                cast_vote();
                break;
            case 6:
                print_results();
                break;
            case 7:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 7);

    return 0;
}