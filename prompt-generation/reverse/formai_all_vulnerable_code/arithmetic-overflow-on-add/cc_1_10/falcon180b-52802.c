//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_THREADS 5
#define MAX_FORTUNES 100

struct fortune {
    char text[80];
    int length;
};

void *thread_func(void *arg) {
    int thread_id = (int) arg;
    char fortunes_file[100];
    sprintf(fortunes_file, "fortunes_thread_%d.txt", thread_id);

    FILE *fortunes_fp = fopen(fortunes_file, "w");
    if (fortunes_fp == NULL) {
        printf("Error: could not create fortunes file for thread %d\n", thread_id);
        exit(1);
    }

    srand(time(NULL) + thread_id);
    for (int i = 0; i < MAX_FORTUNES; i++) {
        struct fortune fortune;
        fortune.length = rand() % 80;
        for (int j = 0; j < fortune.length; j++) {
            char c = rand() % 26 + 'a';
            if (c > 'z') {
                c = 'a';
            }
            fortune.text[j] = c;
        }
        fprintf(fortunes_fp, "%s\n", fortune.text);
    }

    fclose(fortunes_fp);
    printf("Thread %d finished writing fortunes to file.\n", thread_id);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void *) i);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads have finished.\n");
    return 0;
}