//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TIMESTAMPS 1000
#define TIMESTAMP_SIZE 20

struct timestamp {
    char name[TIMESTAMP_SIZE];
    time_t time;
};

int main() {
    int num_timestamps;
    struct timestamp timestamps[MAX_TIMESTAMPS];
    char input[256];
    char *token;
    int i = 0;
    time_t current_time;

    printf("Enter the number of timestamps to record: ");
    scanf("%d", &num_timestamps);

    while (num_timestamps > MAX_TIMESTAMPS) {
        printf("Error: Maximum number of timestamps is %d.\n", MAX_TIMESTAMPS);
        printf("Enter the number of timestamps to record: ");
        scanf("%d", &num_timestamps);
    }

    for (i = 0; i < num_timestamps; i++) {
        printf("Enter the name of the %dth timestamp: ", i+1);
        scanf("%s", timestamps[i].name);
        timestamps[i].time = time(NULL);
    }

    printf("Enter the name of the timestamp to travel to: ");
    scanf("%s", input);

    token = strtok(input, " ");
    while (token!= NULL) {
        if (strcmp(token, "travel") == 0) {
            token = strtok(NULL, " ");
            if (token!= NULL) {
                if (strcmp(token, "forward") == 0) {
                    current_time = timestamps[i-1].time;
                } else if (strcmp(token, "backward") == 0) {
                    current_time = timestamps[i].time;
                } else {
                    printf("Error: Invalid direction.\n");
                    return 1;
                }
                break;
            }
        }
        token = strtok(NULL, " ");
    }

    if (token == NULL) {
        printf("Error: Invalid input.\n");
        return 1;
    }

    if (current_time == -1) {
        printf("Error: No timestamps recorded.\n");
        return 1;
    }

    printf("Time travel successful! Current time is now %s.\n", ctime(&current_time));

    return 0;
}