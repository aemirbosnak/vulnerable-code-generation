//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
//structure for storing date information
typedef struct
{
    int day;
    int month;
    int year;
} Date;

//function to validate the date entered by the user
int isValidDate(Date* date)
{
    if (date->year < 1 || date->year > 9999)
        return 0;
    if (date->month < 1 || date->month > 12)
        return 0;
    if (date->day < 1 || date->day > 31)
        return 0;
    if (date->month == 2)
    {
        if (date->year % 4 == 0)
        {
            if (date->day > 29)
                return 0;
        }
        else
        {
            if (date->day > 28)
                return 0;
        }
    }
    if (date->month == 4 || date->month == 6 || date->month == 9 || date->month == 11)
    {
        if (date->day > 30)
            return 0;
    }
    return 1;
}

//function to convert standard date to natural language date
void convertToNaturalLanguageDate(Date* date)
{
    //arrays containing natural langauge representation of months and days
    char* months[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
    char* days[] = { "first", "second", "third", "fourth", "fifth", "sixth", "seventh", "eighth", "ninth", "tenth", "eleventh", "twelfth", "thirteenth", "fourteenth", "fifteenth", "sixteenth", "seventeenth", "eighteenth", "nineteenth", "twentieth", "twenty-first", "twenty-second", "twenty-third", "twenty-fourth", "twenty-fifth", "twenty-sixth", "twenty-seventh", "twenty-eighth", "twenty-ninth", "thirtieth", "thirty-first" };
    //get the day, month and year from the date entered by the user
    int day = date->day;
    int month = date->month;
    int year = date->year;
    //display the natural language representation of the date
    printf("The date in natural language is:\n");
    printf("%s %s, %d", days[day-1], months[month-1], year);
}

int main()
{
    Date date;
    //get the date from the user
    printf("Enter the day (1-31): ");
    scanf("%d", &date.day);
    printf("Enter the month (1-12): ");
    scanf("%d", &date.month);
    printf("Enter the year (1-9999): ");
    scanf("%d", &date.year);
    //validate the date entered by the user
    if (!isValidDate(&date))
    {
        printf("Invalid date entered. Please enter a valid date.\n");
        return 0;
    }
    //convert standard date to natural language date and display it
    convertToNaturalLanguageDate(&date);
    return 0;
}