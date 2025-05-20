//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: real-life
#include <stdio.h>
#include <time.h>

int main() {
    printf("Welcome to the C Time Travel Simulator!\n");
    printf("Please enter a year to travel to: ");
    int year;
    scanf("%d", &year);

    time_t current_time;
    struct tm *time_info;
    char time_str[80];

    time(&current_time);
    time_info = localtime(&current_time);

    time_info->tm_year = year - 1900;
    time_info->tm_mon = 0;
    time_info->tm_mday = 1;
    current_time = mktime(time_info);

    time_info = localtime(&current_time);
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", time_info);
    printf("You have traveled to %s!\n", time_str);

    printf("What would you like to do now?\n");
    printf("1. Visit a famous event\n");
    printf("2. Meet a historical figure\n");
    printf("3. Explore a city\n");
    printf("4. Return to the present\n");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Which famous event would you like to visit?\n");
            // code to display a list of events and allow user to choose one
            break;
        case 2:
            printf("Which historical figure would you like to meet?\n");
            // code to display a list of figures and allow user to choose one
            break;
        case 3:
            printf("Which city would you like to explore?\n");
            // code to display a list of cities and allow user to choose one
            break;
        case 4:
            printf("Returning to the present...\n");
            break;
        default:
            printf("Invalid choice, returning to the present...\n");
            break;
    }

    return 0;
}