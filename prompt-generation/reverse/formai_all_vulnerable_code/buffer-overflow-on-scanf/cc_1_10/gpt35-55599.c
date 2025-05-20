//FormAI DATASET v1.0 Category: Password management ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_PASSWORDS 5
#define MAX_LENGTH 10

char passwords[MAX_PASSWORDS][MAX_LENGTH];
int numPasswords = 0;

pthread_mutex_t lock;

void* getPassword(void* arg) {
    pthread_mutex_lock(&lock);
    char* password = (char*)malloc(MAX_LENGTH * sizeof(char));
    printf("Enter a password: ");
    scanf("%s", password);
    if (numPasswords < MAX_PASSWORDS) {
        // Add the password to the array if there is space
        strcpy(passwords[numPasswords++], password);
        printf("Password added successfully.\n");
    } else {
        printf("No more passwords can be added.\n");
    }
    pthread_mutex_unlock(&lock);
    free(password);
    pthread_exit(NULL);
}

void* findPassword(void* arg) {
    char* password = (char*)arg;
    pthread_mutex_lock(&lock);
    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i], password) == 0) {
            printf("Password found at index %d.\n", i);
            pthread_mutex_unlock(&lock);
            pthread_exit(NULL);
        }
    }
    printf("Password not found.\n");
    pthread_mutex_unlock(&lock);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[2];
    pthread_mutex_init(&lock, NULL);
    
    // Get five passwords from the user
    for (int i = 0; i < MAX_PASSWORDS; i++) {
        pthread_create(&threads[0], NULL, getPassword, NULL);
        pthread_join(threads[0], NULL);
    }
    
    // Search for a password
    char password[MAX_LENGTH];
    printf("Enter a password to search for: ");
    scanf("%s", password);
    pthread_create(&threads[1], NULL, findPassword, password);
    pthread_join(threads[1], NULL);

    pthread_mutex_destroy(&lock);
    return 0;
}