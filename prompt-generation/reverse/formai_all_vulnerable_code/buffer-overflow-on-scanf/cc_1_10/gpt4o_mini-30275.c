//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define MAX_USERS 10
#define MAX_LENGTH 50

typedef struct {
    char name[MAX_LENGTH];
    int steps;
} User;

User users[MAX_USERS];
int user_count = 0;
pthread_mutex_t mutex;

void* update_steps(void* arg) {
    User* user = (User*) arg;
    int daily_steps;

    printf("Enter steps for %s: ", user->name);
    scanf("%d", &daily_steps);
    
    pthread_mutex_lock(&mutex);
    user->steps += daily_steps;
    pthread_mutex_unlock(&mutex);
    
    return NULL;
}

void* print_summary(void* arg) {
    pthread_mutex_lock(&mutex);
    printf("\nFitness Tracker Summary:\n");
    printf("User\tSteps\n");
    printf("---------------------\n");
    for (int i = 0; i < user_count; i++) {
        printf("%s\t%d\n", users[i].name, users[i].steps);
    }
    pthread_mutex_unlock(&mutex);
    
    return NULL;
}

int main() {
    pthread_mutex_init(&mutex, NULL);
    pthread_t threads[MAX_USERS];
    pthread_t summary_thread;

    printf("Welcome to the Fitness Tracker!\n");
    printf("Enter the number of users (up to %d): ", MAX_USERS);
    scanf("%d", &user_count);
    
    if (user_count > MAX_USERS) {
        printf("Error: Maximum number of users is %d.\n", MAX_USERS);
        return 1;
    }

    for (int i = 0; i < user_count; i++) {
        printf("Enter name for user %d: ", i + 1);
        scanf("%s", users[i].name);
        users[i].steps = 0; // Initialize steps to zero
    }

    // Create threads for each user to input their steps
    for (int i = 0; i < user_count; i++) {
        pthread_create(&threads[i], NULL, update_steps, (void*)&users[i]);
    }

    // Wait for all user threads to finish
    for (int i = 0; i < user_count; i++) {
        pthread_join(threads[i], NULL);
    }

    // Create a thread for printing the summary
    pthread_create(&summary_thread, NULL, print_summary, NULL);
    pthread_join(summary_thread, NULL);

    pthread_mutex_destroy(&mutex);
    printf("Thank you for using Fitness Tracker!\n");

    return 0;
}