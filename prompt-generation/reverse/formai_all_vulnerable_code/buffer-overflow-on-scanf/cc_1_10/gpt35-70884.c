//FormAI DATASET v1.0 Category: Password management ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    int attempts;
} Password;

Password passwords[MAX_PASSWORDS];
int passwordCount = 0;

void addPassword(char *password) {
    if (passwordCount < MAX_PASSWORDS) {
        Password new_password;
        strcpy(new_password.password, password);
        new_password.attempts = 0;
        passwords[passwordCount++] = new_password;
    } else {
        printf("Maximum number of passwords reached.\n");
    }
}

int getPasswordIndex(char *password) {
    for (int i = 0; i < passwordCount; i++) {
        if (strcmp(passwords[i].password, password) == 0) {
            return i;
        }
    }
    return -1;
}

int authenticate(char *password) {
    int index = getPasswordIndex(password);
    if (index != -1) {
        passwords[index].attempts++;
        return 1;
    }
    return 0;
}

int checkAttempts(char *password) {
    int index = getPasswordIndex(password);
    if (index != -1) {
        return passwords[index].attempts;
    }
    return 0;
}

void showMenu() {
    printf("1. Add new password\n");
    printf("2. Authenticate\n");
    printf("3. Check attempts of a password\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;
    char password[MAX_PASSWORD_LENGTH];

    while (1) {
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter new password: ");
                scanf("%s", password);
                addPassword(password);
                break;

            case 2:
                printf("Enter password: ");
                scanf("%s", password);
                if (authenticate(password)) {
                    printf("Authentication Successful!\n");
                } else {
                    printf("Authentication Failed.\n");
                }
                break;

            case 3:
                printf("Enter password: ");
                scanf("%s", password);
                printf("Attempts: %d\n", checkAttempts(password));
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}