//MISTRAL-7B DATASET v1.0 Category: Time Travel Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME 100
#define TIME_INCREMENT 1

typedef struct {
    int time;
    int value;
} TimeData;

TimeData memory[MAX_TIME];

void set_time(int time) {
    if (time < 0 || time >= MAX_TIME) {
        printf("Invalid time.\n");
        return;
    }
    memory[time].time = time;
    memory[time].value = 1;
}

int get_value(int time) {
    if (time < 0 || time >= MAX_TIME) {
        printf("Invalid time.\n");
        return -1;
    }
    return memory[time].value;
}

void travel_back(int time) {
    if (time < 0 || time > memory[MAX_TIME - 1].time) {
        printf("Cannot travel back in time further than current memory.\n");
        return;
    }

    int current_time = memory[MAX_TIME - 1].time;
    for (int i = current_time; i > time; i--) {
        memory[i] = memory[i - TIME_INCREMENT];
    }

    memory[time].time = time;
    memory[time].value = 1;
}

void print_memory() {
    printf("Time Travel Simulator Memory:\n");
    for (int i = 0; i < MAX_TIME; i++) {
        printf("Time %d: Value %d\n", memory[i].time, memory[i].value);
    }
}

int main() {
    srand(time(NULL));
    clock_t start = clock();

    for (int i = 0; i < MAX_TIME; i++) {
        set_time(i);
        int random_value = rand() % 10;
        memory[i].value = random_value;
    }

    print_memory();

    int time_to_travel = rand() % MAX_TIME;
    travel_back(time_to_travel);
    print_memory();

    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Simulation completed in %.2f seconds.\n", time_taken);

    return 0;
}