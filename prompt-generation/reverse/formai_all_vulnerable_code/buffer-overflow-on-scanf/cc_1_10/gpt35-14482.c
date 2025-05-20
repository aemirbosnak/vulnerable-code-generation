//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: brave
#include <stdio.h>
#include <string.h>

// Function to convert a string to uppercase
void toUpperCase(char *str) {
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
        i++;
    }
}

// Function to convert a month string to a month number
int convertMonth(char *month) {
    toUpperCase(month);

    if (strcmp(month, "JANUARY") == 0)
        return 1;
    else if (strcmp(month, "FEBRUARY") == 0)
        return 2;
    else if (strcmp(month, "MARCH") == 0)
        return 3;
    else if (strcmp(month, "APRIL") == 0)
        return 4;
    else if (strcmp(month, "MAY") == 0)
        return 5;
    else if (strcmp(month, "JUNE") == 0)
        return 6;
    else if (strcmp(month, "JULY") == 0)
        return 7;
    else if (strcmp(month, "AUGUST") == 0)
        return 8;
    else if (strcmp(month, "SEPTEMBER") == 0)
        return 9;
    else if (strcmp(month, "OCTOBER") == 0)
        return 10;
    else if (strcmp(month, "NOVEMBER") == 0)
        return 11;
    else if (strcmp(month, "DECEMBER") == 0)
        return 12;
    else
        return 0;
}

// Function to convert a date string to a date number
int convertDate(char *date) {
    int i = 0, num = 0;

    while (date[i] != '\0') {
        if (date[i] >= '0' && date[i] <= '9')
            num = (num * 10) + (date[i] - '0');
        i++;
    }

    return num;
}

// Function to convert a string to a year number
int convertYear(char *year) {
    int i = 0, num = 0;

    while (year[i] != '\0') {
        if (year[i] >= '0' && year[i] <= '9')
            num = (num * 10) + (year[i] - '0');
        i++;
    }

    return num;
}

int main() {
    char date[20], month[20], year[20];
    int monthNum, dateNum, yearNum;

    // Get input from user
    printf("Enter a date in the following format: Month Date, Year\n");
    scanf("%s %d, %s", month, &dateNum, year);

    // Convert month string to month number
    monthNum = convertMonth(month);

    // Convert year string to year number
    yearNum = convertYear(year);

    // Print original date in YYYY-MM-DD format
    printf("Original Date: %04d-%02d-%02d\n", yearNum, monthNum, dateNum);

    // Convert date, month, and year to C Natural Language Date format
    switch (monthNum) {
        case 1:
            strcpy(month, "January");
            break;
        case 2:
            strcpy(month, "February");
            break;
        case 3:
            strcpy(month, "March");
            break;
        case 4:
            strcpy(month, "April");
            break;
        case 5:
            strcpy(month, "May");
            break;
        case 6:
            strcpy(month, "June");
            break;
        case 7:
            strcpy(month, "July");
            break;
        case 8:
            strcpy(month, "August");
            break;
        case 9:
            strcpy(month, "September");
            break;
        case 10:
            strcpy(month, "October");
            break;
        case 11:
            strcpy(month, "November");
            break;
        case 12:
            strcpy(month, "December");
            break;
        default:
            printf("Invalid month\n");
            return 0;
    }

    // Print date in C Natural Language format
    printf("C Natural Language Date: %s %d, %d\n", month, dateNum, yearNum);

    return 0;
}