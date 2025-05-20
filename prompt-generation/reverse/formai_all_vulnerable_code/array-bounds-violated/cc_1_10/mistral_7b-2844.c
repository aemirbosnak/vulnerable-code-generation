//MISTRAL-7B DATASET v1.0 Category: Password management ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

#define MAX_PASSWORDS 100
#define PASSWORD_LENGTH 25

typedef struct Password {
    char name[50];
    char password[PASSWORD_LENGTH + 1];
} Password;

void encodePassword(char *password) {
    int i;
    for (i = 0; password[i] != '\0'; i++) {
        password[i] = (char) (isalpha(password[i]) ? (int) (toupper(password[i]) + 3) : password[i]);
    }
}

void savePassword(Password *passwords, int index, char *name, char *password) {
    strcpy(passwords[index].name, name);
    encodePassword(passwords[index].password);
    strcpy(passwords[index].password, password);
}

int findPasswordIndex(Password *passwords, int length, char *name) {
    int i;
    for (i = 0; i < length; i++) {
        if (strcmp(passwords[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void loadPassword(Password *passwords, int index) {
    printf("Name: %s\n", passwords[index].name);
    printf("Password: ");
    int i;
    for (i = 0; passwords[index].password[i] != '\0'; i++) {
        putchar(isalpha(passwords[index].password[i]) ? (char) (toupper(passwords[index].password[i]) - 3) : passwords[index].password[i]);
    }
    printf("\n");
}

int main() {
    Password passwords[MAX_PASSWORDS];
    int length = 0;
    char command[50];
    char name[50], password[PASSWORD_LENGTH + 1];

    while (true) {
        printf("> ");
        fgets(command, sizeof(command), stdin);
        command[strlen(command) - 1] = '\0';

        if (strcmp(command, "quit") == 0) {
            break;
        }

        char *token = strtok(command, " ");
        if (strcmp(token, "add") == 0) {
            token = strtok(NULL, " ");
            strcpy(name, token);
            token = strtok(NULL, " ");
            strcpy(password, token);
            int index = length++;
            savePassword(passwords, index, name, password);
            printf("Password saved.\n");
        } else if (strcmp(token, "load") == 0) {
            token = strtok(NULL, " ");
            int index = findPasswordIndex(passwords, length, token);
            if (index != -1) {
                loadPassword(passwords, index);
            } else {
                printf("Password not found.\n");
            }
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}