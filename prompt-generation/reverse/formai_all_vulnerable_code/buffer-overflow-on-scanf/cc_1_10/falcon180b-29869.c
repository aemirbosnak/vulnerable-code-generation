//Falcon-180B DATASET v1.0 Category: Password management ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char* name, char* password) {
    if (num_passwords == MAX_PASSWORDS) {
        printf("Error: maximum number of passwords reached.\n");
        return;
    }

    strcpy(passwords[num_passwords].name, name);
    strcpy(passwords[num_passwords].password, password);
    num_passwords++;
}

void remove_password(char* name) {
    int i;

    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].name, name) == 0) {
            strcpy(passwords[i].name, "");
            strcpy(passwords[i].password, "");
            num_passwords--;
            return;
        }
    }

    printf("Error: password not found.\n");
}

void list_passwords() {
    int i;

    for (i = 0; i < num_passwords; i++) {
        if (passwords[i].name[0] == '\0')
            continue;

        printf("%s: %s\n", passwords[i].name, passwords[i].password);
    }
}

void main() {
    int choice;
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    while (1) {
        printf("\n");
        printf("1. Add password\n");
        printf("2. Remove password\n");
        printf("3. List passwords\n");
        printf("4. Exit\n");
        printf("\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter password: ");
                scanf("%s", password);
                add_password(name, password);
                break;

            case 2:
                printf("Enter name: ");
                scanf("%s", name);
                remove_password(name);
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