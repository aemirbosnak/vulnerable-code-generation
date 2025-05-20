//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_THREADS 4

typedef struct {
    char *password;
    int score;
} password_info_t;

void *check_password(void *arg) {
    password_info_t *info = (password_info_t *)arg;

    int score = 0;

    // Check password length
    if (strlen(info->password) < 8) {
        score += 1;
    }

    // Check for lowercase characters
    int has_lower = 0;
    for (int i = 0; i < strlen(info->password); i++) {
        if (islower(info->password[i])) {
            has_lower = 1;
            break;
        }
    }
    if (!has_lower) {
        score += 1;
    }

    // Check for uppercase characters
    int has_upper = 0;
    for (int i = 0; i < strlen(info->password); i++) {
        if (isupper(info->password[i])) {
            has_upper = 1;
            break;
        }
    }
    if (!has_upper) {
        score += 1;
    }

    // Check for digits
    int has_digit = 0;
    for (int i = 0; i < strlen(info->password); i++) {
        if (isdigit(info->password[i])) {
            has_digit = 1;
            break;
        }
    }
    if (!has_digit) {
        score += 1;
    }

    // Check for special characters
    int has_special = 0;
    for (int i = 0; i < strlen(info->password); i++) {
        if (!isalnum(info->password[i])) {
            has_special = 1;
            break;
        }
    }
    if (!has_special) {
        score += 1;
    }

    info->score = score;

    return NULL;
}

int main() {
    // Get passwords from the user
    char passwords[4][50];
    for (int i = 0; i < 4; i++) {
        printf("Enter password %d: ", i + 1);
        scanf("%s", passwords[i]);
    }

    // Create a thread pool
    pthread_t threads[NUM_THREADS];

    // Create password info structs
    password_info_t info[4];
    for (int i = 0; i < 4; i++) {
        info[i].password = passwords[i];
        info[i].score = 0;
    }

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, check_password, (void *)&info[i]);
    }

    // Join threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print password scores
    for (int i = 0; i < 4; i++) {
        printf("Password %d: %d\n", i + 1, info[i].score);
    }

    return 0;
}