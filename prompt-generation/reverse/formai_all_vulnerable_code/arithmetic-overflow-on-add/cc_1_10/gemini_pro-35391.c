//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_THREADS 4
#define PASSWORD_LEN 16

typedef struct {
    char password[PASSWORD_LEN + 1];
    int thread_id;
} password_result;

void *generate_password(void *arg) {
    password_result *result = (password_result *)arg;

    srand(time(NULL) + result->thread_id);

    for (int i = 0; i < PASSWORD_LEN; i++) {
        int char_type = rand() % 3;

        if (char_type == 0) {
            result->password[i] = rand() % 26 + 'a';
        } else if (char_type == 1) {
            result->password[i] = rand() % 26 + 'A';
        } else {
            result->password[i] = rand() % 10 + '0';
        }
    }

    result->password[PASSWORD_LEN] = '\0';

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    password_result results[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        results[i].thread_id = i;
        pthread_create(&threads[i], NULL, generate_password, &results[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        printf("Thread %d: %s\n", results[i].thread_id, results[i].password);
    }

    return 0;
}