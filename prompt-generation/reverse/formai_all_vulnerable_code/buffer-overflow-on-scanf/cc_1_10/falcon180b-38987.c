//Falcon-180B DATASET v1.0 Category: Password management ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50
#define MAX_USERNAME_LENGTH 50

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

void generate_password(char *password, int length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    for (int i = 0; i < length; i++) {
        password[i] = charset[rand() % strlen(charset)];
    }
    password[length] = '\0';
}

int main() {
    Password passwords[MAX_PASSWORDS];
    int num_passwords = 0;

    char username[MAX_USERNAME_LENGTH];
    printf("Enter your username: ");
    scanf("%s", username);

    FILE *file = fopen("passwords.txt", "r");
    if (file == NULL) {
        printf("No existing passwords found.\n");
    } else {
        while (fscanf(file, "%s %s", passwords[num_passwords].username, passwords[num_passwords].password)!= EOF) {
            num_passwords++;
        }
        fclose(file);

        char target_username[MAX_USERNAME_LENGTH];
        printf("Enter the username for which you want to retrieve the password: ");
        scanf("%s", target_username);

        int found = 0;
        for (int i = 0; i < num_passwords; i++) {
            if (strcmp(target_username, passwords[i].username) == 0) {
                printf("Password for %s: %s\n", target_username, passwords[i].password);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Password not found.\n");
        }
    }

    return 0;
}