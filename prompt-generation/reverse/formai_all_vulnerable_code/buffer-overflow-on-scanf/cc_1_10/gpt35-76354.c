//FormAI DATASET v1.0 Category: Password management ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PASSWORDS 10
#define MAX_LENGTH 20

typedef struct PasswordManager {
    char passwords[MAX_PASSWORDS][MAX_LENGTH];
    int count;
} PasswordManager;

void addPassword(PasswordManager* manager, char* password) {
    if(manager->count >= MAX_PASSWORDS) {
        printf("Error: Password limit of %d reached!\n", MAX_PASSWORDS);
        return;
    }

    int len = strlen(password);
    if(len > MAX_LENGTH - 1) {
        printf("Error: Password length cannot exceed %d characters!\n", MAX_LENGTH - 1);
        return;
    }

    strcpy(manager->passwords[manager->count], password);
    manager->count++;
}

bool removePassword(PasswordManager* manager, int index) {
    if(index < 0 || index >= manager->count) {
        return false;
    }

    for(int i=index; i<manager->count-1; i++) {
        strcpy(manager->passwords[i], manager->passwords[i+1]);
    }

    manager->count--;
    return true;
}

bool hasPassword(PasswordManager* manager, char* password) {
    for(int i=0; i<manager->count; i++) {
        if(strcmp(manager->passwords[i], password) == 0) {
            return true;
        }
    }

    return false;
}

int main() {
    PasswordManager manager;
    manager.count = 0;

    printf("Welcome to the Password Manager!\n");
    printf("Type 'add' to add a new password.\n");
    printf("Type 'remove' to remove a password.\n");
    printf("Type 'check' to check if a password exists.\n");
    printf("Type 'exit' to quit the program.\n");

    char input[MAX_LENGTH];
    char password[MAX_LENGTH];
    int index;

    while(true) {
        printf("> ");
        scanf("%s", input);

        if(strcmp(input, "add") == 0) {
            printf("Enter password to add: ");
            scanf("%s", password);

            addPassword(&manager, password);
        }
        else if(strcmp(input, "remove") == 0) {
            printf("Enter index of password to remove: ");
            scanf("%d", &index);

            bool removed = removePassword(&manager, index);

            if(!removed) {
                printf("Error: Invalid index!\n");
            }
        }
        else if(strcmp(input, "check") == 0) {
            printf("Enter password to check: ");
            scanf("%s", password);

            bool exists = hasPassword(&manager, password);

            if(exists) {
                printf("The password exists in the manager.\n");
            }
            else {
                printf("The password does not exist in the manager.\n");
            }
        }
        else if(strcmp(input, "exit") == 0) {
            break;
        }
        else {
            printf("Error: Invalid command!\n");
        }

        printf("\n");
    }

    return 0;
}