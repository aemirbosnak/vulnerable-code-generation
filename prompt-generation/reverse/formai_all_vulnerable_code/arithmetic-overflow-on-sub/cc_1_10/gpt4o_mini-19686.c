//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_INPUT 256

void trim_newline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int parse_date(const char *input, struct tm *date) {
    char day_string[32];

    if (sscanf(input, "%31[^\n]", day_string) != 1) {
        return -1; 
    }

    if (strcasecmp(day_string, "today") == 0) {
        time_t t = time(NULL);
        *date = *localtime(&t);
        return 0;
    } else if (strcasecmp(day_string, "tomorrow") == 0) {
        time_t t = time(NULL) + 86400; 
        *date = *localtime(&t);
        return 0;
    }

    // Parsing for specific dates
    if (sscanf(input, "%d %d %d", &date->tm_mday, &date->tm_mon, &date->tm_year) == 3) {
        date->tm_mon -= 1;  
        date->tm_year -= 1900; 
        return 0;
    }

    // Parsing natural language for days of the week
    char *days_of_week[] = {"sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday"};
    
    for (int i = 0; i < 7; i++) {
        if (strcasecmp(day_string, days_of_week[i]) == 0) {
            time_t t = time(NULL);
            struct tm *current_date = localtime(&t);
            int days_ahead = (i - current_date->tm_wday + 7) % 7;
            if (days_ahead <= 0) days_ahead += 7;
            t += days_ahead * 86400;
            *date = *localtime(&t);
            return 0;
        }
    }

    return -1; 
}

void convert_date_to_string(struct tm *date, char *output) {
    strftime(output, MAX_INPUT, "%Y-%m-%d", date);
}

int main() {
    char input[MAX_INPUT];
    struct tm date;
    char output[MAX_INPUT];

    printf("Enter a date in natural language (e.g., 'today', 'next Monday', 'March 5 2023'): ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        return EXIT_FAILURE;
    }

    trim_newline(input);

    if (parse_date(input, &date) == -1) {
        fprintf(stderr, "Invalid date format or input.\n");
        return EXIT_FAILURE;
    }

    convert_date_to_string(&date, output);
    printf("The converted date is: %s\n", output);

    return EXIT_SUCCESS;
}