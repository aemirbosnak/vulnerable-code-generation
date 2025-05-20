//Falcon-180B DATASET v1.0 Category: Password management ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password() {
    char username[MAX_PASSWORD_LENGTH], password[MAX_PASSWORD_LENGTH];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    strcpy(passwords[num_passwords].username, username);
    strcpy(passwords[num_passwords].password, password);
    num_passwords++;
    printf("Password added successfully.\n");
}

void remove_password() {
    int index;
    printf("Enter password index: ");
    scanf("%d", &index);
    if (index >= 0 && index < num_passwords) {
        num_passwords--;
        for (int i = index; i < num_passwords; i++) {
            strcpy(passwords[i].username, passwords[i+1].username);
            strcpy(passwords[i].password, passwords[i+1].password);
        }
        printf("Password removed successfully.\n");
    } else {
        printf("Invalid password index.\n");
    }
}

void view_passwords() {
    printf("Username\tPassword\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("%s\t%s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    int choice;
    do {
        printf("1. Add password\n");
        printf("2. Remove password\n");
        printf("3. View passwords\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_password();
                break;
            case 2:
                remove_password();
                break;
            case 3:
                view_passwords();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);
    return 0;
}