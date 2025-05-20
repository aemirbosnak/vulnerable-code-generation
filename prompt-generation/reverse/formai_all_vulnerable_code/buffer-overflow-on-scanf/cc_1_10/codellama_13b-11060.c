//Code Llama-13B DATASET v1.0 Category: Password management ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_PASSWORD_LENGTH 128
#define MAX_USERNAME_LENGTH 128

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    char username[MAX_USERNAME_LENGTH];
} user_info;

int main() {
    // Get username and password from user
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    // Check if username and password are valid
    if (strlen(username) == 0 || strlen(password) == 0) {
        printf("Username or password cannot be empty.\n");
        return 1;
    }

    // Check if username already exists
    char filepath[MAX_USERNAME_LENGTH + 5];
    sprintf(filepath, "%s.txt", username);
    if (access(filepath, F_OK) == 0) {
        printf("Username already exists.\n");
        return 1;
    }

    // Create new file for user
    int fd = open(filepath, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        printf("Failed to create file.\n");
        return 1;
    }

    // Write username and password to file
    user_info user = {
        .username = username,
        .password = password
    };
    if (write(fd, &user, sizeof(user)) == -1) {
        printf("Failed to write to file.\n");
        return 1;
    }

    // Close file
    if (close(fd) == -1) {
        printf("Failed to close file.\n");
        return 1;
    }

    printf("Account created successfully.\n");
    return 0;
}