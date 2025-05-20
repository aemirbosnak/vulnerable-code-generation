//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>

// Function for converting month name to number
int month_to_number(char* month) {
    if (strcmp(month, "January") == 0)
        return 1;
    else if (strcmp(month, "February") == 0)
        return 2;
    else if (strcmp(month, "March") == 0)
        return 3;
    else if (strcmp(month, "April") == 0)
        return 4;
    else if (strcmp(month, "May") == 0)
        return 5;
    else if (strcmp(month, "June") == 0)
        return 6;
    else if (strcmp(month, "July") == 0)
        return 7;
    else if (strcmp(month, "August") == 0)
        return 8;
    else if (strcmp(month, "September") == 0)
        return 9;
    else if (strcmp(month, "October") == 0)
        return 10;
    else if (strcmp(month, "November") == 0)
        return 11;
    else if (strcmp(month, "December") == 0)
        return 12;
    else
        return -1;
}

// Function for converting date string to number of days
int date_to_days(char* date_string) {
    int days = 0;
    char* month_string = strtok(date_string, " ");
    int month = month_to_number(month_string);
    if (month == -1)
        return -1;
    char* day_string = strtok(NULL, " ");
    int day = atoi(day_string);
    if (day < 1 || day > 31)
        return -1;
    char* year_string = strtok(NULL, " ");
    int year = atoi(year_string);
    if (year < 1900 || year > 2100)
        return -1;
    days += (year - 1900) * 365;
    days += (year - 1901) / 4 + 1;
    switch (month) {
        case 12:
            days += 30;
        case 11:
            days += 31;
        case 10:
            days += 30;
        case 9:
            days += 31;
        case 8:
            days += 31;
        case 7:
            days += 30;
        case 6:
            days += 31;
        case 5:
            days += 30;
        case 4:
            days += 31;
        case 3:
            days += (year % 4 == 0 && year % 100 != 0) || year % 400 == 0 ? 29 : 28;
        case 2:
            days += 31;
        case 1:
            days += day;
            break;
        default:
            return -1;
    }
    return days;
}

// Function for converting number of days to date string
char* days_to_date(int days) {
    if (days < 0)
        return "Invalid date";
    int year = (days / 365) + 1900;
    int leap_years = ((year - 1901) / 4) + 1;
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        leap_years--;
    days -= (leap_years * 366) + ((year - 1901 - leap_years) * 365);
    int month = 1;
    int month_days = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0 ? 29 : 28;
    while (days > month_days) {
        days -= month_days;
        month++;
        switch (month) {
            case 2:
                month_days = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0 ? 29 : 28;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                month_days = 30;
                break;
            default:
                month_days = 31;
        }
    }
    char* month_name = "";
    switch (month) {
        case 1:
            month_name = "January";
            break;
        case 2:
            month_name = "February";
            break;
        case 3:
            month_name = "March";
            break;
        case 4:
            month_name = "April";
            break;
        case 5:
            month_name = "May";
            break;
        case 6:
            month_name = "June";
            break;
        case 7:
            month_name = "July";
            break;
        case 8:
            month_name = "August";
            break;
        case 9:
            month_name = "September";
            break;
        case 10:
            month_name = "October";
            break;
        case 11:
            month_name = "November";
            break;
        case 12:
            month_name = "December";
            break;
    }
    char* date_string = "";
    sprintf(date_string, "%s %d, %d", month_name, days, year);
    return date_string;
}

int main() {
    char* date_string = "February 12, 2019";
    int days = date_to_days(date_string);
    printf("%d\n", days);
    char* new_date_string = days_to_date(days);
    printf("%s\n", new_date_string);
    return 0;
}