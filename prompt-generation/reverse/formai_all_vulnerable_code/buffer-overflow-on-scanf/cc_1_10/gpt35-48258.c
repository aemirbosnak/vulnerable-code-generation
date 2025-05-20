//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Define constants
#define MAX_CANDIDATES 10
#define MAX_VOTERS 20

// Declare structs
typedef struct {
    int id;
    char name[20];
    int num_votes;
} Candidate;

typedef struct {
    int id;
    char name[20];
    int voted_for;
} Voter;

// Declare global variables
Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];

int num_candidates = 0;
int num_voters = 0;

// Function prototypes
void add_candidate();
void print_candidates();
void add_voter();
void print_voters();
void cast_vote();

int main() {
    int choice;
    do {
        printf("\n-- Electronic Voting System --\n");
        printf("1. Add Candidate\n");
        printf("2. Print Candidates\n");
        printf("3. Add Voter\n");
        printf("4. Print Voters\n");
        printf("5. Cast Vote\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_candidate();
                break;
            case 2:
                print_candidates();
                break;
            case 3:
                add_voter();
                break;
            case 4:
                print_voters();
                break;
            case 5:
                cast_vote();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choice != 6);
    return 0;
}

void add_candidate() {
    if (num_candidates < MAX_CANDIDATES) {
        Candidate c;
        printf("Enter candidate ID: ");
        scanf("%d", &c.id);
        printf("Enter candidate name: ");
        scanf("%s", c.name);
        c.num_votes = 0;
        candidates[num_candidates++] = c;
        printf("Candidate added.\n");
    } else {
        printf("Maximum number of candidates reached.\n");
    }
}

void print_candidates() {
    if (num_candidates > 0) {
        printf("\n-- Candidates --\n");
        for (int i = 0; i < num_candidates; i++) {
            printf("%d. %s (%d votes)\n", candidates[i].id, candidates[i].name, candidates[i].num_votes);
        }
    } else {
        printf("No candidates found.\n");
    }
}

void add_voter() {
    if (num_voters < MAX_VOTERS) {
        Voter v;
        printf("Enter voter ID: ");
        scanf("%d", &v.id);
        printf("Enter voter name: ");
        scanf("%s", v.name);
        v.voted_for = 0;
        voters[num_voters++] = v;
        printf("Voter added.\n");
    } else {
        printf("Maximum number of voters reached.\n");
    }
}

void print_voters() {
    if (num_voters > 0) {
        printf("\n-- Voters --\n");
        for (int i = 0; i < num_voters; i++) {
            printf("%d. %s (%d)\n", voters[i].id, voters[i].name, voters[i].voted_for);
        }
    } else {
        printf("No voters found.\n");
    }
}

void cast_vote() {
    if (num_voters > 0 && num_candidates > 0) {
        int voter_id, candidate_id;
        printf("Enter voter ID: ");
        scanf("%d", &voter_id);
        for (int i = 0; i < num_voters; i++) {
            if (voters[i].id == voter_id) {
                if (voters[i].voted_for != 0) {
                    printf("This voter has already cast a vote.\n");
                    return;
                }
                printf("Enter candidate ID: ");
                scanf("%d", &candidate_id);
                for (int j = 0; j < num_candidates; j++) {
                    if (candidates[j].id == candidate_id) {
                        candidates[j].num_votes++;
                        voters[i].voted_for = candidate_id;
                        printf("Vote casted.\n");
                        return;
                    }
                }
                printf("Invalid candidate ID.\n");
                return;
            }
        }
        printf("Invalid voter ID.\n");
        return;
    } else {
        printf("No voters or candidates found.\n");
    }
}