//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10 // maximum number of candidates
#define MAX_VOTERS 100 // maximum number of voters

typedef struct {
    char name[50]; // candidate name
    int votes; // candidate vote count
} Candidate;

Candidate candidates[MAX_CANDIDATES]; // array of candidates
int num_candidates = 0; // number of candidates
char password[50] = "mypassword"; // admin password
int voter_ids[MAX_VOTERS]; // array of voter IDs
int num_voters = 0; // number of registered voters
int voted_ids[MAX_VOTERS]; // array of voted IDs
int num_voted = 0; // number of voted voters

// function prototypes
void add_candidate();
void display_candidates();
void vote();
void admin_login();

int main() {
    int choice;

    printf("***Welcome to My Electronic Voting System***\n");

    while (1) {
        printf("\nPlease select an option:\n");
        printf("1. Add Candidate\n");
        printf("2. Display Candidates\n");
        printf("3. Vote\n");
        printf("4. Admin Login\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_candidate();
                break;
            case 2:
                display_candidates();
                break;
            case 3:
                vote();
                break;
            case 4:
                admin_login();
                break;
            case 5:
                printf("Thank you for using our system.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void add_candidate() {
    if (num_candidates == MAX_CANDIDATES) {
        printf("Maximum number of candidates reached.\n");
        return;
    }

    printf("Enter candidate name: ");
    scanf("%s", candidates[num_candidates].name);
    candidates[num_candidates].votes = 0;
    num_candidates++;

    printf("Candidate added successfully.\n");
}

void display_candidates() {
    printf("List of candidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s (%d votes)\n", i+1, candidates[i].name, candidates[i].votes);
    }
}

void vote() {
    int voter_id;
    int candidate_no;

    if (num_voters == MAX_VOTERS) {
        printf("Maximum number of voters reached.\n");
        return;
    }

    printf("Enter voter ID: ");
    scanf("%d", &voter_id);

    // check if voter already voted
    for (int i = 0; i < num_voted; i++) {
        if (voted_ids[i] == voter_id) {
            printf("You have already voted!\n");
            return;
        }
    }

    // check if voter is registered
    for (int i = 0; i < num_voters; i++) {
        if (voter_ids[i] == voter_id) {
            printf("Enter candidate number: ");
            scanf("%d", &candidate_no);

            if (candidate_no < 1 || candidate_no > num_candidates) {
                printf("Invalid candidate number. Please try again.\n");
                return;
            }

            candidates[candidate_no-1].votes++;
            voted_ids[num_voted] = voter_id;
            num_voted++;

            printf("Thank you for voting!\n");
            return;
        }
    }

    printf("You are not a registered voter. Please contact the administration.\n");
}

void admin_login() {
    char input[50];
    printf("Please enter the password: ");
    scanf("%s", input);

    if (strcmp(input, password) == 0) {
        printf("Admin Login successful.\n");

        printf("\nPlease select an option:\n");
        printf("1. Print Voting Results\n");
        printf("2. Reset Voting Results\n");
        printf("3. Add Voter\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_candidates();
                break;
            case 2:
                for (int i = 0; i < num_candidates; i++) {
                    candidates[i].votes = 0;
                }
                num_voted = 0;
                printf("Voting results reset.\n");
                break;
            case 3:
                if (num_voters == MAX_VOTERS) {
                    printf("Maximum number of voters reached.\n");
                    break;
                }
                printf("Enter voter ID: ");
                int voter_id;
                scanf("%d", &voter_id);
                voter_ids[num_voters] = voter_id;
                num_voters++;
                printf("Voter added successfully.\n");
                break;
            case 4:
                printf("Thank you for using our system.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    else {
        printf("Access denied!\n");
    }
}