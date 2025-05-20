//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

#define MAX_DATE_LENGTH 100

struct tm parse_date(const char *date_str, const char *format)
{
    struct tm result = {0};
    strptime(date_str, format, &result);
    return result;
}

char *format_date(const struct tm *tm, const char *format)
{
    size_t buf_size = strlen(format) + 1;
    char *buf = malloc(buf_size);
    if (!buf) {
        fprintf(stderr, "Error: Unable to allocate memory.\n");
        exit(EXIT_FAILURE);
    }

    strftime(buf, buf_size, format, tm);

    return buf;
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");

    if (argc!= 4) {
        fprintf(stderr, "Usage: %s input_date_format output_date_format input_date\n", argv[0]);
        return 1;
    }

    const char *input_format = argv[1];
    const char *output_format = argv[2];
    const char *input_date = argv[3];

    struct tm input_tm = parse_date(input_date, input_format);
    char *output_date = format_date(&input_tm, output_format);

    printf("Input date: %s\n", input_date);
    printf("Output date: %s\n", output_date);

    free(output_date);
    return 0;
}