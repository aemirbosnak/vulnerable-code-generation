//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store log data
typedef struct {
    char ip[16];
    char date[20];
    char time[10];
    char url[100];
    int http_status;
} log_data;

// Function to parse log data
void parse_log(char* log_entry, log_data* log) {
    char* token;
    int count = 0;

    // Extract IP address
    token = strtok(log_entry, " ");
    strcpy(log->ip, token);
    count++;

    // Extract date and time
    token = strtok(NULL, " ");
    strcpy(log->date, token);
    count++;

    token = strtok(NULL, " ");
    strcpy(log->time, token);
    count++;

    // Extract URL
    token = strtok(NULL, " ");
    strcpy(log->url, token);
    count++;

    // Extract HTTP status code
    token = strtok(NULL, " ");
    log->http_status = atoi(token);
}

// Function to print log data
void print_log(log_data* log) {
    printf("IP address: %s\n", log->ip);
    printf("Date: %s\n", log->date);
    printf("Time: %s\n", log->time);
    printf("URL: %s\n", log->url);
    printf("HTTP status code: %d\n", log->http_status);
}

// Function to analyze log data
void analyze_log(log_data* log) {
    if (log->http_status >= 400) {
        printf("Error: HTTP status code %d\n", log->http_status);
    } else {
        printf("Success: HTTP status code %d\n", log->http_status);
    }
}

// Main function
int main(int argc, char* argv[]) {
    FILE* log_file;
    char log_entry[256];
    log_data log;

    log_file = fopen("logfile.txt", "r");

    if (log_file == NULL) {
        printf("Error: Could not open log file.\n");
        exit(1);
    }

    while (fgets(log_entry, sizeof(log_entry), log_file)!= NULL) {
        parse_log(log_entry, &log);
        print_log(&log);
        analyze_log(&log);
    }

    fclose(log_file);

    return 0;
}