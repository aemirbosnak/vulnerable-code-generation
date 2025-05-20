//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: visionary
#include <stdio.h>
#include <string.h>

// function to convert input date to local date format
void convertDate(char date[10]) {
    int year, month, day;
    char monthName[10];

    // split the date into year, month and day
    sscanf(date, "%d-%d-%d", &year, &month, &day);

    // convert month number to month name
    switch (month) {
        case 1:
            strcpy(monthName, "January");
            break;
        case 2:
            strcpy(monthName, "February");
            break;
        case 3:
            strcpy(monthName, "March");
            break;
        case 4:
            strcpy(monthName, "April");
            break;
        case 5:
            strcpy(monthName, "May");
            break;
        case 6:
            strcpy(monthName, "June");
            break;
        case 7:
            strcpy(monthName, "July");
            break;
        case 8:
            strcpy(monthName, "August");
            break;
        case 9:
            strcpy(monthName, "September");
            break;
        case 10:
            strcpy(monthName, "October");
            break;
        case 11:
            strcpy(monthName, "November");
            break;
        case 12:
            strcpy(monthName, "December");
            break;
        default:
            printf("Invalid month\n");
            return;
    }

    // print the date in local format
    printf("%s %d, %d", monthName, day, year);

}

int main() {
    char inputDate[10];

    // get input date from user
    printf("Enter date in yyyy-mm-dd format: ");
    scanf("%s", inputDate);

    // call the convertDate() function to convert date to local format
    convertDate(inputDate);

    return 0;
}