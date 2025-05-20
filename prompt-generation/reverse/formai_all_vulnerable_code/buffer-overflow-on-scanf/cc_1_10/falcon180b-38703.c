//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_TIME_TRAVEL 10

struct time_travel {
    time_t time;
    int destination;
};

int main() {
    struct time_travel travels[MAX_TIME_TRAVEL];
    int num_travels = 0, choice;
    time_t current_time;

    srand(time(NULL));

    while (1) {
        printf("Time Travel Simulator\n");
        printf("1. Travel to a random time\n");
        printf("2. Travel to a specific time\n");
        printf("3. View travel history\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                travels[num_travels].time = rand() % (time(NULL) - 946684800); // Limit to Unix Epoch
                travels[num_travels].destination = -1;
                num_travels++;
                break;
            case 2:
                printf("Enter the destination time (Unix timestamp): ");
                scanf("%ld", &travels[num_travels].time);
                travels[num_travels].destination = -1;
                num_travels++;
                break;
            case 3:
                for (int i = 0; i < num_travels; i++) {
                    if (travels[i].destination == -1) {
                        printf("Travel #%d: Random time\n", i + 1);
                    } else {
                        printf("Travel #%d: %s", i + 1, ctime(&travels[i].time));
                    }
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}