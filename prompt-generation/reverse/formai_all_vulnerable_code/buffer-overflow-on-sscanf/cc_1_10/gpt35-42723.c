//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int get_month(char *month) {
    if (strcmp(month, "January") == 0) {
        return 1;
    } else if (strcmp(month, "February") == 0) {
        return 2;
    } else if (strcmp(month, "March") == 0) {
        return 3;
    } else if (strcmp(month, "April") == 0) {
        return 4;
    } else if (strcmp(month, "May") == 0) {
        return 5;
    } else if (strcmp(month, "June") == 0) {
        return 6;
    } else if (strcmp(month, "July") == 0) {
        return 7;
    } else if (strcmp(month, "August") == 0) {
        return 8;
    } else if (strcmp(month, "September") == 0) {
        return 9;
    } else if (strcmp(month, "October") == 0) {
        return 10;
    } else if (strcmp(month, "November") == 0) {
        return 11;
    } else if (strcmp(month, "December") == 0) {
        return 12;
    } else {
        return 0;
    }
}

void print_date(int day, int month, int year) {
    printf("%02d/%02d/%04d", day, month, year);
}

int main() {
    char date_str[100];
    printf("Enter date in natural language format (e.g. January 1, 2000): ");
    fgets(date_str, sizeof(date_str), stdin);

    int day, month, year;
    char month_str[20];
    int matches = sscanf(date_str, "%s %d, %d", month_str, &day, &year);
    if (matches < 3) {
        printf("Invalid date format.\n");
        return EXIT_FAILURE;
    }
    month = get_month(month_str);
    if (month == 0) {
        printf("Invalid month.\n");
        return EXIT_FAILURE;
    }

    print_date(day, month, year);
    return EXIT_SUCCESS;
}