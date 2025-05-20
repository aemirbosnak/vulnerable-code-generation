//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100
#define MAX_DATE_LENGTH 100

void getCurrentDate(char* buffer) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(buffer, MAX_DATE_LENGTH, "%Y-%m-%d", t);
}

int parseNaturalDate(const char* input, char* output) {
    struct tm date = {0};
    time_t now = time(NULL);
    struct tm *current = localtime(&now);
    char command[MAX_INPUT_LENGTH];

    if (sscanf(input, "%s", command) == 1) {
        if (strcmp(command, "today") == 0) {
            getCurrentDate(output);
            return 1;
        } else if (strcmp(command, "tomorrow") == 0) {
            current->tm_mday += 1;
            mktime(current);
            strftime(output, MAX_DATE_LENGTH, "%Y-%m-%d", current);
            return 1;
        } else if (strcmp(command, "yesterday") == 0) {
            current->tm_mday -= 1;
            mktime(current);
            strftime(output, MAX_DATE_LENGTH, "%Y-%m-%d", current);
            return 1;
        } else if (sscanf(input, "%d days from now", &date.tm_mday) == 1) {
            current->tm_mday += date.tm_mday;
            mktime(current);
            strftime(output, MAX_DATE_LENGTH, "%Y-%m-%d", current);
            return 1;
        } else if (sscanf(input, "%d days ago", &date.tm_mday) == 1) {
            current->tm_mday -= date.tm_mday;
            mktime(current);
            strftime(output, MAX_DATE_LENGTH, "%Y-%m-%d", current);
            return 1;
        } else if (sscanf(input, "next %s", command) == 1) {
            if (strcmp(command, "Monday") == 0) {
                current->tm_mday += (1 - current->tm_wday + 7) % 7 + 7;
            } else if (strcmp(command, "Tuesday") == 0) {
                current->tm_mday += (2 - current->tm_wday + 7) % 7 + 7;
            } else if (strcmp(command, "Wednesday") == 0) {
                current->tm_mday += (3 - current->tm_wday + 7) % 7 + 7;
            } else if (strcmp(command, "Thursday") == 0) {
                current->tm_mday += (4 - current->tm_wday + 7) % 7 + 7;
            } else if (strcmp(command, "Friday") == 0) {
                current->tm_mday += (5 - current->tm_wday + 7) % 7 + 7;
            } else if (strcmp(command, "Saturday") == 0) {
                current->tm_mday += (6 - current->tm_wday + 7) % 7 + 7;
            } else if (strcmp(command, "Sunday") == 0) {
                current->tm_mday += (0 - current->tm_wday + 7) % 7 + 7;
            } else {
                return 0; // Unknown day
            }
            mktime(current);
            strftime(output, MAX_DATE_LENGTH, "%Y-%m-%d", current);
            return 1;
        }
    }
    return 0; // Parsing failed
}

int main() {
    char input[MAX_INPUT_LENGTH];
    char output[MAX_DATE_LENGTH];

    printf("Enter a natural language date (e.g., \"today\", \"next Friday\", \"3 days from now\"): ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Remove newline character from the input
    input[strcspn(input, "\n")] = 0;

    if (parseNaturalDate(input, output)) {
        printf("Converted date: %s\n", output);
    } else {
        printf("Could not understand the date input. Please try again.\n");
    }

    return 0;
}