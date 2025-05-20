//FormAI DATASET v1.0 Category: Password management ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20

int main() {
    char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH];  // Initialize 2D array to store passwords
    int count = 0;  // Initialize count variable to keep track of passwords entered
    char input[MAX_PASSWORD_LENGTH];  // Initialize input variable to store user input

    printf("Welcome to Password Manager!\n");

    // Loop until maximum number of passwords are entered or user enters "QUIT"
    while(count < MAX_PASSWORDS) {
        printf("Enter password %d (or type \"QUIT\" to exit): ", count+1);
        scanf("%s", input);

        // If user enters "QUIT", exit the loop
        if(strcmp(input, "QUIT") == 0) {
            break;
        }

        // Check if password length is within the allowed limit
        if(strlen(input) > MAX_PASSWORD_LENGTH-1) {
            printf("Password is too long. Please enter a password with no more than %d characters.\n", MAX_PASSWORD_LENGTH-1);
            continue;
        }

        // Add password to the list and increment count
        strcpy(passwords[count], input);
        count++;
    }

    // If no passwords were entered, print a message and exit
    if(count == 0) {
        printf("No passwords were entered. Goodbye!\n");
        return 0;
    }

    // Sort the passwords alphabetically
    for(int i=0; i<count-1; i++) {
        for(int j=i+1; j<count; j++) {
            if(strcmp(passwords[i], passwords[j]) > 0) {
                char temp[MAX_PASSWORD_LENGTH];
                strcpy(temp, passwords[i]);
                strcpy(passwords[i], passwords[j]);
                strcpy(passwords[j], temp);
            }
        }
    }

    // Print out the sorted list of passwords
    printf("Here are your passwords, sorted alphabetically:\n");
    for(int i=0; i<count; i++) {
        printf("%d. %s\n", i+1, passwords[i]);
    }

    return 0;
}