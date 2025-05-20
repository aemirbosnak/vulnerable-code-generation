//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <pthread.h>

#define MAX_THREADS 10
#define PASSWORD_LENGTH 12
#define CHARACTER_SET "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_-+={}[];:,.<>?/|\\"

typedef struct {
    int id;
    char password[PASSWORD_LENGTH + 1];
} thread_data;

void *generate_password(void *arg) {
    thread_data *data = (thread_data *) arg;
    int id = data->id;
    char password[PASSWORD_LENGTH + 1];

    srand(time(NULL) + id);
    for(int i=0; i<PASSWORD_LENGTH; i++) {
        password[i] = CHARACTER_SET[rand() % strlen(CHARACTER_SET)];
    }
    password[PASSWORD_LENGTH] = '\0';

    strcpy(data->password, password);

    pthread_exit(0);
}

int main() {
    pthread_t threads[MAX_THREADS];
    thread_data data[MAX_THREADS];

    int i;
    for(i=0; i<MAX_THREADS; i++) {
        data[i].id = i;
        pthread_create(&threads[i], NULL, generate_password, &data[i]);
    }

    for(i=0; i<MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Password generated for thread 0: %s\n", data[0].password);

    return 0;
}