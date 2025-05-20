//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#define MAX_BAGS 20

sem_t available_carts; // semaphore for carts available
sem_t full_carts; // semaphore for carts full of bags
pthread_mutex_t mutex; // mutex for accessing conveyor belt
int conveyor_belt[MAX_BAGS]; // array to represent conveyor belt
int next_in = 0; // index of next available conveyor belt slot
int next_out = 0; // index of next bag to be processed on conveyor belt
int bags_processed = 0; // counter for bags processed

void *airline_agent(void *arg) {
    int num_bags = *(int*)arg;
    printf("Airline agent starts processing %d bags\n", num_bags);
    for (int i = 0; i < num_bags; i++) {
        sem_wait(&available_carts);
        pthread_mutex_lock(&mutex);
        conveyor_belt[next_in] = i + 1;
        printf("Airline agent puts bag %d on conveyor belt\n", i + 1);
        next_in = (next_in + 1) % MAX_BAGS;
        pthread_mutex_unlock(&mutex);
        sem_post(&full_carts);
    }
    printf("Airline agent finishes processing bags\n");
    pthread_exit(NULL);
}

void *security_agent(void *arg) {
    while (bags_processed < MAX_BAGS) {
        sem_wait(&full_carts);
        pthread_mutex_lock(&mutex);
        int bag = conveyor_belt[next_out];
        printf("Security agent checks bag %d\n", bag);
        next_out = (next_out + 1) % MAX_BAGS;
        bags_processed++;
        pthread_mutex_unlock(&mutex);
        sem_post(&available_carts);
    }
    printf("Security agent finishes processing bags\n");
    pthread_exit(NULL);
}

int main() {
    sem_init(&available_carts, 0, MAX_BAGS);
    sem_init(&full_carts, 0, 0);
    pthread_mutex_init(&mutex, NULL);
    printf("Airport baggage handling simulation begins\n");

    int num_bags;
    printf("Enter number of bags to process: ");
    scanf("%d", &num_bags);

    pthread_t airline_thread, security_thread;

    pthread_create(&airline_thread, NULL, airline_agent, &num_bags);
    pthread_create(&security_thread, NULL, security_agent, NULL);

    pthread_join(airline_thread, NULL);
    pthread_join(security_thread, NULL);

    sem_destroy(&available_carts);
    sem_destroy(&full_carts);
    pthread_mutex_destroy(&mutex);

    printf("Airport baggage handling simulation ends\n");

    return 0;
}