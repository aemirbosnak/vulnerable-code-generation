//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT 100
#define MAX_DAY_ARRAY 7
#define MAX_MONTH_ARRAY 12

const char *dayNames[MAX_DAY_ARRAY] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
const char *monthNames[MAX_MONTH_ARRAY] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

void printUsage() {
    printf("========= Natural Language Date Converter =========\n");
    printf("Enter a date in natural language like:\n");
    printf("  - 'next Friday'\n");
    printf("  - 'last Tuesday of March'\n");
    printf("  - 'three days from today'\n");
    printf("  - 'first of January'\n");
    printf("  - 'yesterday'\n");
    printf("===================================================\n");
}

int getDayOfWeek(const char *day) {
    for (int i = 0; i < MAX_DAY_ARRAY; i++) {
        if (strcasecmp(day, dayNames[i]) == 0) {
            return i;
        }
    }
    return -1;
}

int getMonth(const char *month) {
    for (int i = 0; i < MAX_MONTH_ARRAY; i++) {
        if (strcasecmp(month, monthNames[i]) == 0) {
            return i;
        }
    }
    return -1;
}

void getDateFromInput(const char *input, struct tm *date) {
    time_t now = time(NULL);
    localtime_r(&now, date);

    char command[MAX_INPUT];
    strcpy(command, input);

    // Fill the date based on the command
    if (strstr(command, "today")) {
        // do nothing as `date` is initialized to current date
    } else if (strstr(command, "yesterday")) {
        date->tm_mday -= 1;
    } else if (strstr(command, "tomorrow")) {
        date->tm_mday += 1;
    } else if (sscanf(command, "next %s", command) == 1) {
        int weekday = getDayOfWeek(command);
        if (weekday != -1) {
            date->tm_mday += (weekday - date->tm_wday + 7) % 7 + 1;
        }
    } else if (sscanf(command, "last %s", command) == 1) {
        int weekday = getDayOfWeek(command);
        if (weekday != -1) {
            date->tm_mday += (weekday - date->tm_wday - 7) % 7;
        }
    } else if (strstr(command, "days from today")) {
        int days;
        if (sscanf(command, "%d days from today", &days) == 1) {
            date->tm_mday += days;
        }
    } else if (strstr(command, "first of")) {
        char month[20];
        if (sscanf(command, "first of %s", month) == 1) {
            int m = getMonth(month);
            if (m != -1) {
                date->tm_mon = m;
                date->tm_mday = 1;
            }
        }
    } else if (strstr(command, "last")) {
        char day[20], month[20];
        if (sscanf(command, "last %s of %s", day, month) == 2) {
            int m = getMonth(month);
            if (m != -1) {
                date->tm_mon = m;
                date->tm_mday = 0;  // Go to last day of the month
                mktime(date); // Normalize date
            }
        }
    }
}

int main() {
    char input[MAX_INPUT];
    struct tm date;

    printUsage();

    printf(">>> Enter your date request: ");
    fgets(input, MAX_INPUT, stdin);
    input[strcspn(input, "\n")] = 0; // Remove trailing newline

    getDateFromInput(input, &date);
    mktime(&date); // Normalize the tm structure

    printf("Converted Date: %s, %02d %s %d\n",
           dayNames[date.tm_wday],
           date.tm_mday,
           monthNames[date.tm_mon],
           date.tm_year + 1900);

    return 0;
}