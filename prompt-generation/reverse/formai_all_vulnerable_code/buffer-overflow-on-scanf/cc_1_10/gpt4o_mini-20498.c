//GPT-4o-mini DATASET v1.0 Category: Spam Detection System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_USERS 5
#define MAX_MESSAGE_LENGTH 256
#define SPAM_THRESHOLD 3

char *spam_keywords[] = {
    "win", "free", "money", "prize", "click", "buy", "offer"
};

typedef struct {
    char username[20];
    int spam_counter;
} User;

User users[MAX_USERS];
int user_count = 0;

pthread_mutex_t lock;

void *send_message(void *arg) {
    User *user = (User *)arg;
    char message[MAX_MESSAGE_LENGTH];

    while (1) {
        printf("%s, enter your message: ", user->username);
        fgets(message, MAX_MESSAGE_LENGTH, stdin);
        message[strcspn(message, "\n")] = 0; // Remove newline

        int spam_flag = 0;
        for (int i = 0; i < sizeof(spam_keywords) / sizeof(spam_keywords[0]); i++) {
            if (strstr(message, spam_keywords[i]) != NULL) {
                user->spam_counter++;
                spam_flag = 1;
                printf("Warning: Your message may be spam. (%s detected)\n", spam_keywords[i]);
                break;
            }
        }

        if (spam_flag == 0) {
            printf("%s: %s\n", user->username, message);
        }

        if (user->spam_counter >= SPAM_THRESHOLD) {
            printf("User %s has been banned for spamming!\n", user->username);
            break;
        }
    }
    return NULL;
}

void *monitor_users(void *arg) {
    while (1) {
        sleep(10);
        pthread_mutex_lock(&lock);
        for (int i = 0; i < user_count; i++) {
            printf("Current spam count for %s: %d\n", users[i].username, users[i].spam_counter);
            if (users[i].spam_counter >= SPAM_THRESHOLD) {
                printf("User %s is banned.\n", users[i].username);
            }
        }
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main() {
    pthread_mutex_init(&lock, NULL);
    pthread_t threads[MAX_USERS];
    pthread_t monitor_thread;

    printf("Welcome to the Multiplayer Chat! Please enter usernames for up to %d users.\n", MAX_USERS);
    for (int i = 0; i < MAX_USERS; i++) {
        printf("Enter username for user %d: ", i + 1);
        scanf("%s", users[i].username);
        users[i].spam_counter = 0;
        user_count++;
        getchar(); // Consume newline character after scanf
        pthread_create(&threads[i], NULL, send_message, &users[i]);
    }

    pthread_create(&monitor_thread, NULL, monitor_users, NULL);

    for (int i = 0; i < user_count; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_cancel(monitor_thread);
    pthread_mutex_destroy(&lock);
    return 0;
}