//Falcon-180B DATASET v1.0 Category: Password management ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    int length;
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void *generatePasswords(void *arg) {
    char *username = (char *) arg;
    int i;

    for (i = 0; i < 5; i++) {
        int length = rand() % MAX_PASSWORD_LENGTH + 8;
        char password[MAX_PASSWORD_LENGTH];
        snprintf(password, length, "%s%d", username, i);
        strcpy(passwords[numPasswords].password, password);
        passwords[numPasswords].length = length;
        numPasswords++;
    }

    return NULL;
}

void *checkPasswords(void *arg) {
    char *username = (char *) arg;
    int i;

    for (i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].password, username) == 0) {
            printf("Password found: %s\n", passwords[i].password);
        }
    }

    return NULL;
}

int main() {
    pthread_t threads[2];
    char username[MAX_PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);

    pthread_create(&threads[0], NULL, generatePasswords, (void *) username);
    pthread_create(&threads[1], NULL, checkPasswords, (void *) username);

    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);

    return 0;
}