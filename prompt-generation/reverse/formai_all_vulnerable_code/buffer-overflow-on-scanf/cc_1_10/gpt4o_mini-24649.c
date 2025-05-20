//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_HISTORY 10
#define YEAR_OFFSET 1900

typedef struct {
    int year;
    int month;
    int day;
    char description[100];
} Timestamp;

typedef struct {
    Timestamp history[MAX_HISTORY];
    int current_index;
} TimeTravelHistory;

void initialize_history(TimeTravelHistory* history) {
    history->current_index = 0;
}

void add_timestamp(TimeTravelHistory* history, int year, int month, int day, const char* description) {
    if (history->current_index < MAX_HISTORY) {
        history->history[history->current_index].year = year;
        history->history[history->current_index].month = month;
        history->history[history->current_index].day = day;
        strcpy(history->history[history->current_index].description, description);
        history->current_index++;
    } else {
        printf("History is full. Cannot add more timestamps.\n");
    }
}

void display_history(const TimeTravelHistory* history) {
    printf("Time Travel History:\n");
    for (int i = 0; i < history->current_index; i++) {
        printf("%d-%02d-%02d: %s\n", 
               history->history[i].year, 
               history->history[i].month, 
               history->history[i].day, 
               history->history[i].description);
    }
}

void travel_to_time(int year, int month, int day) {
    printf("Traveling to %d-%02d-%02d...\n", year, month, day);
    time_t t = time(NULL);
    struct tm new_time;
    new_time.tm_year = year - YEAR_OFFSET;  // tm_year is years since 1900
    new_time.tm_mon = month - 1;             // tm_mon is 0-11 for Jan-Dec
    new_time.tm_mday = day;                   // tm_mday is day of the month
    new_time.tm_hour = 0;
    new_time.tm_min = 0;
    new_time.tm_sec = 0;
    
    time_t travel_time = mktime(&new_time);
    if (travel_time == -1) {
        printf("Invalid date!\n");
        return;
    }
    
    char buffer[80];
    struct tm* tm_info = localtime(&travel_time);
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm_info);
    printf("Successfully arrived at: %s\n", buffer);
}

void perform_time_travel(TimeTravelHistory* history) {
    int year, month, day;
    char description[100];

    printf("Enter year to travel to: ");
    scanf("%d", &year);
    printf("Enter month to travel to (1-12): ");
    scanf("%d", &month);
    printf("Enter day to travel to (1-31): ");
    scanf("%d", &day);
    printf("Enter a travel description: ");
    scanf(" %[^\n]", description); // Take input with space

    travel_to_time(year, month, day);
    add_timestamp(history, year, month, day, description);
}

int main() {
    TimeTravelHistory history;
    initialize_history(&history);
    
    char command[10];
    
    while (1) {
        printf("\nCommands: travel, history, exit\n");
        printf("Enter command: ");
        scanf("%s", command);

        if (strcmp(command, "travel") == 0) {
            perform_time_travel(&history);
        } else if (strcmp(command, "history") == 0) {
            display_history(&history);
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting Time Travel Simulator. Safe travels!\n");
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}