//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_YEARS 5
#define MAX_FACT_LENGTH 256

typedef struct {
    int year;
    char fact[MAX_FACT_LENGTH];
} TimeTravelFact;

void displayMenu(TimeTravelFact facts[], int size) {
    printf("\n=== Time Travel Simulator ===\n");
    printf("Available Years to Travel:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %d\n", i + 1, facts[i].year);
    }
    printf("6. Exit\n");
    printf("Select a year to travel to (1-6): ");
}

void showFact(TimeTravelFact facts[], int index) {
    printf("\nTraveling to the year %d...\n", facts[index].year);
    printf("Did you know? %s\n", facts[index].fact);
}

int main() {
    TimeTravelFact facts[MAX_YEARS] = {
        {1990, "The Hubble Space Telescope was launched, providing incredible images of the universe."},
        {2000, "The Y2K bug caused widespread concern, but major problems were mostly avoided."},
        {2010, "The first iPad was released, revolutionizing the tablet market."},
        {2020, "The COVID-19 pandemic lead to significant changes in global health and lifestyle."},
        {2023, "Artificial Intelligence continues to advance rapidly, changing industries."}
    };

    int choice;

    do {
        displayMenu(facts, MAX_YEARS);
        scanf("%d", &choice);

        if (choice >= 1 && choice <= MAX_YEARS) {
            showFact(facts, choice - 1);
        } else if (choice != 6) {
            printf("Invalid option, please try again.\n");
        }
    } while (choice != 6);

    printf("Thank you for using the Time Travel Simulator! See you next time!\n");
    return EXIT_SUCCESS;
}