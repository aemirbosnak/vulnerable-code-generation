//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to convert the date to Julian Day
int julianDay(int d, int m, int y){
    int a = (14 - m) / 12;
    int y1 = y + 4800 - a;
    int m1 = m + 12 * a - 3;

    int j = d + (153 * m1 + 2) / 5 
            + y1 * 365 + y1 / 4 - y1 / 100 
            + y1 / 400 - 32045;

    return j;

}

// function to convert Julian Day to Gregorian date
void gregorianCalendar(int j, int *d, int *m, int *y){
    int l = j + 68569;
    int n = 4 * l / 146097;
    l = l - (146097 * n + 3) / 4;
    int i = 4000 * (l + 1) / 1461001;
    l = l - 1461 * i / 4 + 31;
    int j1 = 80 * l / 2447;
    *d = l - 2447 * j1 / 80;
    l = j1 / 11;
    *m = j1 + 2 - 12 * l;
    *y = 100 * (n - 49) + i + l;
}

// function to convert a date string to Julian Day
int dateToJulianDay(char *dateString){
    char *token;
    int d, m, y;

    token = strtok(dateString, "/");
    d = atoi(token);

    token  = strtok(NULL, "/");
    m = atoi(token);

    token = strtok(NULL, "/");
    y = atoi(token);

    int julian_day = julianDay(d, m, y);

    return julian_day;
}

// function to convert Julian Day to a date string
char *julianDayToDate(int julian_day){
    int d, m, y;
    char *dateString = (char*)malloc(sizeof(char)*15);

    gregorianCalendar(julian_day, &d, &m, &y);

    sprintf(dateString, "%d/%d/%d", d, m, y);

    return dateString;
}

int main(){
    char *dateString = (char*)malloc(sizeof(char)*15);
    printf("Enter date in format DD/MM/YYYY: ");
    scanf("%s", dateString);

    int julian_day = dateToJulianDay(dateString);

    char *convertedDate = julianDayToDate(julian_day);

    printf("The converted date is: %s\n", convertedDate);

    free(dateString);
    free(convertedDate);

    return 0;
}