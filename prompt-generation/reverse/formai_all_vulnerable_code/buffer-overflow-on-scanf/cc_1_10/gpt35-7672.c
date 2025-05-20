//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: shape shifting
#include <stdio.h>
#include <string.h>

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
    } else if (strcmp(month, "October")) {
        return 10;
    } else if (strcmp(month, "November") == 0) {
        return 11;
    } else if (strcmp(month, "December") == 0) {
        return 12;
    }

    return -1;
}

int main() {

    int day, year;
    char month[10];

    printf("Enter the date in natural language: ");
    scanf("%d %s %d", &day, month, &year);

    int month_num = get_month(month);

    if (month_num == -1) {
        printf("Invalid month");
        return 0;
    }

    printf("Date in integer format: %d/%d/%d", month_num, day, year);

    return 0;
}