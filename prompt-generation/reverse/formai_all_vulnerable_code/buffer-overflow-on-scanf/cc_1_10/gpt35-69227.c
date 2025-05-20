//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: Dennis Ritchie
#include<stdio.h>

int isLeapYear(int year){
    if(year % 4 != 0)
        return 0;
    else if(year % 100 != 0)
        return 1;
    else if(year % 400 != 0)
        return 0;
    else
        return 1;
}

int getDaysInMonth(int month, int year){
    int days;

    if(month == 2){
        if(isLeapYear(year))
            days = 29;
        else
            days = 28;
    }
    else if(month == 4 || month == 6 || month == 9 || month == 11)
        days = 30;
    else
        days = 31;

    return days;
}

void convertToJulian(int day, int month, int year){
    int i, julianDay = 0;

    for(i = 1; i < month; i++)
        julianDay += getDaysInMonth(i, year);

    julianDay += day;

    printf("\nJulian Date for %d/%d/%d is: %d\n", day, month, year, julianDay);
}

void convertToGregorian(int julianDay, int year){
    int i, daysInMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int day = julianDay;

    if(isLeapYear(year))
        daysInMonth[2] = 29;

    for(i = 1; i <= 12; i++){
        if(day <= daysInMonth[i])
            break;
        day -= daysInMonth[i];
    }

    printf("\nGregorian Date for %d in year %d is: %d/%d/%d\n", julianDay, year, day, i, year);
}

int main(){
    int choice, day, month, year, julianDay;

    do{
        printf("Enter 1 to Convert Gregorian date to Julian date\n");
        printf("Enter 2 to Convert Julian date to Gregorian date\n");
        printf("Enter 3 to Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter Gregorian date to convert to Julian date\n");
                printf("Enter day: ");
                scanf("%d", &day);
                printf("Enter month: ");
                scanf("%d", &month);
                printf("Enter year: ");
                scanf("%d", &year);
                convertToJulian(day, month, year);
                break;
            case 2:
                printf("\nEnter Julian date to convert to Gregorian date\n");
                printf("Enter year: ");
                scanf("%d", &year);
                printf("Enter Julian day: ");
                scanf("%d", &julianDay);
                convertToGregorian(julianDay, year);
                break;
            case 3:
                printf("\nExiting Program...\n");
                break;
            default:
                printf("\nInvalid choice...\n");
        }
    }while(choice != 3);

    return 0;
}