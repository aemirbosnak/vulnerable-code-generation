//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_STRING_LENGTH 80

typedef struct {
    char *month_name;
    int month_number;
} Month;

Month months[] = {
    {"January", 1},
    {"February", 2},
    {"March", 3},
    {"April", 4},
    {"May", 5},
    {"June", 6},
    {"July", 7},
    {"August", 8},
    {"September", 9},
    {"October", 10},
    {"November", 11},
    {"December", 12}
};

int main(void) {
    char input_string[MAX_STRING_LENGTH];
    char *token;
    int year, month, day;
    Month *month_ptr;

    printf("Enter a date in the format of'month day, year': ");
    fgets(input_string, MAX_STRING_LENGTH, stdin);

    // Remove newline character at the end of input string
    input_string[strcspn(input_string, "\n")] = '\0';

    // Tokenize input string
    token = strtok(input_string, ",");
    if (token == NULL) {
        printf("Invalid input format.\n");
        return 1;
    }
    strcpy(input_string, token);

    if (sscanf(input_string, "%d %s %d", &day, input_string, &year)!= 3) {
        printf("Invalid input format.\n");
        return 1;
    }

    month_ptr = months;
    while (month_ptr->month_name!= NULL) {
        if (strcmp(input_string, month_ptr->month_name) == 0) {
            month = month_ptr->month_number;
            break;
        }
        month_ptr++;
    }

    if (month_ptr->month_name == NULL) {
        printf("Invalid month name.\n");
        return 1;
    }

    printf("Date: %s %d, %d\n", input_string, day, year);
    printf("Formal date: %d-%02d-%02d\n", year, month, day);

    return 0;
}