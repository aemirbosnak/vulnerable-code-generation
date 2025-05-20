//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 100

typedef struct {
    time_t time;
    char *description;
} Event;

int main() {
    srand(time(NULL));

    Event events[MAX_EVENTS];
    int num_events = 0;

    while (num_events < MAX_EVENTS) {
        time_t current_time = time(NULL);
        int year = 1900 + rand() % 120;
        struct tm *tm = gmtime(&current_time);
        tm->tm_year = year;
        tm->tm_mon = rand() % 12;
        tm->tm_mday = rand() % 28 + 1;
        char *description = asctime(tm);
        events[num_events] = (Event) {.time = current_time,.description = description };
        num_events++;
    }

    printf("Welcome to the Time Travel Simulator!\n\n");
    for (int i = 0; i < num_events; i++) {
        printf("%s - %s\n", ctime(&events[i].time), events[i].description);
    }

    int choice;
    do {
        printf("\nEnter the number of the event you want to travel to: ");
        scanf("%d", &choice);
        if (choice >= 0 && choice < num_events) {
            time_t target_time = events[choice].time;
            while (difftime(time(NULL), target_time) > 0) {
                sleep(1);
            }
            printf("\nYou have arrived at your destination: %s\n", events[choice].description);
        } else {
            printf("Invalid choice.\n");
        }
        printf("Do you want to travel again? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return 0;
}