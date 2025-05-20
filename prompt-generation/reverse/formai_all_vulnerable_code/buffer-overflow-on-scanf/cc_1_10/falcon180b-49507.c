//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

int is_valid_date(char* str, int* day, int* month, int* year) {
    int len = strlen(str);
    if (len!= 10 || str[2]!= '/' || str[5]!= '/') {
        return 0;
    }

    if (!isdigit(str[0]) ||!isdigit(str[1]) ||!isdigit(str[3]) ||!isdigit(str[4]) ||!isdigit(str[6]) ||!isdigit(str[7]) ||!isdigit(str[8]) ||!isdigit(str[9])) {
        return 0;
    }

    *day = atoi(str) % 100;
    *month = atoi(str + 3) % 100;
    *year = atoi(str + 6) % 100;

    return 1;
}

char* month_to_string(int month) {
    static char months[][4] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    return months[month % 12];
}

char* date_to_string(int day, int month, int year) {
    char* str = malloc(MAX_LENGTH * sizeof(char));
    sprintf(str, "%s %d, %d", month_to_string(month), day, year);
    return str;
}

int main() {
    char input[MAX_LENGTH];
    int day, month, year;

    printf("Enter a date in the format dd/mm/yyyy: ");
    scanf("%s", input);

    if (is_valid_date(input, &day, &month, &year)) {
        printf("The date is: %s\n", date_to_string(day, month, year));
    } else {
        printf("Invalid date format.\n");
    }

    return 0;
}