//Falcon-180B DATASET v1.0 Category: Password management ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define PASSWORD_LENGTH 16

typedef struct {
    char name[64];
    char password[PASSWORD_LENGTH];
} PasswordEntry;

PasswordEntry passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword(char* name, char* password) {
    strcpy(passwords[numPasswords].name, name);
    strcpy(passwords[numPasswords].password, password);
    numPasswords++;
}

int findPassword(char* name) {
    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    char name[64];
    char password[PASSWORD_LENGTH];
    int choice;

    while (1) {
        printf("1. Add password\n2. Find password\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter password: ");
            scanf("%s", password);
            addPassword(name, password);
            break;
        case 2:
            printf("Enter name: ");
            scanf("%s", name);
            int index = findPassword(name);
            if (index!= -1) {
                printf("Password: %s\n", passwords[index].password);
            } else {
                printf("Password not found.\n");
            }
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}