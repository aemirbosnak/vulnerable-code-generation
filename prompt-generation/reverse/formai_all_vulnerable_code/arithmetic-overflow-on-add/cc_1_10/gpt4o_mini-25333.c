//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Function Prototypes
void convertNaturalLanguageDate(char *inputDate);
void getCurrentDate(int *year, int *month, int *day);
void addDays(int *year, int *month, int *day, int daysToAdd);
void printDate(int year, int month, int day);

int main() {
    char inputDate[100];
    
    printf("\n🎉 Welcome to the Enthusiastic Natural Language Date Converter! 🎉\n");
    printf("Type a date in natural language and I'll convert it for you! 🌟\n");
    printf("Examples: 'Tomorrow', 'Next Friday', 'February 25, 2023'.\n");
    printf("Type 'exit' to end the program. 🚀\n");

    while (1) {
        printf("\nEnter your date: ");
        fgets(inputDate, sizeof(inputDate), stdin);
       
        // Remove newline character
        size_t len = strlen(inputDate);
        if (len > 0 && inputDate[len - 1] == '\n') {
            inputDate[len - 1] = '\0';
        }

        // Check for exit command
        if (strcmp(inputDate, "exit") == 0) {
            printf("Thanks for using the Date Converter! Goodbye! 👋\n");
            break;
        }

        // Convert the date
        convertNaturalLanguageDate(inputDate);
    }

    return 0;
}

void convertNaturalLanguageDate(char *inputDate) {
    int year, month, day;
    char *token = strtok(inputDate, " ");
    time_t t = time(NULL);
    struct tm *tmInfo = localtime(&t);

    // Get current date
    getCurrentDate(&year, &month, &day);
    
    printf("You entered: '%s'\n", inputDate);

    // Process natural language input
    if (strcmp(inputDate, "Tomorrow") == 0) {
        printf("Converting to date... 🗓️\n");
        addDays(&year, &month, &day, 1);
    } else if (strcmp(inputDate, "Yesterday") == 0) {
        printf("Converting to date... 🗓️\n");
        addDays(&year, &month, &day, -1);
    } else if (strstr(inputDate, "Next") != NULL) {
        if (strstr(inputDate, "Monday")) addDays(&year, &month, &day, (8 - tmInfo->tm_wday)%7);
        else if (strstr(inputDate, "Tuesday")) addDays(&year, &month, &day, (9 - tmInfo->tm_wday)%7);
        else if (strstr(inputDate, "Wednesday")) addDays(&year, &month, &day, (10 - tmInfo->tm_wday)%7);
        else if (strstr(inputDate, "Thursday")) addDays(&year, &month, &day, (11 - tmInfo->tm_wday)%7);
        else if (strstr(inputDate, "Friday")) addDays(&year, &month, &day, (12 - tmInfo->tm_wday)%7);
        else if (strstr(inputDate, "Saturday")) addDays(&year, &month, &day, (13 - tmInfo->tm_wday)%7);
        else if (strstr(inputDate, "Sunday")) addDays(&year, &month, &day, (14 - tmInfo->tm_wday)%7);
    } else if (strstr(inputDate, "February") != NULL) {
        sscanf(inputDate, "February %d", &day);
        month = 2; year = tmInfo->tm_year + 1900; // Current year
    } else {
        printf("Sorry, I couldn't understand that date format! 😕\n");
        return;
    }

    // Print the converted date
    printDate(year, month, day);
}

void getCurrentDate(int *year, int *month, int *day) {
    time_t t = time(NULL);
    struct tm *tmInfo = localtime(&t);
    *year = tmInfo->tm_year + 1900;
    *month = tmInfo->tm_mon + 1; // Months are 0-11 in struct tm
    *day = tmInfo->tm_mday;
}

void addDays(int *year, int *month, int *day, int daysToAdd) {
    struct tm date = {0};
    date.tm_year = *year - 1900;
    date.tm_mon = *month - 1;
    date.tm_mday = *day + daysToAdd;

    mktime(&date); // Normalize the date
    *year = date.tm_year + 1900;
    *month = date.tm_mon + 1;
    *day = date.tm_mday;
}

void printDate(int year, int month, int day) {
    printf("The converted date is: %04d-%02d-%02d 🎊\n", year, month, day);
}