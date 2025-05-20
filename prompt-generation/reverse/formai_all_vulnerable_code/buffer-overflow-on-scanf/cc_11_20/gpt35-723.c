//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

int is_leap_year(int year);

int main() {
    int day, month, year;
    char month_name[20];
    printf("Enter a date (dd mm yyyy): ");
    scanf("%d %d %d", &day, &month, &year);
    
    switch(month) {
        case 1:
            sprintf(month_name, "January");
            break;
        case 2:
            sprintf(month_name, "February");
            break;
        case 3:
            sprintf(month_name, "March");
            break;
        case 4:
            sprintf(month_name, "April");
            break;
        case 5:
            sprintf(month_name, "May");
            break;
        case 6:
            sprintf(month_name, "June");
            break;
        case 7:
            sprintf(month_name, "July");
            break;
        case 8:
            sprintf(month_name, "August");
            break;
        case 9:
            sprintf(month_name, "September");
            break;
        case 10:
            sprintf(month_name, "October");
            break;
        case 11:
            sprintf(month_name, "November");
            break;
        case 12:
            sprintf(month_name, "December");
            break;
        default:
            printf("Invalid month.\n");
            exit(0);
    }
    
    if (day < 1 || day > 31) {
        printf("Invalid day.\n");
        exit(0);
    }
    
    if (month == 2) {
        if (is_leap_year(year)) {
            if (day > 29) {
                printf("Invalid day.\n");
                exit(0);
            }
        } else {
            if (day > 28) {
                printf("Invalid day.\n");
                exit(0);
            }
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30) {
            printf("Invalid day.\n");
            exit(0);
        }
    }
    
    printf("The date is %s %d, %d.\n", month_name, day, year);
    return 0;
}

int is_leap_year(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 1;
        }
    } else {
        return 0;
    }
}