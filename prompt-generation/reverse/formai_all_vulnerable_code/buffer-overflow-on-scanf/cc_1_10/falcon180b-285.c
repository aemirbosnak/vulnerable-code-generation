//Falcon-180B DATASET v1.0 Category: Password management ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define PASSWORD_LENGTH 20
#define MAX_PASSWORDS 100

typedef struct {
    char username[20];
    char password[PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void print_passwords() {
    printf("Username\t\tPassword\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("%s\t\t%s\n", passwords[i].username, passwords[i].password);
    }
}

int compare_usernames(const void *a, const void *b) {
    return strcmp(*(char **) a, *(char **) b);
}

void sort_passwords() {
    qsort(passwords, num_passwords, sizeof(Password), compare_usernames);
}

int main() {
    char username[20];
    char password[PASSWORD_LENGTH];
    char choice;
    int index;

    do {
        printf("Password Manager\n");
        printf("1. Add password\n");
        printf("2. View passwords\n");
        printf("3. Sort passwords\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            printf("Enter username: ");
            scanf("%s", username);
            printf("Enter password: ");
            scanf("%s", password);
            strcpy(passwords[num_passwords].username, username);
            strcpy(passwords[num_passwords].password, password);
            num_passwords++;
            break;

        case '2':
            print_passwords();
            break;

        case '3':
            sort_passwords();
            printf("Passwords sorted by username:\n");
            print_passwords();
            break;

        case '4':
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}