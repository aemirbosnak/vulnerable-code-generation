//GEMINI-pro DATASET v1.0 Category: Automated Fortune Teller ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_THREADS 4

typedef struct {
    int thread_id;
    int num_fortunes;
} thread_data;

void *print_fortune(void *arg) {
    thread_data *data = (thread_data *)arg;

    srand(time(NULL) + data->thread_id);

    for (int i = 0; i < data->num_fortunes; i++) {
        int fortune_num = rand() % 10 + 1;
        printf("Thread %d: Fortune %d: ", data->thread_id, fortune_num);

        switch (fortune_num) {
            case 1:
                printf("A new adventure is on the horizon.\n");
                break;
            case 2:
                printf("Your hard work will pay off in the end.\n");
                break;
            case 3:
                printf("Be careful of what you wish for.\n");
                break;
            case 4:
                printf("A change is coming, but for better or for worse remains to be seen.\n");
                break;
            case 5:
                printf("Your intuition is telling you the truth.\n");
                break;
            case 6:
                printf("Don't give up on your dreams.\n");
                break;
            case 7:
                printf("You are stronger than you think.\n");
                break;
            case 8:
                printf("Love is in the air.\n");
                break;
            case 9:
                printf("Money is not everything.\n");
                break;
            case 10:
                printf("The future is bright.\n");
                break;
        }
    }

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    thread_data data[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        data[i].thread_id = i;
        data[i].num_fortunes = 3;
        pthread_create(&threads[i], NULL, print_fortune, &data[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}