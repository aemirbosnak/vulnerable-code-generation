//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define NUM_OF_THREADS 5
#define TARGET_YEAR 2123

typedef struct {
    int thread_id;
    int time_jump_years;
} ThreadData;

void *time_travel_simulation(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    int current_year = 2023;
    int travel_year = current_year + data->time_jump_years;

    printf("Thread %d: Preparing to travel from %d to %d!\n", data->thread_id, current_year, travel_year);
    sleep(1); // Simulate time spent in time travel
    printf("Thread %d: Successfully traveled to %d!\n", data->thread_id, travel_year);
    
    // Simulating different events after time travel
    const char *events[] = {
        "witnessed the first Mars colony",
        "met a robotic AI",
        "saw flying cars",
        "experienced the great AI revolution",
        "attended the first intergalactic conference"
    };
    
    srand(time(NULL) + data->thread_id); // Different seed for randomness per thread
    int random_event = rand() % 5;

    printf("Thread %d: In %d, I %s!\n", data->thread_id, travel_year, events[random_event]);
    
    // Return the traveled year for demonstration purposes
    pthread_exit((void *)(size_t)travel_year);
}

int main() {
    pthread_t threads[NUM_OF_THREADS];
    ThreadData thread_data[NUM_OF_THREADS];
    int travel_years[] = {100, 50, 10, 70, 80}; // Different years for each thread
    void *status;
    
    printf("Starting Time Travel Simulator\n");

    for(int i = 0; i < NUM_OF_THREADS; i++) {
        thread_data[i].thread_id = i+1;
        thread_data[i].time_jump_years = travel_years[i];
        int rc = pthread_create(&threads[i], NULL, time_travel_simulation, (void *)&thread_data[i]);
        
        if (rc) {
            printf("Error: unable to create thread, %d\n", rc);
            exit(-1);
        }
    }

    for(int i = 0; i < NUM_OF_THREADS; i++) {
        pthread_join(threads[i], &status);
        printf("Thread %d finished time travel. Returned year: %ld\n", i+1, (long)status);
    }

    printf("All threads have completed time travel.\n");
    return 0;
}