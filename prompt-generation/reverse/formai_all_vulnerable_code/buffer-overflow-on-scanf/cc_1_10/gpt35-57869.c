//FormAI DATASET v1.0 Category: Password management ; Style: paranoid
#include <stdio.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20
#define MAX_USERNAME_LENGTH 20
#define MAX_NUM_ACCOUNTS 100

char usernames[MAX_NUM_ACCOUNTS][MAX_USERNAME_LENGTH];
char passwords[MAX_NUM_ACCOUNTS][MAX_PASSWORD_LENGTH];

int num_accounts = 0;

void encrypt_password(char *password) {
    // Here is where we would implement some sophisticated encryption algorithm.
    // For now, we'll just swap the first and last characters of the password.
    int length = strlen(password);
    char temp = password[0];
    password[0] = password[length - 1];
    password[length - 1] = temp;
}

int is_valid_password(char *password) {
    int length = strlen(password);
    int num_digits = 0;
    int num_uppercase = 0;
    int num_lowercase = 0;
    for (int i = 0; i < length; i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            num_digits++;
        }
        if (password[i] >= 'A' && password[i] <= 'Z') {
            num_uppercase++;
        }
        if (password[i] >= 'a' && password[i] <= 'z') {
            num_lowercase++;
        }
    }
    if (length < 8 || num_digits < 2 || num_uppercase < 2 || num_lowercase < 2) {
        return 0;
    }
    return 1;
}

int login() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);
    for (int i = 0; i < num_accounts; i++) {
        if (strcmp(username, usernames[i]) == 0 && strcmp(password, passwords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

void create_account() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter your desired username: ");
    scanf("%s", username);
    printf("Enter your desired password: ");
    scanf("%s", password);
    if (!is_valid_password(password)) {
        printf("Invalid password! Your password must be at least 8 characters long and contain at least 2 digits, uppercase letters, and lowercase letters.\n");
        return;
    }
    encrypt_password(password);
    strcpy(usernames[num_accounts], username);
    strcpy(passwords[num_accounts], password);
    printf("Account created successfully!\n");
    num_accounts++;
}

int main() {
    int choice = 0;
    while (choice != 3) {
        printf("\n---------------\n");
        printf("1. Login\n");
        printf("2. Create a new account\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            if (login()) {
                printf("Login successful!\n");
            } else {
                printf("Invalid username or password!\n");
            }
        } else if (choice == 2) {
            create_account();
        } else if (choice == 3) {
            printf("Goodbye!\n");
        } else {
            printf("Invalid choice!\n");
        }
    }
    return 0;
}