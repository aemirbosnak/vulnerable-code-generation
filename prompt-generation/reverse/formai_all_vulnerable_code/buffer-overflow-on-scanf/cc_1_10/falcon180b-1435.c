//Falcon-180B DATASET v1.0 Category: Password management ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define PASSWORD_LENGTH 20

typedef struct {
    char username[50];
    char password[PASSWORD_LENGTH];
    int is_valid;
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password() {
    char username[50];
    char password[PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    for(int i = 0; i < num_passwords; i++) {
        if(strcmp(passwords[i].username, username) == 0) {
            printf("Username already exists.\n");
            return;
        }
    }

    strcpy(passwords[num_passwords].username, username);
    strcpy(passwords[num_passwords].password, password);
    passwords[num_passwords].is_valid = 1;

    num_passwords++;

    printf("Password added successfully.\n");
}

void remove_password() {
    char username[50];

    printf("Enter username: ");
    scanf("%s", username);

    for(int i = 0; i < num_passwords; i++) {
        if(strcmp(passwords[i].username, username) == 0) {
            passwords[i].is_valid = 0;
            printf("Password removed successfully.\n");
            return;
        }
    }

    printf("Username not found.\n");
}

void list_passwords() {
    for(int i = 0; i < num_passwords; i++) {
        if(passwords[i].is_valid == 1) {
            printf("%s - %s\n", passwords[i].username, passwords[i].password);
        }
    }
}

void main() {
    int choice;

    while(1) {
        printf("1. Add password\n2. Remove password\n3. List passwords\n4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_password();
                break;
            case 2:
                remove_password();
                break;
            case 3:
                list_passwords();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}