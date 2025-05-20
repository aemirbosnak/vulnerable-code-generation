//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_MONTHS 12

char* month_names[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

int main() {
    char input_date[20];
    char output_date[50];
    char month_str[10];
    char day_str[10];
    char year_str[10];
    char delimiter;
    int month, day, year;
    int i;

    printf("Enter a date in MM/DD/YYYY format: ");
    scanf("%s", input_date);

    // Extract month, day, and year from input date
    sscanf(input_date, "%d/%d/%d", &month, &day, &year);

    // Convert month to string
    snprintf(month_str, sizeof(month_str), "%d", month);

    // Get the month name
    for (i = 0; i < NUM_MONTHS; i++) {
        if (atoi(month_str) == i + 1) {
            strncpy(month_str, month_names[i], sizeof(month_str));
            break;
        }
    }

    // Convert day and year to strings
    snprintf(day_str, sizeof(day_str), "%d", day);
    snprintf(year_str, sizeof(year_str), "%d", year);

    // Build the output date string
    strncpy(output_date, month_str, sizeof(output_date));
    strncat(output_date, " ", sizeof(output_date));
    strncat(output_date, day_str, sizeof(output_date));
    strncat(output_date, ", ", sizeof(output_date));
    strncat(output_date, year_str, sizeof(output_date));

    printf("The date %s is %s.\n", input_date, output_date);

    return 0;
}