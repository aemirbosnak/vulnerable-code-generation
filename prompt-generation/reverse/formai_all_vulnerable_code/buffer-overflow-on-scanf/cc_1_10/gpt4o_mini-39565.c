//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_TRAVELS 10
#define BUFFER_SIZE 256

typedef struct {
    char name[30];
    int year;
    char event[100];
} TimeTravelEvent;

void logEvent(TimeTravelEvent *events, int count, const char *name, int year, const char *event) {
    if (count >= MAX_TRAVELS) {
        printf("Event log is full!\n");
        return;
    }
    strncpy(events[count].name, name, sizeof(events[count].name) - 1);
    events[count].year = year;
    strncpy(events[count].event, event, sizeof(events[count].event) - 1);
}

void displayEvents(TimeTravelEvent *events, int count) {
    printf("\nTime Travel Event Log:\n");
    printf("------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%s traveled to %d: %s\n", events[i].name, events[i].year, events[i].event);
    }
    printf("------------------------\n");
}

void timeTravel(TimeTravelEvent *events, int *count) {
    char name[30];
    int year;
    char event[100];
    
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;  // Remove newline

    printf("Enter the year to travel to: ");
    scanf("%d", &year);
    getchar(); // Consume newline character left in input buffer

    printf("Enter a brief description of the event: ");
    fgets(event, sizeof(event), stdin);
    event[strcspn(event, "\n")] = 0;  // Remove newline

    logEvent(events, *count, name, year, event);
    (*count)++;
}

int main() {
    TimeTravelEvent events[MAX_TRAVELS];
    int count = 0;
    char choice[3];

    printf("Welcome to the Time Travel Simulator!\n");
    printf("=======================================\n");

    do {
        timeTravel(events, &count);
        
        if (count < MAX_TRAVELS) {
            printf("Would you like to time travel again? (yes/no): ");
            fgets(choice, sizeof(choice), stdin);
            choice[strcspn(choice, "\n")] = 0;  // Remove newline
        } else {
            strcpy(choice, "no");
            printf("You have reached the maximum number of travels.\n");
        }

    } while (strcmp(choice, "yes") == 0);

    displayEvents(events, count);

    printf("Thank you for using the Time Travel Simulator!\n");
    return 0;
}