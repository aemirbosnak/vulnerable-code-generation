//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: genious
#include <stdio.h>
#include <string.h>

typedef struct date {
    int day;
    int month;
    int year;
} Date;

// Function to get the number of days in a given month of a given year
int getDaysInMonth(int month, int year) {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(month == 2 && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)) {
        return 29;
    }
    return daysInMonth[month - 1];
}

// Function to convert a date from string to date struct
Date toDate(char datestr[]) {
    Date date;
    sscanf(datestr, "%d-%d-%d", &date.day, &date.month, &date.year);
    return date;
}

// Function to convert a date from date struct to string
char* toString(Date date) {
    static char datestr[11];
    sprintf(datestr, "%02d-%02d-%04d", date.day, date.month, date.year);
    return datestr;
}

// Function to add a number of days to a given date
void addDays(Date *date, int days) {
    while(days > 0) {
        int daysInMonth = getDaysInMonth(date->month, date->year);
        if(date->day + days <= daysInMonth) {
            date->day += days;
            days = 0;
            break;
        }
        days -= daysInMonth - date->day + 1;
        date->day = 1;
        if(date->month == 12) {
            date->year++;
            date->month = 1;
        } else {
            date->month++;
        }
    }
}

int main() {
    char datestr[11];
    printf("Enter a date in the format dd-mm-yyyy: ");
    scanf("%s", datestr);
    Date date = toDate(datestr);
    
    int daysToAdd;
    printf("Enter the number of days to add: ");
    scanf("%d", &daysToAdd);
    
    addDays(&date, daysToAdd);
    
    printf("The new date is: %s", toString(date));
    
    return 0;
}