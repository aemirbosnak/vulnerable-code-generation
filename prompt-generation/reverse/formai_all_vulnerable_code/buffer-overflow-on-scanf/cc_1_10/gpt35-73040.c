//FormAI DATASET v1.0 Category: Password management ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 1000
#define MAX_PASSWORD_LENGTH 50
#define MASTER_PASSWORD "password123"

void add_password(char passwords[][MAX_PASSWORD_LENGTH], int *size);
void view_passwords(char passwords[][MAX_PASSWORD_LENGTH], int size);
void delete_password(char passwords[][MAX_PASSWORD_LENGTH], int *size);

int main() {
    char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH];
    int size = 0;
    char input[50];

    while(1) {
        printf("Enter your master password: ");
        scanf("%s", input);

        if(strcmp(input, MASTER_PASSWORD) != 0) {
            printf("Access denied.\n");
            continue;
        }

        printf("Access granted.\n");

        while(1) {
            printf("What would you like to do?\n");
            printf("1. Add password\n");
            printf("2. View passwords\n");
            printf("3. Delete password\n");
            printf("4. Exit\n");
            printf("Enter your choice: ");

            int choice;
            scanf("%d", &choice);

            switch(choice) {
                case 1:
                    add_password(passwords, &size);
                    break;
                case 2:
                    view_passwords(passwords, size);
                    break;
                case 3:
                    delete_password(passwords, &size);
                    break;
                case 4:
                    printf("Exiting.\n");
                    exit(0);
                default:
                    printf("Invalid choice.\n");
            }
        }
    }

    return 0;
}

void add_password(char passwords[][MAX_PASSWORD_LENGTH], int *size) {
    printf("Enter the password: ");
    char password[MAX_PASSWORD_LENGTH];
    scanf("%s", password);

    if(*size >= MAX_PASSWORDS) {
        printf("Password database full.\n");
        return;
    }

    strcpy(passwords[*size], password);
    (*size)++;

    printf("Password added successfully.\n");
}

void view_passwords(char passwords[][MAX_PASSWORD_LENGTH], int size) {
    if(size == 0) {
        printf("No passwords saved.\n");
        return;
    }

    printf("Saved passwords:\n");

    for(int i = 0; i < size; i++) {
        printf("%d. %s\n", i+1, passwords[i]);
    }
}

void delete_password(char passwords[][MAX_PASSWORD_LENGTH], int *size) {
    if(*size == 0) {
        printf("No passwords saved.\n");
        return;
    }

    printf("Enter the index of the password you want to delete: ");
    int choice;
    scanf("%d", &choice);

    if(choice < 1 || choice > *size) {
        printf("Invalid choice.\n");
        return;
    }

    strcpy(passwords[choice-1], passwords[*size-1]);
    (*size)--;

    printf("Password deleted successfully.\n");
}