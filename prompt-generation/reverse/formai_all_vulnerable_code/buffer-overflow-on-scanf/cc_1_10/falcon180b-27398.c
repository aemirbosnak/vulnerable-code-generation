//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define QR_SIZE 21
#define BLOCK_SIZE 5

typedef struct {
    int id;
    int start_row;
    int end_row;
} ThreadData;

void *generate_qr(void *arg) {
    ThreadData *data = (ThreadData *) arg;
    int start_row = data->start_row;
    int end_row = data->end_row;

    for (int i = start_row; i <= end_row; i++) {
        for (int j = 0; j < QR_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                printf("  ");
            } else {
                printf("██");
            }
        }
        printf("\n");
    }

    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    printf("Enter the number of threads: ");
    scanf("%d", &thread_count);

    ThreadData data[thread_count];

    for (int i = 0; i < thread_count; i++) {
        data[i].id = i + 1;
        data[i].start_row = i * (QR_SIZE / thread_count);
        data[i].end_row = (i + 1) * (QR_SIZE / thread_count);

        pthread_create(&threads[i], NULL, generate_qr, &data[i]);
    }

    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}