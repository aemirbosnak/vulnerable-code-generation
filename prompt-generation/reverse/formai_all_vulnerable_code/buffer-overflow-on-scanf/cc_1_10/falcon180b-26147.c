//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME_TRAVEL 10
#define MAX_TIME_TRAVEL_LENGTH 1000

typedef struct {
    int start_time;
    int end_time;
    int length;
} TimeTravel;

int main(void) {
    srand(time(NULL));
    int num_travels = rand() % MAX_TIME_TRAVEL + 1;
    TimeTravel travels[num_travels];

    for (int i = 0; i < num_travels; i++) {
        travels[i].start_time = rand() % MAX_TIME_TRAVEL_LENGTH;
        travels[i].end_time = rand() % MAX_TIME_TRAVEL_LENGTH;
        travels[i].length = rand() % MAX_TIME_TRAVEL_LENGTH + 1;
    }

    int choice;
    do {
        printf("Enter your choice:\n");
        printf("1. Travel through time\n");
        printf("2. Quit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            int travel_index = rand() % num_travels;
            printf("You are about to embark on a journey through time.\n");
            printf("You will travel from %d to %d for a duration of %d seconds.\n", travels[travel_index].start_time, travels[travel_index].end_time, travels[travel_index].length);
            printf("Are you ready? (y/n)\n");
            char confirm;
            scanf(" %c", &confirm);

            if (confirm == 'y' || confirm == 'Y') {
                int start_time = travels[travel_index].start_time;
                int end_time = travels[travel_index].end_time;
                int length = travels[travel_index].length;

                for (int j = start_time; j <= end_time; j++) {
                    printf("%d seconds have passed...\n", j);
                    sleep(1);
                }
            } else {
                printf("Aborting time travel.\n");
            }
        }
    } while (choice!= 2);

    return 0;
}