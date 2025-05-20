//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_YEARS 6
#define MAX_LENGTH 100

typedef struct {
    int year;
    char event[MAX_LENGTH];
} Timeline;

void display_menu() {
    printf("Welcome to the Time Travel Simulator!\n");
    printf("1. Travel to the Past\n");
    printf("2. Travel to the Future\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

void travel_to_past() {
    Timeline timeline[MAX_YEARS] = {
        { 2000, "Y2K bug scare" },
        { 1969, "First Moon Landing" },
        { 1945, "End of World War II" },
        { 1929, "The Great Depression" },
        { 1776, "Declaration of Independence" },
        { 44, "Assassination of Julius Caesar" }
    };

    printf("\nChoose a year to travel to:\n");
    for (int i = 0; i < MAX_YEARS; i++) {
        printf("%d. %d: %s\n", i + 1, timeline[i].year, timeline[i].event);
    }

    int choice;
    printf("Enter your choice (1-%d): ", MAX_YEARS);
    scanf("%d", &choice);

    if (choice < 1 || choice > MAX_YEARS) {
        printf("Invalid choice. Please try again.\n");
        return;
    }

    printf("Time traveling to %d...\n", timeline[choice - 1].year);
    printf("Event: %s\n", timeline[choice - 1].event);
}

void travel_to_future() {
    Timeline timeline[MAX_YEARS] = {
        { 2025, "First human colony on Mars" },
        { 2050, "Global climate neutrality" },
        { 2100, "Human-robot coexistence" },
        { 2200, "Intergalactic travel begins" },
        { 2300, "Discovery of extraterrestrial life" },
        { 3000, "Humanity enters the cosmic age" }
    };

    printf("\nChoose a year to travel to:\n");
    for (int i = 0; i < MAX_YEARS; i++) {
        printf("%d. %d: %s\n", i + 1, timeline[i].year, timeline[i].event);
    }

    int choice;
    printf("Enter your choice (1-%d): ", MAX_YEARS);
    scanf("%d", &choice);

    if (choice < 1 || choice > MAX_YEARS) {
        printf("Invalid choice. Please try again.\n");
        return;
    }

    printf("Time traveling to %d...\n", timeline[choice - 1].year);
    printf("Event: %s\n", timeline[choice - 1].event);
}

int main() {
    int option;

    while (1) {
        display_menu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                travel_to_past();
                break;
            case 2:
                travel_to_future();
                break;
            case 3:
                printf("Exiting the Time Travel Simulator. Safe travels!\n");
                exit(0);
            default:
                printf("Invalid option. Try again!\n");
        }
        printf("\n");
    }

    return 0;
}