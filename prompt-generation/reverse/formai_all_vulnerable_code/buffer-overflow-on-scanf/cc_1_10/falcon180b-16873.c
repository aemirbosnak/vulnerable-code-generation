//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIMESTAMPS 100

struct Timestamp {
    time_t timestamp;
    char description[80];
};

int main() {
    srand(time(NULL));

    struct Timestamp *timestamps = malloc(MAX_TIMESTAMPS * sizeof(struct Timestamp));
    int num_timestamps = 0;

    printf("Welcome to the Cyberpunk Time Travel Simulator!\n");
    printf("You are a hacker who has discovered a way to travel through time.\n");
    printf("However, each jump can only take you to a random point in history.\n");
    printf("Be careful not to get stuck in the past!\n");

    while (1) {
        int choice;
        printf("Enter your choice:\n");
        printf("1. Jump through time\n");
        printf("2. View timeline\n");
        printf("3. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_timestamps >= MAX_TIMESTAMPS) {
                    printf("You cannot jump through time anymore.\n");
                    break;
                }

                time_t current_time = time(NULL);
                struct tm *current_tm = localtime(&current_time);

                time_t new_time = current_time - rand() % 1000000000;
                struct tm *new_tm = localtime(&new_time);

                timestamps[num_timestamps].timestamp = new_time;
                strftime(timestamps[num_timestamps].description, 80, "%Y-%m-%d %H:%M:%S", new_tm);
                num_timestamps++;

                printf("You have jumped to the year %s.\n", timestamps[num_timestamps - 1].description);
                break;

            case 2:
                printf("Timeline:\n");
                for (int i = 0; i < num_timestamps; i++) {
                    printf("%s - %s\n", timestamps[i].description, timestamps[i + 1].description);
                }
                break;

            case 3:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}