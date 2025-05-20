//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VOTE_COUNT_MAX 10

typedef struct {
    char name[32];
    int vote_count;
} candidate_t;

candidate_t candidates[VOTE_COUNT_MAX];
int candidate_count = 0;

void add_candidate(char *name) {
    strcpy(candidates[candidate_count].name, name);
    candidates[candidate_count].vote_count = 0;
    candidate_count++;
}

void print_candidates() {
    printf("Candidates:\n");
    for (int i = 0; i < candidate_count; i++) {
        printf("%s - %d votes\n", candidates[i].name, candidates[i].vote_count);
    }
}

void vote_candidate(char *name) {
    for (int i = 0; i < candidate_count; i++) {
        if (strcmp(candidates[i].name, name) == 0) {
            candidates[i].vote_count++;
            return;
        }
    }
}

int main() {
    add_candidate("Romeo");
    add_candidate("Juliet");
    add_candidate("Tybalt");

    int choice;
    char input[32];

    while (1) {
        printf("1. Vote\n2. View Results\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter candidate name: ");
                scanf("%s", input);
                vote_candidate(input);
                break;
            case 2:
                print_candidates();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}