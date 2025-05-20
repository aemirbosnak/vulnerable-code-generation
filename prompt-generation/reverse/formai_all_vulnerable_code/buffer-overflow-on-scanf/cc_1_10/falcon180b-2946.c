//Falcon-180B DATASET v1.0 Category: Password management ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LEN 50
#define MAX_USERNAME_LEN 50

typedef struct {
    char username[MAX_USERNAME_LEN];
    char password[MAX_PASSWORD_LEN];
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char *username, char *password) {
    strncpy(passwords[num_passwords].username, username, MAX_USERNAME_LEN);
    strncpy(passwords[num_passwords].password, password, MAX_PASSWORD_LEN);
    num_passwords++;
}

int find_password(char *username) {
    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    char username[MAX_USERNAME_LEN];
    char password[MAX_PASSWORD_LEN];
    int choice;
    int i;

    do {
        printf("Password Manager\n");
        printf("1. Add password\n");
        printf("2. Retrieve password\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
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
                i = find_password(username);
                if (i!= -1) {
                    printf("Password: %s\n", passwords[i].password);
                } else {
                    printf("Password not found.\n");
                }
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}