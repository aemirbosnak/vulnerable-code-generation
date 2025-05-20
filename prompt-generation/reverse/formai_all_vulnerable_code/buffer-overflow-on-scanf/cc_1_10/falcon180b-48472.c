//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TIME_LIMIT 10
#define TIME_TRAVEL_LIMIT 100

int main() {
    int time_travel_count = 0;
    int time_travel_limit = TIME_TRAVEL_LIMIT;
    int current_time = 0;
    int choice;
    char choice_str[10];

    do {
        printf("Current time: %d\n", current_time);
        printf("You have %d time travels left.\n", time_travel_limit);
        printf("Enter your choice:\n1. Go back in time\n2. Go forward in time\n3. Quit\n");
        scanf("%s", choice_str);
        choice = atoi(choice_str);

        switch (choice) {
            case 1:
                current_time -= 1;
                if (current_time < 0) {
                    printf("You cannot go back in time further.\n");
                } else {
                    printf("You went back in time to %d.\n", current_time);
                }
                break;
            case 2:
                current_time += 1;
                if (current_time > TIME_LIMIT) {
                    printf("You cannot go forward in time further.\n");
                } else {
                    printf("You went forward in time to %d.\n", current_time);
                }
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

        if (choice == 1) {
            time_travel_count++;
            if (time_travel_count == time_travel_limit) {
                printf("You have reached the time travel limit. Exiting program...\n");
                exit(0);
            }
        }
    } while (choice!= 3);

    return 0;
}