//MISTRAL-7B DATASET v1.0 Category: Fitness Tracker ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>

#define STEPS_PER_MINUTE 100
#define STEPS_PER_DAY (60 * STEPS_PER_MINUTE)
#define LOG_FILE "fitness.log"

typedef struct {
    time_t timestamp;
    int steps;
} log_entry;

int main(int argc, char *argv[]) {
    int fd;
    log_entry current_entry;
    struct stat file_stats;
    int total_steps = 0;

    // Initialize log file if it doesn't exist
    if (access(LOG_FILE, F_OK) != 0) {
        fd = open(LOG_FILE, O_CREAT | O_WRONLY | O_TRUNC, 0644);
        current_entry.timestamp = time(NULL);
        current_entry.steps = 0;
        write(fd, &current_entry, sizeof(current_entry));
        close(fd);
    }

    // Main fitness tracking loop
    while (1) {
        // Read previous log entry
        fd = open(LOG_FILE, O_RDONLY);
        read(fd, &current_entry, sizeof(current_entry));
        close(fd);

        // Increment steps since last log entry
        total_steps += current_entry.steps;
        current_entry.steps = 0;

        // Sleep for a minute to simulate real-world usage
        sleep(60);

        // Increment steps during this minute
        current_entry.steps += STEPS_PER_MINUTE;

        // Write new log entry
        fd = open(LOG_FILE, O_WRONLY);
        write(fd, &current_entry, sizeof(current_entry));
        close(fd);

        printf("Total steps: %d\n", total_steps);
    }

    return 0;
}