//GEMINI-pro DATASET v1.0 Category: Temperature monitor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/epoll.h>
#include <string.h>

#define MAX_EVENTS 10
#define TEMP_SENSOR_PATH "/sys/class/thermal/thermal_zone0/temp"

int main(void) {
    // Create an epoll instance
    int epoll_fd = epoll_create1(0);
    if (epoll_fd == -1) {
        perror("epoll_create1");
        exit(EXIT_FAILURE);
    }

    // Open the temperature sensor file
    int temp_sensor_fd = open(TEMP_SENSOR_PATH, O_RDONLY);
    if (temp_sensor_fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Add the temperature sensor file descriptor to the epoll instance
    struct epoll_event event;
    event.events = EPOLLIN;
    event.data.fd = temp_sensor_fd;
    if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, temp_sensor_fd, &event) == -1) {
        perror("epoll_ctl");
        exit(EXIT_FAILURE);
    }

    // Loop forever, waiting for events on the epoll instance
    while (1) {
        // Wait for events
        struct epoll_event events[MAX_EVENTS];
        int num_events = epoll_wait(epoll_fd, events, MAX_EVENTS, -1);
        if (num_events == -1) {
            perror("epoll_wait");
            exit(EXIT_FAILURE);
        }

        // Process events
        for (int i = 0; i < num_events; i++) {
            if (events[i].data.fd == temp_sensor_fd) {
                // Read the temperature from the sensor file
                char buffer[16];
                if (read(temp_sensor_fd, buffer, sizeof(buffer)) == -1) {
                    perror("read");
                    exit(EXIT_FAILURE);
                }

                // Remove the newline character from the buffer
                buffer[strcspn(buffer, "\n")] = '\0';

                // Convert the temperature to a floating-point value
                float temperature = atof(buffer) / 1000;

                // Print the temperature
                printf("Temperature: %.2f C\n", temperature);
            }
        }
    }

    // Close the temperature sensor file
    close(temp_sensor_fd);

    // Close the epoll instance
    close(epoll_fd);

    return 0;
}