//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_PASSWORD_LENGTH 32

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    int length;
    int strength;
} Password;

void *check_password_strength(void *arg) {
    Password *password = (Password *) arg;

    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_digit = 0;
    int has_special = 0;

    for (int i = 0; i < password->length; i++) {
        if (isupper(password->password[i])) {
            has_uppercase = 1;
        } else if (islower(password->password[i])) {
            has_lowercase = 1;
        } else if (isdigit(password->password[i])) {
            has_digit = 1;
        } else {
            has_special = 1;
        }
    }

    int strength = 0;

    if (has_uppercase && has_lowercase && has_digit && has_special) {
        strength = 4;
    } else if (has_uppercase && has_lowercase && has_digit) {
        strength = 3;
    } else if (has_uppercase && has_lowercase && has_special) {
        strength = 3;
    } else if (has_uppercase && has_digit && has_special) {
        strength = 3;
    } else if (has_lowercase && has_digit && has_special) {
        strength = 3;
    } else if (has_uppercase && has_lowercase) {
        strength = 2;
    } else if (has_uppercase && has_digit) {
        strength = 2;
    } else if (has_lowercase && has_digit) {
        strength = 2;
    } else if (has_uppercase && has_special) {
        strength = 2;
    } else if (has_lowercase && has_special) {
        strength = 2;
    } else if (has_digit && has_special) {
        strength = 2;
    } else {
        strength = 1;
    }

    password->strength = strength;

    pthread_exit(0);
}

int main() {
    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    Password passwords[MAX_THREADS];

    printf("Enter passwords to check (up to %d):\n", MAX_THREADS - 1);

    for (int i = 0; i < MAX_THREADS - 1; i++) {
        scanf("%s", passwords[i].password);
        passwords[i].length = strlen(passwords[i].password);

        pthread_create(&threads[thread_count], NULL, check_password_strength, (void *) &passwords[i]);
        thread_count++;
    }

    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Password strengths:\n");

    for (int i = 0; i < MAX_THREADS - 1; i++) {
        printf("Password %d: %d\n", i + 1, passwords[i].strength);
    }

    return 0;
}