//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 1024

struct log_entry {
    char *ip_address;
    char *request_method;
    char *request_url;
    int response_code;
};

struct log_entry *parse_log_line(char *line) {
    struct log_entry *entry = malloc(sizeof(struct log_entry));
    char *token;

    entry->ip_address = strtok(line, " ");
    token = strtok(NULL, " ");
    entry->request_method = strtok(NULL, " ");
    entry->request_url = strtok(NULL, " ");
    entry->response_code = atoi(strtok(NULL, " "));

    return entry;
}

void print_log_entry(struct log_entry *entry) {
    printf("IP Address: %s\n", entry->ip_address);
    printf("Request Method: %s\n", entry->request_method);
    printf("Request URL: %s\n", entry->request_url);
    printf("Response Code: %d\n\n", entry->response_code);
}

void analyze_log_file(char *filename) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    int total_entries = 0;
    int successful_entries = 0;
    int failed_entries = 0;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open log file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        struct log_entry *entry = parse_log_line(line);
        if (entry == NULL) {
            continue;
        }

        total_entries++;

        if (entry->response_code >= 200 && entry->response_code < 300) {
            successful_entries++;
        } else {
            failed_entries++;
        }

        print_log_entry(entry);
        free(entry);
    }

    printf("\nTotal Entries: %d\n", total_entries);
    printf("Successful Entries: %d\n", successful_entries);
    printf("Failed Entries: %d\n", failed_entries);

    fclose(file);
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        exit(1);
    }

    analyze_log_file(argv[1]);

    return 0;
}