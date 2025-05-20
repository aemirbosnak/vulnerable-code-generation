//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define NUM_THREADS 4

typedef struct {
    char *password;
    int strength;
} password_strength_t;

void *check_password_strength(void *arg) {
    password_strength_t *ps = (password_strength_t *)arg;

    int score = 0;

    // Check the length of the password
    if (strlen(ps->password) < 8) {
        score += 1;
    }

    // Check for uppercase characters
    int num_upper = 0;
    for (int i = 0; i < strlen(ps->password); i++) {
        if (ps->password[i] >= 'A' && ps->password[i] <= 'Z') {
            num_upper++;
        }
    }
    if (num_upper == 0) {
        score += 1;
    }

    // Check for lowercase characters
    int num_lower = 0;
    for (int i = 0; i < strlen(ps->password); i++) {
        if (ps->password[i] >= 'a' && ps->password[i] <= 'z') {
            num_lower++;
        }
    }
    if (num_lower == 0) {
        score += 1;
    }

    // Check for digits
    int num_digits = 0;
    for (int i = 0; i < strlen(ps->password); i++) {
        if (ps->password[i] >= '0' && ps->password[i] <= '9') {
            num_digits++;
        }
    }
    if (num_digits == 0) {
        score += 1;
    }

    // Check for special characters
    int num_specials = 0;
    for (int i = 0; i < strlen(ps->password); i++) {
        if (ps->password[i] >= '!' && ps->password[i] <= '~') {
            num_specials++;
        }
    }
    if (num_specials == 0) {
        score += 1;
    }

    // Set the strength of the password
    ps->strength = 5 - score;

    return NULL;
}

int main() {
    // Get the passwords from the user
    char passwords[NUM_THREADS][100];
    for (int i = 0; i < NUM_THREADS; i++) {
        printf("Enter password %d: ", i + 1);
        scanf("%s", passwords[i]);
    }

    // Create the threads
    pthread_t threads[NUM_THREADS];
    password_strength_t ps[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        ps[i].password = passwords[i];
        pthread_create(&threads[i], NULL, check_password_strength, &ps[i]);
    }

    // Join the threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the strength of the passwords
    for (int i = 0; i < NUM_THREADS; i++) {
        printf("The strength of password %d is %d\n", i + 1, ps[i].strength);
    }

    return 0;
}