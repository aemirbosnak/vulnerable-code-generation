//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_YEARS 1000
#define MAX_TIME_TRAVELERS 10

typedef struct {
    char name[50];
    int year;
} TimeTraveler;

void greetTraveler() {
    printf("Welcome, noble traveler of time!\n");
    printf("Prepare to embark on a journey through the annals of history.\n");
}

void displayEra(int year) {
    if (year < 500) {
        printf("You have arrived in the Ancient Era, a time of empires and legends.\n");
    } else if (year < 1000) {
        printf("Welcome to the Early Middle Ages, a period of feudalism and knights.\n");
    } else if (year < 1500) {
        printf("You are now in the High Middle Ages, a flourishing era of culture and chivalry.\n");
    } else {
        printf("Ah! The Late Middle Ages, a time of transition and turmoil.\n");
    }
}

int travelTime(int currentYear) {
    int travelYears;
    printf("Enter how many years to travel (positive for future, negative for past): ");
    scanf("%d", &travelYears);

    int newYear = currentYear + travelYears;
    if (newYear < 0 || newYear > 9999) {
        printf("Alas! The time travel has failed due to bounds. Please input a valid number!\n");
        return currentYear;
    }
    return newYear;
}

void registerTraveler(TimeTraveler travelers[], int *count) {
    if (*count >= MAX_TIME_TRAVELERS) {
        printf("The time traveler registry is full!\n");
        return;
    }

    printf("Enter the name of the time traveler: ");
    scanf("%s", travelers[*count].name);
    travelers[*count].year = 0; // Default year
    (*count)++;
}

void displayTravelers(TimeTraveler travelers[], int count) {
    printf("List of Time Travelers:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - Year: %d\n", i + 1, travelers[i].name, travelers[i].year);
    }
}

void simulateTimeTravel(TimeTraveler travelers[], int count) {
    int travelerChoice;
    printf("Choose a traveler to simulate time travel (1-%d): ", count);
    scanf("%d", &travelerChoice);
    if (travelerChoice < 1 || travelerChoice > count) {
        printf("Invalid choice!\n");
        return;
    }

    TimeTraveler *traveler = &travelers[travelerChoice - 1];
    printf("%s, you are currently in the year %d.\n", traveler->name, traveler->year);

    traveler->year = travelTime(traveler->year);
    displayEra(traveler->year);
}

int main() {
    TimeTraveler travelers[MAX_TIME_TRAVELERS];
    int travelerCount = 0;
    int userChoice;
    int currentYear = 2023;

    greetTraveler();

    do {
        printf("\n--- Time Travel Simulator ---\n");
        printf("1. Register a Traveler\n");
        printf("2. Display Travelers\n");
        printf("3. Simulate Time Travel\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &userChoice);

        switch (userChoice) {
            case 1:
                registerTraveler(travelers, &travelerCount);
                break;
            case 2:
                displayTravelers(travelers, travelerCount);
                break;
            case 3:
                if (travelerCount == 0) {
                    printf("No travelers registered yet!\n");
                } else {
                    simulateTimeTravel(travelers, travelerCount);
                }
                break;
            case 4:
                printf("Farewell, noble traveler!\n");
                break;
            default:
                printf("Invalid option! Please choose again.\n");
                break;
        }

    } while (userChoice != 4);

    return 0;
}