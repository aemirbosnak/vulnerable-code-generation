//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_SUBSCRIBERS 100

typedef struct {
    char name[50];
    char email[100];
} Subscriber;

Subscriber subscribers[MAX_SUBSCRIBERS];
int num_subscribers = 0;

void *send_email(void *arg) {
    int i;
    char subject[100] = "Newsletter";
    char message[500] = "Dear ";

    for (i = 0; i < num_subscribers; i++) {
        strcat(message, subscribers[i].name);
        strcat(message, ",");
    }

    strcat(message, "\n\nBest regards,\nThe Team");

    printf("Sending email to %s...\n", subscribers[0].email);
    // Code to send email
    return NULL;
}

int main() {
    int i, j;
    pthread_t threads[MAX_THREADS];

    printf("Enter number of subscribers: ");
    scanf("%d", &num_subscribers);

    for (i = 0; i < num_subscribers; i++) {
        printf("Enter name of subscriber %d: ", i + 1);
        scanf("%s", subscribers[i].name);

        printf("Enter email of subscriber %d: ", i + 1);
        scanf("%s", subscribers[i].email);
    }

    for (i = 0; i < num_subscribers; i++) {
        pthread_create(&threads[i], NULL, send_email, (void *)i);
    }

    for (i = 0; i < num_subscribers; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}