//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    int day;
    int month;
    int year;
} SurrealDate;

const char *monthNames[] = {"Janus", "Februari", "März", "Aesthetic", "Mistral", "Jupiter", "Julian", "Oberon", "Septérieur", "Octobrer", "Novembrum", "Twilight"};

// Function to summon a surreal date from the cosmos
SurrealDate conjureDate(int day, int month, int year) {
    SurrealDate date = {day, month, year};
    printf("A date has emerged from the void: %d %s %d!\n", day, monthNames[month - 1], year);
    return date;
}

// Function to check if the cosmic year is leap
int isCosmicLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            return year % 400 == 0;
        }
        return 1;
    }
    return 0;
}

// Function to compute the number of days in a surreal month
int cosmicDaysInMonth(int month, int year) {
    if (month == 2) {
        return isCosmicLeapYear(year) ? 29 : 28;
    }
    if (month <= 7) {
        return month % 2 == 0 ? 30 : 31;
    }
    return month % 2 == 0 ? 31 : 30;
}

// Function to rub the temporal crystal and convert earthly date to surreal format
void convertToSurreal(char *earthDate) {
    SurrealDate surrealDate;
    int day, month, year;
    sscanf(earthDate, "%d-%d-%d", &year, &month, &day);
    
    if (month < 1 || month > 12 || day < 1 || day > cosmicDaysInMonth(month, year)) {
        printf("The universe rejects your feeble earthly date: %s\n", earthDate);
        return;
    }

    surrealDate = conjureDate(day, month, year);
    printf("In the abstract realm, today's date is: %d %s %d\n\n",
           surrealDate.day, monthNames[surrealDate.month - 1], surrealDate.year);
}

// Function to process date summoning requests
void processRequests() {
    char earthDate[20];
    
    printf("Whisper your earthly dates to the ether (format YYYY-MM-DD, type 'exit' to escape): \n");
    
    while (1) {
        printf("> ");
        fgets(earthDate, sizeof(earthDate), stdin);
        
        if (strncmp(earthDate, "exit", 4) == 0) {
            printf("Thank you for sharing dreams of time with us.\n");
            break;
        }

        // Remove the newline character from the input
        earthDate[strcspn(earthDate, "\n")] = 0;
        
        convertToSurreal(earthDate);
    }
}

int main() {
    printf("Welcome to the Surrealist Date Converter!\n");
    printf("Here, we transform mundane dates into surreal expressions of time.\n");
    printf("Liquidate your calendar and enter a date from your familiar world.\n");

    processRequests(); // Gather and process date conversions

    return 0;
}