//MISTRAL-7B DATASET v1.0 Category: Fitness Tracker ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <math.h>

#define STEPS_PER_MINUTE 3000
#define SLEEP_INTERVAL 60000
#define MAX_STEPS 10000
#define FILE_NAME "steps.txt"

typedef struct {
    time_t timestamp;
    int steps;
} StepData;

void write_to_file(int steps) {
    StepData data;
    int fd;

    data.timestamp = time(NULL);
    data.steps = steps;

    fd = open(FILE_NAME, O_WRONLY | O_APPEND);
    if (fd < 0) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    if (write(fd, &data, sizeof(StepData)) != sizeof(StepData)) {
        perror("Error writing to file");
        exit(EXIT_FAILURE);
    }

    close(fd);
}

int main(void) {
    int steps = 0;
    int prev_steps = 0;
    int prev_timestamp = 0;
    double avg_steps_per_minute = 0;

    while (1) {
        time_t current_time = time(NULL);
        int elapsed_seconds = current_time - prev_timestamp;

        if (steps > MAX_STEPS) {
            printf("You have reached your daily step goal of %d steps.\n", MAX_STEPS);
            break;
        }

        printf("Current time: %s\n", ctime(&current_time));
        printf("Steps taken: %d\n", steps);
        printf("Average steps per minute: %.2f\n", avg_steps_per_minute);
        printf("\n");

        steps += rand() % 50 + 50; // Generate random steps between 50 and 100
        avg_steps_per_minute = (avg_steps_per_minute * (elapsed_seconds / 60.0) + steps) / ((elapsed_seconds / 60.0) + 1 / 60.0);

        if (steps > prev_steps) {
            printf("You have taken %d more steps than your previous record of %d steps.\n", steps - prev_steps, prev_steps);
        }

        prev_steps = steps;
        prev_timestamp = current_time;

        write_to_file(steps);

        usleep(SLEEP_INTERVAL);
    }

    return 0;
}