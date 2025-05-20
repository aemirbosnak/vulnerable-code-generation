//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct candidate {
    char name[50];
    int votes;
};

void cast_vote(struct candidate candidates[], int num) {
    int choice;
    printf("Select your candidate:\n");
    for(int i=0; i<num; i++) {
        printf("%d. %s\n", i+1, candidates[i].name);
    }
    printf("Enter your choice: ");
    scanf("%d", &choice);
    if(choice>=1 && choice<=num) {
        candidates[choice-1].votes++;
        printf("Your vote has been cast for %s. Thank you!\n", candidates[choice-1].name);
    }
    else {
        printf("Invalid choice! Please try again.\n");
    }
}

void display_results(struct candidate candidates[], int num) {
    printf("----------- ELECTION RESULTS -----------\n");
    for(int i=0; i<num; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
    printf("----------------------------------------\n");
}

int main() {
    int num;
    printf("Enter the number of candidates: ");
    scanf("%d", &num);
    struct candidate candidates[num];
    for(int i=0; i<num; i++) {
        printf("Enter the name of candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }
    while(1) {
        printf("Welcome to the Electronic Voting System!\n");
        printf("1. Cast Vote\n");
        printf("2. Display Results\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                cast_vote(candidates, num);
                break;
            case 2:
                display_results(candidates, num);
                break;
            case 3:
                printf("Thank you for using the Electronic Voting System!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}