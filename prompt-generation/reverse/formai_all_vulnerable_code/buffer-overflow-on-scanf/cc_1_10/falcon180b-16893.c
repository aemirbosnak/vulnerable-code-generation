//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char password[MAX_PASSWORD_LENGTH+1];
    int strength;
} Password;

void *check_password_strength(void *arg) {
    Password *password = (Password *) arg;
    int length = strlen(password->password);
    int uppercase_count = 0, lowercase_count = 0, digit_count = 0;

    for (int i = 0; i < length; i++) {
        if (isupper(password->password[i])) {
            uppercase_count++;
        } else if (islower(password->password[i])) {
            lowercase_count++;
        } else if (isdigit(password->password[i])) {
            digit_count++;
        }
    }

    if (length >= 8 && uppercase_count >= 1 && lowercase_count >= 1 && digit_count >= 1) {
        password->strength = 3;
    } else if (length >= 8 && (uppercase_count >= 1 || lowercase_count >= 1 || digit_count >= 1)) {
        password->strength = 2;
    } else if (length >= 8) {
        password->strength = 1;
    } else {
        password->strength = 0;
    }

    return NULL;
}

int main() {
    int num_passwords = 10;
    Password passwords[num_passwords];
    pthread_t threads[num_passwords];

    for (int i = 0; i < num_passwords; i++) {
        printf("Enter password %d: ", i+1);
        scanf("%s", passwords[i].password);
        pthread_create(&threads[i], NULL, check_password_strength, &passwords[i]);
    }

    for (int i = 0; i < num_passwords; i++) {
        pthread_join(threads[i], NULL);
        printf("Password %d strength: %d\n", i+1, passwords[i].strength);
    }

    return 0;
}