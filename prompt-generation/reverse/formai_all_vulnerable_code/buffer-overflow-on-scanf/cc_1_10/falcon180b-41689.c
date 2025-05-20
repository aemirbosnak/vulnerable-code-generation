//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4
#define MAX_SONGS 100
#define MAX_THREADS 10

typedef struct song {
    char title[50];
    char artist[50];
    int duration;
} song;

song library[MAX_SONGS];
int num_songs = 0;

pthread_mutex_t lock;

void *thread_func(void *param) {
    int thread_num = *(int *)param;
    char thread_name[10];
    sprintf(thread_name, "Thread %d", thread_num);
    pthread_setname_np(pthread_self(), thread_name);

    while (1) {
        pthread_mutex_lock(&lock);
        if (num_songs == MAX_SONGS) {
            printf("Thread %s: Library is full.\n", thread_name);
            pthread_mutex_unlock(&lock);
            break;
        }
        printf("Thread %s: Adding song...\n", thread_name);
        fflush(stdout);
        printf("Enter song title: ");
        scanf("%s", library[num_songs].title);
        printf("Enter song artist: ");
        scanf("%s", library[num_songs].artist);
        printf("Enter song duration (in seconds): ");
        scanf("%d", &library[num_songs].duration);
        num_songs++;
        pthread_mutex_unlock(&lock);
        sleep(1);
    }

    return NULL;
}

int main() {
    int i;
    pthread_t threads[NUM_THREADS];

    pthread_mutex_init(&lock, NULL);

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void *)&i);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Library:\n");
    for (i = 0; i < num_songs; i++) {
        printf("%s - %s (%d seconds)\n", library[i].title, library[i].artist, library[i].duration);
    }

    return 0;
}