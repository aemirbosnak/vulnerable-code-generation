//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 1000000 // maximum size of log file

struct log_entry {
    char ip_address[16];
    char date_time[20];
    char request_type[10];
    char response_code[4];
    char user_agent[50];
};

int main(int argc, char *argv[]) {
    FILE *log_file;
    struct log_entry log_entries[MAX_LOG_SIZE];
    int num_entries = 0;

    log_file = fopen("log.txt", "r");
    if (log_file == NULL) {
        printf("Error: could not open log file.\n");
        exit(1);
    }

    while (fscanf(log_file, "%s %s %s %s %s\n", log_entries[num_entries].ip_address, log_entries[num_entries].date_time, log_entries[num_entries].request_type, log_entries[num_entries].response_code, log_entries[num_entries].user_agent)!= EOF) {
        num_entries++;
    }

    fclose(log_file);

    // sort log entries by IP address
    for (int i = 0; i < num_entries - 1; i++) {
        for (int j = i + 1; j < num_entries; j++) {
            if (strcmp(log_entries[i].ip_address, log_entries[j].ip_address) > 0) {
                struct log_entry temp = log_entries[i];
                log_entries[i] = log_entries[j];
                log_entries[j] = temp;
            }
        }
    }

    // print summary statistics
    printf("Number of log entries: %d\n", num_entries);
    printf("Unique IP addresses: %d\n", num_entries); // assuming each log entry has a unique IP address

    for (int i = 0; i < num_entries - 1; i++) {
        if (strcmp(log_entries[i].ip_address, log_entries[i + 1].ip_address)!= 0) {
            printf("IP address: %s\n", log_entries[i].ip_address);
        }
    }

    return 0;
}