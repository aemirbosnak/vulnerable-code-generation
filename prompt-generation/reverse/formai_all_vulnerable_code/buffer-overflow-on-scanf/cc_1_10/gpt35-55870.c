//FormAI DATASET v1.0 Category: Password management ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20

void print_menu();
void add_password(char passwords[][MAX_PASSWORD_LENGTH], int *num_passwords);
void remove_password(char passwords[][MAX_PASSWORD_LENGTH], int *num_passwords);
void display_passwords(char passwords[][MAX_PASSWORD_LENGTH], int num_passwords);

int main() {
    char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH];
    int num_passwords = 0;
    int choice;
    
    do {
        print_menu();
        scanf("%d", &choice);
        
        switch (choice) {
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
                printf("Exiting program...\n");
                break;
                
            default:
                printf("Invalid choice\n");
                break;
        }
        
    } while (choice != 4);
    
    return 0;
}

void print_menu() {
    printf("1. Add password\n");
    printf("2. Remove password\n");
    printf("3. Display passwords\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

void add_password(char passwords[][MAX_PASSWORD_LENGTH], int *num_passwords) {
    if (*num_passwords >= MAX_PASSWORDS) {
        printf("You have reached the maximum number of passwords\n");
        return;
    }
    
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter password: ");
    scanf("%s", password);
    
    if (strlen(password) >= MAX_PASSWORD_LENGTH) {
        printf("Password is too long\n");
        return;
    }
    
    strcpy(passwords[*num_passwords], password);
    (*num_passwords)++;
    
    printf("Password added successfully\n");
}

void remove_password(char passwords[][MAX_PASSWORD_LENGTH], int *num_passwords) {
    if (*num_passwords == 0) {
        printf("There are no passwords to remove\n");
        return;
    }
    
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter password to remove: ");
    scanf("%s", password);
    
    for (int i = 0; i < *num_passwords; i++) {
        if (strcmp(passwords[i], password) == 0) {
            for (int j = i; j < *num_passwords - 1; j++) {
                strcpy(passwords[j], passwords[j+1]);
            }
            (*num_passwords)--;
            printf("Password removed successfully\n");
            return;
        }
    }
    
    printf("Password not found\n");
}

void display_passwords(char passwords[][MAX_PASSWORD_LENGTH], int num_passwords) {
    if (num_passwords == 0) {
        printf("There are no passwords to display\n");
        return;
    }
    
    for (int i = 0; i < num_passwords; i++) {
        printf("%d. %s\n", i+1, passwords[i]);
    }
}