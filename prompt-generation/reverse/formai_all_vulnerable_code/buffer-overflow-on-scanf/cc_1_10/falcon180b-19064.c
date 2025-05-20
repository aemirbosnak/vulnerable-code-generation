//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: multi-threaded
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_PASSWORD_LENGTH 20

struct thread_data {
    char password[MAX_PASSWORD_LENGTH];
    int strength;
};

void *check_password_strength(void *arg) {
    struct thread_data *data = (struct thread_data *) arg;
    char *password = data->password;
    int strength = 0;

    // Check for length
    if (strlen(password) < 8) {
        printf("Thread %d: Password is too short\n", data->strength);
        return NULL;
    }
    strength++;

    // Check for uppercase letters
    if (!strchr(password, 'A')) {
        printf("Thread %d: Password must contain at least one uppercase letter\n", data->strength);
        return NULL;
    }
    strength++;

    // Check for lowercase letters
    if (!strchr(password, 'a')) {
        printf("Thread %d: Password must contain at least one lowercase letter\n", data->strength);
        return NULL;
    }
    strength++;

    // Check for numbers
    if (!strchr(password, '0')) {
        printf("Thread %d: Password must contain at least one number\n", data->strength);
        return NULL;
    }
    strength++;

    // Check for special characters
    if (!strchr(password, '!')) {
        printf("Thread %d: Password must contain at least one special character\n", data->strength);
        return NULL;
    }
    strength++;

    printf("Thread %d: Password strength is %d\n", data->strength, strength);
    return NULL;
}

int main() {
    int num_threads = MAX_THREADS;
    pthread_t threads[MAX_THREADS];
    int i;
    char passwords[MAX_THREADS][MAX_PASSWORD_LENGTH];

    // Get passwords from user
    for (i = 0; i < num_threads; i++) {
        printf("Enter password %d: ", i + 1);
        scanf("%s", passwords[i]);
    }

    // Create threads
    for (i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, check_password_strength, (void *) &i);
    }

    // Wait for threads to finish
    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}