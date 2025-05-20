//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_SUBSCRIBERS 100
#define EMAIL_LENGTH 50
#define MESSAGE_LENGTH 256

typedef struct {
    char email[EMAIL_LENGTH];
} Subscriber;

Subscriber subscribers[MAX_SUBSCRIBERS];
int subscriber_count = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void paranoid_delay() {
    // Simulating paranoia that someone is watching
    for (volatile int i = 0; i < 100000; i++);
}

void add_subscriber(const char *email) {
    pthread_mutex_lock(&mutex);
    
    if (subscriber_count >= MAX_SUBSCRIBERS) {
        printf("Maximum subscriber limit reached! Can't add more emails.\n");
        pthread_mutex_unlock(&mutex);
        return;
    }

    // Check for duplicate
    for (int i = 0; i < subscriber_count; i++) {
        if (strcmp(subscribers[i].email, email) == 0) {
            printf("Email %s is already subscribed!\n", email);
            pthread_mutex_unlock(&mutex);
            return;
        }
    }

    strcpy(subscribers[subscriber_count].email, email);
    subscriber_count++;
    printf("Added subscriber: %s\n", email);
    pthread_mutex_unlock(&mutex);
}

void send_message(const char *message) {
    pthread_mutex_lock(&mutex);
    
    for (int i = 0; i < subscriber_count; i++) {
        printf("Sending message to: %s\n", subscribers[i].email);
        paranoid_delay(); // simulating paranoia in sending messages
    }
    
    printf("All messages sent!\n");
    pthread_mutex_unlock(&mutex);
}

void display_subscribers() {
    pthread_mutex_lock(&mutex);
    
    printf("Current Subscribers (%d):\n", subscriber_count);
    for (int i = 0; i < subscriber_count; i++) {
        printf("%s\n", subscribers[i].email);
    }
    
    pthread_mutex_unlock(&mutex);
}

void* subscription_thread(void* arg) {
    char email[EMAIL_LENGTH];

    while (1) {
        printf("Enter email to subscribe (or 'exit' to quit): ");
        scanf("%s", email);
        
        if (strcmp(email, "exit") == 0) {
            break;
        }

        add_subscriber(email);
    }
    return NULL;
}

void* messaging_thread(void* arg) {
    char message[MESSAGE_LENGTH];

    while (1) {
        printf("Enter message to send (or 'exit' to quit): ");
        getchar(); // Consume remaining newline
        fgets(message, MESSAGE_LENGTH, stdin);
        message[strcspn(message, "\n")] = 0; // Remove newline
        
        if (strcmp(message, "exit") == 0) {
            break;
        }

        send_message(message);
    }
    return NULL;
}

int main() {
    pthread_t subscriber_tid, messenger_tid;

    pthread_create(&subscriber_tid, NULL, subscription_thread, NULL);
    pthread_create(&messenger_tid, NULL, messaging_thread, NULL);

    pthread_join(subscriber_tid, NULL);
    pthread_join(messenger_tid, NULL);

    display_subscribers();
    printf("Exiting the mailing list manager. Stay vigilant!\n");
    
    return 0;
}