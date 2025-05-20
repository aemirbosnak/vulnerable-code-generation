//FormAI DATASET v1.0 Category: Password management ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASS_LENGTH 20

int main() {
    char passwords[MAX_PASSWORDS][MAX_PASS_LENGTH];
    int num_passwords = 0;
    
    while (1) {
        printf("\nWelcome to Password Manager!\n");
        printf("1. Add Password\n");
        printf("2. View Passwords\n");
        printf("3. Exit\n");
        
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                if (num_passwords == MAX_PASSWORDS) {
                    printf("Sorry, you have reached the maximum number of passwords that can be stored.\n");
                    break;
                }
                char password[MAX_PASS_LENGTH];
                printf("Enter new password (up to 20 characters): ");
                scanf("%s", password);
                strcpy(passwords[num_passwords], password);
                num_passwords++;
                printf("New password added successfully!\n");
                break;
            case 2:
                if (num_passwords == 0) {
                    printf("No passwords have been added yet.\n");
                    break;
                }
                printf("Here are your saved passwords:\n");
                for (int i = 0; i < num_passwords; i++) {
                    printf("%d. %s\n", i+1, passwords[i]);
                }
                break;
            case 3:
                printf("Thank you for using Password Manager.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}