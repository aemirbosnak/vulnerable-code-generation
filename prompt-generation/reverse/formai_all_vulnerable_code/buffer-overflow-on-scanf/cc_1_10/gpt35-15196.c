//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: modular
// C Electronic Voting System Example Program

#include <stdio.h>
#include <stdlib.h>

int main() {
    int voterID, choice, count = 0;
    char confirm;
    FILE *fp;
    
    // Open file for writing the results
    fp = fopen("results.txt", "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    
    // Welcome message and voter ID input
    printf("Welcome to the Electronic Voting System.\n");
    printf("Enter your Voter ID: ");
    scanf("%d", &voterID);
    
    // Display voting options and input choice
    printf("\n\t\t~~~ Voting Options ~~~\n");
    printf("1. Option 1\n");
    printf("2. Option 2\n");
    printf("3. Option 3\n");
    printf("4. Option 4\n");
    printf("5. Option 5\n");
    printf("\nEnter your vote (1-5): ");
    scanf("%d", &choice);
    
    // Confirmation message and input
    printf("\nAre you sure you want to cast this vote? (Y/N): ");
    scanf(" %c", &confirm);
    
    // If voter confirms vote, write it to file
    if (confirm == 'Y' || confirm == 'y') {
        fprintf(fp, "Voter ID: %d\nChoice: %d\n\n", voterID, choice);
        printf("\nThank you! Your vote has been cast.\n");
        count++;
    } else {
        printf("\nVote cancelled. Please try again.\n");
    }
    
    // Close file
    fclose(fp);
    
    // Display voting results
    printf("\n~~~ Voting Results ~~~\n");
    printf("%d vote(s) were cast.\n", count);
    
    // Open file for reading and display results
    fp = fopen("results.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    char c;
    while ((c = getc(fp)) != EOF) {
        putchar(c);
    }
    
    // Close file
    fclose(fp);
    
    return 0;
}