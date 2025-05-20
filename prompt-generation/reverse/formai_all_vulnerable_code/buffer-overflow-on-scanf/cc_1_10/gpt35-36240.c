//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: imaginative
#include <stdio.h>
#include <stdbool.h>

bool is_leap_year(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return true;
            } else {
                return false;
            }
        } else {
            return true;
        }
    } else {
        return false;
    }
}

void convert_date(char* date) {
    // Extract day, month, and year from the input string
    int day = ((date[0] - '0') * 10) + (date[1] - '0');
    int month = ((date[3] - '0') * 10) + (date[4] - '0');
    int year = ((date[6] - '0') * 1000) + ((date[7] - '0') * 100) + ((date[8] - '0') * 10) + (date[9] - '0');

    // Print the date in natural language
    printf("The date is ");
    switch (month) {
        case 1:
            printf("January ");
            break;
        case 2:
            printf("February ");
            break;
        case 3:
            printf("March ");
            break;
        case 4:
            printf("April ");
            break;
        case 5:
            printf("May ");
            break;
        case 6:
            printf("June ");
            break;
        case 7:
            printf("July ");
            break;
        case 8:
            printf("August ");
            break;
        case 9:
            printf("September ");
            break;
        case 10:
            printf("October ");
            break;
        case 11:
            printf("November ");
            break;
        case 12:
            printf("December ");
            break;
        default:
            printf("Invalid month");
            return;
    }

    printf("%d, %d", day, year);

    // Check if the year is a leap year
    if (is_leap_year(year)) {
        printf(" (Leap Year)\n");
    } else {
        printf("\n");
    }
}

int main() {
    // Take input date in the format "DD/MM/YYYY"
    char date[11];
    printf("Enter date in the format 'DD/MM/YYYY': ");
    scanf("%s", date);

    convert_date(date);

    return 0;
}