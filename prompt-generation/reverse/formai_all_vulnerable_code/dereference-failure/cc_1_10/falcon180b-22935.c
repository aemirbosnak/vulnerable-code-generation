//Falcon-180B DATASET v1.0 Category: Password management ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20
#define NUM_THREADS 3

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    int length;
} Password;

Password passwords[MAX_PASSWORDS];
pthread_t threads[NUM_THREADS];
int thread_count = 0;

void *generate_password(void *param) {
    int i;
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    Password *password = (Password *) param;

    for (i = 0; i < password->length; i++) {
        password->password[i] = charset[rand() % strlen(charset)];
    }
    password->password[password->length] = '\0';

    return NULL;
}

int main() {
    int i;

    for (i = 0; i < MAX_PASSWORDS; i++) {
        passwords[i].length = rand() % (MAX_PASSWORD_LENGTH - 4) + 4;
        printf("Generating password of length %d...\n", passwords[i].length);
        pthread_create(&threads[thread_count++], NULL, generate_password, &passwords[i]);
    }

    for (i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    for (i = 0; i < MAX_PASSWORDS; i++) {
        printf("Password %d: %s\n", i + 1, passwords[i].password);
    }

    return 0;
}