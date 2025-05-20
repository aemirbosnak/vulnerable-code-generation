//Falcon-180B DATASET v1.0 Category: Password management ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100

typedef struct {
    char username[50];
    char password[50];
    int is_valid;
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password() {
    printf("Enter username: ");
    scanf("%s", passwords[num_passwords].username);
    printf("Enter password: ");
    scanf("%s", passwords[num_passwords].password);
    passwords[num_passwords].is_valid = 1;
    num_passwords++;
    printf("Password added successfully.\n");
}

void remove_password() {
    printf("Enter username: ");
    char username[50];
    scanf("%s", username);
    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(username, passwords[i].username) == 0 && passwords[i].is_valid == 1) {
            passwords[i].is_valid = 0;
            printf("Password removed successfully.\n");
            return;
        }
    }
    printf("Password not found.\n");
}

void search_password() {
    printf("Enter username: ");
    char username[50];
    scanf("%s", username);
    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(username, passwords[i].username) == 0 && passwords[i].is_valid == 1) {
            printf("Password: %s\n", passwords[i].password);
            return;
        }
    }
    printf("Password not found.\n");
}

void main() {
    int choice;
    do {
        printf("1. Add password\n");
        printf("2. Remove password\n");
        printf("3. Search password\n");
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
                search_password();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);
}