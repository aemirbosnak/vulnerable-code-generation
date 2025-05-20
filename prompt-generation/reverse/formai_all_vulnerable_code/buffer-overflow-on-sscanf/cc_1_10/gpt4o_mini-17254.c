//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void romanticDateFormat(const char* dateInput) {
    char month[15], day[3], year[5];
    int monthIndex;
    
    // Extracting day, month name, and year from the input
    sscanf(dateInput, "%s %s %s", month, day, year);
    
    // Defining month names
    const char* months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    // Finding the month index
    for (monthIndex = 0; monthIndex < 12; monthIndex++) {
        if (strcasecmp(months[monthIndex], month) == 0) {
            break;
        }
    }

    // Check if month index is valid
    if (monthIndex < 12) {
        printf("Ah, the day of our fateful encounter was %s, the %s of the passionate month of %s, in the year of our destiny %s.\n", 
               day, day, months[monthIndex], year);
    } else {
        printf("Oh, my beloved, it seems there was a misunderstanding. The month you mentioned does not exist in our earthly calendar.\n");
    }
}

void gatherDateInput() {
    char date[50];
    printf("My dear, please share the enchanting date of our love story (e.g., 'October 15 2023'): ");
    fgets(date, sizeof(date), stdin);
    date[strcspn(date, "\n")] = 0; // Remove newline character

    romanticDateFormat(date);
}

void poeticGreeting() {
    printf("Welcome, my love, to this humble abode of code.\n");
    printf("Here we shall weave our dreams into the tapestry of time.\n");
}

void expressLove() {
    printf("Every date that passes is but a step in this beautiful journey we share.\n");
    printf("Let us celebrate each moment as if it were a blooming flower.\n");
}

int main() {
    poeticGreeting();
    expressLove();
    gatherDateInput();
    
    printf("Remember, love is eternal, just like the stars above.\n");
    printf("May our moments together be forever cherished in the cosmic dance of time.\n");

    return 0;
}