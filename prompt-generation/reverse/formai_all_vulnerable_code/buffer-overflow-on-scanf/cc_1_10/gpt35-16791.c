//FormAI DATASET v1.0 Category: Digital Diary ; Style: visionary
#include <stdio.h>

/* This program is a digital diary that allows users to input and store their thoughts in a file. */

int main() {
    char entry[1000]; // Array to store user input
    FILE *fp; // Variable to reference file
    int choice; // Variable to hold user's choice

    printf("Welcome to your digital diary.\n");
    
    // Get user's choice
    printf("\nWould you like to:\n");
    printf("1. View existing diary entries\n");
    printf("2. Create a new entry\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // View existing diary entries
    if (choice == 1) {
        fp = fopen("diary.txt", "r");
        if (fp == NULL) {
            printf("Error: File not found.\n");
            return 1;
        }
        printf("\nYour existing diary entries:\n");
        while(fgets(entry, 1000, fp) != NULL) {
            printf("%s", entry);
        }
        fclose(fp);
    }

    // Create new entry
    else if (choice == 2) {
        fp = fopen("diary.txt", "a"); // Open file in append mode
        if (fp == NULL) {
            printf("Error: Could not create file.\n");
            return 1;
        }
        printf("\nEnter your diary entry:\n");
        fflush(stdin); // Clear buffer
        fgets(entry, 1000, stdin); // Read user input
        fprintf(fp, "%s\n", entry); // Write input to file
        fclose(fp);
    }

    // Exit
    else if (choice == 3) {
        printf("\nGoodbye!\n");
        return 0;
    }

    // Invalid input
    else {
        printf("\nInvalid input. Please try again.\n");
        return 1;
    }

    return 0;
}