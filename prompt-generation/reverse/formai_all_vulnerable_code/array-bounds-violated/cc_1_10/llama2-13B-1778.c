//LLAMA2-13B DATASET v1.0 Category: Bitwise operations ; Style: secure
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20
#define MAX_USERNAME_LENGTH 20

typedef struct {
    uint32_t password_hash[5];  // salted password hash
    uint32_t username_hash[5];   // salted username hash
} user_info_t;

void generate_salt(user_info_t *user) {
    uint32_t salt = (uint32_t)time(NULL);
    user->password_hash[0] = salt;
    user->username_hash[0] = salt;
}

void hash_password(user_info_t *user, const char *password) {
    uint32_t hash[5];
    for (int i = 0; i < 5; i++) {
        hash[i] = (uint32_t)password[i] << 24;
    }
    for (int i = 5; i < 10; i++) {
        hash[i] = hash[i - 5] ^ (uint32_t)password[i] << 24;
    }
    user->password_hash[1] = hash[0];
    user->password_hash[2] = hash[1];
    user->password_hash[3] = hash[2];
    user->password_hash[4] = hash[3];
}

void hash_username(user_info_t *user, const char *username) {
    uint32_t hash[5];
    for (int i = 0; i < 5; i++) {
        hash[i] = (uint32_t)username[i] << 24;
    }
    for (int i = 5; i < 10; i++) {
        hash[i] = hash[i - 5] ^ (uint32_t)username[i] << 24;
    }
    user->username_hash[1] = hash[0];
    user->username_hash[2] = hash[1];
    user->username_hash[3] = hash[2];
    user->username_hash[4] = hash[3];
}

int compare_password(user_info_t *user, const char *password) {
    uint32_t hash[5];
    for (int i = 0; i < 5; i++) {
        hash[i] = user->password_hash[i] ^ (uint32_t)password[i] << 24;
    }
    for (int i = 5; i < 10; i++) {
        hash[i] = hash[i - 5] ^ (uint32_t)password[i] << 24;
    }
    for (int i = 0; i < 5; i++) {
        if (hash[i] != user->password_hash[i]) {
            return 0;
        }
    }
    return 1;
}

int compare_username(user_info_t *user, const char *username) {
    uint32_t hash[5];
    for (int i = 0; i < 5; i++) {
        hash[i] = user->username_hash[i] ^ (uint32_t)username[i] << 24;
    }
    for (int i = 5; i < 10; i++) {
        hash[i] = hash[i - 5] ^ (uint32_t)username[i] << 24;
    }
    for (int i = 0; i < 5; i++) {
        if (hash[i] != user->username_hash[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    user_info_t user;
    generate_salt(&user);
    hash_password(&user, "secret");
    hash_username(&user, "johndoe");
    if (compare_password(&user, "secret")) {
        printf("Password correct\n");
    } else {
        printf("Password incorrect\n");
    }
    if (compare_username(&user, "johndoe")) {
        printf("Username correct\n");
    } else {
        printf("Username incorrect\n");
    }
    return 0;
}