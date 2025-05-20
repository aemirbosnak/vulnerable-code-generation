//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LOG_ENTRY_LENGTH 1024
#define MAX_KEYWORDS 100
#define MAX_KEYWORD_LENGTH 32

struct log_entry {
    char message[MAX_LOG_ENTRY_LENGTH];
    time_t timestamp;
};

struct keyword {
    char keyword[MAX_KEYWORD_LENGTH];
    int count;
};

int num_log_entries = 0;
struct log_entry log_entries[MAX_LOG_ENTRIES];

int num_keywords = 0;
struct keyword keywords[MAX_KEYWORDS];

void log_message(const char* message) {
    if (num_log_entries >= MAX_LOG_ENTRIES) {
        printf("Error: Log is full.\n");
        return;
    }

    strncpy(log_entries[num_log_entries].message, message, MAX_LOG_ENTRY_LENGTH - 1);
    log_entries[num_log_entries].message[MAX_LOG_ENTRY_LENGTH - 1] = '\0';
    log_entries[num_log_entries].timestamp = time(NULL);

    num_log_entries++;
}

void analyze_keywords() {
    char message[MAX_LOG_ENTRY_LENGTH];
    int i;

    for (i = 0; i < num_log_entries; i++) {
        strncpy(message, log_entries[i].message, MAX_LOG_ENTRY_LENGTH - 1);
        message[MAX_LOG_ENTRY_LENGTH - 1] = '\0';

        int j;
        for (j = 0; j < num_keywords; j++) {
            int keyword_length = strlen(keywords[j].keyword);
            int message_length = strlen(message);

            int k;
            for (k = 0; k <= message_length - keyword_length; k++) {
                if (strncasecmp(message + k, keywords[j].keyword, keyword_length) == 0) {
                    keywords[j].count++;
                    break;
                }
            }
        }
    }
}

void print_keyword_counts() {
    printf("Keyword Counts:\n");
    for (int i = 0; i < num_keywords; i++) {
        printf("%s: %d\n", keywords[i].keyword, keywords[i].count);
    }
}

int main() {
    // Initialize keyword table
    struct keyword keywords[MAX_KEYWORDS];
    num_keywords = 0;

    char keyword[MAX_KEYWORD_LENGTH];
    while (1) {
        printf("Enter a keyword (or press enter to finish): ");
        scanf("%s", keyword);

        if (strlen(keyword) == 0) {
            break;
        }

        if (num_keywords >= MAX_KEYWORDS) {
            printf("Error: Too many keywords.\n");
            exit(1);
        }

        strncpy(keywords[num_keywords].keyword, keyword, MAX_KEYWORD_LENGTH - 1);
        keywords[num_keywords].keyword[MAX_KEYWORD_LENGTH - 1] = '\0';
        keywords[num_keywords].count = 0;

        num_keywords++;
    }

    // Start logging messages
    while (1) {
        char message[MAX_LOG_ENTRY_LENGTH];
        printf("Enter a message: ");
        scanf("%s", message);

        log_message(message);
    }

    return 0;
}