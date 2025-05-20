//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct candidate {
    char name[50];
    int votes;
};

void print_candidates(struct candidate *list, int size) {
    printf("Candidates:\n");
    for(int i=0; i<size; i++) {
        printf("%d) %s\n", i+1, list[i].name);
    }
}

void vote(struct candidate *list, int size, int choice) {
    if(choice < 1 || choice > size) {
        printf("Invalid choice!\n");
        return;
    }
    list[choice-1].votes++;
    printf("Your vote for %s has been counted!\n", list[choice-1].name);
}

void print_results(struct candidate *list, int size) {
    if(size == 0) {
        printf("No candidates!\n");
        return;
    }
    printf("Results:\n");
    for(int i=0; i<size; i++) {
        printf("%s - %d votes\n", list[i].name, list[i].votes);
    }
}

int main() {
    int num_candidates, choice;
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    struct candidate *candidates = (struct candidate *) malloc(num_candidates * sizeof(struct candidate));
    for(int i=0; i<num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    printf("Welcome to the voting system!\n");
    while(true) {
        printf("Options:\n1) View candidates\n2) Vote\n3) View results\n4) Quit\n");

        int option;
        printf("Enter an option: ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                print_candidates(candidates, num_candidates);
                break;
            case 2:
                printf("Enter your choice: ");
                scanf("%d", &choice);
                vote(candidates, num_candidates, choice);
                break;
            case 3:
                print_results(candidates, num_candidates);
                break;
            case 4:
                printf("Goodbye!\n");
                free(candidates);
                return 0;
            default:
                printf("Invalid option!\n");
                break;
        }
    }
}