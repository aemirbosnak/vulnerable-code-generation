//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: multi-threaded
//This program simulates the baggage handling process in an airport using multi-threading
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

//global variables
int baggage_count = 0, loaded_bags = 0, unloaded_bags = 0, total_bags = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t conveyor_condition = PTHREAD_COND_INITIALIZER;
pthread_cond_t loader_condition = PTHREAD_COND_INITIALIZER;
pthread_cond_t unloader_condition = PTHREAD_COND_INITIALIZER;

//function prototypes
void* feed_conveyor(void* arg);
void* loader(void* arg);
void* unloader(void* arg);

int main() {
    //initialize variables
    printf("Enter the number of bags to be loaded onto the conveyor: ");
    scanf("%d", &total_bags);
    printf("\n");

    //create threads
    pthread_t conveyor;
    pthread_t l1, l2;
    pthread_t u1, u2;

    pthread_create(&conveyor, NULL, feed_conveyor, NULL);
    pthread_create(&l1, NULL, loader, NULL);
    pthread_create(&l2, NULL, loader, NULL);
    pthread_create(&u1, NULL, unloader, NULL);
    pthread_create(&u2, NULL, unloader, NULL);

    //wait for threads to finish
    pthread_join(conveyor, NULL);
    pthread_join(l1, NULL);
    pthread_join(l2, NULL);
    pthread_join(u1, NULL);
    pthread_join(u2, NULL);

    //print results
    printf("All bags have been loaded and unloaded\n");
    printf("Total bags: %d\n", total_bags);
    printf("Bags loaded: %d\n", loaded_bags);
    printf("Bags unloaded: %d\n", unloaded_bags);

    return 0;
}

void* feed_conveyor(void* arg) {
    printf("Feeding conveyor with bags...\n");
    for (int i = 0; i < total_bags; i++) {
        //wait for conveyor to be available
        pthread_mutex_lock(&mutex);
        while (baggage_count != 0) {
            pthread_cond_wait(&conveyor_condition, &mutex);
        }
        /* Load the baggage onto conveyor */
        printf("Load baggage onto conveyor\n\n");
        baggage_count = 1;
        //signal loader thread
        pthread_cond_signal(&loader_condition);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void* loader(void* arg) {
    printf("Loader thread waiting...\n");
    while (loaded_bags < total_bags) {
        //wait for conveyor to be available
        pthread_mutex_lock(&mutex);
        while (baggage_count == 0) {
            pthread_cond_wait(&loader_condition, &mutex);
        }
        /* Transfer the baggage to the plane */
        printf("Transfer baggage to the plane\n\n");
        loaded_bags++;
        baggage_count = 0;
        //signal unloader thread
        pthread_cond_signal(&unloader_condition);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void* unloader(void* arg) {
    printf("Unloader thread waiting...\n");
    while (unloaded_bags < total_bags) {
        //wait for plane to be available
        pthread_mutex_lock(&mutex);
        while (baggage_count == 1) {
            pthread_cond_wait(&unloader_condition, &mutex);
        }
        /* Unload the baggage from the plane */
        printf("Unload baggage from the plane\n\n");
        unloaded_bags++;
        //signal conveyor thread
        pthread_cond_signal(&conveyor_condition);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}