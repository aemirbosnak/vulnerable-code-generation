//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayMenu();
void travelToYear(int year);
void printEraDetails(int year);

int main() {
    int choice;
    
    while (1) {
        displayMenu();
        printf("Enter your choice (1-5) or 0 to exit: ");
        scanf("%d", &choice);
        
        if (choice == 0) {
            printf("Thank you for using the Time Travel Simulator. Safe travels!\n");
            break;
        }
        
        switch (choice) {
            case 1:
                travelToYear(1920);
                break;
            case 2:
                travelToYear(1960);
                break;
            case 3:
                travelToYear(1980);
                break;
            case 4:
                travelToYear(2000);
                break;
            case 5:
                travelToYear(2020);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}

void displayMenu() {
    printf("\n*** Time Travel Simulator ***\n");
    printf("1. Travel to 1920s\n");
    printf("2. Travel to 1960s\n");
    printf("3. Travel to 1980s\n");
    printf("4. Travel to 2000s\n");
    printf("5. Travel to 2020s\n");
}

void travelToYear(int year) {
    printf("Initiating time travel to the year %d...\n", year);
    printf("Distorting space-time...\n");
    printf("Arriving in %d...\n", year);
    printEraDetails(year);
}

void printEraDetails(int year) {
    switch (year) {
        case 1920:
            printf("Welcome to the Roaring Twenties!\n");
            printf("Key events: Prohibition, rise of jazz, and the flapper culture.\n");
            printf("Famous figures: Louis Armstrong, F. Scott Fitzgerald.\n");
            printf("Popular culture: Jazz music, Art Deco movement.\n");
            break;
        case 1960:
            printf("Welcome to the Swinging Sixties!\n");
            printf("Key events: Civil Rights Movement, Vietnam War protests.\n");
            printf("Famous figures: John F. Kennedy, Martin Luther King Jr.\n");
            printf("Popular culture: The Beatles, Woodstock festival.\n");
            break;
        case 1980:
            printf("Welcome to the Glamorous Eighties!\n");
            printf("Key events: Fall of the Berlin Wall, rise of techno music.\n");
            printf("Famous figures: Madonna, Ronald Reagan.\n");
            printf("Popular culture: MTV, Pac-Man games, big hair styles.\n");
            break;
        case 2000:
            printf("Welcome to the New Millennium!\n");
            printf("Key events: Y2K scare, rise of the Internet.\n");
            printf("Famous figures: George W. Bush, Oprah Winfrey.\n");
            printf("Popular culture: Reality TV, the dot-com bubble.\n");
            break;
        case 2020:
            printf("Welcome to the Year Twenty-Twenty!\n");
            printf("Key events: Global pandemic, rise of remote work.\n");
            printf("Famous figures: Dr. Anthony Fauci, Greta Thunberg.\n");
            printf("Popular culture: Streaming wars, social media influencers.\n");
            break;
        default:
            printf("Unknown era. Time travel uncharted!\n");
            break;
    }
    
    printf("Time travel completed. Ready to return to your original timeline.\n");
}