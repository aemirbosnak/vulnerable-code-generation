//FormAI DATASET v1.0 Category: Password management ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 30

void add_password(char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH], int* num_passwords);
void view_passwords(char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH], int num_passwords);
void delete_password(char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH], int* num_passwords);

int main() {
    char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH];
    int num_passwords = 0;
    int choice;
    
    while (1) {
        printf("\n\nPassword Management Program\n");
        printf("1. Add Password\n");
        printf("2. View Passwords\n");
        printf("3. Delete Password\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_password(passwords, &num_passwords);
                break;
            case 2:
                view_passwords(passwords, num_passwords);
                break;
            case 3:
                delete_password(passwords, &num_passwords);
                break;
            case 4:
                printf("Thanks for using Password Management Program!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    
    return 0;
}

void add_password(char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH], int* num_passwords) {
    if (*num_passwords == MAX_PASSWORDS) {
        printf("Maximum number of passwords exceeded!\n");
        return;
    }
    
    printf("\nEnter new password: ");
    char new_password[MAX_PASSWORD_LENGTH];
    scanf("%s", new_password);
    
    strcpy(passwords[*num_passwords], new_password);
    (*num_passwords)++;
    
    printf("Password added successfully!\n");
}

void view_passwords(char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH], int num_passwords) {
    if (num_passwords == 0) {
        printf("No passwords to display!\n");
        return;
    }
    
    printf("\nList of passwords:\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("%d. %s\n", i+1, passwords[i]);
    }
}

void delete_password(char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH], int* num_passwords) {
    if (*num_passwords == 0) {
        printf("No passwords to delete!\n");
        return;
    }
    
    printf("\nEnter password number to delete: ");
    int password_num;
    scanf("%d", &password_num);
    
    if (password_num < 1 || password_num > *num_passwords) {
        printf("Invalid password number!\n");
        return;
    }
    
    for (int i = password_num-1; i < *num_passwords-1; i++) {
        strcpy(passwords[i], passwords[i+1]);
    }
    (*num_passwords)--;
    
    printf("Password deleted successfully!\n");
}