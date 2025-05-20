//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
int isLeapYear(int year);
int getMonthDays(int month, int year);
void convertToWord(int num, char *str);

// Main function
int main()
{
    char input[30], dayStr[10], monthStr[15], yearStr[5];
    int day, month, year, days, i, j;

    printf("Enter the date in the format dd/mm/yyyy: ");
    scanf("%s", input);

    // Extracting day, month and year from input string
    for(i = 0; input[i] != '/'; i++)
    {
        dayStr[i] = input[i];
    }
    dayStr[i] = '\0';

    for(j = 0, i++; input[i] != '/'; i++, j++)
    {
        monthStr[j] = input[i];
    }
    monthStr[j] = '\0';

    for(j = 0, i++; input[i] != '\0'; i++, j++)
    {
        yearStr[j] = input[i];
    }
    yearStr[j] = '\0';

    // Converting day, month and year strings to integers
    day = atoi(dayStr);
    month = atoi(monthStr);
    year = atoi(yearStr);

    days = 0;

    // Calculating total number of days up to the current date
    for(i = 1; i < month; i++)
    {
        days += getMonthDays(i, year);
    }

    days += day;

    // Checking if the current year is a leap year and the month is February
    if(isLeapYear(year) && month > 2)
    {
        days++;
    }

    // Converting total number of days to words
    char daysWord[200] = "";
    char temp[20];

    if(days >= 100)
    {
        int hundreds = days / 100;
        days %= 100;
        sprintf(temp, "%d hundred ", hundreds);
        strcat(daysWord, temp);
    }

    if(days >= 20)
    {
        int tens = days / 10;
        days %= 10;

        switch(tens)
        {
        case 2:
            strcat(daysWord, "twenty ");
            break;
        case 3:
            strcat(daysWord, "thirty ");
            break;
        case 4:
            strcat(daysWord, "forty ");
            break;
        case 5:
            strcat(daysWord, "fifty ");
            break;
        case 6:
            strcat(daysWord, "sixty ");
            break;
        case 7:
            strcat(daysWord, "seventy ");
            break;
        case 8:
            strcat(daysWord, "eighty ");
            break;
        case 9:
            strcat(daysWord, "ninety ");
            break;
        }

        if(days > 0)
        {
            sprintf(temp, "%d ", days);
            strcat(daysWord, temp);
        }
    }
    else if(days > 0)
    {
        switch(days)
        {
        case 1:
            strcat(daysWord, "one ");
            break;
        case 2:
            strcat(daysWord, "two ");
            break;
        case 3:
            strcat(daysWord, "three ");
            break;
        case 4:
            strcat(daysWord, "four ");
            break;
        case 5:
            strcat(daysWord, "five ");
            break;
        case 6:
            strcat(daysWord, "six ");
            break;
        case 7:
            strcat(daysWord, "seven ");
            break;
        case 8:
            strcat(daysWord, "eight ");
            break;
        case 9:
            strcat(daysWord, "nine ");
            break;
        }
    }

    if(daysWord[strlen(daysWord) - 1] == ' ')
    {
        daysWord[strlen(daysWord) - 1] = '\0';
    }

    strcat(daysWord, " day of ");

    // Converting month to words
    switch(month)
    {
    case 1:
        strcat(daysWord, "January");
        break;
    case 2:
        strcat(daysWord, "February");
        break;
    case 3:
        strcat(daysWord, "March");
        break;
    case 4:
        strcat(daysWord, "April");
        break;
    case 5:
        strcat(daysWord, "May");
        break;
    case 6:
        strcat(daysWord, "June");
        break;
    case 7:
        strcat(daysWord, "July");
        break;
    case 8:
        strcat(daysWord, "August");
        break;
    case 9:
        strcat(daysWord, "September");
        break;
    case 10:
        strcat(daysWord, "October");
        break;
    case 11:
        strcat(daysWord, "November");
        break;
    case 12:
        strcat(daysWord, "December");
        break;
    }

    strcat(daysWord, ", ");

    // Converting year to words
    char yearWord[20] = "";
    convertToWord(year, yearWord);

    strcat(daysWord, yearWord);

    printf("The date in words is: %s", daysWord);

    return 0;
}

// Function to check if a year is a leap year
int isLeapYear(int year)
{
    if(year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Function to get the number of days in a given month of a given year
int getMonthDays(int month, int year)
{
    int days;

    switch(month)
    {
    case 2:
        if(isLeapYear(year))
        {
            days = 29;
        }
        else
        {
            days = 28;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        days = 30;
        break;
    default:
        days = 31;
        break;
    }

    return days;
}

// Function to convert a number to words
void convertToWord(int num, char *str)
{
    char ones[11][10] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    char tens[10][10] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

    if(num > 999)
    {
        sprintf(str, "Invalid year!");
        return;
    }

    // Converting hundreds digit to words
    if(num >= 100)
    {
        sprintf(str, "%s hundred", ones[num/100]);
        num %= 100;

        if(num > 0)
        {
            strcat(str, " ");
        }
    }

    // Converting tens digit to words
    if(num >= 20)
    {
        strcat(str, tens[num/10]);
        num %= 10;

        if(num > 0)
        {
            strcat(str, " ");
        }
    }

    // Converting ones digit to words
    if(num > 0)
    {
        strcat(str, ones[num]);
    }
}