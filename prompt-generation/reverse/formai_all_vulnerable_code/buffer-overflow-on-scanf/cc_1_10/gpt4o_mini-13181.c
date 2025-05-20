//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EVENTS 10
#define MAX_DESCRIPTION 256

typedef struct {
    char name[50];
    char description[MAX_DESCRIPTION];
    int year;
} HistoricalEvent;

void displayEvents(HistoricalEvent events[], int count);
void travelToTime(HistoricalEvent events[], int count);

int main() {
    HistoricalEvent events[MAX_EVENTS] = {
        {"The Signing of the Declaration of Independence", "Colonies declared independence from Britain.", 1776},
        {"The Moon Landing", "Astronauts landed on the moon for the first time.", 1969},
        {"The Fall of the Berlin Wall", "The wall dividing East and West Berlin was brought down.", 1989},
        {"World War II Ends", "The war in Europe officially ended with the surrender of Germany.", 1945},
        {"The Launch of the First Satellite", "Sputnik was launched by the Soviet Union.", 1957},
        {"The Invention of the Printing Press", "Johannes Gutenberg invented the movable-type printing press.", 1440},
        {"The French Revolution", "A period of radical social and political upheaval in France.", 1789},
        {"The Great Depression", "The worldwide economic downturn that began in the late 1920s.", 1929},
        {"Discovery of America", "Christopher Columbus discovered America in his voyage.", 1492},
        {"The Renaissance", "A period of cultural revival and renewed interest in arts and sciences.", 1400}
    };

    int eventCount = 10;
    int choice;

    printf("Welcome to the Time Travel Simulator!\n");
    printf("You can experience significant events in history.\n");

    do {
        printf("\nChoose an option:\n");
        printf("1. List Historical Events\n");
        printf("2. Travel to a Specific Event\n");
        printf("3. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                displayEvents(events, eventCount);
                break;
            case 2:
                travelToTime(events, eventCount);
                break;
            case 3:
                printf("Thank you for using the Time Travel Simulator. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 3);

    return 0;
}

void displayEvents(HistoricalEvent events[], int count) {
    printf("\nHistorical Events:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s (%d)\n", i + 1, events[i].name, events[i].year);
    }
}

void travelToTime(HistoricalEvent events[], int count) {
    int eventChoice;
    printf("Enter the number of the event you want to travel to: ");
    scanf("%d", &eventChoice);

    if (eventChoice > 0 && eventChoice <= count) {
        HistoricalEvent chosenEvent = events[eventChoice - 1];
        printf("\n*** Time Traveling to %s in %d ***\n", chosenEvent.name, chosenEvent.year);
        printf("Description: %s\n", chosenEvent.description);
        printf("Enjoy your journey through time!\n");
    } else {
        printf("Invalid event number. Please try again.\n");
    }
}