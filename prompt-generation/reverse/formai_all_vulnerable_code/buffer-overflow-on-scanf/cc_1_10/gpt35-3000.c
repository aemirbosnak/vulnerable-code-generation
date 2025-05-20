//FormAI DATASET v1.0 Category: Password management ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 20 // Maximum number of passwords that can be saved
#define MAX_PASSWORD_LENGTH 50 // Maximum length of a password

// function prototypes
void add_password(char passwords[][MAX_PASSWORD_LENGTH], int *num_passwords);
void view_passwords(char passwords[][MAX_PASSWORD_LENGTH], int num_passwords);

int main(void) {
    char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH]; // 2D array for storing passwords
    int num_passwords = 0; // number of passwords saved currently
    
    int choice = 0; // user's menu choice
    do {
        printf("Please choose an option:\n");
        printf("1. Add a password\n");
        printf("2. View saved passwords\n");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_password(passwords, &num_passwords);
                break;
            case 2:
                view_passwords(passwords, num_passwords);
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 3);
    
    return 0;
}

void add_password(char passwords[][MAX_PASSWORD_LENGTH], int *num_passwords) {
    char new_password[MAX_PASSWORD_LENGTH]; // hold the new password temporarily
    
    if (*num_passwords < MAX_PASSWORDS) { // check if there's space to save another password
        printf("Please enter the new password: ");
        scanf("%s", new_password);
        
        // Copy the new password into the array and increment the number of passwords
        strcpy(passwords[*num_passwords], new_password);
        (*num_passwords)++;
        
        printf("Password saved successfully.\n");
    } else {
        // Prompt the user that there is no more space for passwords
        printf("Sorry, you have reached the maximum number of passwords that can be saved.\n");
    }
}

void view_passwords(char passwords[][MAX_PASSWORD_LENGTH], int num_passwords) {
    if (num_passwords == 0) { // check if there are no saved passwords
        printf("There are no saved passwords.\n");
    } else { // display all saved passwords one by one
        printf("Saved passwords:\n");
        for (int i = 0; i < num_passwords; i++) {
            printf("%d. %s\n", i+1, passwords[i]);
        }
    }
}