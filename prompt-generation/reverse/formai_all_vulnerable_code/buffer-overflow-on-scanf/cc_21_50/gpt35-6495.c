//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: puzzling
#include <stdio.h>

int main() {
    int year, month, day, days_in_month;
    printf("Enter a date in natural language (e.g. January 1st, 2000): ");
    
    // Getting user input
    char month_name[20], comma, suffix[3];
    scanf("%s %d%c%c %d", month_name, &day, &comma, suffix, &year);

    // Handling suffixes
    if (suffix[0] != '\0') {
        if (suffix[0] == 's') {
            if (suffix[1] == 't' || suffix[1] == 'd' || suffix[1] == 'th') {
                suffix[1] = '\0';
            }
        }
        else if (suffix[0] == 'n') {
            if (suffix[1] == 'd') {
                suffix[1] = '\0';
            }
        }
        else if (suffix[0] == 'r') {
            if (suffix[1] == 'd') {
                suffix[1] = '\0';
            }
        }
    }

    // Determining the month number
    switch(month_name[0]) {
        case 'J':
        case 'j':
            if (month_name[1] == 'a' || month_name[1] == 'A') month = 1;
            else if (month_name[2] == 'n' || month_name[2] == 'N') month = 6;
            else month = 7;
            break;
        case 'F':
        case 'f':
            month = 2;
            break;
        case 'M':
        case 'm':
            if (month_name[2] == 'r' || month_name[2] == 'R') month = 3;
            else month = 5;
            break;
        case 'A':
        case 'a':
            if (month_name[1] == 'p' || month_name[1] == 'P') month = 4;
            else month = 8;
            break;
        case 'S':
        case 's':
            month = 9;
            break;
        case 'O':
        case 'o':
            month = 10;
            break;
        case 'N':
        case 'n':
            month = 11;
            break;
        case 'D':
        case 'd':
            month = 12;
            break;
        default:
            printf("Invalid month name.\n");
            return 0;
    }

    // Checking for valid day ranges
    if (day < 1 || day > 31) {
        printf("Invalid day.\n");
        return 0;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30) {
            printf("Invalid day.\n");
            return 0;
        }
    }
    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) days_in_month = 29;
        else days_in_month = 28;
        if (day > days_in_month) {
            printf("Invalid day.\n");
            return 0;
        }
    }

    // Printing output
    printf("%d-%02d-%02d\n", year, month, day);
    return 0;
}