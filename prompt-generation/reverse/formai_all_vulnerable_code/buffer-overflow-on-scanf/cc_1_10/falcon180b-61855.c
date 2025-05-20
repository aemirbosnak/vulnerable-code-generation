//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: distributed
/* C Time Travel Simulator example program */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_TIME_TRAVELERS 10
#define TIME_TRAVEL_DELAY 5 // in seconds
#define TIME_TRAVEL_DURATION 10 // in seconds

/* global variables */
int num_travelers;
pthread_t travelers[MAX_TIME_TRAVELERS];
pthread_mutex_t mutex;

/* function prototypes */
void *travel_through_time(void *arg);

int main(int argc, char *argv[]) {
    int i;
    char input[10];
    num_travelers = 0;

    /* initialize mutex */
    pthread_mutex_init(&mutex, NULL);

    /* prompt user for number of time travelers */
    printf("Enter the number of time travelers: ");
    scanf("%d", &num_travelers);

    /* check if number of time travelers is within range */
    if (num_travelers > MAX_TIME_TRAVELERS) {
        printf("Error: number of time travelers exceeds maximum limit.\n");
        return 1;
    }

    /* create time travelers */
    for (i = 0; i < num_travelers; i++) {
        sprintf(input, "%d", i);
        pthread_create(&travelers[i], NULL, travel_through_time, input);
        printf("Time traveler %s created.\n", input);
    }

    /* wait for time travelers to return */
    for (i = 0; i < num_travelers; i++) {
        pthread_join(travelers[i], NULL);
        printf("Time traveler %s returned.\n", argv[i+1]);
    }

    return 0;
}

/* time travel function */
void *travel_through_time(void *arg) {
    int id = *((int *) arg);
    char name[10];
    sprintf(name, "traveler%d", id);
    printf("Time traveler %s starting time travel.\n", name);

    /* lock mutex */
    pthread_mutex_lock(&mutex);

    /* simulate time travel */
    sleep(TIME_TRAVEL_DELAY);
    printf("Time traveler %s traveling through time...\n", name);
    sleep(TIME_TRAVEL_DURATION);

    /* unlock mutex */
    pthread_mutex_unlock(&mutex);

    printf("Time traveler %s returned to the present.\n", name);
    return NULL;
}