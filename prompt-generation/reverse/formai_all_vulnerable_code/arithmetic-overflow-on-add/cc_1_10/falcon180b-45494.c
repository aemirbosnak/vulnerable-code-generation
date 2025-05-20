//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5
#define NUM_CDs 10
#define NUM_SONGS 5

typedef struct {
    int id;
    char name[50];
    char artist[50];
    char genre[50];
    int num_songs;
    int *songs;
} CD;

CD cds[NUM_CDs] = {
    {1, "Thriller", "Michael Jackson", "Pop", 5, {1, 2, 3, 4, 5}},
    {2, "Rumours", "Fleetwood Mac", "Rock", 5, {6, 7, 8, 9, 10}},
    {3, "Back in Black", "AC/DC", "Hard Rock", 5, {11, 12, 13, 14, 15}},
    {4, "Dark Side of the Moon", "Pink Floyd", "Progressive Rock", 5, {16, 17, 18, 19, 20}},
    {5, "The Wall", "Pink Floyd", "Progressive Rock", 5, {21, 22, 23, 24, 25}},
    {6, "Born in the USA", "Bruce Springsteen", "Rock", 5, {26, 27, 28, 29, 30}},
    {7, "Led Zeppelin IV", "Led Zeppelin", "Hard Rock", 5, {31, 32, 33, 34, 35}},
    {8, "Hotel California", "Eagles", "Rock", 5, {36, 37, 38, 39, 40}},
    {9, "Tapestry", "Carole King", "Pop", 5, {41, 42, 43, 44, 45}},
    {10, "The Bodyguard", "Whitney Houston", "R&B", 5, {46, 47, 48, 49, 50}}
};

void *thread_func(void *arg);

int main() {
    pthread_t threads[NUM_THREADS];
    int i, j, k;

    for (i = 0; i < NUM_THREADS; i++) {
        for (j = 0; j < NUM_CDs; j++) {
            if (cds[j].num_songs > 0) {
                cds[j].songs[k] = j;
                k++;
            }
        }
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void *)i);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

void *thread_func(void *arg) {
    int id = *((int *)arg);
    int i, j;

    for (i = id; i < NUM_CDs; i += NUM_THREADS) {
        for (j = 0; j < cds[i].num_songs; j++) {
            printf("Thread %d is playing song %d from CD %s by %s in the genre %s\n", id, cds[i].songs[j] + 1, cds[i].name, cds[i].artist, cds[i].genre);
        }
    }

    return NULL;
}