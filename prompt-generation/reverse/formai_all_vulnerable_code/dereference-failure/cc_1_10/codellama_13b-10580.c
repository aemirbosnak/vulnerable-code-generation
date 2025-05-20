//Code Llama-13B DATASET v1.0 Category: Natural Language Date Converter ; Style: calm
/*
 * Natural Language Date Converter
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void convert_date(char *date_string, int *year, int *month, int *day) {
    char *month_names[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    char *day_names[] = {
        "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"
    };

    char *temp_date_string = strdup(date_string);
    char *token;
    int i;

    // Get the day of the week
    token = strtok(temp_date_string, " ");
    for (i = 0; i < 7; i++) {
        if (strcmp(token, day_names[i]) == 0) {
            *day = i + 1;
            break;
        }
    }

    // Get the month
    token = strtok(NULL, " ");
    for (i = 0; i < 12; i++) {
        if (strcmp(token, month_names[i]) == 0) {
            *month = i + 1;
            break;
        }
    }

    // Get the year
    token = strtok(NULL, " ");
    *year = atoi(token);

    free(temp_date_string);
}

int main() {
    char date_string[] = "March 21, 2023";
    int year, month, day;

    convert_date(date_string, &year, &month, &day);

    printf("Year: %d\n", year);
    printf("Month: %d\n", month);
    printf("Day: %d\n", day);

    return 0;
}