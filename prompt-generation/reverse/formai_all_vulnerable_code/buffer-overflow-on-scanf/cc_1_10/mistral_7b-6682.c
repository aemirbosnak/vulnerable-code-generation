//MISTRAL-7B DATASET v1.0 Category: Password management ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PASSWORDS 10

typedef struct {
    char username[50];
    char password[50];
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;
char master_password[50];

bool is_master_password_correct() {
    return strcmp(master_password, "masterpassword123") == 0;
}

void add_password() {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Password storage is full.\n");
        return;
    }

    printf("Enter username: ");
    scanf("%s", passwords[num_passwords].username);

    printf("Enter password: ");
    scanf("%s", passwords[num_passwords].password);

    num_passwords++;
}

void delete_password() {
    if (num_passwords == 0) {
        printf("No passwords to delete.\n");
        return;
    }

    char username[50];
    printf("Enter username of the password to delete: ");
    scanf("%s", username);

    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            for (int j = i; j < num_passwords - 1; j++) {
                passwords[j] = passwords[j + 1];
            }
            num_passwords--;
            break;
        }
    }

    if (i == num_passwords) {
        printf("Password not found.\n");
    }
}

void display_passwords() {
    if (num_passwords == 0) {
        printf("No passwords to display.\n");
        return;
    }

    printf("Passwords:\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("%s: %s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    printf("Enter master password: ");
    scanf("%s", master_password);

    while (true) {
        printf("\nPassword manager\n1. Add password\n2. Delete password\n3. Display passwords\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            if (is_master_password_correct()) {
                add_password();
            } else {
                printf("Incorrect master password.\n");
            }
        } else if (choice == 2) {
            if (is_master_password_correct()) {
                delete_password();
            } else {
                printf("Incorrect master password.\n");
            }
        } else if (choice == 3) {
            if (is_master_password_correct()) {
                display_passwords();
            } else {
                printf("Incorrect master password.\n");
            }
        } else if (choice == 4) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}