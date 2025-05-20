//MISTRAL-7B DATASET v1.0 Category: Time Travel Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TIME_STEP 10
#define MAX_LINE_LENGTH 100
#define MAX_COMMANDS 10

typedef struct {
    int time;
    char command[MAX_LINE_LENGTH];
} TimeTravelCommand;

TimeTravelCommand commands[MAX_COMMANDS];
int currentCommand = 0;

void timeTravel(int steps) {
    int prevTime = time(NULL);
    time_t newTime = prevTime + steps * 60;

    setenv("TZ", "UTC", 1);
    tzset();

    printf("\nTime Traveled: %s", ctime(&newTime));
    fflush(stdout);

    while (prevTime < newTime && currentCommand < MAX_COMMANDS) {
        int cmdLen = strlen(commands[currentCommand].command);
        char *argList[MAX_LINE_LENGTH / MAX_LINE_LENGTH];
        char *token;

        int i = 0;
        token = strtok(commands[currentCommand].command, " ");
        while (token != NULL) {
            argList[i++] = token;
            token = strtok(NULL, " ");
        }
        argList[i] = NULL;

        pid_t pid = fork();

        if (pid == 0) {
            execvp(argList[0], argList);
            perror("Command Execution Failed");
            exit(1);
        } else if (pid > 0) {
            wait(NULL);
        } else {
            perror("Fork Failed");
            exit(1);
        }

        prevTime = time(NULL);
        currentCommand++;
    }

    setenv("TZ", "UTC+0", 1);
    tzset();
}

int main() {
    char line[MAX_LINE_LENGTH];
    int timeStep;

    while (1) {
        printf("\nEnter Time Travel Commands (Format: 'time step command'): ");
        fgets(line, MAX_LINE_LENGTH, stdin);
        line[strlen(line) - 1] = '\0';

        sscanf(line, "%d %s", &timeStep, commands[currentCommand].command);

        if (timeStep > MAX_TIME_STEP || timeStep < -MAX_TIME_STEP) {
            printf("Invalid Time Step.\n");
            continue;
        }

        commands[currentCommand].time = time(NULL);
        currentCommand++;

        if (currentCommand == MAX_COMMANDS) {
            printf("Max Commands Reached. Traveling now.\n");
            timeTravel(MAX_TIME_STEP * 60);
            currentCommand = 0;
        }
    }

    return 0;
}