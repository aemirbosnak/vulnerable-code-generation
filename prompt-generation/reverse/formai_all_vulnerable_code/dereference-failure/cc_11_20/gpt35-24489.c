//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int check_leap_year(int year)
{
    if((year%4==0 && year%100!=0) || year%400==0) return 1;
    else return 0;
}

int to_date(char* input_date)
{
    int day, month, year;
    char* month_name;

    sscanf(input_date, "%d %s %d", &day, month_name, &year);

    if(strcmp(month_name, "Yanuary")==0) month = 1;
    else if(strcmp(month_name, "Feberuary")==0) month = 2;
    else if(strcmp(month_name, "March")==0) month = 3;
    else if(strcmp(month_name, "April")==0) month = 4;
    else if(strcmp(month_name, "May")==0) month = 5;
    else if(strcmp(month_name, "June")==0) month = 6;
    else if(strcmp(month_name, "July")==0) month = 7;
    else if(strcmp(month_name, "August")==0) month = 8;
    else if(strcmp(month_name, "September")==0) month = 9;
    else if(strcmp(month_name, "October")==0) month = 10;
    else if(strcmp(month_name, "November")==0) month = 11;
    else if(strcmp(month_name, "December")==0) month = 12;

    int is_leap_year = check_leap_year(year);

    if(month == 2)
    {
        if(is_leap_year && (day > 29))
        {
            return 0;
        }
        else if(!is_leap_year && (day > 28))
        {
            return 0;
        }
    }
    else if(month == 4 || month == 6 || month == 9 || month == 11)
    {
        if(day > 30)
        {
            return 0;
        }
    }

    if(year < 1900 || year > 2100) return 0;

    int total_days = 0;
    for(int i=1900;i<year;i++)
    {
        if(check_leap_year(i)) total_days += 366;
        else total_days += 365;
    }

    for(int i=1;i<month;i++)
    {
        if(i==2) 
        {
            if(is_leap_year) total_days += 29;
            else total_days += 28;
        }
        else if(i==4 || i==6 || i==9 || i==11) total_days += 30;
        else total_days += 31;
    }

    total_days += day - 1;

    return total_days;
}

char* to_words(int date)
{
    int year = 1900, month = 1, day = 1;

    while(date > 0)
    {
        if(check_leap_year(year)) date -= 366;
        else date -= 365;
        year++;
    }

    year--;

    while(date > 0)
    {
        int days_in_month;
        if(month == 2)
        {
            if(check_leap_year(year)) days_in_month = 29;
            else days_in_month = 28;
        }
        else if(month == 4 || month == 6 || month == 9 || month == 11) days_in_month = 30;
        else days_in_month = 31;
        date -= days_in_month;
        month++;
    }

    month--;

    day += date;

    char* month_name = malloc(sizeof(char)*10);

    switch (month)
    {
        case 1:
            strcpy(month_name, "Yanuary");
            break;
        case 2:
            strcpy(month_name, "Feberuary");
            break;
        case 3:
            strcpy(month_name, "March");
            break;
        case 4:
            strcpy(month_name, "April");
            break;
        case 5:
            strcpy(month_name, "May");
            break;
        case 6:
            strcpy(month_name, "June");
            break;
        case 7:
            strcpy(month_name, "July");
            break;
        case 8:
            strcpy(month_name, "August");
            break;
        case 9:
            strcpy(month_name, "September");
            break;
        case 10:
            strcpy(month_name, "October");
            break;
        case 11:
            strcpy(month_name, "November");
            break;
        case 12:
            strcpy(month_name, "December");
            break;
        default:
            break;
    }

    char* result = malloc(sizeof(char)*20);

    sprintf(result, "%d %s %d", day, month_name, year);

    return result;
}

int main()
{
    char input_date[20];

    printf("Enter a Cyberpunk style date (e.g. 3 June 2077):\n");
    fgets(input_date, 20, stdin);

    int date = to_date(input_date); 

    if(date == 0)
    {
        printf("Invalid input\n");
        return 1;
    }

    printf("Date in days since 1st January 1900: %d\n", date);

    char* words = to_words(date); 

    printf("Converted back to words: %s\n", words); 

    free(words);

    return 0;
}