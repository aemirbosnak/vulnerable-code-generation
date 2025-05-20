//Falcon-180B DATASET v1.0 Category: Password management ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100

typedef struct {
    char username[50];
    char password[50];
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password() {
    char username[50];
    char password[50];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    strcpy(passwords[num_passwords].username, username);
    strcpy(passwords[num_passwords].password, password);

    num_passwords++;
}

void delete_password() {
    char username[50];

    printf("Enter username: ");
    scanf("%s", username);

    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            for (int j = i; j < num_passwords - 1; j++) {
                strcpy(passwords[j].username, passwords[j + 1].username);
                strcpy(passwords[j].password, passwords[j + 1].password);
            }
            num_passwords--;
            break;
        }
    }
}

void search_password() {
    char username[50];

    printf("Enter username: ");
    scanf("%s", username);

    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            printf("Password: %s\n", passwords[i].password);
            break;
        }
    }
}

void main() {
    int choice;

    do {
        printf("\nPassword Management System\n");
        printf("1. Add Password\n");
        printf("2. Delete Password\n");
        printf("3. Search Password\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_password();
                break;
            case 2:
                delete_password();
                break;
            case 3:
                search_password();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 4);
}