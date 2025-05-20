//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Date {
    int day, month, year;
};

int daysInMonth(int month, int year) {
    int days[] = {31, 28 + (year % 4 == 0 && year % 100 != 0 || year % 400 == 0), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return days[month-1];
}

struct Date convertDate(char *str) {
    struct Date date;
    char *token = strtok(str, " ");
    char *monthNames[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    while(token != NULL) {
        for(int i = 0; i < 12; i++) {
            if(strstr(token, monthNames[i])) {
                date.month = i+1;
                break;
            }
        }

        if(strstr(token, "st") || strstr(token, "nd") || strstr(token, "rd") || strstr(token, "th")) {
            date.day = atoi(token);
        } else {
            date.year = atoi(token);
        }
        
        token = strtok(NULL, " ");
    }

    if(date.day == 0) {
        date.day = 1;
    }

    if(date.year == 0) {
        date.year = 2022;
    }

    return date;
}

int main() {
    char dateStr[100];
    printf("Enter a date in natural language: ");
    fgets(dateStr, 100, stdin);

    struct Date date = convertDate(dateStr);
    int days = daysInMonth(date.month, date.year);

    if(date.day > days || date.day == 0) {
        printf("Invalid day for the given month.\n");
        return 1;
    }

    printf("Date in dd/mm/yyyy format: %02d/%02d/%d\n", date.day, date.month, date.year);

    return 0;
}