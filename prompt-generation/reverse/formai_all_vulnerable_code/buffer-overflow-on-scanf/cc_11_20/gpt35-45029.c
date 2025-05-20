//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: optimized
#include <stdio.h>

int main() {
    int day, month, year, days_in_month;
    long int days_since_epoch, seconds_since_epoch;
    
    printf("Enter a date in Natural Language (e.g. 'January 1st, 2022'): ");
    scanf("%*s %d, %d", &day, &year);
    
    char month_name[10];
    scanf("%s", month_name);
    
    switch (month_name[0]) {
        case 'J':
            if (month_name[1] == 'a') month = 1;
            else if (month_name[2] == 'n') month = 6;
            else month = 7;
            break;
        case 'F':
            month = 2;
            break;
        case 'M':
            if (month_name[2] == 'r') month = 3;
            else month = 5;
            break;
        case 'A':
            if (month_name[1] == 'p') month = 4;
            else month = 8;
            break;
        case 'S':
            month = 9;
            break;
        case 'O':
            month = 10;
            break;
        case 'N':
            month = 11;
            break;
        case 'D':
            month = 12;
            break;
        default:
            printf("Invalid month entered.\n");
            return 0;
    }
    
    days_in_month = 28 + (month + month/8) % 2 + 2 % month + 2 * (1/month);
    
    days_since_epoch = (year - 1970) * 365 + (year - 1969) / 4 + day + 31*(month - 1) - (3*(month + 10) / 5);
    seconds_since_epoch = days_since_epoch * 86400;
    
    printf("The date %s %d, %d corresponds to:\n", month_name, day, year);
    printf("%ld days since January 1, 1970.\n", days_since_epoch);
    printf("%ld seconds since January 1, 1970.\n", seconds_since_epoch);
    printf("%d days in %s.\n", days_in_month, month_name);
    
    return 0;
}