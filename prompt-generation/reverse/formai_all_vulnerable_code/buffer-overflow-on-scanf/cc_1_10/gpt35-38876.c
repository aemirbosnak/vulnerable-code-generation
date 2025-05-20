//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_month_name(int month) {
    switch(month) {
        case 1:
            return "January";
            break;
        case 2:
            return "February";
            break;
        case 3:
            return "March";
            break;
        case 4:
            return "April";
            break;
        case 5:
            return "May";
            break;
        case 6:
            return "June";
            break;
        case 7:
            return "July";
            break;
        case 8:
            return "August";
            break;
        case 9:
            return "September";
            break;
        case 10:
            return "October";
            break;
        case 11:
            return "November";
            break;
        case 12:
            return "December";
            break;
        default:
            return "";
    }
}

int get_month_days(int month, int year) {
    switch(month) {
        case 2:
            if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
                return 29;
            } else {
                return 28;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
            break;
        default:
            return 31;
            break;
    }
}

int main() {
    char date[15];
    int day, month, year;
    
    printf("Enter date in format dd/mm/yyyy: ");
    scanf("%s", date);
    
    day = atoi(strtok(date, "/"));
    month = atoi(strtok(NULL, "/"));
    year = atoi(strtok(NULL, "/"));
    
    printf("The date is %s %d, %d\n", get_month_name(month), day, year);
    
    int days_in_month = get_month_days(month, year);
    
    if(day < 1 || day > days_in_month) {
        printf("Invalid date\n");
        return 0;
    }
    
    // day of the year
    int day_of_year = day;
    
    for(int i = 1; i < month; i++) {
        day_of_year += get_month_days(i, year);
    }
    
    printf("The day of the year is %d\n", day_of_year);
    
    // days until next birthday
    int current_day_of_year = 0;
    
    for(int i = 1; i < month; i++) {
        current_day_of_year += get_month_days(i, year);
    }
    
    current_day_of_year += day;
    
    int next_birthday_day_of_year = 0;
    
    for(int i = 1; i < month; i++) {
        next_birthday_day_of_year += get_month_days(i, year + 1);
    }
    
    next_birthday_day_of_year += day;
    
    int days_until_next_birthday = next_birthday_day_of_year - current_day_of_year;
    
    if(days_until_next_birthday < 0) {
        days_until_next_birthday += get_month_days(month, year + 1);
    }
    
    printf("Days until next birthday: %d\n", days_until_next_birthday);
    
    return 0;
}