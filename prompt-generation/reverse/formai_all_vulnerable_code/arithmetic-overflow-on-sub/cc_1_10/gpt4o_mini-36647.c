//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 256

// Function prototypes
void clearBuffer();
void getInput(char *prompt, char *inputBuffer);
void convertDate(const char *dateStr, struct tm *date);
void printConvertedDate(const struct tm *date);
int isLeapYear(int year);
void getDayOfYear(const struct tm *date);
void printUsage();

int main() {
    char inputDate[BUFFER_SIZE];
    struct tm date = {0};

    printf("Welcome to the C Natural Language Date Converter!\n");
    printf("This program converts natural language date into structured date format.\n");

    while (1) {
        getInput("Please enter a date (e.g., '25th December 2023' or 'next Friday'): ", inputDate);
        
        // Convert input date string to struct tm
        convertDate(inputDate, &date);

        // Print converted date in structured format
        printConvertedDate(&date);

        char continueResponse[BUFFER_SIZE];
        getInput("Would you like to convert another date? (yes/no): ", continueResponse);
        if (strcasecmp(continueResponse, "no") == 0) {
            break;
        }
    }

    printf("Thank you for using the C Natural Language Date Converter. Goodbye!\n");
    return 0;
}

void clearBuffer() {
    while (getchar() != '\n');  // Clear the input buffer
}

void getInput(char *prompt, char *inputBuffer) {
    printf("%s", prompt);
    fgets(inputBuffer, BUFFER_SIZE, stdin);
    inputBuffer[strcspn(inputBuffer, "\n")] = 0; // Remove newline from string
}

void convertDate(const char *dateStr, struct tm *date) {
    char monthStr[20];
    int day, year;

    if (sscanf(dateStr, "%d %s %d", &day, monthStr, &year) == 3) {
        // Parse full date: "25 December 2023"
        date->tm_mday = day;
        date->tm_year = year - 1900; // Years since 1900
        date->tm_mon = (strcasecmp(monthStr, "January") == 0) ? 0 :
                       (strcasecmp(monthStr, "February") == 0) ? 1 :
                       (strcasecmp(monthStr, "March") == 0) ? 2 :
                       (strcasecmp(monthStr, "April") == 0) ? 3 :
                       (strcasecmp(monthStr, "May") == 0) ? 4 :
                       (strcasecmp(monthStr, "June") == 0) ? 5 :
                       (strcasecmp(monthStr, "July") == 0) ? 6 :
                       (strcasecmp(monthStr, "August") == 0) ? 7 :
                       (strcasecmp(monthStr, "September") == 0) ? 8 :
                       (strcasecmp(monthStr, "October") == 0) ? 9 :
                       (strcasecmp(monthStr, "November") == 0) ? 10 :
                       (strcasecmp(monthStr, "December") == 0) ? 11 : -1;
    } else {
        // Assume input in form: "next Friday" or similar
        // Here is a placeholder for more complex natural language processing
        time_t t = time(NULL);
        struct tm now = *localtime(&t);
        date->tm_year = now.tm_year;
        date->tm_mon = now.tm_mon;
        date->tm_mday = now.tm_mday;

        // Simple simulative logic for finding next Friday
        if (strcasestr(dateStr, "next Friday")) {
            while (date->tm_wday != 5) { // Friday is 5
                date->tm_mday++;
                mktime(date); // Normalize struct tm
            }
        } else {
            printf("Date format not recognized! Defaulting to today's date.\n");
            date->tm_year = now.tm_year;
            date->tm_mon = now.tm_mon;
            date->tm_mday = now.tm_mday;
        }
    }
    mktime(date); // Normalize the date
}

void printConvertedDate(const struct tm *date) {
    char dateBuffer[BUFFER_SIZE];
    strftime(dateBuffer, sizeof(dateBuffer), "%Y-%m-%d %A", date);
    printf("Converted Date: %s\n", dateBuffer);

    getDayOfYear(date);
}

void getDayOfYear(const struct tm *date) {
    int dayOfYear = 0;
    for (int i = 0; i < date->tm_mon; i++) {
        dayOfYear += (i == 1) ? (isLeapYear(date->tm_year + 1900) ? 29 : 28) : 
                   (i == 3 || i == 5 || i == 8 || i == 10) ? 30 : 31;
    }
    dayOfYear += date->tm_mday;
    printf("Day of the year: %d\n", dayOfYear);
}

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void printUsage() {
    printf("Usage:\n");
    printf("\tEnter a date in natural language.\n");
    printf("\tExample: '25 December 2023' or 'next Friday'.\n");
}