//MISTRAL-7B DATASET v1.0 Category: Fitness Tracker ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

#define MAX_STEPS 20000
#define STEP_SIZE 0.05
#define SLEEP_TIME 100

typedef struct {
    time_t timestamp;
    int steps;
    float distance;
} StepData;

void save_step_data(StepData data) {
    char filename[20];
    int fd;

    snprintf(filename, sizeof(filename), "data/%04d%02d%02d.dat",
             (int) localtime(&data.timestamp)->tm_year + 1900,
             (int) localtime(&data.timestamp)->tm_mon + 1,
             (int) localtime(&data.timestamp)->tm_mday);

    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd < 0) {
        perror("Failed to open file");
        return;
    }

    write(fd, &data, sizeof(StepData));
    close(fd);
}

int main(void) {
    StepData current_data;
    int steps = 0;
    float distance = 0.0;

    while (steps < MAX_STEPS) {
        current_data.timestamp = time(NULL);
        current_data.steps = steps;

        steps++;
        distance += STEP_SIZE;

        printf("Steps: %d, Distance: %.2f km\n", steps, distance / 1000.0);
        save_step_data(current_data);
        usleep(SLEEP_TIME * 1000);
    }

    printf("Reached goal: %d steps and %.2f km\n", steps, distance / 1000.0);

    return EXIT_SUCCESS;
}