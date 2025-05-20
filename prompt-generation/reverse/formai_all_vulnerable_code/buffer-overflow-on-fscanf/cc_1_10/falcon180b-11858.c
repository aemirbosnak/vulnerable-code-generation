//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_LOG_ENTRIES 1000
#define LOG_FILE "intrusion_detection.log"

struct log_entry {
    char ip_address[16];
    time_t timestamp;
    char event_type[32];
};

void log_event(char* ip_address, char* event_type) {
    struct log_entry entry;
    strcpy(entry.ip_address, ip_address);
    strcpy(entry.event_type, event_type);
    time(&entry.timestamp);

    FILE* log_file = fopen(LOG_FILE, "a");
    if (log_file!= NULL) {
        fprintf(log_file, "IP Address: %s, Event Type: %s, Timestamp: %s\n", entry.ip_address, entry.event_type, ctime(&entry.timestamp));
        fclose(log_file);
    }
}

int main() {
    FILE* log_file = fopen(LOG_FILE, "r");
    if (log_file == NULL) {
        fprintf(stdout, "Error: Log file not found\n");
        return 1;
    }

    char ip_address[16];
    char event_type[32];
    bool first_entry = true;

    while (fscanf(log_file, "IP Address: %s, Event Type: %s, Timestamp: %s\n", ip_address, event_type, event_type) == 3) {
        if (first_entry) {
            fprintf(stdout, "IP Address\tEvent Type\tTimestamp\n");
            first_entry = false;
        }
        fprintf(stdout, "%s\t%s\t%s\n", ip_address, event_type, ctime(&event_type));
    }

    fclose(log_file);
    return 0;
}