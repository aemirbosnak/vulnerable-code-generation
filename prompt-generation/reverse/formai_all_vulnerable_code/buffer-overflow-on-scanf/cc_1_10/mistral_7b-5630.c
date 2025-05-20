//MISTRAL-7B DATASET v1.0 Category: Educational ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define PASSWORD_FILE "passwords.bin"
#define MAX_PASSWORDS 100
#define PASSWORD_LENGTH 50

typedef struct {
    char username[50];
    unsigned char hash[SHA256_DIGEST_LENGTH];
} Password;

void hash_password(const char *password, unsigned char hash[SHA256_DIGEST_LENGTH]) {
    SHA256_CTX ctx;
    SHA256_Init(&ctx);
    SHA256_Update(&ctx, password, strlen(password));
    SHA256_Final(hash, &ctx);
}

int add_password(const char *username, const char *password) {
    FILE *fp = fopen(PASSWORD_FILE, "ab");
    if (!fp) {
        perror("Error opening file");
        return 1;
    }

    Password new_password;
    strcpy(new_password.username, username);
    hash_password(password, new_password.hash);

    size_t size = sizeof(Password);
    if (fwrite(&new_password, size, 1, fp) != 1) {
        perror("Error writing to file");
        fclose(fp);
        return 1;
    }

    fclose(fp);
    return 0;
}

int get_password(const char *username, char *password, size_t *password_length) {
    FILE *fp = fopen(PASSWORD_FILE, "rb");
    if (!fp) {
        perror("Error opening file");
        return 1;
    }

    Password stored_password;
    size_t size = sizeof(Password);

    while (fread(&stored_password, size, 1, fp) == 1) {
        if (strcmp(stored_password.username, username) == 0) {
            memcpy(password, stored_password.hash, SHA256_DIGEST_LENGTH);
            *password_length = SHA256_DIGEST_LENGTH;
            fclose(fp);
            return 0;
        }
    }

    fclose(fp);
    return 1;
}

int main() {
    char username[50], password[SHA256_DIGEST_LENGTH + 1];
    size_t password_length;

    while (1) {
        printf("Enter username: ");
        scanf("%s", username);

        if (strcmp(username, "exit") == 0) {
            break;
        }

        printf("Enter password: ");
        scanf("%s", password);

        add_password(username, password);
        printf("Password added successfully.\n");
    }

    while (1) {
        printf("Enter username to retrieve password: ");
        scanf("%s", username);

        if (strcmp(username, "exit") == 0) {
            break;
        }

        int result = get_password(username, password, &password_length);
        if (result == 1) {
            printf("Password not found.\n");
        } else {
            printf("Retrieved password: ");
            for (int i = 0; i < password_length; i++) {
                printf("%02x", password[i]);
            }
            printf("\n");
        }
    }

    return 0;
}