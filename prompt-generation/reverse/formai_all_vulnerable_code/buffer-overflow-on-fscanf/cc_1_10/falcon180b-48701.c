//Falcon-180B DATASET v1.0 Category: Password management ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_PASSWORDS 100

typedef struct {
    char username[50];
    char password[50];
    int length;
    time_t last_modified;
} Password;

int load_passwords(Password *passwords) {
    FILE *file = fopen("passwords.txt", "r");
    if (file == NULL) {
        return 0;
    }

    int count = 0;
    while (fscanf(file, "%s %s %d %ld\n", passwords[count].username, passwords[count].password, &passwords[count].length, &passwords[count].last_modified) == 4) {
        count++;
    }

    fclose(file);
    return count;
}

Password *search_username(Password *passwords, int count, char *username) {
    for (int i = 0; i < count; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            return &passwords[i];
        }
    }
    return NULL;
}

void generate_password(char *password, int length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    for (int i = 0; i < length; i++) {
        password[i] = charset[rand() % strlen(charset)];
    }
    password[length] = '\0';
}

int main() {
    Password passwords[MAX_PASSWORDS];
    int count = load_passwords(passwords);

    char username[50];
    printf("Enter your username: ");
    scanf("%s", username);

    Password *current_password = search_username(passwords, count, username);

    if (current_password == NULL) {
        printf("User not found.\n");
        return 1;
    }

    time_t current_time = time(NULL);
    if (difftime(current_time, current_password->last_modified) > 86400) {
        printf("Your password has expired. Please reset your password.\n");
        return 1;
    }

    char new_password[50];
    printf("Enter your new password: ");
    scanf("%s", new_password);

    if (strcmp(new_password, current_password->password) == 0) {
        printf("Password cannot be the same as the current password.\n");
        return 1;
    }

    strcpy(current_password->password, new_password);
    current_password->last_modified = current_time;

    FILE *file = fopen("passwords.txt", "w");
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %s %d %ld\n", passwords[i].username, passwords[i].password, passwords[i].length, passwords[i].last_modified);
    }
    fclose(file);

    printf("Password updated successfully.\n");
    return 0;
}