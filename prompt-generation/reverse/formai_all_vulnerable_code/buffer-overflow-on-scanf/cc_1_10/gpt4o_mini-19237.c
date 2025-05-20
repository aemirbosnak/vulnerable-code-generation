//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    char name[50];
    char era[50];
    char loveInterest[50];
    char message[200];
} TimeTraveler;

void displayRomanticMessage(TimeTraveler traveler) {
    printf("Dear %s,\n", traveler.loveInterest);
    printf("I traveled from the year %s, and here is my message for you:\n", traveler.era);
    printf("\"%s\"\n", traveler.message);
    printf("Forever yours,\n%s\n\n", traveler.name);
}

void travelToEra(TimeTraveler *traveler, const char *newEra, const char *loveInterest, const char *message) {
    strcpy(traveler->era, newEra);
    strcpy(traveler->loveInterest, loveInterest);
    strcpy(traveler->message, message);
}

int main() {
    TimeTraveler traveler;
    
    // Setting the traveler's initial identity
    strcpy(traveler.name, "Elio");
    strcpy(traveler.era, "2023");

    printf("Welcome to the Time Travel Simulator!\n");
    printf("--------------------------------------\n");

    char newEra[50];
    char loveInterest[50];
    char romanticMessage[200];
    char continueTravel;

    do {
        printf("Enter the era you wish to travel to (e.g., '1920s', '1600s', '2100s'): ");
        scanf("%s", newEra);
        
        printf("Who is your love interest in this era? ");
        scanf(" %[^\n]s", loveInterest);

        printf("What romantic message would you like to share? ");
        scanf(" %[^\n]s", romanticMessage);

        // Traveling to the new era
        travelToEra(&traveler, newEra, loveInterest, romanticMessage);

        // Displaying the romantic message
        displayRomanticMessage(traveler);

        printf("Would you like to travel again? (y/n): ");
        scanf(" %c", &continueTravel);
        
    } while (continueTravel == 'y' || continueTravel == 'Y');

    printf("Thank you for using the Time Travel Simulator. Safe travels, dear romantic!\n");
    
    return 0;
}