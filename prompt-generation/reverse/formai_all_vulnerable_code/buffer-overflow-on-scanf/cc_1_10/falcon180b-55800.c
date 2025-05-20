//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <stdbool.h>

#define MAX_SUBSCRIBERS 100
#define MAX_EMAILS 100
#define MAX_THREADS 10

typedef struct {
    char name[50];
    char email[100];
} Subscriber;

Subscriber subscribers[MAX_SUBSCRIBERS];
int num_subscribers;

void *send_email(void *arg) {
    char *email = (char *) arg;
    printf("Sending email to %s...\n", email);
}

int main() {
    printf("Enter number of subscribers: ");
    scanf("%d", &num_subscribers);

    printf("Enter subscriber information:\n");
    for (int i = 0; i < num_subscribers; i++) {
        printf("Name: ");
        scanf("%s", subscribers[i].name);
        printf("Email: ");
        scanf("%s", subscribers[i].email);
    }

    pthread_t threads[MAX_THREADS];
    int rc;
    for (int i = 0; i < num_subscribers; i++) {
        rc = pthread_create(&threads[i % MAX_THREADS], NULL, send_email, subscribers[i].email);
        if (rc) {
            printf("Error: unable to create thread, %d\n", rc);
            exit(-1);
        }
    }

    for (int i = 0; i < num_subscribers; i++) {
        pthread_join(threads[i % MAX_THREADS], NULL);
    }

    return 0;
}