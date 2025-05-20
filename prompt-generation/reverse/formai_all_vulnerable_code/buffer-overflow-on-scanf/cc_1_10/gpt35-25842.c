//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cyberpunk style electronic voting system

int main() {

    char passphrase[10] = "cyber";
    int voteCountA = 0, voteCountB = 0, voteCountC = 0, voteCountD = 0;
    int passCorrect = 0, voteComplete = 0, voteSelected = 0;
    char voterName[50], voterID[50], candidate[50];

    // login system
    printf("Enter your passphrase to access the voting panel: ");
    scanf("%s", &passphrase);
    if(strcmp(passphrase, "cyber") == 0) {
        printf("Access granted! Welcome to the electronic voting system.\n");
        passCorrect = 1;
    } else {
        printf("Access denied! Please try again later.\n");
        exit(0);
    }

    // voter registration system
    printf("Please enter your name: ");
    scanf("%s", &voterName);
    printf("Please enter your voter ID: ");
    scanf("%s", &voterID);
    printf("Registration successful!\n");

    // voting system
    while(voteComplete == 0) {
        printf("Vote for one of the following candidates by entering their name:\n");
        printf("A: Mr. Hacker\n");
        printf("B: Ms. Virus\n");
        printf("C: Dr. Cyber\n");
        printf("D: Mr. Robot\n");
        scanf("%s", &candidate);

        if(strcmp(candidate, "A") == 0) {
            printf("Thank you for voting for Mr. Hacker!\n");
            voteCountA++;
            voteSelected = 1;
        } else if(strcmp(candidate, "B") == 0) {
            printf("Thank you for voting for Ms. Virus!\n");
            voteCountB++;
            voteSelected = 1;
        } else if(strcmp(candidate, "C") == 0) {
            printf("Thank you for voting for Dr. Cyber!\n");
            voteCountC++;
            voteSelected = 1;
        } else if(strcmp(candidate, "D") == 0) {
            printf("Thank you for voting for Mr. Robot!\n");
            voteCountD++;
            voteSelected = 1;
        } else {
            printf("Invalid selection! Please try again.\n");
            voteSelected = 0;
        }

        if(voteSelected == 1) {
            printf("Do you want to continue voting? (Y/N): ");
            char choice[1];
            scanf("%s", &choice);
            if(strcmp(choice, "Y") != 0) {
                voteComplete = 1;
            }
        }
    }

    // results
    printf("Results:\n");
    printf("Mr. Hacker: %d votes\n", voteCountA);
    printf("Ms. Virus: %d votes\n", voteCountB);
    printf("Dr. Cyber: %d votes\n", voteCountC);
    printf("Mr. Robot: %d votes\n", voteCountD);

    return 0;
}