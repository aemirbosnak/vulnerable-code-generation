//Falcon2-11B DATASET v1.0 Category: Natural Language Date Converter ; Style: creative
#include <stdio.h>
#include <string.h>
#include <time.h>

// Function to convert natural language date to calendar date
void convertDate(char* dateString, time_t* calendarDate) {
    char* dayOfWeek[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    char* monthName[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int monthIndex = 0;
    int year = 0;

    strcpy(dateString, dateString); // Remove whitespace from date string
    if (strlen(dateString) >= 4) {
        strncpy(dateString, dateString + 4, strlen(dateString) - 4); // Remove day of the week from date string
    }

    if (strlen(dateString) >= 7) {
        strncpy(dateString, dateString + 7, strlen(dateString) - 7); // Remove month from date string
    }

    if (dateString[0] == '0' && dateString[1] == '0' && dateString[2] == '0' && dateString[3] == '0') {
        dateString[0] = dateString[1] = dateString[2] = dateString[3] = '1'; // If date is 00, replace with 01
    }

    if (dateString[1] == '0') {
        dateString[1] = '1'; // If month is 0, replace with 1
    }

    if (dateString[4] == '0') {
        dateString[4] = '1'; // If day is 0, replace with 1
    }

    sscanf(dateString, "%d-%s-%d", &year, monthName + monthIndex, &calendarDate);
    monthIndex++;
    if (monthIndex > 12) {
        monthIndex = 1;
    }

    *calendarDate = mktime(localtime(&(calendarDate)));
}

int main() {
    time_t calendarDate;
    char dateString[30];

    printf("Enter a date in natural language format (e.g. March 15, 2021): ");
    fgets(dateString, sizeof(dateString), stdin);
    dateString[strcspn(dateString, "\n")] = 0; // Remove newline character from input string

    convertDate(dateString, &calendarDate);
    printf("The corresponding calendar date is: %s\n", asctime(localtime(&calendarDate)));

    return 0;
}