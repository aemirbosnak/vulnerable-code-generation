//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Donald Knuth
/* Electronic Voting System Program
   Written by [Your Name], inspired by Donald Knuth
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_CANDIDATES 10           /* Maximum number of candidates */
#define MAX_VOTERS 50               /* Maximum number of voters */
#define MAX_NAME_LENGTH 20          /* Maximum length of candidate name */
#define PASSWORD 1234               /* Administrator password */

struct candidate {
    char name[MAX_NAME_LENGTH];
    int votes;
};

struct voter {
    char name[MAX_NAME_LENGTH];
    int voted_for;
};

int num_candidates;                 /* Number of candidates */
int num_voters;                     /* Number of voters */

struct candidate candidates[MAX_CANDIDATES];
struct voter voters[MAX_VOTERS];

int authenticate_admin() {
    int password_input;
    printf("\nPlease enter the administrator password: ");
    scanf("%d", &password_input);

    if(password_input != PASSWORD) {
        printf("\nIncorrect password. Access denied.\n");
        return 0;
    }
    else {
        printf("\nAccess granted.\n");
        return 1;
    }
}

void add_candidate() {
    if(num_candidates < MAX_CANDIDATES) {
        printf("\nEnter the name of the candidate: ");
        scanf("%s", candidates[num_candidates].name);
        candidates[num_candidates].votes = 0;
        num_candidates++;
        printf("\nCandidate %d added.\n", num_candidates);
    }
    else {
        printf("\nMaximum number of candidates reached.\n");
    }
}

void list_candidates() {
    printf("\nList of candidates:\n");
    for(int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i+1, candidates[i].name);
    }
}

void add_voter() {
    if(num_voters < MAX_VOTERS) {
        printf("\nEnter the name of the voter: ");
        scanf("%s", voters[num_voters].name);
        voters[num_voters].voted_for = -1;
        num_voters++;
        printf("\nVoter %d added.\n", num_voters);
    }
    else {
        printf("\nMaximum number of voters reached.\n");
    }
}

void cast_vote() {
    char voter_name[MAX_NAME_LENGTH];
    int candidate_choice;

    printf("\nEnter your name: ");
    scanf("%s", voter_name);

    for(int i = 0; i < num_voters; i++) {
        if(strcmp(voter_name, voters[i].name) == 0) {
            if(voters[i].voted_for == -1) {
                printf("\nList of candidates:\n");
                for(int j = 0; j < num_candidates; j++) {
                    printf("%d. %s\n", j+1, candidates[j].name);
                }

                printf("\nEnter your choice: ");
                scanf("%d", &candidate_choice);
                candidate_choice--;

                if(candidate_choice >= 0 && candidate_choice < num_candidates) {
                    voters[i].voted_for = candidate_choice;
                    candidates[candidate_choice].votes++;
                    printf("\nVote casted successfully.\n");
                }
                else {
                    printf("\nInvalid candidate choice.\n");
                }
            }
            else {
                printf("\nYou have already casted your vote.\n");
            }

            return;
        }
    }

    printf("\nYour name was not found in the voter list.\n");
}

void print_results() {
    int max_votes = 0;
    int max_votes_index = -1;

    for(int i = 0; i < num_candidates; i++) {
        if(candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            max_votes_index = i;
        }
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    if(max_votes_index != -1) {
        printf("\n%s wins the election with %d votes.\n", candidates[max_votes_index].name, max_votes);
    }
    else {
        printf("\nNo candidate has won the election.\n");
    }
}

int main() {
    num_candidates = 0;
    num_voters = 0;

    printf("Welcome to the Electronic Voting System.\n");

    while(1) {
        printf("\nMenu:\n");
        printf("1. Administrator login\n");
        printf("2. Add candidate\n");
        printf("3. List candidates\n");
        printf("4. Add voter\n");
        printf("5. Cast vote\n");
        printf("6. Print results\n");
        printf("7. Exit\n");
        printf("\nEnter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(authenticate_admin()) {
                    printf("\nAccess granted. Welcome, administrator.\n");
                }
                break;
            case 2:
                if(num_candidates < MAX_CANDIDATES) {
                    add_candidate();
                }
                else {
                    printf("\nMaximum number of candidates reached.\n");
                }
                break;
            case 3:
                list_candidates();
                break;
            case 4:
                if(num_voters < MAX_VOTERS) {
                    add_voter();
                }
                else {
                    printf("\nMaximum number of voters reached.\n");
                }
                break;
            case 5:
                cast_vote();
                break;
            case 6:
                if(num_candidates > 0 && num_voters > 0) {
                    print_results();
                }
                else {
                    printf("\nThere are no candidates and/or voters.\n");
                }
                break;
            case 7:
                printf("\nThanks for using the Electronic Voting System. Goodbye.\n");
                exit(0);
                break;
            default:
                printf("\nInvalid choice.\n");
                break;
        }
    }

    return 0;
}