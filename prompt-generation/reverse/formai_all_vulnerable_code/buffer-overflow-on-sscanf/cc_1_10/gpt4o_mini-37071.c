//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BUFFER 100

// Function prototypes
void getDateInput(char *date_input);
void convertDateToStruct(char *date_input, struct tm *date_struct);
void formatDate(struct tm *date_struct);
void displayDate(struct tm *date_struct);
void displayHelp();

int main() {
    char date_input[MAX_BUFFER];
    struct tm date_struct;

    displayHelp();
    getDateInput(date_input);
    convertDateToStruct(date_input, &date_struct);
    formatDate(&date_struct);
    displayDate(&date_struct);

    return 0;
}

void displayHelp() {
    printf("Welcome to the C Natural Language Date Converter!\n");
    printf("This program accepts date inputs in the following formats:\n");
    printf("1. 'January 1st, 2023'\n");
    printf("2. '1 Jan 2023'\n");
    printf("3. '2023-01-01'\n");
    printf("Please enter a date in any of the above formats:\n");
}

void getDateInput(char *date_input) {
    printf("Enter your date: ");
    fgets(date_input, MAX_BUFFER, stdin);
    date_input[strcspn(date_input, "\n")] = 0;  // Remove newline character
}

void convertDateToStruct(char *date_input, struct tm *date_struct) {
    memset(date_struct, 0, sizeof(struct tm)); // Clear the structure

    if (strstr(date_input, "Jan")) {
        sscanf(date_input, "%d %s %d", &date_struct->tm_mday, date_input, &date_struct->tm_year);
        date_struct->tm_year -= 1900; // Adjust year
        date_struct->tm_mon = 0; // January is month 0
    } else if (strstr(date_input, "February")) {
        sscanf(date_input, "%s %d, %d", date_input, &date_struct->tm_mday, &date_struct->tm_year);
        date_struct->tm_year -= 1900;
        date_struct->tm_mon = 1; // February is month 1
    } else if (strstr(date_input, "March")) {
        sscanf(date_input, "%s %d, %d", date_input, &date_struct->tm_mday, &date_struct->tm_year);
        date_struct->tm_year -= 1900;
        date_struct->tm_mon = 2; // March is month 2
    } else if (strstr(date_input, "April")) {
        sscanf(date_input, "%s %d, %d", date_input, &date_struct->tm_mday, &date_struct->tm_year);
        date_struct->tm_year -= 1900;
        date_struct->tm_mon = 3; // April is month 3
    } else if (strstr(date_input, "May")) {
        sscanf(date_input, "%s %d, %d", date_input, &date_struct->tm_mday, &date_struct->tm_year);
        date_struct->tm_year -= 1900;
        date_struct->tm_mon = 4; // May is month 4
    } else if (strstr(date_input, "June")) {
        sscanf(date_input, "%s %d, %d", date_input, &date_struct->tm_mday, &date_struct->tm_year);
        date_struct->tm_year -= 1900;
        date_struct->tm_mon = 5; // June is month 5
    } else if (strstr(date_input, "July")) {
        sscanf(date_input, "%s %d, %d", date_input, &date_struct->tm_mday, &date_struct->tm_year);
        date_struct->tm_year -= 1900;
        date_struct->tm_mon = 6; // July is month 6
    } else if (strstr(date_input, "August")) {
        sscanf(date_input, "%s %d, %d", date_input, &date_struct->tm_mday, &date_struct->tm_year);
        date_struct->tm_year -= 1900;
        date_struct->tm_mon = 7; // August is month 7
    } else if (strstr(date_input, "September")) {
        sscanf(date_input, "%s %d, %d", date_input, &date_struct->tm_mday, &date_struct->tm_year);
        date_struct->tm_year -= 1900;
        date_struct->tm_mon = 8; // September is month 8
    } else if (strstr(date_input, "October")) {
        sscanf(date_input, "%s %d, %d", date_input, &date_struct->tm_mday, &date_struct->tm_year);
        date_struct->tm_year -= 1900;
        date_struct->tm_mon = 9; // October is month 9
    } else if (strstr(date_input, "November")) {
        sscanf(date_input, "%s %d, %d", date_input, &date_struct->tm_mday, &date_struct->tm_year);
        date_struct->tm_year -= 1900;
        date_struct->tm_mon = 10; // November is month 10
    } else if (strstr(date_input, "December")) {
        sscanf(date_input, "%s %d, %d", date_input, &date_struct->tm_mday, &date_struct->tm_year);
        date_struct->tm_year -= 1900;
        date_struct->tm_mon = 11; // December is month 11
    } else {
        sscanf(date_input, "%d-%d-%d", &date_struct->tm_year, &date_struct->tm_mon, &date_struct->tm_mday);
        date_struct->tm_year -= 1900; // Adjust year
        date_struct->tm_mon -= 1;      // Adjust month
    }
}

void formatDate(struct tm *date_struct) {
    // Normalize the date structure
    mktime(date_struct);
}

void displayDate(struct tm *date_struct) {
    char buffer[MAX_BUFFER];
    strftime(buffer, sizeof(buffer), "Formatted Date: %A, %B %d, %Y", date_struct);
    printf("%s\n", buffer);
}