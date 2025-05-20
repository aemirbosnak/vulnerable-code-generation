//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: puzzling
#include <stdio.h>

int main() {
    int day, month, year;
    char input_format[10], output_format[10];

    // Puzzle piece 1: Get input date and format
    printf("Enter date in DD/MM/YYYY format: ");
    scanf("%d/%d/%d", &day, &month, &year);
    printf("Enter input format (DD/MM/YYYY, MM/DD/YYYY, YYYY/MM/DD, YYYY/DD/MM): ");
    scanf("%s", input_format);

    // Puzzle piece 2: Determine output format
    printf("Enter output format (DD/MM/YYYY, MM/DD/YYYY, YYYY/MM/DD, YYYY/DD/MM): ");
    scanf("%s", output_format);

    // Puzzle piece 3: Convert input date to decimal format
    int decimal_date;
    if (input_format[0] == 'D' && input_format[1] == 'D') { // DD/MM/YYYY
        decimal_date = year * 10000 + month * 100 + day;
    } else if (input_format[3] == 'D' && input_format[4] == 'D') { // MM/DD/YYYY
        decimal_date = year * 10000 + day * 100 + month;
    } else if (input_format[5] == 'D' && input_format[6] == 'D') { // YYYY/MM/DD
        decimal_date = day * 10000 + month * 100 + year;
    } else if (input_format[8] == 'D' && input_format[9] == 'D') { // YYYY/DD/MM
        decimal_date = month * 10000 + day * 100 + year;
    }

    // Puzzle piece 4: Convert decimal date to output format
    int output_day, output_month, output_year;
    if (output_format[0] == 'D' && output_format[1] == 'D') { // DD/MM/YYYY
        output_day = decimal_date % 100;
        output_month = (decimal_date / 100) % 100;
        output_year = decimal_date / 10000;
    } else if (output_format[3] == 'D' && output_format[4] == 'D') { // MM/DD/YYYY
        output_month = decimal_date % 100;
        output_day = (decimal_date / 100) % 100;
        output_year = decimal_date / 10000;
    } else if (output_format[5] == 'D' && output_format[6] == 'D') { // YYYY/MM/DD
        output_year = decimal_date % 10000;
        output_month = (decimal_date / 10000) % 100;
        output_day = decimal_date / 1000000;
    } else if (output_format[8] == 'D' && output_format[9] == 'D') { // YYYY/DD/MM
        output_year = decimal_date % 10000;
        output_day = decimal_date / 10000;
        output_month = (decimal_date / 100) % 100;
    }

    // Puzzle piece 5: Print output date
    printf("Output date: %02d/%02d/%04d\n", output_day, output_month, output_year);

    return 0;
}