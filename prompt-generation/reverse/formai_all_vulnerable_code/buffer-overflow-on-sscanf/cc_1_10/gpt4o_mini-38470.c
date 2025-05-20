//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_LISTS 10
#define MAX_SUBSCRIBERS 100
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char email[MAX_EMAIL_LENGTH];
} Subscriber;

typedef struct {
    char name[50];
    Subscriber subscribers[MAX_SUBSCRIBERS];
    int subscriber_count;
    pthread_mutex_t lock; // to lock access to subscribers
} MailingList;

MailingList mailing_lists[MAX_LISTS];
int list_count = 0;

void initialize_lists() {
    for (int i = 0; i < MAX_LISTS; i++) {
        mailing_lists[i].subscriber_count = 0;
        pthread_mutex_init(&mailing_lists[i].lock, NULL);
    }
}

void create_list(char *name) {
    if (list_count < MAX_LISTS) {
        strncpy(mailing_lists[list_count].name, name, 50);
        mailing_lists[list_count].name[49] = '\0'; // ensure null termination
        list_count++;
        printf("Mailing list '%s' created successfully.\n", name);
    } else {
        printf("Maximum mailing lists reached!\n");
    }
}

void subscribe(char *list_name, char *email) {
    for (int i = 0; i < list_count; i++) {
        if (strcmp(mailing_lists[i].name, list_name) == 0) {
            pthread_mutex_lock(&mailing_lists[i].lock);
            if (mailing_lists[i].subscriber_count < MAX_SUBSCRIBERS) {
                strncpy(mailing_lists[i].subscribers[mailing_lists[i].subscriber_count].email, email, MAX_EMAIL_LENGTH);
                mailing_lists[i].subscribers[mailing_lists[i].subscriber_count].email[MAX_EMAIL_LENGTH-1] = '\0'; // ensure null termination
                mailing_lists[i].subscriber_count++;
                printf("Email '%s' subscribed to list '%s'.\n", email, list_name);
            } else {
                printf("List '%s' is full!\n", list_name);
            }
            pthread_mutex_unlock(&mailing_lists[i].lock);
            return;
        }
    }
    printf("List '%s' not found!\n", list_name);
}

void list_subscribers(char *list_name) {
    for (int i = 0; i < list_count; i++) {
        if (strcmp(mailing_lists[i].name, list_name) == 0) {
            pthread_mutex_lock(&mailing_lists[i].lock);
            printf("Subscribers of '%s':\n", list_name);
            for (int j = 0; j < mailing_lists[i].subscriber_count; j++) {
                printf("- %s\n", mailing_lists[i].subscribers[j].email);
            }
            pthread_mutex_unlock(&mailing_lists[i].lock);
            return;
        }
    }
    printf("List '%s' not found!\n", list_name);
}

void *worker_thread(void *arg) {
    char command[100];
    while (1) {
        printf("Enter command (create/subscribe/list/exit): ");
        fgets(command, sizeof(command), stdin);
        
        char action[20], param1[50], param2[MAX_EMAIL_LENGTH];
        sscanf(command, "%s %s %[^\n]", action, param1, param2);
        
        if (strcmp(action, "create") == 0) {
            create_list(param1);
        } else if (strcmp(action, "subscribe") == 0) {
            subscribe(param1, param2);
        } else if (strcmp(action, "list") == 0) {
            list_subscribers(param1);
        } else if (strcmp(action, "exit") == 0) {
            pthread_exit(NULL);
        } else {
            printf("Unknown command!\n");
        }
    }
}

int main() {
    initialize_lists();
    pthread_t thread;

    if (pthread_create(&thread, NULL, worker_thread, NULL) != 0) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }

    pthread_join(thread, NULL);
    printf("Exiting mailing list manager.\n");

    return 0;
}