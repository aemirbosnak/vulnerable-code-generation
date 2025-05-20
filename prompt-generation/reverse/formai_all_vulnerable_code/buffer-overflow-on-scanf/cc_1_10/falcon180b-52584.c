//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct {
    char name[100];
    int votes;
} candidate;

candidate candidates[10];
int num_candidates;

void add_candidate() {
    printf("Enter candidate name: ");
    scanf("%s", candidates[num_candidates].name);
    candidates[num_candidates].votes = 0;
    num_candidates++;
}

void display_candidates() {
    printf("Candidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
}

void cast_vote() {
    int choice;
    printf("Enter candidate number: ");
    scanf("%d", &choice);
    candidates[choice - 1].votes++;
}

void display_results() {
    printf("Results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    srand(time(NULL));
    num_candidates = 0;

    while (num_candidates < 2) {
        add_candidate();
    }

    int choice;
    while (1) {
        display_candidates();
        printf("Enter 1 to vote or 0 to exit: ");
        scanf("%d", &choice);
        if (choice == 0) {
            break;
        }
        cast_vote();
    }

    display_results();

    return 0;
}