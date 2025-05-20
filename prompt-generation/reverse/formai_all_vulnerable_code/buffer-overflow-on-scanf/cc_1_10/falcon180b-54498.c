//Falcon-180B DATASET v1.0 Category: Password management ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_USERS 100
#define MAX_PASSWORDS 100

struct user {
    char username[20];
    char password[50];
    int id;
};

struct user users[MAX_USERS];
int num_users = 0;

void *add_user_thread(void *arg) {
    char username[20];
    char password[50];
    int id;

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("User already exists.\n");
            return NULL;
        }
    }

    strcpy(users[num_users].username, username);
    strcpy(users[num_users].password, password);
    users[num_users].id = id;
    num_users++;

    printf("User added successfully.\n");
    return NULL;
}

void *login_thread(void *arg) {
    char username[20];
    char password[50];

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Login successful.\n");
            return NULL;
        }
    }

    printf("Login failed.\n");
    return NULL;
}

int main() {
    pthread_t thread_id;

    while (1) {
        printf("1. Add user\n2. Login\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                pthread_create(&thread_id, NULL, add_user_thread, NULL);
                break;
            case 2:
                pthread_create(&thread_id, NULL, login_thread, NULL);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}