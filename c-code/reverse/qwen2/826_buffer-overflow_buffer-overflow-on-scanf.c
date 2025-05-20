#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define NAME_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
} Candidate;

Candidate candidates[MAX_CANDIDATES];
int candidate_count = 0;

void add_candidate() {
    if (candidate_count >= MAX_CANDIDATES) {
        printf("Cannot add more candidates.\n");
        return;
    }
    printf("Enter candidate name: ");
    scanf("%s", candidates[candidate_count].name);
    candidate_count++;
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Add Candidate\n2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_candidate();
                break;
            case 2:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
