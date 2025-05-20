//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_YEARS 10
#define MAX_EVENTS 5

typedef struct {
    int year;
    char events[MAX_EVENTS][100];
    int eventCount;
} TimePeriod;

TimePeriod history[MAX_YEARS];

void initializeHistory() {
    // Sample historical events
    history[0] = (TimePeriod){ 1900, {"First electric tram system opens", "Max Planck develops quantum theory", "First Zeppelin flight", "Formation of the first automobile company", "Publication of The Call of the Wild"}, 5 };
    history[1] = (TimePeriod){ 1969, {"Apollo 11 Moon landing", "Woodstock festival", "First ATM is installed", "The Beatles release Abbey Road", "The Internet concept is introduced"}, 5 };
    history[2] = (TimePeriod){ 1989, {"Fall of the Berlin Wall", "The Simpsons first aired", "The Game Boy is released", "World Wide Web is proposed", "The first episode of Seinfeld airs"}, 5 };
    history[3] = (TimePeriod){ 2000, {"Y2K bug is anticipated", "The first season of Survivor airs", "The dot-com bubble bursts", "Launch of ICQ", "PlayStation 2 is released"}, 5 };
    history[4] = (TimePeriod){ 2020, {"COVID-19 pandemic declared", "Black Lives Matter protests peak", "The first electric car company goes public", "Astronomers suggest 'Planet 9'", "The US gains a new president"}, 5 };
    // Add more years as needed...
}

void displayMenu() {
    printf("Welcome to the Time Travel Simulator!\n");
    printf("Please select a year to explore the historical events:\n");
    printf("1. 1900\n");
    printf("2. 1969\n");
    printf("3. 1989\n");
    printf("4. 2000\n");
    printf("5. 2020\n");
    printf("0. Exit\n");
}

void exploreYear(int yearIndex) {
    printf("Exploring the year %d:\n", history[yearIndex].year);
    for (int i = 0; i < history[yearIndex].eventCount; ++i) {
        printf("- %s\n", history[yearIndex].events[i]);
    }
}

int main() {
    int choice;
    initializeHistory();
    
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                exploreYear(0);
                break;
            case 2:
                exploreYear(1);
                break;
            case 3:
                exploreYear(2);
                break;
            case 4:
                exploreYear(3);
                break;
            case 5:
                exploreYear(4);
                break;
            case 0:
                printf("Exiting the Time Travel Simulator. Safe travels!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
    
    return 0;
}