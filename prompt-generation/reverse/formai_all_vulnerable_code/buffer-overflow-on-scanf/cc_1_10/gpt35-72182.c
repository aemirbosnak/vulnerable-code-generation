//FormAI DATASET v1.0 Category: Password management ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORD_LEN 20
#define MAX_USERNAME_LEN 20

// Structure for storing username and password
struct LoginCreds {
    char username[MAX_USERNAME_LEN + 1];
    char password[MAX_PASSWORD_LEN + 1];
};

// Initialize the login credentials with default values
void init_login_creds(struct LoginCreds *login_creds) {
    memset(login_creds->username, 0, sizeof(login_creds->username));
    memset(login_creds->password, 0, sizeof(login_creds->password));
}

// Read the login credentials from the user
void read_login_creds(struct LoginCreds *login_creds) {
    printf("Enter username: ");
    scanf("%s", login_creds->username);

    printf("Enter password: ");
    scanf("%s", login_creds->password);
}

// Write the login credentials to a file
void write_login_creds(const struct LoginCreds *login_creds, FILE *file) {
    fwrite(login_creds->username, 1, strlen(login_creds->username), file);
    fwrite(":", 1, 1, file);
    fwrite(login_creds->password, 1, strlen(login_creds->password), file);
    fwrite("\n", 1, 1, file);    
}

// Read the login credentials from a file
int read_login_creds_file(struct LoginCreds *login_creds, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return 0;
    }

    char buffer[MAX_USERNAME_LEN + 1 + MAX_PASSWORD_LEN + 1];
    if (fgets(buffer, sizeof(buffer), file) == NULL) {
        fclose(file);
        return 0;
    }

    char *username_end = strchr(buffer, ':');
    if (username_end == NULL) {
        fclose(file);
        return 0;
    }
    memcpy(login_creds->username, buffer, username_end - buffer);
    login_creds->username[username_end - buffer] = '\0';

    char *password_end = strchr(username_end + 1, '\n');
    if (password_end == NULL) {
        fclose(file);
        return 0;
    }
    memcpy(login_creds->password, username_end + 1, password_end - username_end - 1);
    login_creds->password[password_end - username_end - 1] = '\0';

    fclose(file);
    return 1;
}

int main() {
    struct LoginCreds login_creds;
    init_login_creds(&login_creds);

    // Check if login credentials already exist on file
    if (read_login_creds_file(&login_creds, "login.txt")) {
        printf("Welcome back, %s!\n", login_creds.username);
    } else {
        printf("Welcome, new user!\n");
        read_login_creds(&login_creds);

        // Write login credentials to file
        FILE *file = fopen("login.txt", "w");
        if (file == NULL) {
            printf("Error: Could not write login credentials to file\n");
            return 1;
        }

        write_login_creds(&login_creds, file);
        fclose(file);
    }

    return 0;
}