//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATE_LENGTH 11 // String length of the longest possible date "mm/dd/yyyy"

char* convert_date(char* input_date) {
    char* res = (char*)malloc(MAX_DATE_LENGTH * sizeof(char)); // Allocate memory for the result
    int m, d, y;

    sscanf(input_date, "%d/%d/%d", &m, &d, &y); // Parse input date string

    // Check for invalid month, day, or year
    if (m < 1 || m > 12 || d < 1 || d > 31 || y < 0) {
        sprintf(res, "Invalid date: %s", input_date);
        return res;
    }

    // Determine the month name
    char* month_name;
    switch(m) {
        case 1: month_name = "January"; break;
        case 2: month_name = "February"; break;
        case 3: month_name = "March"; break;
        case 4: month_name = "April"; break;
        case 5: month_name = "May"; break;
        case 6: month_name = "June"; break;
        case 7: month_name = "July"; break;
        case 8: month_name = "August"; break;
        case 9: month_name = "September"; break;
        case 10: month_name = "October"; break;
        case 11: month_name = "November"; break;
        case 12: month_name = "December"; break;
    }

    // Build the result string
    sprintf(res, "%s %d, %d", month_name, d, y);

    return res;
}

int main() {
    char input_date[MAX_DATE_LENGTH];
    char* result;

    printf("Enter a date in the format mm/dd/yyyy: ");
    scanf("%s", input_date);

    result = convert_date(input_date);

    printf("Converted date: %s\n", result);

    free(result); // Free memory allocated for result string

    return 0;
}