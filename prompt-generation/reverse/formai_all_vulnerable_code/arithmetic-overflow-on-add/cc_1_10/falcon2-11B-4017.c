//Falcon2-11B DATASET v1.0 Category: Fitness Tracker ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define MIN_STEPS 5000
#define MAX_STEPS 10000

typedef struct {
    int steps;
    int goal;
} fitness_tracker;

fitness_tracker* create_fitness_tracker() {
    fitness_tracker* tracker = malloc(sizeof(fitness_tracker));
    tracker->steps = 0;
    tracker->goal = rand() % (MAX_STEPS - MIN_STEPS) + MIN_STEPS;
    return tracker;
}

void update_fitness_tracker(fitness_tracker* tracker, int steps) {
    if (steps > tracker->goal) {
        tracker->steps = 0;
        tracker->goal = rand() % (MAX_STEPS - MIN_STEPS) + MIN_STEPS;
        printf("Goal updated to %d\n", tracker->goal);
    } else {
        tracker->steps += steps;
        printf("Steps added: %d\n", steps);
    }
}

int main() {
    fitness_tracker* tracker = create_fitness_tracker();
    int steps;
    while (1) {
        struct timeval start_time, end_time;
        gettimeofday(&start_time, NULL);
        
        // simulate some activity
        sleep(rand() % 10);
        steps = rand() % (MAX_STEPS - MIN_STEPS) + MIN_STEPS;
        
        // update fitness tracker
        update_fitness_tracker(tracker, steps);
        
        gettimeofday(&end_time, NULL);
        double elapsed_time = (end_time.tv_sec - start_time.tv_sec) * 1000000 + (end_time.tv_usec - start_time.tv_usec);
        
        printf("Elapsed time: %f seconds\n", elapsed_time);
    }
    
    free(tracker);
    return 0;
}