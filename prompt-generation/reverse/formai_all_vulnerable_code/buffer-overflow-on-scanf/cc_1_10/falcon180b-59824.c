//Falcon-180B DATASET v1.0 Category: Password management ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

struct password {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

int main() {
    char choice;
    int num_passwords = 0;
    struct password passwords[MAX_PASSWORDS];

    printf("Welcome to the Password Manager!\n");
    printf("Please choose an option:\n");
    printf("1. Add password\n");
    printf("2. Delete password\n");
    printf("3. View passwords\n");
    printf("4. Exit\n");
    scanf(" %c", &choice);

    while (choice!= '4') {
        switch (choice) {
        case '1':
            printf("Enter password name: ");
            scanf(" %s", passwords[num_passwords].name);
            printf("Enter password: ");
            scanf(" %s", passwords[num_passwords].password);
            num_passwords++;
            break;
        case '2':
            printf("Enter password name to delete: ");
            scanf(" %s", passwords[num_passwords - 1].name);
            num_passwords--;
            break;
        case '3':
            printf("Password Name\tPassword\n");
            for (int i = 0; i < num_passwords; i++) {
                printf("%s\t%s\n", passwords[i].name, passwords[i].password);
            }
            break;
        }
        printf("\n");
        printf("Please choose an option:\n");
        printf("1. Add password\n");
        printf("2. Delete password\n");
        printf("3. View passwords\n");
        printf("4. Exit\n");
        scanf(" %c", &choice);
    }

    return 0;
}