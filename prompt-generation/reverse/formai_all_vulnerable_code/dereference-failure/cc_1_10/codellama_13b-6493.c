//Code Llama-13B DATASET v1.0 Category: Natural Language Date Converter ; Style: cheerful
/*
 * Date Converter
 *
 * This program converts a date from one format to another.
 *
 * Usage:
 *   ./date_converter <input_format> <output_format> <date>
 *
 * Example:
 *   ./date_converter "dd/mm/yyyy" "yyyy-mm-dd" "15/12/2022"
 *   Output: 2022-12-15
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: ./date_converter <input_format> <output_format> <date>\n");
        return 1;
    }

    char *input_format = argv[1];
    char *output_format = argv[2];
    char *date = argv[3];

    if (strcmp(input_format, "dd/mm/yyyy") == 0) {
        int day = atoi(date);
        int month = atoi(date + 3);
        int year = atoi(date + 6);
        printf("%04d-%02d-%02d\n", year, month, day);
    } else if (strcmp(input_format, "mm/dd/yyyy") == 0) {
        int month = atoi(date);
        int day = atoi(date + 3);
        int year = atoi(date + 6);
        printf("%04d-%02d-%02d\n", year, month, day);
    } else if (strcmp(input_format, "yyyy/mm/dd") == 0) {
        int year = atoi(date);
        int month = atoi(date + 5);
        int day = atoi(date + 8);
        printf("%04d-%02d-%02d\n", year, month, day);
    } else if (strcmp(input_format, "yyyy-mm-dd") == 0) {
        int year = atoi(date);
        int month = atoi(date + 5);
        int day = atoi(date + 8);
        printf("%04d-%02d-%02d\n", year, month, day);
    } else {
        fprintf(stderr, "Invalid input format: %s\n", input_format);
        return 1;
    }

    return 0;
}