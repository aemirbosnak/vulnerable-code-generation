//FormAI DATASET v1.0 Category: Log analysis ; Style: real-life
/*
 * This program analyzes logs from a web server and extracts useful information
 * about the number of requests, unique IP addresses, response codes, and more.
 *
 * The log file should be in the Apache combined log format, where each line
 * has the following format:
 *
 *   remote_host rfc931 authuser [date] "request" status bytes
 *
 * For example:
 *
 *   127.0.0.1 - - [01/Jan/2021:12:00:00 -0500] "GET /index.html HTTP/1.1" 200 1234
 *
 * In this example, the remote host is 127.0.0.1, there is no information about the
 * user's identity or authentication, the date and time of the request is 01/Jan/2021:12:00:00 -0500,
 * the request is "GET /index.html HTTP/1.1", the status code is 200, and the number of bytes
 * in the response is 1234.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

struct log_entry {
    char remote_host[64];
    char rfc931[64];
    char authuser[64];
    char date[64];
    char request[1024];
    int status;
    int bytes;
};

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s log_file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: cannot open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    int num_requests = 0;
    int num_unique_ips = 0;
    int status_codes[6] = { 0 };
    int num_bytes_sent = 0;
    int num_entries = 0;
    char line[MAX_LINE_LENGTH];

    struct log_entry entries[1000];

    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        num_entries++;
        struct log_entry entry;
        sscanf(line, "%s %s %s [%s] \"%[^\"]\" %d %d",
               entry.remote_host, entry.rfc931, entry.authuser,
               entry.date, entry.request, &entry.status, &entry.bytes);

        num_requests++;
        num_bytes_sent += entry.bytes;

        int status = entry.status / 100;

        if (status >= 1 && status <= 5) {
            status_codes[status]++;
        }

        int i;
        for (i = 0; i < num_unique_ips; i++) {
            if (strcmp(entries[i].remote_host, entry.remote_host) == 0) {
                break;
            }
        }

        if (i == num_unique_ips) {
            num_unique_ips++;
        }

        entries[num_unique_ips - 1] = entry;
    }

    printf("Parsed %d log entries from file %s\n", num_entries, argv[1]);
    printf("Number of requests: %d\n", num_requests);
    printf("Number of unique IP addresses: %d\n", num_unique_ips);
    printf("Number of bytes sent: %d\n", num_bytes_sent);
    printf("HTTP status codes:\n");
    printf("  1xx: %d\n", status_codes[1]);
    printf("  2xx: %d\n", status_codes[2]);
    printf("  3xx: %d\n", status_codes[3]);
    printf("  4xx: %d\n", status_codes[4]);
    printf("  5xx: %d\n", status_codes[5]);

    fclose(fp);

    return 0;
}