//MISTRAL-7B DATASET v1.0 Category: Time Travel Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_TIME_TRAVEL 10
#define TIME_UNIT 1000

struct TimeTravel {
    int id;
    struct tm date;
    char description[100];
};

struct TimeTravel time_travel_log[MAX_TIME_TRAVEL];
int time_travel_pointer = 0;

void print_time() {
    time_t now = time(NULL);
    struct tm *ltm = localtime(&now);

    printf("\nCurrent Time: %d-%02d-%02d %02d:%02d:%02d", ltm->tm_year + 1900, ltm->tm_mon + 1, ltm->tm_mday, ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
}

void time_travel(int minutes) {
    time_t new_time;
    struct tm *new_tm;

    time(&new_time);
    new_tm = localtime(&new_time);

    new_tm->tm_min += minutes;

    if (new_tm->tm_min > 59) {
        new_tm->tm_min -= 60;
        new_tm->tm_hour++;
    }

    time(&new_time);
    settimeofday(new_tm, localtime(&new_time));

    print_time();
    printf(" - Traveling to %d minutes in the past...\n", minutes);

    time_travel_log[time_travel_pointer].id = time_travel_pointer + 1;
    strftime(time_travel_log[time_travel_pointer].description, sizeof(time_travel_log[time_travel_pointer].description), "Time Travel %d: %Y-%m-%d %H:%M:%S", localtime(&new_time));
    time_travel_pointer++;
}

int main() {
    int choice, minutes;

    printf("Welcome to the C Time Travel Simulator!\n");
    print_time();

    while (1) {
        printf("\nChoose an option:\n1. Travel in time\n2. Display time travel log\n3. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter minutes to travel: ");
                scanf("%d", &minutes);
                time_travel(minutes);
                break;
            case 2:
                printf("\nTime Travel Log:\n");
                for (int i = 0; i < time_travel_pointer; i++) {
                    printf("\nTime Travel %d: %s", time_travel_log[i].id, time_travel_log[i].description);
                }
                break;
            case 3:
                printf("\nExiting...\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}