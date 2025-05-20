//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_SUBJECTS 100
#define MAX_RECIPIENTS 1000
#define MAX_MESSAGE_LENGTH 1024

typedef struct {
    char subject[MAX_SUBJECTS];
    char message[MAX_MESSAGE_LENGTH];
    int num_recipients;
    char *recipients[MAX_RECIPIENTS];
} message_t;

void *send_email(void *arg) {
    message_t *message = (message_t *) arg;

    printf("Sending email with subject: %s\n", message->subject);
    printf("To: ");
    for (int i = 0; i < message->num_recipients; i++) {
        printf("%s ", message->recipients[i]);
    }
    printf("\nMessage:\n%s\n", message->message);

    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    int num_threads = 0;

    message_t messages[MAX_THREADS];

    while (num_threads < MAX_THREADS) {
        printf("Enter subject: ");
        scanf("%s", messages[num_threads].subject);

        printf("Enter number of recipients: ");
        scanf("%d", &messages[num_threads].num_recipients);

        printf("Enter recipients (comma separated): ");
        scanf("%s", messages[num_threads].recipients[0]);

        int i = 1;
        while (i < messages[num_threads].num_recipients && messages[num_threads].recipients[i] == NULL) {
            printf("Enter recipient %d: ", i);
            scanf("%s", messages[num_threads].recipients[i]);
            i++;
        }

        printf("Enter message: ");
        scanf("%[^\n]", messages[num_threads].message);

        num_threads++;
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, send_email, &messages[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}