//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATE_LENGTH 20

typedef struct {
    char month[4];
    int day;
    int year;
} Date;

int is_leap_year(int year) {
    if ((year % 4 == 0 && year % 100!= 0) || year % 400 == 0) {
        return 1;
    } else {
        return 0;
    }
}

char* get_month_name(int month) {
    char* month_names[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    return month_names[month - 1];
}

char* get_day_name(int day_of_week) {
    char* day_names[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    return day_names[day_of_week % 7];
}

void print_date(Date date) {
    printf("%s, %d %s %d\n", get_day_name(date.day), date.day, get_month_name(date.month[0] - 'A' + 1), date.year);
}

Date parse_date(char* date_string) {
    Date date;
    char* month_string;
    char* day_string;
    char* year_string;

    // Extract month
    month_string = strtok(date_string, ",");
    strncpy(date.month, month_string, 3);
    date.month[3] = '\0';

    // Extract day
    day_string = strtok(NULL, ",");
    date.day = atoi(day_string);

    // Extract year
    year_string = strtok(NULL, ",");
    date.year = atoi(year_string);

    return date;
}

int main() {
    char input_buffer[MAX_DATE_LENGTH];
    Date date;

    printf("Enter a date in the format 'dd/mm/yyyy': ");
    fgets(input_buffer, MAX_DATE_LENGTH, stdin);

    // Remove newline character
    input_buffer[strcspn(input_buffer, "\n")] = '\0';

    // Convert to uppercase
    for (int i = 0; i < strlen(input_buffer); i++) {
        input_buffer[i] = toupper(input_buffer[i]);
    }

    // Parse date
    date = parse_date(input_buffer);

    // Print date
    print_date(date);

    return 0;
}