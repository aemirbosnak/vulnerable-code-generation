//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_LINE 1024
#define MAX_PATTERN_LEN 1024
#define MAX_PATTERNS 100
#define MAX_LOG_ENTRIES 1000

typedef struct {
    char *pattern;
    int len;
    int count;
} pattern_t;

typedef struct {
    time_t timestamp;
    char ip[16];
    char method[8];
    char url[256];
    char user_agent[256];
} log_entry_t;

pattern_t patterns[MAX_PATTERNS];
int num_patterns = 0;

void add_pattern(char *pattern) {
    if (num_patterns >= MAX_PATTERNS) {
        printf("Error: too many patterns\n");
        return;
    }
    patterns[num_patterns].pattern = strdup(pattern);
    patterns[num_patterns].len = strlen(pattern);
    patterns[num_patterns].count = 0;
    num_patterns++;
}

int match_pattern(char *str, int str_len, pattern_t *pattern) {
    int i;
    for (i = 0; i <= str_len - pattern->len; i++) {
        if (memcmp(str + i, pattern->pattern, pattern->len) == 0) {
            pattern->count++;
            return 1;
        }
    }
    return 0;
}

void analyze_log_entry(log_entry_t *entry) {
    int i;
    for (i = 0; i < num_patterns; i++) {
        if (match_pattern(entry->method, strlen(entry->method), &patterns[i])) {
            printf("ALERT: matched pattern '%s' in method\n", patterns[i].pattern);
        }
        if (match_pattern(entry->url, strlen(entry->url), &patterns[i])) {
            printf("ALERT: matched pattern '%s' in URL\n", patterns[i].pattern);
        }
        if (match_pattern(entry->user_agent, strlen(entry->user_agent), &patterns[i])) {
            printf("ALERT: matched pattern '%s' in user agent\n", patterns[i].pattern);
        }
    }
}

void process_log_file(char *filename) {
    FILE *fp;
    char line[MAX_LINE];
    log_entry_t entry;
    time_t now = time(NULL);
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open log file\n");
        return;
    }
    while (fgets(line, MAX_LINE, fp)!= NULL) {
        if (sscanf(line, "%s %s %s [%s]", entry.ip, entry.method, entry.url, entry.user_agent)!= 4) {
            printf("Error: invalid log entry\n");
            continue;
        }
        entry.timestamp = now;
        analyze_log_entry(&entry);
    }
    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s log_file\n", argv[0]);
        return 1;
    }
    process_log_file(argv[1]);
    return 0;
}