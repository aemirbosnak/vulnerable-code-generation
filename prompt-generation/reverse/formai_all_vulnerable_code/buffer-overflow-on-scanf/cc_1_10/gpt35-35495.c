//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void convertMonth(char *month);
void printDate(int day, char *month, int year, int julianDate);

int main() {
    int day, year, julianDate;
    char month[10];

    printf("Enter the date in the format DD-MMM-YYYY: ");
    scanf("%d-%s-%d", &day, month, &year);

    convertMonth(month);

    printf("Enter the Julian date: ");
    scanf("%d", &julianDate);

    printDate(day, month, year, julianDate);

    return 0;
}

// Convert month abbreviation to full month name
void convertMonth(char *month) {
    if (strlen(month) == 3) {
        for (int i = 0; i < 3; i++) {
            month[i] = toupper(month[i]);
        }
        if (strcmp(month, "JAN") == 0) {
            strcpy(month, "January");
        } else if (strcmp(month, "FEB") == 0) {
            strcpy(month, "February");
        } else if (strcmp(month, "MAR") == 0) {
            strcpy(month, "March");
        } else if (strcmp(month, "APR") == 0) {
            strcpy(month, "April");
        } else if (strcmp(month, "MAY") == 0) {
            strcpy(month, "May");
        } else if (strcmp(month, "JUN") == 0) {
            strcpy(month, "June");
        } else if (strcmp(month, "JUL") == 0) {
            strcpy(month, "July");
        } else if (strcmp(month, "AUG") == 0) {
            strcpy(month, "August");
        } else if (strcmp(month, "SEP") == 0) {
            strcpy(month, "September");
        } else if (strcmp(month, "OCT") == 0) {
            strcpy(month, "October");
        } else if (strcmp(month, "NOV") == 0) {
            strcpy(month, "November");
        } else if (strcmp(month, "DEC") == 0) {
            strcpy(month, "December");
        }
    }
}

// Print the date in the format DAY MONTH YEAR (Julian Date)
void printDate(int day, char *month, int year, int julianDate) {
    printf("%d %s %d (%d)", day, month, year, julianDate);
}