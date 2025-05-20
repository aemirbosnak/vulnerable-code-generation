//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

// Function to validate user input for month
int validate_month(char* month) {
    int len = strlen(month);
    if (len!= 3 && len!= 9) {
        return 0;
    }
    for (int i = 0; i < len; i++) {
        if (!isalpha(month[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to validate user input for day
int validate_day(char* day) {
    int len = strlen(day);
    if (len!= 1 && len!= 2) {
        return 0;
    }
    for (int i = 0; i < len; i++) {
        if (!isdigit(day[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to validate user input for year
int validate_year(char* year) {
    int len = strlen(year);
    if (len!= 2 && len!= 4) {
        return 0;
    }
    for (int i = 0; i < len; i++) {
        if (!isdigit(year[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to convert user input to date format
char* convert_to_date(char* month, char* day, char* year) {
    time_t timestamp;
    struct tm date;
    strptime(year, "%Y", &date);
    date.tm_mon = atoi(month) - 1;
    date.tm_mday = atoi(day);
    timestamp = mktime(&date);
    return ctime(&timestamp);
}

// Function to print the date in natural language format
void print_date(char* date) {
    printf("Today's date is %s\n", date);
}

int main() {
    char month[20];
    char day[20];
    char year[20];
    printf("Enter the current month (e.g. January): ");
    scanf("%s", month);
    printf("Enter the current day (e.g. 01): ");
    scanf("%s", day);
    printf("Enter the current year (e.g. 2022): ");
    scanf("%s", year);
    if (validate_month(month) && validate_day(day) && validate_year(year)) {
        char* date = convert_to_date(month, day, year);
        print_date(date);
    } else {
        printf("Invalid input\n");
    }
    return 0;
}