//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: Ada Lovelace
/*
 * Ada Lovelace's Date Converter
 *
 * This program converts a date from one format to another.
 *
 * The input format is:
 *
 *   YYYY-MM-DD
 *
 * The output format is:
 *
 *   DD/MM/YYYY
 *
 * Usage:
 *
 *   ./date_converter YYYY-MM-DD
 *
 * Example:
 *
 *   ./date_converter 2023-03-08
 *
 *   Output:
 *
 *   08/03/2023
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s YYYY-MM-DD\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *input_date = argv[1];

    // Check if the input date is in the correct format.

    if (strlen(input_date) != 10)
    {
        fprintf(stderr, "Error: Invalid date format. Expected YYYY-MM-DD, got %s.\n", input_date);
        return EXIT_FAILURE;
    }

    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7)
        {
            if (input_date[i] != '-')
            {
                fprintf(stderr, "Error: Invalid date format. Expected YYYY-MM-DD, got %s.\n", input_date);
                return EXIT_FAILURE;
            }
        }
        else
        {
            if (!isdigit(input_date[i]))
            {
                fprintf(stderr, "Error: Invalid date format. Expected YYYY-MM-DD, got %s.\n", input_date);
                return EXIT_FAILURE;
            }
        }
    }

    // Extract the year, month, and day from the input date.

    int year = atoi(input_date);
    int month = atoi(input_date + 5);
    int day = atoi(input_date + 8);

    // Check if the year, month, and day are valid.

    if (year < 1 || year > 9999)
    {
        fprintf(stderr, "Error: Invalid year. Expected a year between 1 and 9999, got %d.\n", year);
        return EXIT_FAILURE;
    }

    if (month < 1 || month > 12)
    {
        fprintf(stderr, "Error: Invalid month. Expected a month between 1 and 12, got %d.\n", month);
        return EXIT_FAILURE;
    }

    if (day < 1 || day > 31)
    {
        fprintf(stderr, "Error: Invalid day. Expected a day between 1 and 31, got %d.\n", day);
        return EXIT_FAILURE;
    }

    // Convert the date to the output format.

    char output_date[11];
    sprintf(output_date, "%02d/%02d/%04d", day, month, year);

    // Print the output date.

    printf("%s\n", output_date);

    return EXIT_SUCCESS;
}