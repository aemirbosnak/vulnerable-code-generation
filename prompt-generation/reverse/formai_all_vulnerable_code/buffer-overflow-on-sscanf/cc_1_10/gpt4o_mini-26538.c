//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DATE_LENGTH 100

void trim_newline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int parse_date(const char *date_str, struct tm *date) {
    char month[20];
    int day, year;
    if (sscanf(date_str, "%d %s %d", &day, month, &year) != 3) {
        return 0; // Failed to parse
    }

    // Convert month name to number
    char *months[] = {"January", "February", "March", "April", "May", "June",
                      "July", "August", "September", "October", "November", "December"};
    int month_num = -1;
    for (int i = 0; i < 12; i++) {
        if (strcasecmp(months[i], month) == 0) {
            month_num = i;
            break;
        }
    }
    
    if (month_num == -1) return 0; // Invalid month

    date->tm_mday = day;
    date->tm_mon = month_num; // Months are 0-11
    date->tm_year = year - 1900; // Years since 1900
    date->tm_isdst = -1; // Not considering Daylight saving time

    return 1; // Successfully parsed
}

void print_date(struct tm *date) {
    char buffer[100];
    strftime(buffer, sizeof(buffer), "%A, %B %d, %Y", date);
    printf("The date is: %s\n", buffer);
}

int main() {
    char input[MAX_DATE_LENGTH];
    struct tm date = {0};

    printf("Enter a date (e.g., 21 March 2023): ");
    fgets(input, sizeof(input), stdin);
    trim_newline(input);

    if (parse_date(input, &date)) {
        print_date(&date);
    } else {
        printf("Error: Invalid date format.\n");
    }

    return 0;
}