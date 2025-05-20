//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int current_year = 2021;
    int target_year;
    int travel_years;
    char choice;

    printf("Welcome to Time Travel Simulation!\n");
    do {
        printf("\nYou are currently in the year %d.\n", current_year);
        printf("Where would you like to go?\n");
        printf("A) Ancient Egypt\n");
        printf("B) Renaissance Italy\n");
        printf("C) Wild West\n");
        printf("D) Future\n");
        printf("E) Exit\n");
        printf(">> ");
        scanf(" %c", &choice); // Read a single character choice and ignore leading whitespace
        switch (tolower(choice)) {
            case 'a':  // Ancient Egypt
                target_year = -3000 + rand() % 100; // Random year between -3000 BCE and -2901 BCE
                break;
            case 'b':  // Renaissance Italy
                target_year = 1450 + rand() % 151; // Random year between 1450 CE and 1600 CE
                break;
            case 'c':  // Wild West
                target_year = 1850 + rand() % 31; // Random year between 1850 CE and 1880 CE
                break;
            case 'd':  // Future
                printf("Which year in the future would you like to visit?\n");
                printf("Enter a positive number of years (e.g., 10 means 2031).\n");
                printf(">> ");
                scanf("%d", &travel_years);
                target_year = current_year + travel_years; // Travel forward in time
                break;
            case 'e':  // Exit
                printf("Goodbye traveler!\n");
                return 0;
            default:  // Invalid choice
                printf("Invalid choice. Try again.\n");
                continue; // Go back to the start of the loop
        }
        if (target_year < current_year) {
            printf("You traveled back in time to %d.\n", target_year);
        } else if (target_year > current_year) {
            printf("You traveled forward in time to %d.\n", target_year);
        } else {
            printf("You traveled in time but ended up in the same year.\n");
        }
        current_year = target_year;
    } while (1); // Infinite loop until user chooses to exit

    return 0;
}