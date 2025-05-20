//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    //Initializing variables
    char date[12];
    char day[3];
    char month[3];
    char year[5];
    int n, m, yearInt;
    const int JAN = 1, FEB = 2, MAR = 3, APR = 4, MAY = 5, JUN = 6, JUL = 7, AUG = 8, SEP = 9, OCT = 10, NOV = 11, DEC = 12;
    const int MAX_DAYS = 31;
    const int MIN_YEAR = 1583; 

    //Getting user input
    printf("Enter date in the format of (dd/mm/yyyy): ");
    scanf("%s", date);

    //Tokenizing the input by '/' delimiter
    char *split = strtok(date, "/");
    int count = 0;
    while (split != NULL)
    {
        if (count == 0)
        {
            strcpy(day, split);
        }
        else if (count == 1)
        {
            strcpy(month, split);
        }
        else if (count == 2)
        {
            strcpy(year, split);
        }

        split = strtok(NULL, "/");
        count++;
    }

    //Converting strings to integers
    n = atoi(day);
    m = atoi(month);
    yearInt = atoi(year);

    //Checking for valid date inputs
    if (n < 1 || n > MAX_DAYS || m < JAN || m > DEC || yearInt < MIN_YEAR)
    {
        printf("Invalid date input\n");
        return 0;
    }

    //Identifying the number of days in the input month
    int maxDaysInMonth = 0;
    if (m == APR || m == JUN || m == SEP || m == NOV)
        maxDaysInMonth = 30;
    else if (m == FEB)
    {
        if ((yearInt % 4 == 0 && yearInt % 100 != 0) || (yearInt % 400 == 0))
            maxDaysInMonth = 29;
        else
            maxDaysInMonth = 28;
    }
    else
        maxDaysInMonth = MAX_DAYS;

    //Checking if the input day is within the max days in the input month
    if (n > maxDaysInMonth)
    {
        printf("Invalid date input\n");
        return 0;
    }

    //Calculating the day of the week for the given date using Zeller's congruence algorithm
    int monthMap[] = { 0,3,3,6,1,4,6,2,5,0,3,5 };
    int yearMap[] = { 6,4,2,0 };
    int dayNum = (n + monthMap[m - 1] + (yearInt - MIN_YEAR) + (yearInt - MIN_YEAR) / 4 + yearMap[(yearInt - MIN_YEAR) % 4]) % 7;

    //Displaying the output to the user
    char *dayString;
    switch (dayNum)
    {
    case 0:
        dayString = "Saturday";
        break;
    case 1:
        dayString = "Sunday";
        break;
    case 2:
        dayString = "Monday";
        break;
    case 3:
        dayString = "Tuesday";
        break;
    case 4:
        dayString = "Wednesday";
        break;
    case 5:
        dayString = "Thursday";
        break;
    case 6:
        dayString = "Friday";
        break;
    }
    printf("The date %s falls on a %s\n", date, dayString);

    return 0;
}