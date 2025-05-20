//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char password[MAX_PASSWORD_LENGTH + 1];
    int strength;
} Password;

void *check_password_strength(void *arg) {
    Password *password = (Password *) arg;
    int length = strlen(password->password);
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_digit = 0;
    int has_special = 0;

    for (int i = 0; i < length; i++) {
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

    if (length >= 8) {
        strength++;
    }

    if (has_uppercase && has_lowercase) {
        strength++;
    }

    if (has_digit && has_special) {
        strength++;
    }

    password->strength = strength;

    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    Password passwords[MAX_THREADS];

    int num_passwords = 0;

    while (num_passwords < MAX_THREADS) {
        printf("Enter a password (or press enter to stop): ");
        char input[MAX_PASSWORD_LENGTH + 1];
        scanf("%s", input);

        if (strcmp(input, "") == 0) {
            break;
        }

        strcpy(passwords[num_passwords].password, input);
        num_passwords++;
    }

    for (int i = 0; i < num_passwords; i++) {
        pthread_create(&threads[i], NULL, check_password_strength, &passwords[i]);
    }

    for (int i = 0; i < num_passwords; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < num_passwords; i++) {
        printf("Password %d strength: %d\n", i + 1, passwords[i].strength);
    }

    return 0;
}