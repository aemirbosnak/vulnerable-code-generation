//Falcon-180B DATASET v1.0 Category: Password management ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 5
#define MAX_USERS 50
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char username[MAX_USERS];
    char password[MAX_PASSWORD_LENGTH];
} User;

User users[MAX_USERS];

int num_users = 0;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *thread_function(void *arg) {
    int thread_id = *(int *) arg;

    printf("Thread %d starting\n", thread_id);

    while (1) {
        pthread_mutex_lock(&lock);

        if (num_users == MAX_USERS) {
            printf("Thread %d: User limit reached\n", thread_id);
            pthread_mutex_unlock(&lock);
            break;
        }

        printf("Thread %d: Enter username: ", thread_id);
        scanf("%s", users[num_users].username);

        printf("Thread %d: Enter password: ", thread_id);
        scanf("%s", users[num_users].password);

        num_users++;

        pthread_mutex_unlock(&lock);

        sleep(1);
    }

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_function, (void *) &i);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}