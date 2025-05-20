//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: detailed
/*
This program takes a string of dates in natural language format and returns them in Date format.
Example Input: "tomorrow", "next week", "in two weeks"
Example Output: 2021-06-08, 2021-06-15, 2021-06-22
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function declarations
void convert_to_date(char *natural_language_date, char *output_date, int length);
void tomorrow(char *output_date);
void next_week(char *output_date);
void in_two_weeks(char *output_date);

int main(){
    char natural_language_date[20];
    char output_date[12];
    int length;

    printf("Enter the natural language date: ");
    scanf("%s",natural_language_date);

    length = strlen(natural_language_date);

    convert_to_date(natural_language_date,output_date,length);

    printf("The date in YYYY-MM-DD format is: %s\n",output_date);

    return 0;
}

void convert_to_date(char *natural_language_date, char *output_date, int length){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    if(strcmp(natural_language_date,"today")==0){
        sprintf(output_date,"%d-%02d-%02d",(tm.tm_year + 1900), (tm.tm_mon + 1), tm.tm_mday);
    }
    else if(strcmp(natural_language_date,"tomorrow")==0){
        tomorrow(output_date);
    }
    else if(strcmp(natural_language_date,"next week")==0){
        next_week(output_date);
    }
    else if(strcmp(natural_language_date,"in two weeks")==0){
        in_two_weeks(output_date);
    }
}

void tomorrow(char *output_date){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    tm.tm_mday++;

    mktime(&tm);

    sprintf(output_date,"%d-%02d-%02d",(tm.tm_year + 1900), (tm.tm_mon + 1), tm.tm_mday);
}

void next_week(char *output_date){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    tm.tm_mday += 7;

    mktime(&tm);

    sprintf(output_date,"%d-%02d-%02d",(tm.tm_year + 1900), (tm.tm_mon + 1), tm.tm_mday);
}

void in_two_weeks(char *output_date){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    tm.tm_mday += 14;

    mktime(&tm);

    sprintf(output_date,"%d-%02d-%02d",(tm.tm_year + 1900), (tm.tm_mon + 1), tm.tm_mday);
}