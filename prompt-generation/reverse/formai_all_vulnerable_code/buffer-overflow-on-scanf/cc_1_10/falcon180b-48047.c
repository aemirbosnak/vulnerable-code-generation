//Falcon-180B DATASET v1.0 Category: Text to Morse code conversion ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_MSG_LENGTH 100

char msg[MAX_THREADS][MAX_MSG_LENGTH];
int msg_length[MAX_THREADS];
int num_threads = 0;

void *thread_func(void *arg) {
    char *message = (char *) arg;
    int msg_len = strlen(message);

    if (msg_len > MAX_MSG_LENGTH) {
        printf("Error: Message too long.\n");
        exit(1);
    }

    strcpy(msg[num_threads], message);
    msg_length[num_threads] = msg_len;
    num_threads++;

    return NULL;
}

void morse_encode(char *message, int msg_len) {
    char *morse_code = ".-";
    char *alpha_numeric = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    for (int i = 0; i < msg_len; i++) {
        if (isalpha(message[i])) {
            printf("%c ", morse_code[toupper(message[i]) - 'A']);
        } else if (isdigit(message[i])) {
            printf("%c ", morse_code[message[i] - '0']);
        } else {
            printf("%c ", message[i]);
        }
    }

    printf("\n");
}

int main() {
    printf("Enter message to encode (max %d characters): ", MAX_MSG_LENGTH - 1);
    scanf("%s", msg[0]);
    msg_length[0] = strlen(msg[0]);
    num_threads = 1;

    pthread_t threads[MAX_THREADS];

    for (int i = 1; i < MAX_THREADS && num_threads < MAX_THREADS; i++) {
        printf("Enter message for thread %d (max %d characters): ", i, MAX_MSG_LENGTH - 1);
        scanf("%s", msg[i]);
        msg_length[i] = strlen(msg[i]);
        num_threads++;

        pthread_create(&threads[i], NULL, thread_func, (void *) msg[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < num_threads; i++) {
        morse_encode(msg[i], msg_length[i]);
    }

    return 0;
}