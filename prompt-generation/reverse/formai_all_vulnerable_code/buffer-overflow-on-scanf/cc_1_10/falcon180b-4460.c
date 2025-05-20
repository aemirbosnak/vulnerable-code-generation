//Falcon-180B DATASET v1.0 Category: Password management ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define PASSWORD_LENGTH 20

typedef struct {
    char name[50];
    char password[PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password() {
    char name[50];
    char password[PASSWORD_LENGTH];

    printf("Enter the name of the website/account: ");
    scanf("%s", name);

    printf("Enter the password: ");
    scanf("%s", password);

    strcpy(passwords[num_passwords].name, name);
    strcpy(passwords[num_passwords].password, password);
    num_passwords++;
}

void remove_password() {
    int index;

    printf("Enter the index of the password you want to remove: ");
    scanf("%d", &index);

    if (index >= 0 && index < num_passwords) {
        num_passwords--;
        for (int i = index; i < num_passwords; i++) {
            strcpy(passwords[i].name, passwords[i+1].name);
            strcpy(passwords[i].password, passwords[i+1].password);
        }
    } else {
        printf("Invalid index.\n");
    }
}

void display_passwords() {
    printf("Name\t\tPassword\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("%s\t\t%s\n", passwords[i].name, passwords[i].password);
    }
}

int main() {
    int choice;

    printf("Password Manager\n");
    printf("1. Add password\n");
    printf("2. Remove password\n");
    printf("3. Display passwords\n");
    printf("4. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_password();
                break;
            case 2:
                remove_password();
                break;
            case 3:
                display_passwords();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}