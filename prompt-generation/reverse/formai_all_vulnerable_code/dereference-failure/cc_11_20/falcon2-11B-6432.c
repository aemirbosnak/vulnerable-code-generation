//Falcon2-11B DATASET v1.0 Category: Natural Language Date Converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert date in natural language to date in ISO format
void convertToIso(char* naturalLanguageDate) {
    // Split the date into month, day, and year
    char* month = strtok(naturalLanguageDate, " ");
    char* day = strtok(NULL, " ");
    char* year = strtok(NULL, " ");

    // Check if the month is valid
    if (strlen(month)!= 3 || strcmp(month, "Jan")!= 0 || strcmp(month, "Feb")!= 0 || strcmp(month, "Mar")!= 0 || strcmp(month, "Apr")!= 0 || strcmp(month, "May")!= 0 || strcmp(month, "Jun")!= 0 || strcmp(month, "Jul")!= 0 || strcmp(month, "Aug")!= 0 || strcmp(month, "Sep")!= 0 || strcmp(month, "Oct")!= 0 || strcmp(month, "Nov")!= 0 || strcmp(month, "Dec")!= 0) {
        printf("Invalid month\n");
        return;
    }

    // Check if the day is valid
    if (strlen(day)!= 2 || (day[0] < '0' || day[0] > '9' || day[1] < '0' || day[1] > '9')) {
        printf("Invalid day\n");
        return;
    }

    // Check if the year is valid
    int yearInt;
    sscanf(year, "%d", &yearInt);
    if (yearInt < 1900 || yearInt > 2100) {
        printf("Invalid year\n");
        return;
    }

    // Convert the month to ISO format
    char isoMonth[3] = {month[0], month[1], month[2]};

    // Convert the day to ISO format
    char isoDay[2] = {day[0], day[1]};

    // Convert the year to ISO format
    char isoYear[4];
    sprintf(isoYear, "%d", yearInt);

    // Concatenate the ISO format month, day, and year
    char isoDate[11];
    sprintf(isoDate, "%s-%s-%s", isoMonth, isoDay, isoYear);

    // Print the converted date
    printf("ISO Date: %s\n", isoDate);
}

// Main function
int main() {
    char naturalLanguageDate[100];
    printf("Enter a natural language date: ");
    fgets(naturalLanguageDate, sizeof(naturalLanguageDate), stdin);
    naturalLanguageDate[strcspn(naturalLanguageDate, "\n")] = '\0'; // Remove newline character

    convertToIso(naturalLanguageDate);

    return 0;
}