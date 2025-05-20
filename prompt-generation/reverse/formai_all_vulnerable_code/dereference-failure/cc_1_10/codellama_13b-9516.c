//Code Llama-13B DATASET v1.0 Category: Secure Password Generator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define PASSWORD_LENGTH 16

bool check_password(char *password) {
    bool is_valid = true;

    if (strlen(password) < PASSWORD_LENGTH) {
        is_valid = false;
    }

    if (!strchr(password, 'a')) {
        is_valid = false;
    }

    if (!strchr(password, 'A')) {
        is_valid = false;
    }

    if (!strchr(password, '1')) {
        is_valid = false;
    }

    if (!strchr(password, '!')) {
        is_valid = false;
    }

    return is_valid;
}

char *generate_password() {
    char *password = malloc(PASSWORD_LENGTH + 1);

    srand(time(NULL));

    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        if (i % 2 == 0) {
            password[i] = 'a' + rand() % 26;
        } else {
            password[i] = 'A' + rand() % 26;
        }
    }

    password[PASSWORD_LENGTH] = '\0';

    return password;
}

int main() {
    char *password = generate_password();

    while (!check_password(password)) {
        password = generate_password();
    }

    printf("Your password is: %s\n", password);

    free(password);

    return 0;
}