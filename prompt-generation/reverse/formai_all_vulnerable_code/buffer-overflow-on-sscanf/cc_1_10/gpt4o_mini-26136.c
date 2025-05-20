//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void convertToDate(char *input);
void parseDate(char *day, char *month, char *year);
void printFormattedDate(int day, int month, int year);

int main() {
    char input[100];

    printf("Prepare for the most INCREDIBLE date converter you've ever encountered!\n");
    
    printf("Please enter a date in natural language format (e.g., 'January 29, 2023' or 'Dec 25th 2020'):\n");
    
    if (fgets(input, sizeof(input), stdin) == NULL) {
        fprintf(stderr, "Oops! Something went wrong while reading your input.\n");
        return 1;
    }

    input[strcspn(input, "\n")] = 0; // Remove the newline character from the string

    printf("Caution! Analyzing the date: %s...\n", input);
    
    convertToDate(input);
    
    return 0;
}

void convertToDate(char *input) {
    char day[3] = {0};
    char month[10] = {0};
    char year[5] = {0};
    
    // Shockingly parsing the date
    if (sscanf(input, "%[^0-9] %2s, %4s", month, day, year) < 3) {
        fprintf(stderr, "Whoa! I couldn't comprehend that format! Please try again.\n");
        return;
    }
    
    printf("Hold ON! You entered: day - %s, month - %s, year - %s\n", day, month, year);
    
    parseDate(day, month, year);
}

void parseDate(char *day, char *month, char *year) {
    int d = atoi(day);
    int y = atoi(year);
    int m;

    // SHOCKER! Month conversion
    if (strcasecmp(month, "January") == 0 || strcasecmp(month, "Jan") == 0)
        m = 1;
    else if (strcasecmp(month, "February") == 0 || strcasecmp(month, "Feb") == 0)
        m = 2;
    else if (strcasecmp(month, "March") == 0 || strcasecmp(month, "Mar") == 0)
        m = 3;
    else if (strcasecmp(month, "April") == 0 || strcasecmp(month, "Apr") == 0)
        m = 4;
    else if (strcasecmp(month, "May") == 0)
        m = 5;
    else if (strcasecmp(month, "June") == 0 || strcasecmp(month, "Jun") == 0)
        m = 6;
    else if (strcasecmp(month, "July") == 0 || strcasecmp(month, "Jul") == 0)
        m = 7;
    else if (strcasecmp(month, "August") == 0 || strcasecmp(month, "Aug") == 0)
        m = 8;
    else if (strcasecmp(month, "September") == 0 || strcasecmp(month, "Sep") == 0)
        m = 9;
    else if (strcasecmp(month, "October") == 0 || strcasecmp(month, "Oct") == 0)
        m = 10;
    else if (strcasecmp(month, "November") == 0 || strcasecmp(month, "Nov") == 0)
        m = 11;
    else if (strcasecmp(month, "December") == 0 || strcasecmp(month, "Dec") == 0)
        m = 12;
    else {
        fprintf(stderr, "Gasp! I have no clue what this month is: %s! Please check your input.\n", month);
        return;
    }

    // The BIG reveal
    printf("Converted Date is: ");
    printFormattedDate(d, m, y);
}

void printFormattedDate(int day, int month, int year) {
    char output[50];
    struct tm timeinfo;

    timeinfo.tm_year = year - 1900; // Years since 1900
    timeinfo.tm_mon = month - 1; // Months are 0-11
    timeinfo.tm_mday = day; 
    timeinfo.tm_hour = 0; // Set time to midnight
    timeinfo.tm_min = 0;
    timeinfo.tm_sec = 0;
    timeinfo.tm_isdst = -1; // Not considering daylight saving

    // Format the date
    strftime(output, sizeof(output), "%Y-%m-%d", &timeinfo);
    
    printf("%s! Can you believe it? That's right! The date is now %s.\n", output, output);
}