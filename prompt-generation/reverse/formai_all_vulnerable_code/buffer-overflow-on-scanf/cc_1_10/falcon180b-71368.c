//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

struct tm get_date(char *date_str) {
    struct tm date = {0};
    char *ptr = date_str;
    int year = 0, month = 0, day = 0;

    // Extract year
    while (isdigit(*ptr)) {
        year = year * 10 + (*ptr - '0');
        ptr++;
    }
    date.tm_year = year - 1900;

    // Extract month
    while (*ptr!= '\0' &&!isdigit(*ptr)) {
        ptr++;
    }
    while (isdigit(*ptr)) {
        month = month * 10 + (*ptr - '0');
        ptr++;
    }
    date.tm_mon = month - 1;

    // Extract day
    while (*ptr!= '\0' &&!isdigit(*ptr)) {
        ptr++;
    }
    while (isdigit(*ptr)) {
        day = day * 10 + (*ptr - '0');
        ptr++;
    }
    date.tm_mday = day;

    return date;
}

char *format_date(struct tm date, char *format) {
    static char buf[100];
    strftime(buf, sizeof(buf), format, &date);
    return buf;
}

int main() {
    char input_date[100], output_format[100];

    printf("Enter a date (YYYY-MM-DD): ");
    scanf("%s", input_date);

    printf("Enter the desired output format (e.g. \"%A, %B %d, %Y\"): ");
    scanf("%s", output_format);

    struct tm date = get_date(input_date);
    char *formatted_date = format_date(date, output_format);

    printf("The formatted date is: %s\n", formatted_date);

    return 0;
}