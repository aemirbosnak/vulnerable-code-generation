//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

char candidate_names[MAX_CANDIDATES][50];
int candidate_votes[MAX_CANDIDATES];
char voter_names[MAX_VOTERS][50];
bool has_voted[MAX_VOTERS];

int num_of_candidates;
int num_of_voters;

void print_menu() {
    printf("Menu:\n");
    printf("1. Add candidate\n");
    printf("2. Display candidates\n");
    printf("3. Add voter\n");
    printf("4. Vote for a candidate\n");
    printf("5. Display results\n");
    printf("6. Exit\n");
}

void add_candidate() {
    if (num_of_candidates == MAX_CANDIDATES) {
        printf("Maximum number of candidates reached\n");
        return;
    }
    printf("Enter candidate name: ");
    scanf("%s", candidate_names[num_of_candidates]);
    candidate_votes[num_of_candidates] = 0;
    num_of_candidates++;
}

void display_candidates() {
    if (num_of_candidates == 0) {
        printf("No candidates found\n");
        return;
    }

    printf("List of candidates:\n");
    for (int i = 0; i < num_of_candidates; i++) {
        printf("%d. %s\n", i+1, candidate_names[i]);
    }
}

void add_voter() {
    if (num_of_voters == MAX_VOTERS) {
        printf("Maximum number of voters reached\n");
        return;
    }
    printf("Enter voter name: ");
    scanf("%s", voter_names[num_of_voters]);
    has_voted[num_of_voters] = false;
    num_of_voters++;
}

void vote_for_candidate() {
    if (num_of_candidates == 0) {
        printf("No candidates found\n");
        return;
    }

    char voter_name[50];
    printf("Enter voter name: ");
    scanf("%s", voter_name);

    for (int i = 0; i < num_of_voters; i++) {
        if (strcmp(voter_name, voter_names[i]) == 0) {
            if (has_voted[i]) {
                printf("Voter has already voted\n");
                return;
            }
            has_voted[i] = true;

            int candidate_num;
            printf("Enter candidate number: ");
            scanf("%d", &candidate_num);
            candidate_votes[candidate_num - 1]++;
            printf("Successfully voted\n");
            return;
        }
    }

    printf("Voter not found\n");
}

void display_results() {
    if (num_of_candidates == 0) {
        printf("No candidates found\n");
        return;
    }

    printf("Results:\n");
    for (int i = 0; i < num_of_candidates; i++) {
        printf("%s - %d votes\n", candidate_names[i], candidate_votes[i]);
    }
}

int main() {
    num_of_candidates = 0;
    num_of_voters = 0;

    int option;
    while (true) {
        print_menu();
        printf("Enter option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                add_candidate();
                break;
            case 2:
                display_candidates();
                break;
            case 3:
                add_voter();
                break;
            case 4:
                vote_for_candidate();
                break;
            case 5:
                display_results();
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Invalid option\n");
        }
    }

    return 0;
}