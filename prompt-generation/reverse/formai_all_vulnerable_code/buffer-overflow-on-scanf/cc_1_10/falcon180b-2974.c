//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10

typedef struct {
    int id;
    char *message;
    int message_len;
    int start_pos;
    int watermark_pos;
} ThreadData;

void *thread_func(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    char *message = data->message;
    int message_len = data->message_len;
    int start_pos = data->start_pos;
    int watermark_pos = data->watermark_pos;

    int i;
    for(i = start_pos; i < message_len; i++) {
        if(i == watermark_pos) {
            message[i] = '*';
        } else {
            message[i] = message[i] ^ '*';
        }
    }

    printf("Thread %d finished watermarking message.\n", data->id);
    pthread_exit(NULL);
}

int main() {
    int num_threads;
    printf("Enter number of threads: ");
    scanf("%d", &num_threads);

    if(num_threads > MAX_THREADS) {
        printf("Error: Maximum number of threads is %d.\n", MAX_THREADS);
        return 1;
    }

    pthread_t threads[MAX_THREADS];
    ThreadData data[MAX_THREADS];

    char message[1024] = "This is a secret message. ";
    int message_len = strlen(message);
    int watermark_pos = message_len / 2;

    int chunk_size = message_len / num_threads;
    int remainder = message_len % num_threads;

    int i;
    for(i = 0; i < num_threads; i++) {
        int start_pos = i * chunk_size;
        if(i < remainder) {
            start_pos += chunk_size;
        }

        data[i].id = i + 1;
        data[i].message = message;
        data[i].message_len = message_len;
        data[i].start_pos = start_pos;
        data[i].watermark_pos = watermark_pos;

        pthread_create(&threads[i], NULL, thread_func, (void *)&data[i]);
    }

    for(i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Watermarking completed.\n");
    return 0;
}