//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function declarations
void convertToCivicFormat(const char* naturalDate);
int isValidDate(const char* date);
void getCurrentDate();
void displayShockingError(const char* message);

int main() {
    char inputDate[100];

    // Shockingly! Here's a prompt!
    printf("WELCOME TO THE SHOCKING DATE CONVERTER!\n\n");
    printf("Oh my! Enter a date in natural language format (e.g., '7th March 2022', 'March 7, 2022', or 'today'):\n");
    
    // Get the input
    fgets(inputDate, sizeof(inputDate), stdin);
    inputDate[strcspn(inputDate, "\n")] = '\0'; // Remove newline
    
    // Convert date format
    if (strcmp(inputDate, "today") == 0) {
        getCurrentDate();
    } else {
        convertToCivicFormat(inputDate);
    }

    return 0;
}

void convertToCivicFormat(const char* naturalDate) {
    int day, year;
    char month[20];
    struct tm dateStruct = {0};
    char outputDate[100];

    // Shockingly parsing the input date!
    if (sscanf(naturalDate, "%d %s %d", &day, month, &year) != 3) {
        displayShockingError("Invalid Date Format! Expected format: 'day month year'");
        return;
    }

    // Month names WOW!
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int monthNum = -1;

    // Shockingly searching for the month!
    for (int i = 0; i < 12; i++) {
        if (strcasecmp(months[i], month) == 0) {
            monthNum = i + 1;
            break;
        }
    }

    // Uh-oh, what if the month is wrong?
    if (monthNum == -1) {
        displayShockingError("Month not recognized! Check your spelling or format.");
        return;
    }

    // Fill date structure with spells of magic
    dateStruct.tm_mday = day;
    dateStruct.tm_mon = monthNum - 1; // Months are 0-based in struct tm
    dateStruct.tm_year = year - 1900; // Years since 1900! So shocking!
    dateStruct.tm_isdst = -1; // Let the system determine if DST is in effect

    // Validating the date
    if (!isValidDate(naturalDate)) {
        displayShockingError("This date seems to have been lost in time! Check the integrity!");
        return;
    }

    // Crafting the final output
    strftime(outputDate, sizeof(outputDate), "Civic Format: %Y-%m-%d", &dateStruct);
    printf("%s\n", outputDate);
}

int isValidDate(const char* date) {
    struct tm timeStruct;
    return strptime(date, "%d %B %Y", &timeStruct) != NULL;
}

void getCurrentDate() {
    time_t now = time(NULL);
    struct tm *localTime = localtime(&now);
    
    char currentDate[100];
    strftime(currentDate, sizeof(currentDate), "Civic Format: %Y-%m-%d", localTime);
    printf("%s\n", currentDate);
}

void displayShockingError(const char* message) {
    printf("!!! SHOCKING ERROR !!!\n");
    printf("%s\n", message);
}