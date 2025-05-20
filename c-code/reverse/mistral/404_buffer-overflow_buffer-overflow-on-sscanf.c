#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 100

void parse_date(char *input, struct tm *tm_struct) {
    int day, month, year;
    sscanf(input, "%d/%d/%d", &day, &month, &year);
    tm_struct->tm_mday = day;
    tm_struct->tm_mon = month - 1;
    tm_struct->tm_year = year - 1900;
}

void print_date(struct tm *tm_struct) {
    char date[30];
    strftime(date, sizeof(date), "%m/%d/%Y", tm_struct);
    printf("Current date: %s\n", date);
}

int main() {
    char buffer[BUFFER_SIZE];
    struct tm *current_time = malloc(sizeof(struct tm));
    time_t rawtime;
    time(&rawtime);
    localtime_r(&rawtime, current_time);

    printf("Enter date (format: MM/DD/YYYY): ");
    fgets(buffer, BUFFER_SIZE, stdin);
    parse_date(buffer, current_time);

    print_date(current_time);

    // Time travel to the entered date
    struct tm *time_travel_point = malloc(sizeof(struct tm));
    memcpy(time_travel_point, current_time, sizeof(struct tm));

    time_t travel_time = mktime(time_travel_point);
    struct tm *traveled_time = localtime(&travel_time);

    printf("Time traveled to: %s\n", asctime(traveled_time));

    free(current_time);
    free(time_travel_point);

    return 0;
}
