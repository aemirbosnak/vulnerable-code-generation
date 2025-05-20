//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_INPUT 256

// Function to parse the date in "Day Month Year" format
time_t parseDate(char *input) {
    struct tm timeinfo;
    char month[10];
    int day, year;
    
    // Initialize tm structure
    memset(&timeinfo, 0, sizeof(struct tm));
    
    // Divide the input into components
    sscanf(input, "%d %s %d", &day, month, &year);

    // Convert the month name to an integer
    if (strcasecmp(month, "January") == 0) timeinfo.tm_mon = 0;
    else if (strcasecmp(month, "February") == 0) timeinfo.tm_mon = 1;
    else if (strcasecmp(month, "March") == 0) timeinfo.tm_mon = 2;
    else if (strcasecmp(month, "April") == 0) timeinfo.tm_mon = 3;
    else if (strcasecmp(month, "May") == 0) timeinfo.tm_mon = 4;
    else if (strcasecmp(month, "June") == 0) timeinfo.tm_mon = 5;
    else if (strcasecmp(month, "July") == 0) timeinfo.tm_mon = 6;
    else if (strcasecmp(month, "August") == 0) timeinfo.tm_mon = 7;
    else if (strcasecmp(month, "September") == 0) timeinfo.tm_mon = 8;
    else if (strcasecmp(month, "October") == 0) timeinfo.tm_mon = 9;
    else if (strcasecmp(month, "November") == 0) timeinfo.tm_mon = 10;
    else if (strcasecmp(month, "December") == 0) timeinfo.tm_mon = 11;
    else {
        printf("Alas! Month is unknown, dear heart.\n");
        return -1;
    }

    // Assign the day and year
    timeinfo.tm_mday = day;
    timeinfo.tm_year = year - 1900; // Years since 1900

    // Normalize and convert to time_t
    time_t result = mktime(&timeinfo);
    if (result == -1) {
        printf("Oh, what tragedy! Date is not valid!\n");
    }
    return result;
}

// Function to display the date in the modern format
void displayDate(time_t date) {
    struct tm *tm_info;
    char buffer[80];

    tm_info = localtime(&date);
    strftime(buffer, sizeof(buffer), "%B %d, %Y", tm_info);
    printf("Verily, the date thou sought be: %s\n", buffer);
}

int main() {
    char input[MAX_INPUT];

    printf("O! Speaketh thy date in the style of yonder times (e.g., '12 March 2023'):\n");
    fgets(input, MAX_INPUT, stdin);
    
    // Remove the newline character if present
    input[strcspn(input, "\n")] = 0;

    // Perform parsing of the date
    time_t convertedDate = parseDate(input);
    
    // Only display if parsing was successful
    if (convertedDate != -1) {
        displayDate(convertedDate);
    }

    return 0;
}