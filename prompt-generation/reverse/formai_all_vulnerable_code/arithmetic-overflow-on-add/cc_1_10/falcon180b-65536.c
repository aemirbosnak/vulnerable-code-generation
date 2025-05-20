//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_PASSWORD_LENGTH 16

struct thread_data {
    int id;
    char password[MAX_PASSWORD_LENGTH];
};

void *generate_password(void *data) {
    struct thread_data *thread_data = (struct thread_data *) data;
    int id = thread_data->id;
    char password[MAX_PASSWORD_LENGTH];

    srand(time(NULL) + id);

    for (int i = 0; i < MAX_PASSWORD_LENGTH; i++) {
        char ch = rand() % 26 + 'a';
        if (isalpha(ch)) {
            password[i] = ch;
        }
    }

    strcpy(thread_data->password, password);

    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    struct thread_data thread_data[MAX_THREADS];

    for (int i = 0; i < MAX_THREADS; i++) {
        thread_data[i].id = i;
        pthread_create(&threads[i], NULL, generate_password, &thread_data[i]);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        printf("Thread %d generated password: %s\n", thread_data[i].id, thread_data[i].password);
    }

    return 0;
}