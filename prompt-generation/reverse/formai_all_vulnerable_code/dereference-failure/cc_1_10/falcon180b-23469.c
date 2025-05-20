//Falcon-180B DATASET v1.0 Category: Password management ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PASSWORD_LENGTH 16

typedef struct {
    char username[64];
    char password[PASSWORD_LENGTH];
    time_t creation_time;
} User;

User *create_user(const char *username) {
    User *new_user = malloc(sizeof(User));
    strcpy(new_user->username, username);
    new_user->creation_time = time(NULL);
    new_user->password[0] = '\0';
    return new_user;
}

int main() {
    User *user = NULL;
    char *username;
    char *password;
    int choice;

    do {
        printf("Enter username: ");
        scanf("%s", username);
        user = create_user(username);
        printf("User %s created.\n", username);

        do {
            printf("Enter password for %s: ", username);
            scanf("%s", password);
            if (strlen(password) == PASSWORD_LENGTH) {
                strcpy(user->password, password);
                printf("Password set.\n");
                break;
            } else {
                printf("Password must be exactly %d characters long.\n", PASSWORD_LENGTH);
            }
        } while (1);

        do {
            printf("Choose an option:\n1. View password\n2. Change password\n3. Delete user\n");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    if (user->password[0] == '\0') {
                        printf("Password not set.\n");
                    } else {
                        printf("Password: %s\n", user->password);
                    }
                    break;
                case 2:
                    do {
                        printf("Enter new password for %s: ", username);
                        scanf("%s", password);
                        if (strlen(password) == PASSWORD_LENGTH) {
                            strcpy(user->password, password);
                            printf("Password changed.\n");
                            break;
                        } else {
                            printf("Password must be exactly %d characters long.\n", PASSWORD_LENGTH);
                        }
                    } while (1);
                    break;
                case 3:
                    printf("User %s deleted.\n", username);
                    free(user);
                    user = NULL;
                    break;
                default:
                    printf("Invalid option.\n");
            }
        } while (1);

    } while (1);

    return 0;
}