//FormAI DATASET v1.0 Category: Weather simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CITY_NAME_LENGTH 100
#define MAXIMUM_TEMPERATURE 50
#define MINIMUM_TEMPERATURE -20
#define MAX_BUFFER_SIZE 1000

int main(int argc, char const *argv[]) {

    if (argc < 2) {
        printf("Please provide at least one city name as command line argument.\n");
        return 1;
    }

    srand(time(NULL));

    int no_of_cities = argc - 1;

    char city_names[no_of_cities][MAX_CITY_NAME_LENGTH];

    for (int i = 0; i < no_of_cities; i++) {
        strcpy(city_names[i], argv[i+1]);
    }

    printf("Weather Forecasts for %d Cities\n", no_of_cities);
    printf("------------------------------------------\n");

    int pipes[no_of_cities][2];

    // Creating pipes for inter-process communication
    for (int i = 0; i < no_of_cities; i++) {
        if (pipe(pipes[i]) == -1) {
            perror("Failed to create pipe");
            return 1;
        }
    }

    // Forking child processes for each city
    for (int i = 0; i < no_of_cities; i++) {
        pid_t pid = fork();
        if (pid < 0) {
            perror("Failed to fork child process");
            return 1;
        } else if (pid == 0) { // Child Process
            close(pipes[i][0]); // Child is not reading from pipe

            // Generating temperature values randomly
            int temperature = (rand() % (MAXIMUM_TEMPERATURE - MINIMUM_TEMPERATURE + 1)) + MINIMUM_TEMPERATURE;

            char message[MAX_BUFFER_SIZE];
            sprintf(message, "Temperature in %s is %d degrees Celsius.", city_names[i], temperature);
            write(pipes[i][1], message, strlen(message)+1);

            close(pipes[i][1]); // Writing is completed

            exit(0); // Child process exits
        }
    }

    // Parent Process
    close(pipes[0][1]); // Parent is reading from pipe of first child

    char buffer[MAX_BUFFER_SIZE];

    // Reading and printing temperature values from all child processes
    for (int i = 0; i < no_of_cities; i++) {
        pid_t pid = wait(NULL); // Waiting for child process to terminate
        if (pid == -1) {
            perror("Failed to wait child process");
            return 1;
        }

        if (read(pipes[i][0], buffer, MAX_BUFFER_SIZE) == -1) {
            perror("Failed to read from pipe");
            return 1;
        }

        printf("%s\n", buffer);

        close(pipes[i][0]);
    }

    return 0;
}