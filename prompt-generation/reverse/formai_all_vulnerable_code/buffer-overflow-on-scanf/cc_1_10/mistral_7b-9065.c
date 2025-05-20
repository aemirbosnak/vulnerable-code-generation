//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int votes;
} Candidate;

Candidate candidates[MAX_CANDIDATES];

void print_menu() {
    printf("\n--- Electronic Voting System ---\n");
    printf("1. Cast your vote\n");
    printf("2. View current vote count\n");
    printf("3. Exit\n");
}

int main() {
    int choice, i, valid_input;
    char name[MAX_NAME_LEN];

    for (i = 0; i < MAX_CANDIDATES; i++) {
        strcpy(candidates[i].name, "Candidate"); // Initialize names with placeholder values
        candidates[i].votes = 0;
    }

    while (1) {
        print_menu();
        scanf("%d", &choice);

        if (choice < 1 || choice > 3) {
            printf("Invalid input. Please try again.\n");
            continue;
        }

        valid_input = 1;

        switch (choice) {
            case 1:
                printf("Enter candidate name: ");
                scanf("%s", name);

                for (i = 0; i < MAX_CANDIDATES; i++) {
                    if (strcmp(name, candidates[i].name) == 0) {
                        candidates[i].votes++;
                        printf("Your vote has been recorded.\n");
                        valid_input = 0;
                        break;
                    }
                }

                if (valid_input) {
                    printf("Invalid candidate name. Please try again.\n");
                }

                break;

            case 2:
                printf("\nCurrent vote count:\n");
                for (i = 0; i < MAX_CANDIDATES; i++) {
                    printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
                }
                break;

            case 3:
                printf("Exiting the Electronic Voting System...\n");
                exit(0);
        }
    }

    return 0;
}