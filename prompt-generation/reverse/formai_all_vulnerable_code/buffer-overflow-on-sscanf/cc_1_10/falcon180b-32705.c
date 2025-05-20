//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LEN 100

typedef struct {
    char day[MAX_LEN];
    char month[MAX_LEN];
    char year[MAX_LEN];
} Date;

char* get_day(int day_num) {
    static char days[7][MAX_LEN] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    return days[day_num % 7];
}

char* get_month(int month_num) {
    static char months[12][MAX_LEN] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    return months[month_num % 12];
}

char* get_time(time_t time) {
    static char time_str[MAX_LEN];
    strftime(time_str, MAX_LEN, "%X", localtime(&time));
    return time_str;
}

void print_date(Date* date) {
    printf("Date: %s, %s %d, %s\n", date->day, date->month, date->year, get_time(time(NULL)));
}

int main() {
    Date* date = malloc(sizeof(Date));
    char* input = malloc(MAX_LEN * 3 + 1);
    int i = 0, j = 0;
    while (i < 3) {
        printf("Enter the date (dd/mm/yyyy): ");
        fgets(input, MAX_LEN * 3 + 1, stdin);
        sscanf(input, "%s %s %s", date->day, date->month, date->year);
        if (strlen(date->day)!= 2 || strlen(date->month)!= 2 || strlen(date->year)!= 4) {
            printf("Invalid date format. Please enter the date in the format dd/mm/yyyy.\n");
            i = 0;
        } else {
            i++;
        }
    }
    printf("Date entered: %s, %s %d, %s\n", date->day, date->month, date->year, get_time(time(NULL)));
    return 0;
}