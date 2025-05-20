//FormAI DATASET v1.0 Category: Password management ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_PASSWORDS 10 // maximum number of passwords that can be stored
#define MAX_PASSWORD_LENGTH 20 // maximum length of each password

int count = 0; // number of passwords currently stored

char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH]; // 2D array to store passwords

int main() {
    printf("Welcome to the Password Manager!\n");
    printf("Enter 'add' to add a new password or 'show' to display saved passwords.\n");
    printf("Enter 'exit' to quit the program.\n\n");
    
    while (1) {
        char input[MAX_PASSWORD_LENGTH];
        printf("Enter a command: ");
        scanf("%s", input);
        
        if (strcmp(input, "add") == 0) {
            if (count < MAX_PASSWORDS) {
                char password[MAX_PASSWORD_LENGTH];
                printf("Enter a password: ");
                scanf("%s", password);
                
                // Store password in array
                strcpy(passwords[count], password);
                count++;
                
                printf("Password saved successfully!\n\n");
            } else {
                printf("Error: Maximum number of passwords reached.\n\n");
            }
        } else if (strcmp(input, "show") == 0) {
            printf("Saved passwords:\n");
            for (int i = 0; i < count; i++) {
                printf("%d. %s\n", i+1, passwords[i]);
            }
            printf("\n");
        } else if (strcmp(input, "exit") == 0) {
            printf("Goodbye!\n");
            exit(0);
        } else {
            printf("Error: Invalid command entered.\n\n");
        }
    }
    
    return 0;
}