//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <locale.h>

#define MAX_MONTH_NAME_LEN 9
#define MAX_WEEKDAY_NAME_LEN 9
#define MAX_DATE_STRING_LEN 80

struct tm get_timestamp(char* date_string) {
    struct tm result = {0};
    strptime(date_string, "%Y-%m-%d", &result);
    return result;
}

void format_date(struct tm timestamp, char* date_string) {
    strftime(date_string, MAX_DATE_STRING_LEN, "%A, %B %d, %Y", &timestamp);
}

void format_time(struct tm timestamp, char* time_string) {
    strftime(time_string, MAX_DATE_STRING_LEN, "%I:%M %p", &timestamp);
}

void format_weekday(struct tm timestamp, char* weekday_string) {
    strftime(weekday_string, MAX_WEEKDAY_NAME_LEN, "%A", &timestamp);
}

void format_month(struct tm timestamp, char* month_string) {
    strftime(month_string, MAX_MONTH_NAME_LEN, "%B", &timestamp);
}

int main() {
    setlocale(LC_ALL, "en_US.UTF-8");
    char input_date_string[MAX_DATE_STRING_LEN] = {0};
    char formatted_date_string[MAX_DATE_STRING_LEN] = {0};
    char formatted_time_string[MAX_DATE_STRING_LEN] = {0};
    char formatted_weekday_string[MAX_WEEKDAY_NAME_LEN] = {0};
    char formatted_month_string[MAX_MONTH_NAME_LEN] = {0};

    printf("Enter a date in YYYY-MM-DD format: ");
    scanf("%s", input_date_string);

    struct tm timestamp = get_timestamp(input_date_string);

    format_date(timestamp, formatted_date_string);
    format_time(timestamp, formatted_time_string);
    format_weekday(timestamp, formatted_weekday_string);
    format_month(timestamp, formatted_month_string);

    printf("Formatted Date: %s\n", formatted_date_string);
    printf("Formatted Time: %s\n", formatted_time_string);
    printf("Formatted Weekday: %s\n", formatted_weekday_string);
    printf("Formatted Month: %s\n", formatted_month_string);

    return 0;
}