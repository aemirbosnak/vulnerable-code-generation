//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME_TRAVELS 10
#define TIME_TRAVEL_SUCCESS 0
#define TIME_TRAVEL_FAILURE -1

// Function to print the current date and time
void print_current_datetime(void) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    printf("Current date and time: %s", asctime(t));
}

// Function to simulate time travel
int time_travel(int year, int month, int day, int hour, int minute, int second) {
    struct tm new_time = {0};
    new_time.tm_year = year - 1900;
    new_time.tm_mon = month - 1;
    new_time.tm_mday = day;
    new_time.tm_hour = hour;
    new_time.tm_min = minute;
    new_time.tm_sec = second;

    time_t target_time = mktime(&new_time);
    if (target_time == -1) {
        printf("Invalid date and/or time.\n");
        return TIME_TRAVEL_FAILURE;
    }

    if (target_time < time(NULL)) {
        printf("Cannot travel back in time.\n");
        return TIME_TRAVEL_FAILURE;
    }

    printf("Time travel successful! New date and time: %s", asctime(&new_time));
    return TIME_TRAVEL_SUCCESS;
}

int main(void) {
    int choice;
    char input[80];

    srand(time(NULL));

    do {
        system("clear"); // Clear the console screen
        print_current_datetime();

        printf("\nChoose an option:\n");
        printf("1. Time travel\n");
        printf("2. Exit\n");
        printf("> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the target year (e.g. 2022): ");
                scanf("%d", &input[0]);
                printf("Enter the target month (1-12): ");
                scanf("%d", &input[3]);
                printf("Enter the target day (1-31): ");
                scanf("%d", &input[6]);
                printf("Enter the target hour (0-23): ");
                scanf("%d", &input[9]);
                printf("Enter the target minute (0-59): ");
                scanf("%d", &input[12]);
                printf("Enter the target second (0-59): ");
                scanf("%d", &input[15]);

                if (time_travel(input[0], input[3], input[6], input[9], input[12], input[15]) == TIME_TRAVEL_SUCCESS) {
                    printf("\nPress ENTER to continue...");
                    getchar();
                }
                break;

            case 2:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice!= 2);

    return 0;
}