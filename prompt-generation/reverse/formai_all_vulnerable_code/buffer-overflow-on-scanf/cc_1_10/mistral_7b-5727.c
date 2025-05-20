//MISTRAL-7B DATASET v1.0 Category: Password management ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PASSWORDS 100
#define PASSWORD_LENGTH 50

typedef struct {
    char username[50];
    char password[50];
} Password;

Password passwords[MAX_PASSWORDS];
int password_count = 0;

int find_password_index(char* username) {
    for (int i = 0; i < password_count; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            return i;
        }
    }
    return -1;
}

void add_password(char* username, char* password) {
    if (password_count < MAX_PASSWORDS) {
        strcpy(passwords[password_count].username, username);
        strcpy(passwords[password_count].password, password);
        password_count++;
    }
}

void print_password(char* username) {
    int index = find_password_index(username);
    if (index != -1) {
        printf("The password for %s is %s\n", username, passwords[index].password);
    } else {
        printf("No password found for %s\n", username);
    }
}

int main() {
    char command[10], username[50], password[50];

    while (1) {
        printf("Sherlock> ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            scanf("%s %s", username, password);
            add_password(username, password);
            printf("Password added successfully.\n");
        } else if (strcmp(command, "print") == 0) {
            scanf("%s", username);
            print_password(username);
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }

    return 0;
}