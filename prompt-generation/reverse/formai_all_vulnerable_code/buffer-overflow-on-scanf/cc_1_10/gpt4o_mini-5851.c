//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to convert date to natural language
void convertDateToWords(int day, int month, int year, char *result) {
    char *months[] = {"January", "February", "March", "April", "May", "June", 
                      "July", "August", "September", "October", "November", "December"};
    char *suffix[] = {"th", "st", "nd", "rd"};

    // Determine the suffix for the day
    int sIndex = 0;
    if (day % 10 < 4 && day % 100 != 11 && day % 100 != 12 && day % 100 != 13) {
        sIndex = day % 10;
    } else {
        sIndex = 0;
    }

    // Format the result in natural language
    sprintf(result, "%s the %d%s, in the year of our Lord %d", 
            months[month - 1], day, suffix[sIndex], year);
}

// Function to validate the date
int isValidDate(int day, int month, int year) {
    if (year < 1583) return 0; // Gregorian calendar started in 1582
    if (month < 1 || month > 12) return 0;
    if (day < 1 || day > 31) return 0;

    // Check for February
    if (month == 2) {
        int leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        return day <= (leap ? 29 : 28);
    }

    // Check for months with 30 days
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return day <= 30;
    }

    return 1; // Valid date
}

int main() {
    int day, month, year;
    char result[100];

    // Enter the date through the imprints of love
    printf("Oh, fair youth, speak thine day: ");
    scanf("%d", &day);
    printf("And in which month dost thou seek? ");
    scanf("%d", &month);
    printf("In which year doth this love bloom? ");
    scanf("%d", &year);

    // Validate the date with the precision of Cupid
    if (!isValidDate(day, month, year)) {
        printf("Alas! The date thou entered is not valid. Seek ye the heavens to correct it.\n");
        return 1;
    }

    // Convert the date to sweet words
    convertDateToWords(day, month, year, result);

    // Declare the result of the transformation
    printf("Lo! The sweet date in words is: %s\n", result);
    printf("Thus concludes our sonnet of time, a tale in natural language divine.\n");

    return 0;
}