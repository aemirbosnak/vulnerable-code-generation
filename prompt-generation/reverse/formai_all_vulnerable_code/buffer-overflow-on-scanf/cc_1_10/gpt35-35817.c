//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: configurable
#include<stdio.h>
#include<stdlib.h>

struct candidate {
    char name[30];
    int votes;
};

void castVote(int n, struct candidate c[]) {
    int i = 0, choice = 0;
    printf("Please choose your candidate:\n");
    for (i = 0; i < n; i++) {
        printf("%d. %s\n", i+1, c[i].name);
    }
    scanf("%d", &choice);
    if (choice >= 1 && choice <= n) {
        c[choice-1].votes++;
        printf("Your vote has been cast successfully for %s!\n", c[choice-1].name);
    } else {
        printf("Invalid choice. Please try again.\n");
    }
}

void printResults(int n, struct candidate c[]) {
    int i = 0;
    printf("\nFinal Vote Count:\n");
    for (i = 0; i < n; i++) {
        printf("%s: %d vote(s)\n", c[i].name, c[i].votes);
    }
}

int main() {
    int i = 0, n = 0, ch = 0;
    printf("Welcome to the Electronic Voting System!\n");
    printf("Please enter the number of candidates: ");
    scanf("%d", &n);
    struct candidate candidates[n];
    for (i = 0; i < n; i++) {
        printf("Candidate %d: ", i+1);
        scanf("%s", &candidates[i].name);
        candidates[i].votes = 0;
    }

    while (ch != 3) {
        printf("\nPlease choose an option:\n");
        printf("1. Cast Vote\n");
        printf("2. View Results\n");
        printf("3. Exit\n");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                castVote(n, candidates);
                break;
            case 2:
                printResults(n, candidates);
                break;
            case 3:
                printf("\nThank you for using the Electronic Voting System!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}