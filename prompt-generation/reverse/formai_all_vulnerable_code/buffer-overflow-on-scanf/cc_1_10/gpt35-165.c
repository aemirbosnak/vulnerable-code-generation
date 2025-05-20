//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

#define MAX_THREADS 10

void *test_speed(void *arg);

int main() {
    pthread_t thread_ids[MAX_THREADS];
    int thread_args[MAX_THREADS];
    int num_threads, i;

    printf("Enter the number of threads to use (maximum %d): ", MAX_THREADS);
    scanf("%d", &num_threads);

    if (num_threads < 1 || num_threads > MAX_THREADS) {
        printf("Please enter a valid number of threads.\n");
        exit(1);
    }

    printf("\nDownloading a 10MB file to test internet speed...\n");

    for (i = 0; i < num_threads; i++) {
        thread_args[i] = i;
        pthread_create(&thread_ids[i], NULL, test_speed, &thread_args[i]);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(thread_ids[i], NULL);
    }

    printf("\nSpeed test complete.\n");

    return 0;
}

void *test_speed(void *arg) {
    int thread_num = *((int *) arg);
    char cmd[100];
    struct timeval start, end;
    double download_time;

    sprintf(cmd, "curl -o /dev/null -s -w '%%{time_total}' https://speed.hetzner.de/10GB.bin");

    gettimeofday(&start, NULL);
    system(cmd);
    gettimeofday(&end, NULL);

    download_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    printf("Thread %d - Download time: %.2f seconds\n", thread_num, download_time);

    pthread_exit(NULL);
}