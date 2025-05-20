//MISTRAL-7B DATASET v1.0 Category: Fitness Tracker ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#define STEPS_PER_MINUTE 1000
#define SLEEP_TIME 60

typedef struct {
    time_t timestamp;
    int steps;
} StepData;

void write_to_file(StepData data) {
    int fd = open("steps.dat", O_RDWR | O_CREAT | O_APPEND, 0644);
    if (fd < 0) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    StepData current_data;
    lseek(fd, 0, SEEK_SET);
    read(fd, &current_data, sizeof(StepData));

    if (current_data.timestamp == 0 || (data.timestamp - current_data.timestamp) > 60) {
        write(fd, &data, sizeof(StepData));
    } else {
        current_data.steps += data.steps;
        write(fd, &current_data, sizeof(StepData));
    }

    close(fd);
}

int main() {
    srand(time(NULL));

    while (1) {
        StepData data;
        data.timestamp = time(NULL);
        data.steps = rand() % 200 + 500;

        write_to_file(data);

        printf("Timestamp: %s, Steps: %d\n", ctime(&data.timestamp), data.steps);
        fflush(stdout);

        usleep(STEPS_PER_MINUTE * 1000 * SLEEP_TIME);
    }

    return EXIT_SUCCESS;
}