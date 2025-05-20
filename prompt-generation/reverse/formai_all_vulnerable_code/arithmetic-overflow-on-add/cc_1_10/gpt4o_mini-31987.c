//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_HISTORIES 10
#define MAX_INPUT 100

typedef struct {
    time_t timestamp;
    char description[50];
} TimeTravelHistory;

typedef struct {
    int current_year;
    TimeTravelHistory history[MAX_HISTORIES];
    int history_count;
} TimeMachine;

void initialize_time_machine(TimeMachine *tm) {
    tm->current_year = 2023;
    tm->history_count = 0;
    printf("Time Machine initialized to year %d.\n", tm->current_year);
}

void travel_to_year(TimeMachine *tm, int year, const char *event) {
    if (tm->history_count < MAX_HISTORIES) {
        tm->history[tm->history_count].timestamp = time(NULL);
        snprintf(tm->history[tm->history_count].description, 50, "Traveled to the year %d: %s", year, event);
        tm->history_count++;
    }
    tm->current_year = year;
    printf("Traveling to year %d. Event: %s\n", year, event);
}

void display_history(const TimeMachine *tm) {
    printf("Travel History:\n");
    for (int i = 0; i < tm->history_count; i++) {
        printf("%s (Time: %s)\n", tm->history[i].description, ctime(&tm->history[i].timestamp));
    }
}

void delay(int seconds) {
    time_t end_time = time(NULL) + seconds;
    while (time(NULL) < end_time);
}

void show_menu() {
    printf("\nTime Machine Menu:\n");
    printf("1. Travel to a specific year\n");
    printf("2. View travel history\n");
    printf("3. Exit\n");
}

int main() {
    TimeMachine tm;
    char input[MAX_INPUT];
    int year;

    initialize_time_machine(&tm);

    while (1) {
        show_menu();
        printf("Choose an option: ");
        fgets(input, MAX_INPUT, stdin);
        switch (atoi(input)) {
            case 1:
                printf("Enter the year you wish to travel to: ");
                fgets(input, MAX_INPUT, stdin);
                year = atoi(input);
                if (year < 0) {
                    printf("Invalid year. Please enter a valid positive year.\n");
                } else {
                    travel_to_year(&tm, year, "Exploration of the future/past");
                    delay(2); // Simulate time traveling delay
                }
                break;
            case 2:
                display_history(&tm);
                break;
            case 3:
                printf("Exiting the Time Machine...\n");
                exit(0);
            default:
                printf("Invalid option. Please choose again.\n");
        }
    }

    return 0;
}