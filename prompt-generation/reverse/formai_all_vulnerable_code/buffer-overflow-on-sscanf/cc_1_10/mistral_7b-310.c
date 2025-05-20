//MISTRAL-7B DATASET v1.0 Category: Log analysis ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define LOG_FILE "access.log"

typedef struct {
    char method[8];
    char status[4];
    char size[12];
    char user[16];
    char referer[256];
    char user_agent[256];
} LogEntry;

void parse_log_line(const char *line, LogEntry *entry) {
    sscanf(line, "%s %s %s %s %s %s %s %s",
           entry->method, entry->status, entry->size, entry->user,
           entry->referer, entry->user_agent, entry->referer + strlen(entry->referer) - 1, entry->user_agent + strlen(entry->user_agent) - 1);
}

void extract_referer_domain(const char *referer, char *domain) {
    regex_t reg;
    int reti;
    size_t nmatch = 1;
    regmatch_t pmatch[1];

    reti = regcomp(&reg, "^(https?://[^/]+)", REG_EXTENDED);
    if (reti) {
        regfree(&reg);
        return;
    }

    reti = regexec(&reg, referer, nmatch, pmatch, 0);
    if (!reti) {
        strncpy(domain, referer + pmatch[0].rm_so, pmatch[0].rm_eo - pmatch[0].rm_so);
        domain[pmatch[0].rm_eo - pmatch[0].rm_so] = '\0';
    }

    regfree(&reg);
}

void print_log_entry(const LogEntry *entry) {
    printf("%-8s %-3s %-11s %-15s %-256s %-256s\n",
           entry->method, entry->status, entry->size, entry->user,
           entry->referer, entry->user_agent);
}

int main() {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    LogEntry entry;
    char referer_domain[256];
    int line_count = 0;

    fp = fopen(LOG_FILE, "r");

    if (fp == NULL) {
        perror("Unable to open log file");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        line_count++;
        parse_log_line(line, &entry);

        if (strstr(line, "GET")) {
            extract_referer_domain(entry.referer, referer_domain);
            if (strlen(referer_domain) > 0) {
                printf("\n--- Entry #%d ---\n", line_count);
                print_log_entry(&entry);
                printf("Referer Domain: %s\n", referer_domain);
            }
        }
    }

    fclose(fp);

    return 0;
}