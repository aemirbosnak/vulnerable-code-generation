//Falcon-180B DATASET v1.0 Category: Password management ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char username[50];
    char password[50];
    int index;
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
    passwords[num_passwords].index = num_passwords;

    num_passwords++;

    printf("Password added successfully.\n");
}

void search_password() {
    char username[50];

    printf("Enter username to search for: ");
    scanf("%s", username);

    int index = -1;

    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            index = i;
            break;
        }
    }

    if (index!= -1) {
        printf("Password for %s is: %s\n", username, passwords[index].password);
    } else {
        printf("User not found.\n");
    }
}

void delete_password() {
    char username[50];

    printf("Enter username to delete password for: ");
    scanf("%s", username);

    int index = -1;

    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            index = i;
            break;
        }
    }

    if (index!= -1) {
        num_passwords--;

        for (int i = index; i < num_passwords; i++) {
            strcpy(passwords[i].username, passwords[i+1].username);
            strcpy(passwords[i].password, passwords[i+1].password);
            passwords[i].index = i;
        }
    } else {
        printf("User not found.\n");
    }
}

int main() {
    int choice;

    do {
        printf("\nPassword Manager\n");
        printf("1. Add Password\n");
        printf("2. Search Password\n");
        printf("3. Delete Password\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_password();
                break;
            case 2:
                search_password();
                break;
            case 3:
                delete_password();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}