//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_PASSWORDS 20
#define USERNAME_LENGTH 20
#define PASSWORD_LENGTH 50

typedef struct {
    char site[USERNAME_LENGTH];
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];
} PasswordEntry;

typedef struct {
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];
    PasswordEntry passwords[MAX_PASSWORDS];
    int password_count;
} User;

User users[MAX_USERS];
int user_count = 0;

void clearScreen() {
    // Simple way to clear screen in Linux terminal
    printf("\033[H\033[J");
}

void addPassword(User *user) {
    if (user->password_count >= MAX_PASSWORDS) {
        printf("Password limit reached for user: %s\n", user->username);
        return;
    }
    
    PasswordEntry new_entry;
    printf("Enter site name: ");
    scanf("%s", new_entry.site);
    printf("Enter username: ");
    scanf("%s", new_entry.username);
    printf("Enter password: ");
    scanf("%s", new_entry.password);
    
    user->passwords[user->password_count++] = new_entry;
    printf("Password added successfully!\n");
}

void viewPasswords(User *user) {
    if (user->password_count == 0) {
        printf("No passwords stored for user: %s\n", user->username);
        return;
    }

    printf("Stored passwords for %s:\n", user->username);
    for (int i = 0; i < user->password_count; i++) {
        printf("Site: %s, Username: %s, Password: %s\n", user->passwords[i].site, user->passwords[i].username, user->passwords[i].password);
    }
}

void deletePassword(User *user) {
    if (user->password_count == 0) {
        printf("No passwords to delete for user: %s\n", user->username);
        return;
    }

    char site[USERNAME_LENGTH];
    printf("Enter site name to delete: ");
    scanf("%s", site);

    int found_index = -1;
    for (int i = 0; i < user->password_count; i++) {
        if (strcmp(user->passwords[i].site, site) == 0) {
            found_index = i;
            break;
        }
    }

    if (found_index == -1) {
        printf("Site not found!\n");
        return;
    }

    // Shift passwords to remove the deleted one
    for (int i = found_index; i < user->password_count - 1; i++) {
        user->passwords[i] = user->passwords[i + 1];
    }
    user->password_count--;
    printf("Password for site '%s' deleted successfully!\n", site);
}

User* findUser(char *username) {
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0) {
            return &users[i];
        }
    }
    return NULL;
}

void registerUser() {
    if (user_count >= MAX_USERS) {
        printf("User limit reached!\n");
        return;
    }

    User new_user;
    printf("Enter new username: ");
    scanf("%s", new_user.username);
    printf("Enter new password: ");
    scanf("%s", new_user.password);
    new_user.password_count = 0;

    users[user_count++] = new_user;
    printf("User registered successfully!\n");
}

void loginUser() {
    char username[USERNAME_LENGTH], password[PASSWORD_LENGTH];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    User *user = findUser(username);
    if (user == NULL || strcmp(user->password, password) != 0) {
        printf("Invalid username or password!\n");
        return;
    }

    while (1) {
        clearScreen();
        printf("Welcome, %s!\n", user->username);
        printf("1. View Passwords\n2. Add Password\n3. Delete Password\n4. Logout\n");
        int choice;
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                viewPasswords(user);
                break;
            case 2:
                addPassword(user);
                break;
            case 3:
                deletePassword(user);
                break;
            case 4:
                return;
            default:
                printf("Invalid choice!\n");
        }
        printf("Press Enter to continue...");
        getchar(); // flush newline
        getchar();
    }
}

int main() {
    while (1) {
        clearScreen();
        printf("Password Manager\n");
        printf("1. Register\n2. Login\n3. Exit\n");
        int choice;
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
        printf("Press Enter to continue...");
        getchar(); // flush newline
        getchar();
    }
    
    return 0;
}