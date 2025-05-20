//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: calm
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// function to check if a string is a valid date
int is_valid_date(char date[])
{
    int day, month, year;
    int days_in_month[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if (sscanf(date, "%d/%d/%d", &day, &month, &year) != 3) { // check if format is correct
        return 0;
    }

    // check if month and day are valid
    if (month < 1 || month > 12) {
        return 0;
    }
    if (day < 1 || day > days_in_month[month - 1]) {
        return 0;
    }

    // check if year is valid (between 1900 and 2099)
    if (year < 1900 || year > 2099) {
        return 0;
    }

    return 1; // if all checks pass, return 1 (true)
}

// function to convert date string to ISO format (YYYY-MM-DD)
void date_to_iso(char date[], char iso[]) 
{
    int day, month, year;

    sscanf(date, "%d/%d/%d", &day, &month, &year);

    sprintf(iso, "%04d-%02d-%02d", year, month, day); // format as ISO
}

int main()
{
    char date[11]; // array to hold date string
    char iso[11]; // array to hold ISO formatted date

    printf("Enter date in format DD/MM/YYYY: ");
    fgets(date, sizeof(date), stdin); // get date input from user

    if (!is_valid_date(date)) { // check if date is valid
        printf("Invalid date");
        return 1;
    }

    date_to_iso(date, iso); // convert date to ISO format

    printf("Equivalent ISO formatted date: %s", iso);

    return 0;
}