//FormAI DATASET v1.0 Category: Password management ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Constant definitions */
#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 20

/* Function prototypes */
int login(void);
void print_menu(void);
void add_password(char passwords[][MAX_PASSWORD_LENGTH+1], int *count);
void delete_password(char passwords[][MAX_PASSWORD_LENGTH+1], int *count);
void view_passwords(char passwords[][MAX_PASSWORD_LENGTH+1], int count);

/* Main function */
int main(void) {
    int count = 0;
    char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH+1];

    /* Check if user is authorized */
    if (!login()) {
        printf("Authorization failed. Exiting program...\n");
        return 1;
    }

    /* Print menu and execute user's choice */
    int choice;
    do {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_password(passwords, &count);
                break;
            case 2:
                delete_password(passwords, &count);
                break;
            case 3:
                view_passwords(passwords, count);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

/* Function to check user's password */
int login(void) {
    char password[MAX_PASSWORD_LENGTH+1];
    printf("Please enter your password: ");
    scanf("%s", password);
    return strcmp(password, "mypassword") == 0 ? 1 : 0;
}

/* Function to print menu options */
void print_menu(void) {
    printf("\nPlease select an option:\n");
    printf("1. Add password\n");
    printf("2. Delete password\n");
    printf("3. View passwords\n");
    printf("4. Quit\n");
}

/* Function to add password to array */
void add_password(char passwords[][MAX_PASSWORD_LENGTH+1], int *count) {
    if (*count < MAX_PASSWORDS) {
        printf("Please enter a password (max %d characters): ", MAX_PASSWORD_LENGTH);
        scanf("%s", passwords[*count]);
        (*count)++;
        printf("Password added successfully.\n");
    }
    else {
        printf("Cannot add password. Maximum number of passwords (%d) exceeded.\n", MAX_PASSWORDS);
    }
}

/* Function to delete password from array */
void delete_password(char passwords[][MAX_PASSWORD_LENGTH+1], int *count) {
    if (*count > 0) {
        printf("Please enter the password index to delete: ");
        int index;
        scanf("%d", &index);

        if (index >= 0 && index < *count) {
            for (int i = index; i < *count-1; i++) {
                strcpy(passwords[i], passwords[i+1]);
            }
            (*count)--;
            printf("Password deleted successfully.\n");
        }
        else {
            printf("Invalid index.\n");
        }
    }
    else {
        printf("No passwords to delete.\n");
    }
}

/* Function to view all passwords in array */
void view_passwords(char passwords[][MAX_PASSWORD_LENGTH+1], int count) {
    if (count > 0) {
        printf("Here are your saved passwords:\n");
        for (int i = 0; i < count; i++) {
            printf("%d. %s\n", i, passwords[i]);
        }
    }
    else {
        printf("No passwords saved.\n");
    }
}