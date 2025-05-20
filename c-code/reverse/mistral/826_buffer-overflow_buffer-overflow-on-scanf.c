#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

struct Candidate {
    char name[MAX_NAME_LENGTH];
    int votes;
};

struct Candidate candidates[10];
int num_candidates = 0;

void add_candidate(char *name) {
    if (num_candidates >= 10) {
        printf("Maximum number of candidates reached.\n");
        return;
    }
    strcpy(candidates[num_candidates].name, name);
    candidates[num_candidates].votes = 0;
    num_candidates++;
}

int main() {
    char input[MAX_NAME_LENGTH];
    int choice;

    while (1) {
        printf("1. Add Candidate\n2. Vote\n3. Display Results\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter candidate name: ");
                scanf("%s", input);
                add_candidate(input);
                break;
            case 2:
                // Voting logic here
                break;
            case 3:
                // Display results logic here
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
