//MISTRAL-7B DATASET v1.0 Category: Password management ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_PASS 20

typedef struct {
    char name[50];
    char password[MAX_PASS];
} User;

User users[MAX_USERS];
int num_users = 0;

void register_user() {
    if (num_users >= MAX_USERS) {
        printf("Max number of users reached.\n");
        return;
    }

    printf("Enter your name: ");
    scanf("%s", users[num_users].name);

    printf("Enter your password: ");
    fflush(stdin); // clear input buffer
    gets(users[num_users].password);

    num_users++;
}

void login(char name[]) {
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].name, name) == 0) {
            printf("Password for %s is: %s\n", users[i].name, users[i].password);
            return;
        }
    }

    printf("User not found.\n");
}

void shift_passwords() {
    for (int i = 0; i < num_users - 1; i++) {
        strcpy(users[i].password, users[i + 1].password);
    }

    // last user's password is not shifted
}

int main() {
    int choice;

    while (1) {
        printf("\nPassword Manager\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Shift passwords\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                register_user();
                break;
            case 2: {
                char name[50];
                printf("Enter your name: ");
                scanf("%s", name);
                login(name);
                break;
            }
            case 3:
                shift_passwords();
                printf("Passwords shifted successfully.\n");
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}