//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: ultraprecise
#include <stdio.h>
#include <time.h>

int main() {
    time_t current_time;
    struct tm *time_info;
    char time_string[10];

    time(&current_time);
    time_info = localtime(&current_time);

    strftime(time_string, sizeof(time_string), "%H", time_info);

    int current_hour = atoi(time_string);
    int choice;

    printf("Welcome to the C Time Travel Simulator!\n\n");

    printf("It's currently %d:00 hours.\n", current_hour);
    printf("Where would you like to travel?\n");
    printf("1. 5 hours into the future\n");
    printf("2. 10 hours into the future\n");
    printf("3. 5 hours into the past\n");
    printf("4. 10 hours into the past\n");

    scanf("%d", &choice);

    switch (choice) {
        case 1: 
            printf("You have traveled 5 hours into the future.\n");
            current_hour += 5;
            break;

        case 2: 
            printf("You have traveled 10 hours into the future.\n");
            current_hour += 10;
            break;

        case 3: 
            printf("You have traveled 5 hours into the past.\n");
            current_hour -= 5;
            break;

        case 4: 
            printf("You have traveled 10 hours into the past.\n");
            current_hour -= 10;
            break;

        default: 
            printf("Invalid option selected.\n");
            return 1;
    }

    printf("It's now %d:00 hours.\n", current_hour);

    return 0;
}