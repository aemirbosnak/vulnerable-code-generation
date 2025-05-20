//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: unmistakable
// This C program converts a date from natural language format to YYYY/MM/DD format.

#include <stdio.h>
#include <string.h>

char* monthToInt(char* s_month) { // Convert month to numerical value
    if (strcmp(s_month, "January") == 0) {
        return "01";
    } else if (strcmp(s_month, "February") == 0) {
        return "02";
    } else if (strcmp(s_month, "March") == 0) {
        return "03";
    } else if (strcmp(s_month, "April") == 0) {
        return "04";
    } else if (strcmp(s_month, "May") == 0) {
        return "05";
    } else if (strcmp(s_month, "June") == 0) {
        return "06";
    } else if (strcmp(s_month, "July") == 0) {
        return "07";
    } else if (strcmp(s_month, "August") == 0) {
        return "08";
    } else if (strcmp(s_month, "September") == 0) {
        return "09";
    } else if (strcmp(s_month, "October") == 0) {
        return "10";
    } else if (strcmp(s_month, "November") == 0) {
        return "11";
    } else if (strcmp(s_month, "December") == 0) {
        return "12";
    } else {
        return NULL;
    }
}

int main() {
    char s_month[10], s_day[3], s_year[5];

    printf("Enter a date in natural language format (e.g. January 1, 2000): ");
    scanf("%s%s%s", s_month, s_day, s_year);

    // Remove comma from day input
    s_day[strlen(s_day) - 1] = '\0';

    // Convert month to numerical value
    char* n_month = monthToInt(s_month);
    if (n_month == NULL) {
        printf("Invalid month\n");
        return 1;
    }

    printf("\nDate in YYYY/MM/DD format: %s/%s/%s\n", s_year, n_month, s_day);

    return 0;
}