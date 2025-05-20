//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: intelligent
#include <stdio.h>
#include <string.h>

int main()
{
    char date[11];
    int year, month, day;
    printf("Please enter a date in the format of mm/dd/yyyy: ");
    fgets(date, sizeof(date), stdin);

    // Extract year, month, and day from the input date
    sscanf(date, "%d/%d/%d", &month, &day, &year);

    // check if the input date is valid or not
    if (year < 1 || year > 9999 || month < 1 || month > 12 || day < 1 || day > 31)
    {
        printf("Invalid input date!\n");
        return 0;
    }

    // Determine the date suffix
    char suffix[3];
    switch (day)
    {
        case 1:
        case 21:
        case 31:
            strcpy(suffix, "st");
            break;
        case 2:
        case 22:
            strcpy(suffix, "nd");
            break;
        case 3:
        case 23:
            strcpy(suffix, "rd");
            break;
        default:
            strcpy(suffix, "th");
            break;
    }

    // Create the month name array for lookup
    const char *monthNames[] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    // Convert the month number to a month name
    char monthName[10];
    strcpy(monthName, monthNames[month]);

    // Print the formatted output
    printf("The date you entered is: %s %d%s, %d\n", monthName, day, suffix, year);

    return 0;
}