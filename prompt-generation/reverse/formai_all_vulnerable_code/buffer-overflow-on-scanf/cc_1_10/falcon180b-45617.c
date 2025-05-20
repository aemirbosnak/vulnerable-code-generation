//Falcon-180B DATASET v1.0 Category: Password management ; Style: genious
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORDS 100

typedef struct {
    char username[50];
    char password[50];
    int length;
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password() {
    char username[50];
    char password[50];
    int length;

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    printf("Enter password length: ");
    scanf("%d", &length);

    strncpy(passwords[num_passwords].username, username, 50);
    strncpy(passwords[num_passwords].password, password, 50);
    passwords[num_passwords].length = length;

    num_passwords++;
}

void display_passwords() {
    int i;

    for (i = 0; i < num_passwords; i++) {
        printf("%s - %s (%d)\n", passwords[i].username, passwords[i].password, passwords[i].length);
    }
}

int main() {
    int choice;

    do {
        printf("1. Add password\n2. Display passwords\n3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_password();
            break;
        case 2:
            display_passwords();
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}