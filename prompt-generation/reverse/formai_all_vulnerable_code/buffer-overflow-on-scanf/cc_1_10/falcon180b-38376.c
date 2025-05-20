//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX 1000

int arr[MAX];
int n;

void *producer(void *arg) {
    int i = 0;
    while (i < n) {
        arr[i] = rand() % 10;
        printf("Produced %d\n", arr[i]);
        i++;
        sleep(1);
    }
    return NULL;
}

void *consumer(void *arg) {
    int i = 0;
    while (i < n) {
        printf("Consumed %d\n", arr[i]);
        i++;
        sleep(2);
    }
    return NULL;
}

int main() {
    srand(time(NULL));
    pthread_t thread_id[2];
    int choice;
    printf("Enter 1 to start producer-consumer problem\n");
    scanf("%d", &choice);
    if (choice == 1) {
        printf("Enter the number of elements to be produced:\n");
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            arr[i] = -1;
        }
        pthread_create(&thread_id[0], NULL, producer, NULL);
        pthread_create(&thread_id[1], NULL, consumer, NULL);
        for (int i = 0; i < 2; i++) {
            pthread_join(thread_id[i], NULL);
        }
    }
    return 0;
}