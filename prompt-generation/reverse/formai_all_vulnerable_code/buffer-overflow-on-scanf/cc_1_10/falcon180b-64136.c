//Falcon-180B DATASET v1.0 Category: Password management ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LEN 64

typedef struct {
    char password[MAX_PASSWORD_LEN];
    char username[MAX_PASSWORD_LEN];
    char website[MAX_PASSWORD_LEN];
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password() {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Sorry, you have reached the maximum number of passwords.\n");
        return;
    }

    char password[MAX_PASSWORD_LEN];
    char username[MAX_PASSWORD_LEN];
    char website[MAX_PASSWORD_LEN];

    printf("Enter the password: ");
    scanf("%s", password);

    printf("Enter the username: ");
    scanf("%s", username);

    printf("Enter the website: ");
    scanf("%s", website);

    strcpy(passwords[num_passwords].password, password);
    strcpy(passwords[num_passwords].username, username);
    strcpy(passwords[num_passwords].website, website);

    num_passwords++;
}

void remove_password() {
    int i;

    printf("Enter the index of the password you want to remove: ");
    scanf("%d", &i);

    if (i >= 0 && i < num_passwords) {
        num_passwords--;

        for (int j = i; j < num_passwords; j++) {
            strcpy(passwords[j].password, passwords[j+1].password);
            strcpy(passwords[j].username, passwords[j+1].username);
            strcpy(passwords[j].website, passwords[j+1].website);
        }
    } else {
        printf("Invalid index.\n");
    }
}

void print_passwords() {
    for (int i = 0; i < num_passwords; i++) {
        printf("%d. Password: %s\n", i+1, passwords[i].password);
        printf("Username: %s\n", passwords[i].username);
        printf("Website: %s\n\n", passwords[i].website);
    }
}

void main() {
    int choice;

    do {
        printf("1. Add password\n");
        printf("2. Remove password\n");
        printf("3. Print passwords\n");
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
                print_passwords();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);
}