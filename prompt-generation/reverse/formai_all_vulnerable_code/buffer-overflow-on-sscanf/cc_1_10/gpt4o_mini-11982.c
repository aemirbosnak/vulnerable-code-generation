//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 256

// Returns the day of the week for a given date
int getDayOfWeek(int day, int month, int year) {
    // Zeller's Congruence algorithm
    if (month < 3) {
        month += 12;
        year--;
    }
    int K = year % 100;
    int J = year / 100;
    
    int f = day + (13 * (month + 1)) / 5 + K + K / 4 + J / 4 + 5 * J;
    return f % 7;
}

// Convert a string date in "Day Month Year" format to a structured format
void parseDate(const char *input, int *day, int *month, int *year) {
    char monthNames[12][20] = {
        "January", "February", "March", "April", "May", "June", 
        "July", "August", "September", "October", "November", "December"
    };

    char monthStr[20];
    sscanf(input, "%d %s %d", day, monthStr, year);

    for (*month = 0; *month < 12; (*month)++) {
        if (strcmp(monthStr, monthNames[*month]) == 0) {
            break;
        }
    }
    (*month)++; // Convert to 1-based index 
}

// Main function that drives the program
int main() {
    char input[BUFFER_SIZE];
    int day, month, year;

    printf("Welcome to the Mind-Bending Natural Language Date Converter!\n");
    printf("Please enter a date in the format 'Day Month Year' (e.g., '20 April 2023'):\n");

    // Get user input
    fgets(input, BUFFER_SIZE, stdin);
    
    // Parse the input date
    parseDate(input, &day, &month, &year);

    // Print out the parsed date
    printf("You entered:\nDay: %d\nMonth: %d\nYear: %d\n", day, month, year);

    // Determine the day of the week
    int dayOfWeek = getDayOfWeek(day, month, year);
    const char *days[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    
    printf("The day you entered falls on a: %s\n", days[dayOfWeek]);

    // Create a timestamp for the date
    struct tm timeStruct = {0};
    timeStruct.tm_mday = day;
    timeStruct.tm_mon = month - 1; // tm_mon is 0 based
    timeStruct.tm_year = year - 1900; // tm_year is years since 1900

    // Convert to time_t and get formatted date string
    time_t timestamp = mktime(&timeStruct);
    char formattedDate[BUFFER_SIZE];

    strftime(formattedDate, sizeof(formattedDate), "%Y-%m-%d %H:%M:%S", localtime(&timestamp));
    printf("The formatted date is: %s\n", formattedDate);

    // Calculate and display the number of days until the next occurrence of this date in the next year
    struct tm nextDate = timeStruct;
    nextDate.tm_year += 1; // Move to next year
    time_t nextTimestamp = mktime(&nextDate);
    
    double secondsUntilNext = difftime(nextTimestamp, timestamp);
    int daysUntilNext = secondsUntilNext / (60 * 60 * 24);
    
    printf("The number of days until the same date next year: %d days\n", daysUntilNext);

    return 0;
}