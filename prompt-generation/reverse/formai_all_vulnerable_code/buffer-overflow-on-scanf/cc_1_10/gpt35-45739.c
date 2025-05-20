//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: active
#include <stdio.h>
#include <stdlib.h>

struct candidate {
    char name[20];
    int votes;
};

void print_menu() {
    printf("\n");
    printf("*****************************\n");
    printf("ELECTRONIC VOTING SYSTEM MENU\n");
    printf("1. Add candidate\n");
    printf("2. View candidates\n");
    printf("3. Vote for candidate\n");
    printf("4. View vote count\n");
    printf("5. Exit\n");
    printf("*****************************\n");
    printf("\n");
}

void add_candidate(struct candidate* candidates, int* num_candidates) {
    printf("Enter candidate name: ");
    scanf("%s", candidates[*num_candidates].name);
    candidates[*num_candidates].votes = 0;
    *num_candidates += 1;
    printf("Candidate added successfully!\n");
}

void view_candidates(struct candidate* candidates, int num_candidates) {
    printf("Candidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i+1, candidates[i].name);
    }
}

void vote_for_candidate(struct candidate* candidates, int num_candidates) {
    char name[20];
    printf("Enter candidate name: ");
    scanf("%s", name);
    for (int i = 0; i < num_candidates; i++) {
        if (strcmp(name, candidates[i].name) == 0) {
            candidates[i].votes += 1;
            printf("Vote recorded for %s!\n", candidates[i].name);
            return;
        }
    }
    printf("Candidate not found.\n");
}

void view_vote_count(struct candidate* candidates, int num_candidates) {
    for (int i = 0; i < num_candidates; i++) {
        printf("%s has %d votes.\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    struct candidate candidates[10];
    int num_candidates = 0;
    int option;
    do {
        print_menu();
        printf("Enter option: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                add_candidate(candidates, &num_candidates);
                break;
            case 2:
                view_candidates(candidates, num_candidates);
                break;
            case 3:
                vote_for_candidate(candidates, num_candidates);
                break;
            case 4:
                view_vote_count(candidates, num_candidates);
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option.\n");
        }
    } while (option != 5);

    return 0;
}