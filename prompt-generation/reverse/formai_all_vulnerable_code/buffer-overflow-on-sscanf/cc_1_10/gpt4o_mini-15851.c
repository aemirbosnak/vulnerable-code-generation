//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_INPUT 100

void to_lower(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int parse_date(const char *input, struct tm *date) {
    char month[10];
    int day, year;
    if (sscanf(input, "%s %d, %d", month, &day, &year) == 3) {
        to_lower(month);
        
        const char *months[] = {"january", "february", "march", "april", 
                                "may", "june", "july", "august", 
                                "september", "october", "november", "december"};

        for (int i = 0; i < 12; i++) {
            if (strcmp(month, months[i]) == 0) {
                date->tm_mon = i;
                break;
            }
        }
        date->tm_mday = day;
        date->tm_year = year - 1900;  // tm_year is years since 1900
        date->tm_hour = 0;
        date->tm_min = 0;
        date->tm_sec = 0;
        date->tm_isdst = -1;
        return 1;
    }
    return 0;
}

void print_date(const struct tm *date) {
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%A, %B %d, %Y", date);
    printf("Converted date: %s\n", buffer);
}

int is_weekday(const char *day) {
    char *weekdays[] = {"sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday"};
    for (int i = 0; i < 7; i++) {
        if (strcmp(day, weekdays[i]) == 0) {
            return i;
        }
    }
    return -1;
}

void add_days(struct tm *date, int days) {
    const time_t original = mktime(date);
    date->tm_mday += days;
    mktime(date); // Normalize the date
}

int main() {
    char input[MAX_INPUT];
    struct tm date = {0};

    printf("Enter a date (e.g., 'March 14, 2023' or 'next Tuesday'): ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline

    if (strstr(input, "next ")) {
        char day[10];
        sscanf(input, "next %s", day);
        to_lower(day);

        int weekday = is_weekday(day);
        if (weekday == -1) {
            printf("Invalid weekday specified.\n");
            return 1;
        }

        time_t now = time(NULL);
        struct tm *curr_date = localtime(&now);
        
        int days_until_next = (7 + weekday - curr_date->tm_wday) % 7;
        if (days_until_next == 0) days_until_next += 7;  // Go to the next instance

        add_days(curr_date, days_until_next);
        print_date(curr_date);
    } else {
        if (parse_date(input, &date)) {
            print_date(&date);
        } else {
            printf("Invalid date format. Please use 'Month Day, Year'.\n");
        }
    }

    return 0;
}