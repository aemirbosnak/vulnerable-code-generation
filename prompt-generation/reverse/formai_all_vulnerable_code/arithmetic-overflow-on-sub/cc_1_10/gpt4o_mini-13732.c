//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include <time.h>

// Function to parse the natural language date
int parseDate(const char* dateStr, struct tm* date) {
    regex_t regex;
    regmatch_t pmatch[10];

    // Patterns for different date formats
    const char* patterns[] = {
        "^(\\d{1,2})\\s+(January|February|March|April|May|June|July|August|September|October|November|December)\\s+(\\d{4})$",
        "^(\\d{1,2})/(\\d{1,2})/(\\d{4})$",
        "^(January|February|March|April|May|June|July|August|September|October|November|December)\\s+(\\d{1,2}),\\s+(\\d{4})$",
        "^(\\d{4})-(\\d{1,2})-(\\d{1,2})$"
    };

    const char* months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    for (int i = 0; i < sizeof(patterns) / sizeof(patterns[0]); i++) {
        regcomp(&regex, patterns[i], REG_EXTENDED);
        
        if (regexec(&regex, dateStr, 10, pmatch, 0) == 0) {
            // Match found, process the matched groups
            if (i == 0) { // format: DD Month YYYY
                sscanf(dateStr, "%d %*s %d", &date->tm_mday, &date->tm_year);
                date->tm_year -= 1900; // Adjust year
                // Determine month
                char month[20];
                sscanf(dateStr, "%*d %s %*d", month);
                for (int j = 0; j < 12; j++) {
                    if (strcmp(months[j], month) == 0) {
                        date->tm_mon = j; // Set month
                        break;
                    }
                }
            } else if (i == 1) { // format: DD/MM/YYYY
                sscanf(dateStr, "%d/%d/%d", &date->tm_mday, &date->tm_mon, &date->tm_year);
                date->tm_mon--; // Adjust month (0-11)
            } else if (i == 2) { // format: Month DD, YYYY
                sscanf(dateStr, "%*s %d, %d", &date->tm_mday, &date->tm_year);
                date->tm_year -= 1900; // Adjust year
                // Determine month
                char month[20];
                sscanf(dateStr, "%s %*d, %*d", month);
                for (int j = 0; j < 12; j++) {
                    if (strcmp(months[j], month) == 0) {
                        date->tm_mon = j; // Set month
                        break;
                    }
                }
            } else if (i == 3) { // format: YYYY-MM-DD
                sscanf(dateStr, "%d-%d-%d", &date->tm_year, &date->tm_mon, &date->tm_mday);
                date->tm_year -= 1900; // Adjust year
                date->tm_mon--; // Adjust month (0-11)
            }
            regfree(&regex);
            return 1; // Success
        }
        regfree(&regex);
    }
    return 0; // Failure
}

// Function to print the date
void printDate(const struct tm* date) {
    char buffer[30];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", date);
    printf("Converted Date: %s\n", buffer);
}

int main() {
    char input[100];
    struct tm date = {0};

    printf("Enter a date (natural language): ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline

    if (parseDate(input, &date)) {
        printDate(&date);
    } else {
        printf("Invalid date format!\n");
    }

    return 0;
}