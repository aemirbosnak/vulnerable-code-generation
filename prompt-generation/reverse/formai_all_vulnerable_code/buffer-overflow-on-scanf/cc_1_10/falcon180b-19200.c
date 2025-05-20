//Falcon-180B DATASET v1.0 Category: Password management ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_USERS 10
#define MAX_PASSWORD_LENGTH 20
#define INVALID_USER -1

typedef struct {
    int user_id;
    char password[MAX_PASSWORD_LENGTH];
} user_t;

user_t users[MAX_USERS];
int num_users = 0;

pthread_mutex_t user_mutex = PTHREAD_MUTEX_INITIALIZER;

void* add_user_thread(void* arg) {
    int user_id = (int) arg;
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter password for user %d: ", user_id);
    scanf("%s", password);

    pthread_mutex_lock(&user_mutex);
    for (int i = 0; i < num_users; i++) {
        if (users[i].user_id == user_id) {
            printf("User already exists.\n");
            pthread_mutex_unlock(&user_mutex);
            return NULL;
        }
    }

    strcpy(users[num_users].password, password);
    users[num_users].user_id = user_id;
    num_users++;

    printf("User added successfully.\n");
    pthread_mutex_unlock(&user_mutex);

    return NULL;
}

void* check_password_thread(void* arg) {
    int user_id = (int) arg;
    char input_password[MAX_PASSWORD_LENGTH];

    printf("Enter password for user %d: ", user_id);
    scanf("%s", input_password);

    pthread_mutex_lock(&user_mutex);
    for (int i = 0; i < num_users; i++) {
        if (users[i].user_id == user_id) {
            if (strcmp(users[i].password, input_password) == 0) {
                printf("Password is correct.\n");
            } else {
                printf("Password is incorrect.\n");
            }
            pthread_mutex_unlock(&user_mutex);
            return NULL;
        }
    }

    printf("User not found.\n");
    pthread_mutex_unlock(&user_mutex);

    return NULL;
}

int main() {
    pthread_t thread_id[2];

    // Add users
    pthread_create(&thread_id[0], NULL, add_user_thread, (void*) 1);
    pthread_create(&thread_id[1], NULL, add_user_thread, (void*) 2);

    // Check passwords
    pthread_join(thread_id[0], NULL);
    pthread_join(thread_id[1], NULL);

    pthread_exit(0);
}