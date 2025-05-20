//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: ephemeral
//Welcome to the Natural Language Date Converter!
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void clean_stdin(void); //function prototype for cleaning input buffer

int main() {

    //greetings
    printf("Welcome to the Natural Language Date Converter!\n\nPlease enter a date in natural language, such as 'January 1st 2022':\n");

    //getting input from user
    char input[50];
    fgets(input, 50, stdin);
    clean_stdin(); //cleaning input buffer

    //extracting input into month, day, and year
    char month[10], day[3], year[5];
    sscanf(input, "%s %s %s", month, day, year);
 
    //creating tm struct for storing the date
    struct tm date = {0};

    //converting month to integer value
    if (strcmp(month, "January") == 0)
        date.tm_mon = 0;
    else if (strcmp(month, "February") == 0)
        date.tm_mon = 1;
    else if (strcmp(month, "March") == 0)
        date.tm_mon = 2;
    else if (strcmp(month, "April") == 0)
        date.tm_mon = 3;
    else if (strcmp(month, "May") == 0)
        date.tm_mon = 4;
    else if (strcmp(month, "June") == 0)
        date.tm_mon = 5;
    else if (strcmp(month, "July") == 0)
        date.tm_mon = 6;
    else if (strcmp(month, "August") == 0)
        date.tm_mon = 7;
    else if (strcmp(month, "September") == 0)
        date.tm_mon = 8;
    else if (strcmp(month, "October") == 0)
        date.tm_mon = 9;
    else if (strcmp(month, "November") == 0)
        date.tm_mon = 10;
    else if (strcmp(month, "December") == 0)
        date.tm_mon = 11;

    //converting day to integer value
    date.tm_mday = atoi(day);

    //converting year to integer value
    date.tm_year = atoi(year) - 1900;

    //converting tm struct to time_t
    time_t converted_time = mktime(&date);

    //converting time_t to tm struct in UTC
    struct tm *utc_date = gmtime(&converted_time);

    //printing results
    printf("\nThe date you entered is: %s", asctime(&date));
    printf("In UTC time, that is: %s", asctime(utc_date));

    return 0;
}

void clean_stdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}