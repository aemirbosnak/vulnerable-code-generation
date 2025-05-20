//FormAI DATASET v1.0 Category: Password management ; Style: high level of detail
#include <stdio.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20

void input_passwords(char passwords[][MAX_PASSWORD_LENGTH], int *num_passwords);
void add_password(char passwords[][MAX_PASSWORD_LENGTH], int *num_passwords);
void remove_password(char passwords[][MAX_PASSWORD_LENGTH], int *num_passwords);
void display_passwords(char passwords[][MAX_PASSWORD_LENGTH], int num_passwords);

int main() {
    char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH];
    int num_passwords = 0;
    int choice;
    
    printf("Welcome to the Password Management System!\n");
    
    do {
        printf("\nPlease choose an option:\n");
        printf("1. Add Password\n");
        printf("2. Remove Password\n");
        printf("3. View Passwords\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                add_password(passwords, &num_passwords);
                break;
            case 2:
                remove_password(passwords, &num_passwords);
                break;
            case 3:
                display_passwords(passwords, num_passwords);
                break;
            case 4:
                printf("Thank you for using the Password Management System!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while(choice != 4);
    
    return 0;
}

void input_passwords(char passwords[][MAX_PASSWORD_LENGTH], int *num_passwords) {
    char password[MAX_PASSWORD_LENGTH];
    
    printf("Enter passwords (up to %d, type \"quit\" to stop):\n", MAX_PASSWORDS - *num_passwords);
    while(*num_passwords < MAX_PASSWORDS && strcmp(password, "quit") != 0) {
        scanf("%s", password);
        if(strcmp(password, "quit") != 0) {
            strcpy(passwords[*num_passwords], password);
            (*num_passwords)++;
        }
    }
}

void add_password(char passwords[][MAX_PASSWORD_LENGTH], int *num_passwords) {
    char password[MAX_PASSWORD_LENGTH];
    
    printf("Enter a new password (up to %d characters):\n", MAX_PASSWORD_LENGTH - 1);
    scanf("%s", password);
    
    if(*num_passwords >= MAX_PASSWORDS) {
        printf("Password database is full, cannot add new password.\n");
    }
    else {
        strcpy(passwords[*num_passwords], password);
        (*num_passwords)++;
        printf("Password added successfully.\n");
    }
}

void remove_password(char passwords[][MAX_PASSWORD_LENGTH], int *num_passwords) {
    char search_password[MAX_PASSWORD_LENGTH];
    
    printf("Enter a password to remove:\n");
    scanf("%s", search_password);
    
    int index = -1;
    for(int i = 0; i < *num_passwords; i++) {
        if(strcmp(passwords[i], search_password) == 0) {
            index = i;
            break;
        }
    }
    
    if(index == -1) {
        printf("Password could not be found.\n");
    }
    else {
        for(int i = index; i < *num_passwords - 1; i++) {
            strcpy(passwords[i], passwords[i+1]);
        }
        (*num_passwords)--;
        printf("Password removed successfully.\n");
    }
}

void display_passwords(char passwords[][MAX_PASSWORD_LENGTH], int num_passwords) {
    printf("Passwords:\n");
    for(int i = 0; i < num_passwords; i++) {
        printf("%s\n", passwords[i]);
    }
    if(num_passwords == 0) {
        printf("No passwords have been added.\n");
    }
}