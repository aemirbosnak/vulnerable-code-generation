//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT 100
#define OUTPUT_BUFFER 128

void parse_date(const char *input, struct tm *date) {
    if (sscanf(input, "%d-%d-%d", &date->tm_year, &date->tm_mon, &date->tm_mday) != 3) {
        fprintf(stderr, "Invalid date format. Use YYYY-MM-DD.\n");
        exit(EXIT_FAILURE);
    }
    date->tm_year -= 1900; // Year since 1900
    date->tm_mon -= 1;     // Month range is 0-11
    date->tm_hour = 0;
    date->tm_min = 0;
    date->tm_sec = 0;
    date->tm_isdst = -1;   // Not considering daylight saving
}

void format_epoch_time(time_t epoch, char *buffer, size_t buffer_size) {
    struct tm *tm_info = localtime(&epoch);
    strftime(buffer, buffer_size, "%Y-%m-%d %H:%M:%S", tm_info);
}

void convert_date_to_epoch(const char *date_str) {
    struct tm date = {0};
    parse_date(date_str, &date);
    time_t epoch_time = mktime(&date);
    
    if (epoch_time == -1) {
        fprintf(stderr, "Error converting date to epoch time.\n");
        exit(EXIT_FAILURE);
    }

    char output[OUTPUT_BUFFER];
    format_epoch_time(epoch_time, output, OUTPUT_BUFFER);
    printf("Epoch time for %s is: %ld\nFormatted as: %s\n", date_str, (long)epoch_time, output);
}

void show_usage() {
    printf("Usage: date_converter <date>\n");
    printf("Date format: YYYY-MM-DD\n");
    printf("Example: date_converter 2023-10-01\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Error: Incorrect number of arguments.\n");
        show_usage();
        return EXIT_FAILURE;
    }
    
    const char *input_date = argv[1];
    
    if (strlen(input_date) > MAX_INPUT) {
        fprintf(stderr, "Error: Input date exceeds maximum length.\n");
        return EXIT_FAILURE;
    }

    convert_date_to_epoch(input_date);
    
    return EXIT_SUCCESS;
}