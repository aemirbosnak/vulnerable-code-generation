//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_ENTRIES 1000
#define LOG_FILE "intrusion_detection.log"

typedef struct {
    time_t timestamp;
    char ip[16];
    char method[10];
    char url[100];
    int status_code;
    int bytes_sent;
} LogEntry;

void log_request(LogEntry* entry) {
    FILE* log_file = fopen(LOG_FILE, "a");
    if (log_file == NULL) {
        fprintf(stderr, "Error opening log file\n");
        return;
    }
    fprintf(log_file, "Timestamp: %ld\nIP: %s\nMethod: %s\nURL: %s\nStatus Code: %d\nBytes Sent: %d\n",
        entry->timestamp, entry->ip, entry->method, entry->url, entry->status_code, entry->bytes_sent);
    fclose(log_file);
}

int main() {
    FILE* log_file = fopen(LOG_FILE, "r");
    if (log_file == NULL) {
        fprintf(stderr, "Error opening log file\n");
        return 1;
    }
    LogEntry entries[MAX_LOG_ENTRIES];
    int num_entries = 0;
    while (fscanf(log_file, "Timestamp: %ld\nIP: %s\nMethod: %s\nURL: %s\nStatus Code: %d\nBytes Sent: %d\n",
            &entries[num_entries].timestamp, entries[num_entries].ip, entries[num_entries].method, entries[num_entries].url,
            &entries[num_entries].status_code, &entries[num_entries].bytes_sent) == 6) {
        num_entries++;
        if (num_entries == MAX_LOG_ENTRIES) {
            break;
        }
    }
    fclose(log_file);

    for (int i = 0; i < num_entries; i++) {
        time_t current_time = time(NULL);
        if (difftime(current_time, entries[i].timestamp) > 60) {
            log_request(&entries[i]);
        }
    }

    return 0;
}