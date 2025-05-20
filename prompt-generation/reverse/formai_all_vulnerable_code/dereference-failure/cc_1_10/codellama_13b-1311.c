//Code Llama-13B DATASET v1.0 Category: Log analysis ; Style: Linus Torvalds
/*
 * C Log Analysis Program
 *
 * This program is an example of a C program that analyzes a log file
 * and displays the results in a user-friendly format.
 *
 * Usage: ./log_analysis <log_file>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define MAX_FIELDS 10

typedef struct {
    char ip[16];
    char user[32];
    char timestamp[64];
    char request[128];
    char status[8];
    char size[16];
    char referrer[128];
    char agent[128];
} LogEntry;

int main(int argc, char *argv[]) {
    FILE *log_file;
    char line[MAX_LINE_LEN];
    LogEntry entry;
    int i, j, n_fields, n_entries;
    char *field[MAX_FIELDS];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    log_file = fopen(argv[1], "r");
    if (log_file == NULL) {
        fprintf(stderr, "Error: unable to open file %s\n", argv[1]);
        return 1;
    }

    n_entries = 0;
    while (fgets(line, MAX_LINE_LEN, log_file) != NULL) {
        n_fields = 0;
        field[n_fields++] = strtok(line, " ");
        while ((field[n_fields++] = strtok(NULL, " ")) != NULL) {
            if (n_fields == MAX_FIELDS) {
                fprintf(stderr, "Error: too many fields in line %d\n", n_entries + 1);
                return 1;
            }
        }
        if (n_fields < MAX_FIELDS) {
            fprintf(stderr, "Error: too few fields in line %d\n", n_entries + 1);
            return 1;
        }

        strcpy(entry.ip, field[0]);
        strcpy(entry.user, field[1]);
        strcpy(entry.timestamp, field[2]);
        strcpy(entry.request, field[3]);
        strcpy(entry.status, field[4]);
        strcpy(entry.size, field[5]);
        strcpy(entry.referrer, field[6]);
        strcpy(entry.agent, field[7]);

        n_entries++;
    }

    printf("Log File Analysis\n");
    printf("----------------\n");
    printf("Total number of entries: %d\n", n_entries);
    printf("Unique IP addresses: %d\n", n_entries);
    printf("Unique users: %d\n", n_entries);
    printf("Unique timestamps: %d\n", n_entries);
    printf("Unique request paths: %d\n", n_entries);
    printf("Unique status codes: %d\n", n_entries);
    printf("Unique size codes: %d\n", n_entries);
    printf("Unique referrer URLs: %d\n", n_entries);
    printf("Unique user agents: %d\n", n_entries);

    return 0;
}