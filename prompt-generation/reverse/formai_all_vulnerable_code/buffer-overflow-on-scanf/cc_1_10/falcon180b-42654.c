//Falcon-180B DATASET v1.0 Category: Password management ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} password_t;

password_t passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char* username, char* password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: Password list is full.\n");
        return;
    }

    strcpy(passwords[num_passwords].username, username);
    strcpy(passwords[num_passwords].password, password);

    num_passwords++;
}

int find_password(char* username) {
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            return i;
        }
    }

    return -1;
}

void delete_password(int index) {
    if (index < 0 || index >= num_passwords) {
        printf("Error: Password not found.\n");
        return;
    }

    num_passwords--;

    for (int i = index; i < num_passwords; i++) {
        strcpy(passwords[i].username, passwords[i+1].username);
        strcpy(passwords[i].password, passwords[i+1].password);
    }
}

void print_passwords() {
    if (num_passwords == 0) {
        printf("No passwords saved.\n");
        return;
    }

    printf("Passwords:\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("%s\t%s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    printf("Password Manager\n");
    printf("-----------------\n");

    int choice;
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    do {
        printf("\n1. Add password\n");
        printf("2. Find password\n");
        printf("3. Delete password\n");
        printf("4. Print passwords\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);
                add_password(username, password);
                break;
            case 2:
                printf("Enter username: ");
                scanf("%s", username);
                int index = find_password(username);
                if (index!= -1) {
                    printf("Password: %s\n", passwords[index].password);
                }
                break;
            case 3:
                printf("Enter username: ");
                scanf("%s", username);
                index = find_password(username);
                if (index!= -1) {
                    delete_password(index);
                }
                break;
            case 4:
                print_passwords();
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 5);

    return 0;
}