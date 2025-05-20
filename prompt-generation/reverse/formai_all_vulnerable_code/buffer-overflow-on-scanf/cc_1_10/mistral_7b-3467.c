//MISTRAL-7B DATASET v1.0 Category: Fitness Tracker ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <math.h>

#define STEPS_PER_MINUTE 100
#define SLEEP_DURATION 60
#define MAX_STEP_COUNT 2147483647

typedef struct {
    time_t timestamp;
    int steps;
    float distance;
} FitnessData;

void save_data(FitnessData data) {
    int fd = open("fitness.dat", O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd < 0) {
        perror("Error opening file");
        return;
    }

    size_t data_size = sizeof(FitnessData);
    if (write(fd, &data, data_size) != data_size) {
        perror("Error writing data");
    }

    close(fd);
}

int main() {
    printf("Brave Fitness Tracker v1.0\n");
    printf("-------------------------\n");

    FitnessData current_data = {0};
    current_data.timestamp = time(NULL);

    int steps = 0;
    int distance = 0;

    while (1) {
        printf("Current Time: %s", ctime(&current_data.timestamp));
        printf("Steps: %d, Distance: %.2f km\n", steps, distance / 1000.0);

        int input = 0;
        scanf("%d", &input);

        if (input == 1) {
            steps += STEPS_PER_MINUTE * SLEEP_DURATION / 60;
            distance += steps * 0.00524;
            current_data.steps = steps;
            current_data.distance = distance;
            save_data(current_data);
            printf("Saved data to file.\n");
            sleep(SLEEP_DURATION);
            steps = 0;
            distance = 0;
        } else if (input == 2) {
            break;
        }
    }

    current_data.timestamp = time(NULL);
    save_data(current_data);

    printf("Fitness tracking complete.\n");
    return 0;
}