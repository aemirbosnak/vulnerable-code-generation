//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: Sherlock Holmes
#include <stdio.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LOG_ENTRY_LENGTH 256

struct log_entry {
    char ip[16];
    char date_time[24];
    char request[MAX_LOG_ENTRY_LENGTH];
};

void analyze_log_file(FILE *log_file, int *suspicious_activity_count) {
    struct log_entry log_entries[MAX_LOG_ENTRIES];
    int entry_count = 0;

    while (fscanf(log_file, "%s %s %s\n", log_entries[entry_count].ip, log_entries[entry_count].date_time, log_entries[entry_count].request)!= EOF) {
        entry_count++;

        if (entry_count >= MAX_LOG_ENTRIES) {
            break;
        }
    }

    for (int i = 0; i < entry_count; i++) {
        if (strcmp(log_entries[i].request, "admin.php") == 0) {
            (*suspicious_activity_count)++;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    FILE *log_file = fopen(argv[1], "r");

    if (log_file == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    int suspicious_activity_count = 0;

    analyze_log_file(log_file, &suspicious_activity_count);

    fclose(log_file);

    if (suspicious_activity_count > 0) {
        printf("Suspicious activity detected: %d attempts to access admin.php\n", suspicious_activity_count);
    } else {
        printf("No suspicious activity detected.\n");
    }

    return 0;
}