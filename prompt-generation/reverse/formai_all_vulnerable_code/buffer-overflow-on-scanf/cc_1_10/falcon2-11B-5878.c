//Falcon2-11B DATASET v1.0 Category: Natural Language Date Converter ; Style: rigorous
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// Function to convert Natural Language date to Gregorian Calendar date
void convert_date(char *nldate) {
    // Get the date components from the Natural Language date string
    char month[3], day[3], year[3];
    strcpy(month, &nldate[3]);
    strcpy(day, &nldate[6]);
    strcpy(year, &nldate[9]);
    
    // Convert the month, day and year components to integers
    int m, d, y;
    m = atoi(month);
    d = atoi(day);
    y = atoi(year);
    
    // Check if the month is valid
    if (m < 1 || m > 12) {
        printf("Invalid month.\n");
        return;
    }
    
    // Check if the day is valid
    if (d < 1 || d > 31) {
        printf("Invalid day.\n");
        return;
    }
    
    // Check if the year is valid
    if (y < 1) {
        printf("Invalid year.\n");
        return;
    }
    
    // Calculate the day of the week
    int dow = (m + 1) % 12 + 1; // day of week for January 1st of the year
    
    // Calculate the number of days in the month
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int month_days = days[m - 1];
    
    // Adjust the year for leap years
    if (y % 4 == 0) {
        if (y % 100 == 0) {
            if (y % 400 == 0) {
                month_days++;
            }
        }
    }
    
    // Adjust the day for leap years
    if (m == 2 && (y % 4 == 0 && (y % 100!= 0 || y % 400 == 0))) {
        d++;
    }
    
    // Calculate the day of the year
    int day_of_year = d + ((dow - 1) * month_days);
    
    // Print the Gregorian Calendar date
    printf("Gregorian Calendar date: %d/%d/%d\n", day_of_year, m, y);
}

// Main function
int main() {
    char nldate[50];
    printf("Enter a Natural Language date (e.g. 'September 30, 2022'): ");
    scanf("%s", nldate);
    
    // Convert the Natural Language date to Gregorian Calendar date
    convert_date(nldate);
    
    return 0;
}