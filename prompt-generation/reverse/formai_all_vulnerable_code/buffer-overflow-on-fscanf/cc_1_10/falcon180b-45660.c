//Falcon-180B DATASET v1.0 Category: Password management ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_USER 100
#define MAX_PASSWORD_LEN 20
#define MAX_SALT_LEN 8
#define SALT_CHARS "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"

typedef struct {
    char username[MAX_USER];
    char password[MAX_PASSWORD_LEN];
    char salt[MAX_SALT_LEN];
} user_t;

void generate_salt(char* salt) {
    int i;
    for (i = 0; i < MAX_SALT_LEN; i++) {
        salt[i] = SALT_CHARS[rand() % strlen(SALT_CHARS)];
    }
    salt[MAX_SALT_LEN - 1] = '\0';
}

int is_valid_password(char* password, char* salt) {
    char hashed_password[MAX_PASSWORD_LEN];
    int i;
    for (i = 0; i < strlen(password); i++) {
        hashed_password[i] = password[i] ^ salt[i % MAX_SALT_LEN];
    }
    hashed_password[strlen(password)] = '\0';
    return strcmp(hashed_password, password) == 0;
}

int main() {
    char username[MAX_USER];
    char password[MAX_PASSWORD_LEN];
    char salt[MAX_SALT_LEN];
    user_t user;
    FILE* user_file = fopen("users.txt", "r");
    if (user_file == NULL) {
        printf("Error: Unable to open users file.\n");
        return 1;
    }
    while (fscanf(user_file, "%s %s %s\n", username, password, salt)!= EOF) {
        generate_salt(salt);
        if (is_valid_password(password, salt)) {
            printf("Valid user: %s\n", username);
        } else {
            printf("Invalid user: %s\n", username);
        }
    }
    fclose(user_file);
    return 0;
}