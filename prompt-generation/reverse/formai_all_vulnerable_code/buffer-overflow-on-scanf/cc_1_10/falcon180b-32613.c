//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MONTHS 12
#define DAYS_IN_MONTH(m) ((m) == 2? ((m) % 4 == 0 && (m) % 100!= 0 || (m) % 400 == 0)? 29 : 28) + 1

typedef struct {
    int day;
    int month;
    int year;
} Date;

char* get_month_name(int month) {
    static char* months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    return months[month - 1];
}

Date parse_date(char* str) {
    Date date = {0};
    char* token = strtok(str, " ");
    date.day = atoi(token);
    token = strtok(NULL, " ");
    date.month = atoi(token);
    token = strtok(NULL, " ");
    char* year_str = token;
    int year = atoi(year_str);
    if (strlen(year_str) == 4) {
        year += 2000;
    } else if (strlen(year_str) == 2) {
        year += 1900;
    }
    date.year = year;
    return date;
}

void print_date(Date date) {
    char buffer[100];
    sprintf(buffer, "%s %d, %d", get_month_name(date.month), date.day, date.year);
    printf("%s\n", buffer);
}

int main() {
    char input[100];
    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%s", input);
    Date date = parse_date(input);
    print_date(date);
    return 0;
}