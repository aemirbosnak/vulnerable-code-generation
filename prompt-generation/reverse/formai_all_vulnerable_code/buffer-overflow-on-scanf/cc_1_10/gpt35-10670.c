//FormAI DATASET v1.0 Category: Online Examination System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct User {
    char username[30];
    char password[30];
};

bool validate_user(char *username, char *password) {
    FILE *fp;
    fp = fopen("users.txt", "r"); // File containing usernames and passwords

    if (fp == NULL) {
        printf("Error opening file\n");
        return false;
    }

    char line[50];
    char *tok;
    struct User user;

    while (fgets(line, sizeof(line), fp) != NULL) {
        tok = strtok(line, ":");
        strcpy(user.username, tok);
        tok = strtok(NULL, ":");
        strcpy(user.password, tok);
        user.password[strlen(user.password) - 1] = '\0';

        if (strcmp(username, user.username) == 0 && strcmp(password, user.password) == 0) {
            fclose(fp);
            return true;
        }
    }

    fclose(fp);
    return false;
}

int main() {
    char username[30];
    char password[30];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    if (validate_user(username, password)) {
        printf("Login successful.\n");
    } else {
        printf("Invalid credentials.\n");
    }

    return 0;
}