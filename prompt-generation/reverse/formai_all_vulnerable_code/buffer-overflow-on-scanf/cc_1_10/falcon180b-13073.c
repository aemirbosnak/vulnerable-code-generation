//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME_TRAVELS 100
#define MAX_TIME_TRAVEL_DISTANCE 1000
#define TIME_TRAVEL_COST 10

struct TimeTravel {
    int distance;
    time_t time;
};

void print_menu() {
    printf("Time Travel Menu:\n");
    printf("1. Travel through time\n");
    printf("2. View travel history\n");
    printf("3. Exit\n");
}

void travel_through_time(struct TimeTravel travels[], int num_travels) {
    int choice;
    printf("Enter the distance you want to travel (in years): ");
    scanf("%d", &choice);

    if (choice <= 0 || choice > MAX_TIME_TRAVEL_DISTANCE) {
        printf("Invalid distance.\n");
        return;
    }

    if (num_travels >= MAX_TIME_TRAVELS) {
        printf("You have reached the maximum number of time travels.\n");
        return;
    }

    travels[num_travels].distance = choice;
    travels[num_travels].time = time(NULL);

    printf("You have traveled %d years into the future/past.\n", choice);
}

void view_travel_history(struct TimeTravel travels[], int num_travels) {
    printf("Your travel history:\n");
    for (int i = 0; i < num_travels; i++) {
        printf("%d: Traveled %d years at %s", i+1, travels[i].distance, ctime(&travels[i].time));
    }
}

int main() {
    struct TimeTravel travels[MAX_TIME_TRAVELS];
    int num_travels = 0;

    while (1) {
        print_menu();
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_travels >= MAX_TIME_TRAVELS) {
                    printf("You have reached the maximum number of time travels.\n");
                } else {
                    travel_through_time(travels, num_travels);
                    num_travels++;
                }
                break;
            case 2:
                view_travel_history(travels, num_travels);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}