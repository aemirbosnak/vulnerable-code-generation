//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define MAX_INPUT_LENGTH 100
#define MAX_OUTPUT_LENGTH 50

typedef struct {
    char* input;
    char* output;
} ConversionResult;

ConversionResult convert(const char* input, bool is_short_date) {
    time_t timestamp = 0;
    struct tm* tm = NULL;
    char* output = NULL;
    size_t output_length = 0;

    if (strptime(input, "%Y-%m-%d", &tm) == NULL) {
        if (strptime(input, "%m/%d/%y", &tm) == NULL) {
            printf("Invalid input date format\n");
            return (ConversionResult){NULL, NULL};
        }
    }

    if (is_short_date) {
        output_length = snprintf(NULL, 0, "%d/%d/%d", tm->tm_mon + 1, tm->tm_mday, tm->tm_year % 100);
        output = malloc(output_length + 1);
        snprintf(output, output_length + 1, "%d/%d/%d", tm->tm_mon + 1, tm->tm_mday, tm->tm_year % 100);
    } else {
        output_length = strftime(NULL, 0, "%A, %B %d, %Y", tm);
        output = malloc(output_length + 1);
        strftime(output, output_length + 1, "%A, %B %d, %Y", tm);
    }

    return (ConversionResult){input, output};
}

int main() {
    char input[MAX_INPUT_LENGTH];
    char output[MAX_OUTPUT_LENGTH];
    bool is_short_date = false;

    printf("Enter a date in the format YYYY-MM-DD or MM/DD/YYYY: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    if (strlen(input) == 8) {
        is_short_date = true;
        input[2] = '/';
        input[5] = '/';
    } else if (strlen(input) == 10) {
        input[2] = '/';
        input[5] = '/';
    } else {
        printf("Invalid input date format\n");
        return 1;
    }

    ConversionResult result = convert(input, is_short_date);

    if (result.output!= NULL) {
        printf("Converted date: %s\n", result.output);
    } else {
        printf("Invalid input date format\n");
    }

    free(result.input);
    free(result.output);

    return 0;
}