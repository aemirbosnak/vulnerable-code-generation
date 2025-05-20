//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // initialize variables
    int year, choice;
    char era[10];
    time_t current_time;
    struct tm *timeinfo;
    
    // get current year
    time(&current_time);
    timeinfo = localtime(&current_time);
    year = timeinfo->tm_year + 1900;

    // ask for era choice
    printf("Welcome to the Time Travel Simulator!\n");
    printf("Which era would you like to explore?\n");
    printf("1. Mesozoic Era (252 to 66 million years ago)\n");
    printf("2. Medieval Era (5th to 15th century)\n");
    printf("3. Renaissance Era (14th to 17th century)\n");
    printf("4. Industrial Era (18th to 19th century)\n");
    printf("5. Modern Era (20th century to present)\n");
    printf("\nEnter your choice (1-5): ");
    scanf("%d", &choice);

    // set era and time period
    switch (choice) {
        case 1:
            strcpy(era, "Mesozoic Era");
            year = 150000000; // set year to a random value within era
            break;
        case 2:
            strcpy(era, "Medieval Era");
            year = rand() % 1000 + 500; // set year to a random value within era
            break;
        case 3:
            strcpy(era, "Renaissance Era");
            year = rand() % 300 + 1300; // set year to a random value within era
            break;
        case 4:
            strcpy(era, "Industrial Era");
            year = rand() % 200 + 1700; // set year to a random value within era
            break;
        case 5:
            strcpy(era, "Modern Era");
            year = rand() % 120 + 1900; // set year to a random value within era
            break;
        default:
            printf("Invalid choice, exiting...\n");
            exit(1);
    }

    // display information and allow time travel
    printf("\nYou have traveled back in time to the %s (%d)\n", era, year);
    printf("What would you like to do?\n");

    do {
        printf("\n1. Explore the surroundings\n");
        printf("2. Meet a famous person\n");
        printf("3. Learn about historical events\n");
        printf("4. Return to present time\n");
        printf("\nEnter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nYou are exploring the surroundings...\n");
                break;
            case 2:
                printf("\nYou have met a famous person!\n");
                break;
            case 3:
                printf("\nYou are learning about historical events...\n");
                break;
            case 4:
                printf("\nReturning to present time...\n");
                break;
            default:
                printf("\nInvalid choice, please choose again.\n");
        }
    } while (choice != 4);

    printf("\nThank you for using the Time Travel Simulator!\n");

    return 0;
}