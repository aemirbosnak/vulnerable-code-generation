//Falcon-180B DATASET v1.0 Category: Password management ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define PASSWORD_LENGTH 10
#define USER_NAME_LENGTH 30

typedef struct {
    char user_name[USER_NAME_LENGTH];
    char password[PASSWORD_LENGTH];
    time_t last_updated;
} User;

void generate_password(char *password) {
    const char *chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        password[i] = chars[rand() % strlen(chars)];
    }
    password[PASSWORD_LENGTH - 1] = '\0';
}

int main() {
    FILE *file;
    User user;
    char file_name[USER_NAME_LENGTH + 5];
    char password[PASSWORD_LENGTH];

    printf("Enter your name: ");
    scanf("%s", user.user_name);
    strcat(user.user_name, ".txt");

    strcpy(file_name, user.user_name);
    strcat(file_name, ".txt");

    file = fopen(file_name, "r");

    if (file == NULL) {
        printf("User not found. Creating new account.\n");
        strcpy(user.password, "");
        generate_password(user.password);
        strcpy(password, user.password);
        printf("Your password is: %s\n", password);
        fclose(file);
        file = fopen(file_name, "w");
        fprintf(file, "%s", user.password);
        fclose(file);
    } else {
        fscanf(file, "%s", password);
        printf("Your password is: %s\n", password);
        fclose(file);
    }

    return 0;
}