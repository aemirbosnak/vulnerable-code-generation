//Falcon-180B DATASET v1.0 Category: Password management ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LEN 50

typedef struct {
    char username[MAX_PASSWORD_LEN];
    char password[MAX_PASSWORD_LEN];
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password() {
    num_passwords++;
    printf("Enter username: ");
    scanf("%s", passwords[num_passwords - 1].username);
    printf("Enter password: ");
    scanf("%s", passwords[num_passwords - 1].password);
}

void remove_password() {
    int index;
    printf("Enter index of password to remove: ");
    scanf("%d", &index);
    if (index >= 0 && index < num_passwords) {
        num_passwords--;
        for (int i = index; i < num_passwords; i++) {
            passwords[i] = passwords[i + 1];
        }
    } else {
        printf("Invalid index.\n");
    }
}

void view_passwords() {
    if (num_passwords == 0) {
        printf("No passwords saved.\n");
    } else {
        printf("Username\tPassword\n");
        for (int i = 0; i < num_passwords; i++) {
            printf("%s\t%s\n", passwords[i].username, passwords[i].password);
        }
    }
}

int main() {
    int choice;
    do {
        printf("1. Add password\n");
        printf("2. Remove password\n");
        printf("3. View passwords\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_password();
                break;
            case 2:
                remove_password();
                break;
            case 3:
                view_passwords();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);
    return 0;
}