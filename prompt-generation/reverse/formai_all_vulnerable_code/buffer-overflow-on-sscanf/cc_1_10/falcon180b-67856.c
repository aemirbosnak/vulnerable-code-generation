//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LOG_SIZE 1000000 // Maximum size of log file
#define MAX_LINE_SIZE 1000 // Maximum size of each line in log file

typedef struct {
    int count; // Count of occurrences of this IP address
    char ip[16]; // IP address
} IP;

typedef struct {
    int count; // Count of occurrences of this URL
    char url[256]; // URL
} URL;

typedef struct {
    IP *ip; // Pointer to IP address structure
    URL *url; // Pointer to URL structure
} Entry;

void read_log_file(char *filename, Entry *entries, int *num_entries) {
    FILE *fp;
    char line[MAX_LINE_SIZE];
    char *token;
    int num_tokens;
    IP current_ip;
    URL current_url;
    int i;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open log file.\n");
        exit(1);
    }

    *num_entries = 0;

    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        num_tokens = sscanf(line, "%15s %s %s [%d] \"%[^\"]\" %d %d", &current_ip.ip, &current_url.url, &token, &i, &token, &i, &i);
        if (num_tokens == 7) {
            strcpy(current_ip.ip, token);
            strcpy(current_url.url, token);
            entries[*num_entries] = (Entry) {&current_ip, &current_url};
            (*num_entries)++;
        }
    }

    fclose(fp);
}

void print_entries(Entry *entries, int num_entries) {
    int i;

    for (i = 0; i < num_entries; i++) {
        printf("%-15s %-40s %s\n", entries[i].ip->ip, entries[i].url->url, entries[i].ip->count);
    }
}

int main() {
    Entry entries[MAX_LOG_SIZE];
    int num_entries;

    read_log_file("logfile.txt", entries, &num_entries);
    print_entries(entries, num_entries);

    return 0;
}