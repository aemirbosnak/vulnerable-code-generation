//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include <ctype.h>

#define BUFFER_SIZE 256

char naturalLanguageDate[BUFFER_SIZE];

void *processDate(void *arg) {
    char *dateStr = (char *)arg;
    struct tm tm;
    char buffer[BUFFER_SIZE];
    char *ptr;

    // Initialize the tm structure
    memset(&tm, 0, sizeof(tm));

    // Parse the natural language date
    if (strstr(dateStr, "today")) {
        time_t now;
        time(&now);
        memcpy(&tm, localtime(&now), sizeof(tm));
    } else if (sscanf(dateStr, "tomorrow %d %s", &tm.tm_mday, buffer) == 2) {
        time_t now;
        time(&now);
        memcpy(&tm, localtime(&now), sizeof(tm));
        tm.tm_mday += 1;
    } else if (sscanf(dateStr, "yesterday %d %s", &tm.tm_mday, buffer) == 2) {
        time_t now;
        time(&now);
        memcpy(&tm, localtime(&now), sizeof(tm));
        tm.tm_mday -= 1;
    } else if (sscanf(dateStr, "%d %s", &tm.tm_mday, buffer) == 2) {
        // Try to parse a specific date
        tm.tm_year = tm.tm_year + 1900; // Base year
        char *month = buffer;
        if (strcasecmp(month, "January") == 0) {
            tm.tm_mon = 0;
        } else if (strcasecmp(month, "February") == 0) {
            tm.tm_mon = 1;
        } else if (strcasecmp(month, "March") == 0) {
            tm.tm_mon = 2;
        } else if (strcasecmp(month, "April") == 0) {
            tm.tm_mon = 3;
        } else if (strcasecmp(month, "May") == 0) {
            tm.tm_mon = 4;
        } else if (strcasecmp(month, "June") == 0) {
            tm.tm_mon = 5;
        } else if (strcasecmp(month, "July") == 0) {
            tm.tm_mon = 6;
        } else if (strcasecmp(month, "August") == 0) {
            tm.tm_mon = 7;
        } else if (strcasecmp(month, "September") == 0) {
            tm.tm_mon = 8;
        } else if (strcasecmp(month, "October") == 0) {
            tm.tm_mon = 9;
        } else if (strcasecmp(month, "November") == 0) {
            tm.tm_mon = 10;
        } else if (strcasecmp(month, "December") == 0) {
            tm.tm_mon = 11;
        }

        // Adjust for year if mentioned
        if (sscanf(dateStr, "%*d %*s %d", &tm.tm_year) == 1) {
            tm.tm_year -= 1900; // Set year to be relative to 1900
        }
    } else {
        printf("Could not understand the date: %s\n", dateStr);
        return NULL;
    }

    // Normalize and format the date
    mktime(&tm);
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", &tm);
    printf("Formatted Date: %s\n", buffer);
    return NULL;
}

int main() {
    pthread_t thread;
    printf("Enter a natural language date (e.g., 'today', 'tomorrow', '3 March 2025': ");
    fgets(naturalLanguageDate, BUFFER_SIZE, stdin);
    // Remove newline character
    naturalLanguageDate[strcspn(naturalLanguageDate, "\n")] = 0;

    if (pthread_create(&thread, NULL, processDate, (void *)naturalLanguageDate) != 0) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }

    // Wait for the thread to finish
    pthread_join(thread, NULL);
    return 0;
}