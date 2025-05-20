//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// Declare variables
int candidate1 = 0, candidate2 = 0, candidate3 = 0, candidate4 = 0, candidate5 = 0;
char candidateNames[5][20];

void printMenu() {
    printf("\n----- Welcome to the Electronic Voting System -----\n");
    printf("Please select an option:\n");
    printf("1. Add candidate\n");
    printf("2. Vote\n");
    printf("3. View results\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

void addCandidate() {
    printf("\n----- Add Candidate -----\n");
    for(int i=0; i<5; i++) {
        if(candidateNames[i][0] == '\0') {
            printf("Enter candidate name: ");
            scanf("%s", candidateNames[i]);
            printf("Candidate added successfully!\n");
            return;
        }
    }
    printf("Sorry, the maximum number of candidates has been reached.\n");
}

void vote() {
    int choice;
    printf("\n----- Vote -----\n");
    printf("Please select a candidate:\n");
    for(int i=0; i<5; i++) {
        if(candidateNames[i][0] != '\0') {
            printf("%d. %s\n", i+1, candidateNames[i]);
        }
    }
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice) {
        case 1:
            printf("You voted for %s\n",candidateNames[0]);
            candidate1++;
            break;
        case 2:
            printf("You voted for %s\n",candidateNames[1]);
            candidate2++;
            break;
        case 3:
            printf("You voted for %s\n",candidateNames[2]);
            candidate3++;
            break;
        case 4:
            printf("You voted for %s\n",candidateNames[3]);
            candidate4++;
            break;
        case 5:
            printf("You voted for %s\n",candidateNames[4]);
            candidate5++;
            break;
        default:
            printf("Invalid choice.\n");
    }
}

void viewResults() {
    printf("\n----- Results -----\n");
    for(int i=0; i<5; i++) {
        if(candidateNames[i][0] != '\0') {
            printf("%s: %d votes.\n",candidateNames[i],i==0?candidate1:i==1?candidate2:i==2?candidate3:i==3?candidate4:candidate5);
        }
    }
}

int main() {
    int option;
    printf("Enter the names of the candidates:\n");
    for(int i=0; i<5; i++) {
        printf("Candidate %d: ",i+1);
        scanf("%s", candidateNames[i]);
    }
    while(1) {
        printMenu();
        scanf("%d",&option);
        switch(option) {
            case 1:
                addCandidate();
                break;
            case 2:
                vote();
                break;
            case 3:
                viewResults();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}