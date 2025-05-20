//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STRING_SIZE 1000

typedef struct {
    char month[10];
    int day;
    int year;
} Date;

char* get_month_name(int month_number) {
    static char* month_names[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    return month_names[month_number - 1];
}

Date parse_date(char* input_date) {
    Date parsed_date;
    char* month_name = strtok(input_date, " ");
    char* day_str = strtok(NULL, " ");
    char* year_str = strtok(NULL, " ");

    parsed_date.month[0] = '\0';
    strncat(parsed_date.month, month_name, strlen(month_name));

    int day = atoi(day_str);
    int year = atoi(year_str);

    parsed_date.day = day;
    parsed_date.year = year;

    return parsed_date;
}

char* format_date(Date date) {
    char* formatted_date = malloc(MAX_STRING_SIZE * sizeof(char));
    sprintf(formatted_date, "%s %d, %d", get_month_name(date.month[0] - '0'), date.day, date.year);
    return formatted_date;
}

int main() {
    char input_date[MAX_STRING_SIZE];
    printf("Enter a date in the format 'Month Day, Year': ");
    scanf("%s", input_date);

    Date parsed_date = parse_date(input_date);
    char* formatted_date = format_date(parsed_date);

    printf("The date '%s' is '%s'.\n", input_date, formatted_date);

    free(formatted_date);
    return 0;
}