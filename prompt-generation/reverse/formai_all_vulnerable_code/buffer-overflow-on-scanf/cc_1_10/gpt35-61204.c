//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: recursive
#include<stdio.h>

int getMonthDays(int month, int year) {
    switch(month) {
        case 1:
            return 31;
        case 2:
            if(year%4==0 && (year%100!=0 || year%400==0))
                return 29;
            else
                return 28;
        case 3:
            return 31;
        case 4:
            return 30;
        case 5:
            return 31;
        case 6:
            return 30;
        case 7:
            return 31;
        case 8:
            return 31;
        case 9:
            return 30;
        case 10:
            return 31;
        case 11:
            return 30;
        case 12:
            return 31;
    }
}

void incrementDay(int *day, int *month, int *year) {
    if(*day == getMonthDays(*month, *year)) {
        *day = 1;
        (*month)++;
        if(*month == 13) {
            *month = 1;
            (*year)++;
        }
    }
    else {
        (*day)++;
    }
}

void decrementDay(int *day, int *month, int *year) {
    if(*day == 1) {
        (*month)--;
        if(*month == 0) {
            (*year)--;
            *month = 12;
        }
        *day = getMonthDays(*month, *year);
    }
    else {
        (*day)--;
    }
}

void convertToDate(long days, int *day, int *month, int *year) {
    int daysInYear = 365;
    *day = 1;

    while(days > daysInYear) {
        if((*year)%4==0 && ((*year)%100!=0 || (*year)%400==0)) {
            days--;
            if(days == 0) {
                break;
            }
        }
        days -= daysInYear;
        (*year)++;
        daysInYear = ((*year)%4==0 && ((*year)%100!=0 || (*year)%400==0)) ? 366 : 365;
    }

    int m = 1;
    while(days > getMonthDays(m, *year)) {
        if(m == 2 && (*year)%4==0 && ((*year)%100!=0 || (*year)%400==0)) {
            days--;
            if(days == 0) {
                break;
            }
        }
        days -= getMonthDays(m, *year);
        m++;
    }
    *day = (int)days;
    *month = m;
}

long convertFromDate(int day, int month, int year) {
    long days = 0;

    for(int y=1; y<year; y++) {
        days += (y%4==0 && (y%100!=0 || y%400==0)) ? 366 : 365;
    }

    for(int m=1; m<month; m++) {
        days += getMonthDays(m, year);
    }

    days += day;

    return days;
}

void printDate(int day, int month, int year) {
    printf("%d-%d-%d\n", day, month, year);
}

int main() {
    int day, month, year, input;
    printf("Enter date in this format: ddmmyyyy\n");
    scanf("%d", &input);

    day = input % 100;
    input /= 100;
    month = input % 100;
    year = input / 100;

    printf("Original date: ");
    printDate(day, month, year);

    long days = convertFromDate(day, month, year);

    printf("Enter the number of days to be added:\n");
    int addDays;
    scanf("%d", &addDays);

    while(addDays > 0) {
        incrementDay(&day, &month, &year);
        addDays--;
    }

    while(addDays < 0) {
        decrementDay(&day, &month, &year);
        addDays++;
    }

    printf("New date: ");
    printDate(day, month, year);

    int diffDays;
    printf("Enter the second date in this format: ddmmyyyy\n");
    scanf("%d", &input);

    int day2 = input % 100;
    input /= 100;
    int month2 = input % 100;
    int year2 = input / 100;

    long days2 = convertFromDate(day2, month2, year2);

    diffDays = (days > days2) ? days - days2 : days2 - days;

    printf("Difference between dates: %d days\n", diffDays);

    printf("Enter the number of days to be subtracted:\n");
    int subDays;
    scanf("%d", &subDays);

    while(subDays > 0) {
        decrementDay(&day, &month, &year);
        subDays--;
    }

    while(subDays < 0) {
        incrementDay(&day, &month, &year);
        subDays++;
    }

    printf("New date: ");
    printDate(day, month, year);

    printf("Enter the number of days to be converted to date:\n");
    long convertDays;
    scanf("%ld", &convertDays);

    convertToDate(convertDays, &day, &month, &year);

    printf("Date: ");
    printDate(day, month, year);

    return 0;
}