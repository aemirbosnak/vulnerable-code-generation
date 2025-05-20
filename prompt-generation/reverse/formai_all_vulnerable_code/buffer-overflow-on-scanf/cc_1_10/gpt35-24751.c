//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct date {
       int d;
       int m;
       int y;
       int dateStamp;
};

//function to convert date to datestamp
int date_to_datestamp(int d, int m, int y) {
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int totalDays=0, i;

    for(i=1; i<m; i++)
        totalDays += daysInMonth[i];

    totalDays += d;
    if(m > 2 && y%4==0 && (y%100!=0 || y%400==0))
        totalDays++;

    return totalDays;
}

//function to convert datestamp to date
void datestamp_to_date(int dateStamp, struct date *d) {
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int i;

    if(d->y%4==0 && (d->y%100!=0 || d->y%400==0))
        daysInMonth[2] = 29;

    for(i=1; i<=12; i++) {
        if(dateStamp <= daysInMonth[i]) {
            d->d = dateStamp;
            d->m = i;
            break;
        }

        dateStamp -= daysInMonth[i];

        if(i==2 && d->y%4==0 && (d->y%100!=0 || d->y%400==0))
            dateStamp--;
    }
}

void main() {
    struct date d;

    printf("Enter date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &d.d, &d.m, &d.y);

    d.dateStamp = date_to_datestamp(d.d, d.m, d.y);

    printf("Datestamp: %d\n", d.dateStamp);

    datestamp_to_date(d.dateStamp, &d);

    printf("Date: %d/%d/%d\n", d.d, d.m, d.y);
}