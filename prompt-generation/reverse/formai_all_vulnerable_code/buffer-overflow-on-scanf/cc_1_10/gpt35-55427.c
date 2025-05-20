//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

typedef struct Date {
    int year;
    int month;
    int day;
} Date;

void printDate(Date date);
Date convertToEnglish(char *date);
Date convertToFrench(char *date);

int main() {
    char date[20];
    Date eng_date, fr_date;

    printf("Enter a date (dd/mm/yyyy): ");
    scanf("%s", date);

    eng_date = convertToEnglish(date);
    fr_date = convertToFrench(date);
    
    printf("\nDate in English: ");
    printDate(eng_date);
    
    printf("Date in French: ");
    printDate(fr_date);

    return 0;
}

// Function to print date in the format dd/mm/yyyy
void printDate(Date date) {
    printf("%02d/%02d/%d\n", date.day, date.month, date.year);
}

// Function to convert a date in dd/mm/yyyy format to English (mm/dd/yyyy) format
Date convertToEnglish(char *date) {
    Date eng;
    char *day, *month, *year;
    int i;

    // Separate the day, month and year components of the date string
    day = strtok(date, "/");
    month = strtok(NULL, "/");
    year = strtok(NULL, "\0");

    // Convert each component to an integer
    eng.day = atoi(day);
    eng.month = atoi(month);
    eng.year = atoi(year);

    // Swap the day and month to convert to English format
    i = eng.day;
    eng.day = eng.month;
    eng.month = i;

    return eng;
}

// Function to convert a date in dd/mm/yyyy format to French (yyyy/mm/dd) format
Date convertToFrench(char *date) {
    Date fr;
    char *day, *month, *year;

    // Separate the day, month and year components of the date string
    day = strtok(date, "/");
    month = strtok(NULL, "/");
    year = strtok(NULL, "\0");

    // Convert each component to an integer
    fr.day = atoi(day);
    fr.month = atoi(month);
    fr.year = atoi(year);

    // Swap the day and year to convert to French format
    int i = fr.year;
    fr.year = fr.day;
    fr.day = i;

    return fr;
}