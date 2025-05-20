//Falcon-180B DATASET v1.0 Category: Password management ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PASSWORD_LENGTH 20
#define SALT_LENGTH 16
#define HASH_LENGTH 64

void generate_salt(char* salt) {
    srand(time(NULL));
    for (int i = 0; i < SALT_LENGTH; i++) {
        salt[i] = 'A' + rand() % 26;
    }
    salt[SALT_LENGTH] = '\0';
}

void hash_password(char* password, const char* salt, char* hashed_password) {
    char buffer[PASSWORD_LENGTH + SALT_LENGTH];
    strcat(strcat(strcpy(buffer, password), salt), "QWERTYUIOPASDFGHJKLZXCVBNM");
    for (int i = 0; i < PASSWORD_LENGTH + SALT_LENGTH; i++) {
        const char c = buffer[i];
        if (c >= 'a' && c <= 'z') {
            hashed_password[i] = c + 'A' - 'a';
        } else if (c >= 'A' && c <= 'Z') {
            hashed_password[i] = c + 'a' - 'A';
        } else {
            hashed_password[i] = c;
        }
    }
    hashed_password[PASSWORD_LENGTH + SALT_LENGTH] = '\0';
}

int main() {
    char password[PASSWORD_LENGTH + 1];
    char salt[SALT_LENGTH + 1];
    char hashed_password[HASH_LENGTH + 1];

    printf("Enter password: ");
    scanf("%s", password);

    generate_salt(salt);

    hash_password(password, salt, hashed_password);

    printf("Salt: %s\n", salt);
    printf("Hashed password: %s\n", hashed_password);

    return 0;
}