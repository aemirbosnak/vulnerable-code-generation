//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_PASSWORD_LENGTH 64

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    int strength;
} PasswordData;

void *check_password_strength(void *data) {
    PasswordData *password_data = (PasswordData *)data;
    int length = strlen(password_data->password);
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_digit = 0;
    int has_special_char = 0;

    for (int i = 0; i < length; i++) {
        if (isupper(password_data->password[i])) {
            has_uppercase = 1;
        } else if (islower(password_data->password[i])) {
            has_lowercase = 1;
        } else if (isdigit(password_data->password[i])) {
            has_digit = 1;
        } else {
            has_special_char = 1;
        }
    }

    if (length >= 8) {
        password_data->strength = 1;
    } else {
        password_data->strength = 0;
    }

    if (has_uppercase && has_lowercase && has_digit && has_special_char) {
        password_data->strength++;
    }

    if (length >= 12) {
        password_data->strength++;
    }

    if (length >= 16) {
        password_data->strength++;
    }

    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    PasswordData data[MAX_THREADS];

    int num_threads = 0;

    while (num_threads < MAX_THREADS) {
        printf("Enter a password to check (or type 'exit' to quit): ");
        scanf("%s", data[num_threads].password);

        if (strcmp(data[num_threads].password, "exit") == 0) {
            break;
        }

        pthread_create(&threads[num_threads], NULL, check_password_strength, &data[num_threads]);
        num_threads++;
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}