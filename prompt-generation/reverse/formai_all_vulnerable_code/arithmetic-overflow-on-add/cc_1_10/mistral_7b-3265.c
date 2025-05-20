//MISTRAL-7B DATASET v1.0 Category: Fitness Tracker ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#define MAX_STEPS 100000
#define FILE_NAME "steps.txt"

typedef struct {
    int steps;
    time_t timestamp;
} StepData;

void save_step_data(StepData *data) {
    int fd = open(FILE_NAME, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd < 0) {
        perror("Failed to open file for writing");
        return;
    }

    size_t data_size = sizeof(StepData);
    if (write(fd, data, data_size) != data_size) {
        perror("Failed to write data to file");
    }

    close(fd);
}

void print_step_data(StepData *data) {
    char time_str[32];
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", localtime(&data->timestamp));
    printf("Step data:\n");
    printf("  Steps: %d\n", data->steps);
    printf("  Timestamp: %s\n", time_str);
}

int main() {
    StepData current_data;
    int steps_per_minute = 1000;

    while (1) {
        current_data.steps += 1;
        current_data.timestamp = time(NULL);

        if (current_data.steps % steps_per_minute == 0) {
            printf("Minute reached, saving step data...\n");
            save_step_data(&current_data);
            print_step_data(&current_data);
        }

        usleep(500000); // Sleep for 500ms
    }

    return 0;
}