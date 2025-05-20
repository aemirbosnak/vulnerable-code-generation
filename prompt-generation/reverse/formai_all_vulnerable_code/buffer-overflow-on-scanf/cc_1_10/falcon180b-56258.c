//Falcon-180B DATASET v1.0 Category: Password management ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define PASSWORD_LENGTH 20

typedef struct {
    char name[50];
    char password[PASSWORD_LENGTH];
    int length;
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void generate_password(char* password, int length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_-+={}[];:,.<>/?\\|";
    for (int i = 0; i < length; i++) {
        password[i] = charset[rand() % strlen(charset)];
    }
    password[length] = '\0';
}

int main() {
    char username[50];
    printf("Enter your username: ");
    scanf("%s", username);

    Password* pw = NULL;
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].name, username) == 0) {
            pw = &passwords[i];
            break;
        }
    }

    if (pw == NULL) {
        printf("User not found.\n");
        return 1;
    }

    int choice;
    do {
        printf("\nChoose an option:\n");
        printf("1. View password\n");
        printf("2. Change password\n");
        printf("3. Logout\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Your password is: %s\n", pw->password);
                break;
            case 2:
                generate_password(pw->password, PASSWORD_LENGTH);
                printf("Your password has been changed.\n");
                break;
            case 3:
                printf("Goodbye, %s!\n", username);
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}