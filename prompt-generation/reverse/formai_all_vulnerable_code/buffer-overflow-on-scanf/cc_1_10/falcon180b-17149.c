//Falcon-180B DATASET v1.0 Category: Password management ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LEN 50

typedef struct {
    char name[MAX_PASSWORD_LEN];
    char password[MAX_PASSWORD_LEN];
} password_t;

password_t passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char *name, char *password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: maximum number of passwords reached.\n");
        return;
    }

    strcpy(passwords[num_passwords].name, name);
    strcpy(passwords[num_passwords].password, password);

    num_passwords++;
}

void remove_password(char *name) {
    int i;

    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].name, name) == 0) {
            memset(passwords[i].name, 0, MAX_PASSWORD_LEN);
            memset(passwords[i].password, 0, MAX_PASSWORD_LEN);

            num_passwords--;

            return;
        }
    }

    printf("Error: password not found.\n");
}

void list_passwords(void) {
    int i;

    for (i = 0; i < num_passwords; i++) {
        printf("%s: %s\n", passwords[i].name, passwords[i].password);
    }
}

int main(int argc, char *argv[]) {
    int choice;

    do {
        printf("Password Manager\n");
        printf("1. Add password\n");
        printf("2. Remove password\n");
        printf("3. List passwords\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter name: ");
            scanf("%s", passwords[num_passwords].name);
            printf("Enter password: ");
            scanf("%s", passwords[num_passwords].password);
            num_passwords++;
            break;

        case 2:
            printf("Enter name: ");
            scanf("%s", passwords[num_passwords].name);
            remove_password(passwords[num_passwords].name);
            break;

        case 3:
            list_passwords();
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }

    } while (1);

    return 0;
}