//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME_TRAVELS 100
#define TIME_TRAVEL_SUCCESS 0
#define TIME_TRAVEL_FAILURE 1

// Function to print the current date and time
void print_current_datetime() {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    printf("Current date and time: %s", asctime(t));
}

// Function to simulate a time travel
int time_travel(int target_year, int target_month, int target_day) {
    // Check if the target date is valid
    struct tm target_time;
    target_time.tm_year = target_year - 1900;
    target_time.tm_mon = target_month - 1;
    target_time.tm_mday = target_day;

    time_t target_timestamp = mktime(&target_time);
    if (target_timestamp == -1) {
        printf("Invalid target date.\n");
        return TIME_TRAVEL_FAILURE;
    }

    // Simulate the time travel
    srand(time(NULL));
    int time_travel_result = rand() % 2;

    if (time_travel_result == 0) {
        printf("Time travel successful!\n");
        return TIME_TRAVEL_SUCCESS;
    } else {
        printf("Time travel failed.\n");
        return TIME_TRAVEL_FAILURE;
    }
}

int main() {
    int num_time_travels;

    printf("Welcome to the Time Travel Simulator!\n");
    printf("How many time travels do you want to simulate? ");
    scanf("%d", &num_time_travels);

    if (num_time_travels > MAX_TIME_TRAVELS) {
        printf("Sorry, you can only simulate up to %d time travels.\n", MAX_TIME_TRAVELS);
        return 1;
    }

    for (int i = 0; i < num_time_travels; i++) {
        int target_year, target_month, target_day;

        printf("\nEnter the target date (YYYY-MM-DD): ");
        scanf("%d-%d-%d", &target_year, &target_month, &target_day);

        int time_travel_result = time_travel(target_year, target_month, target_day);

        if (time_travel_result == TIME_TRAVEL_SUCCESS) {
            printf("\nYou successfully traveled to %d-%02d-%02d!\n", target_year + 1900, target_month + 1, target_day);
        } else {
            printf("\nSorry, your time travel to %d-%02d-%02d failed.\n", target_year + 1900, target_month + 1, target_day);
        }

        print_current_datetime();
    }

    return 0;
}