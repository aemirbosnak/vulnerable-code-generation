//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_EVENTS 100
#define MAX_STRING_LENGTH 100

typedef struct {
    time_t time;
    char message[MAX_STRING_LENGTH];
} Event;

int main() {
    srand(time(NULL));
    int numEvents = rand() % (MAX_EVENTS - 1) + 1;
    Event events[MAX_EVENTS];
    char input[MAX_STRING_LENGTH];
    printf("Welcome to the Time Travel Simulator!\n");
    printf("Enter your name: ");
    scanf("%s", input);
    strcpy(events[0].message, "You stepped into the time machine and set the dial to the year 1900.");
    events[0].time = time(NULL) - (60 * 60 * 24 * 365 * 120);
    for (int i = 1; i < numEvents; i++) {
        events[i].time = events[i - 1].time + rand() % (60 * 60 * 24 * 365 * 10);
        switch (rand() % 4) {
            case 0:
                strcpy(events[i].message, "You arrived in the bustling city of Paris in the year 1920.");
                break;
            case 1:
                strcpy(events[i].message, "You found yourself in the midst of a grand ball in Vienna in the year 1830.");
                break;
            case 2:
                strcpy(events[i].message, "You witnessed the signing of the Declaration of Independence in Philadelphia in the year 1776.");
                break;
            case 3:
                strcpy(events[i].message, "You shared a tender moment with your beloved under the stars in ancient Greece in the year 400 BC.");
                break;
        }
    }
    printf("As you journey through time, remember that true love transcends all boundaries.\n");
    while (1) {
        time_t currentTime = time(NULL);
        for (int i = 0; i < numEvents; i++) {
            if (events[i].time <= currentTime) {
                printf("%s\n", events[i].message);
            }
        }
        printf("What would you like to do next? ");
        scanf("%s", input);
        if (strcmp(input, "return") == 0) {
            break;
        }
    }
    return 0;
}