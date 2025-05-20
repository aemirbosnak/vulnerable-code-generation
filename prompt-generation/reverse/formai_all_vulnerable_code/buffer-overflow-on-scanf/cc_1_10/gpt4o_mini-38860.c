//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/statvfs.h>
#include <time.h>

#define MAX_LOG_ENTRIES 100
#define LOG_FILE "disk_usage.log"

typedef struct {
    time_t timestamp;
    unsigned long total_size;
    unsigned long free_size;
    unsigned long used_size;
} LogEntry;

void log_usage(LogEntry *entry, int index) {
    FILE *fp = fopen(LOG_FILE, "a");
    if (fp != NULL) {
        fprintf(fp, "Entry %d: [%s] Total: %lu MB, Used: %lu MB, Free: %lu MB\n", 
                index, ctime(&(entry->timestamp)), 
                entry->total_size / (1024 * 1024), 
                entry->used_size / (1024 * 1024), 
                entry->free_size / (1024 * 1024));
        fclose(fp);
    } else {
        perror("Failed to open log file");
    }
}

void print_statistics(LogEntry log[], int count) {
    printf("\nDisk Usage Statistics:\n");
    printf("--------------------------------------------------------\n");
    printf("%-20s %-15s %-15s %-15s\n", "Timestamp", "Total (MB)", "Used (MB)", "Free (MB)");
    printf("--------------------------------------------------------\n");
    for (int i = 0; i < count; ++i) {
        printf("%-20s %-15lu %-15lu %-15lu\n", 
                ctime(&(log[i].timestamp)), 
                log[i].total_size / (1024 * 1024), 
                log[i].used_size / (1024 * 1024), 
                log[i].free_size / (1024 * 1024));
    }
    printf("--------------------------------------------------------\n");
}

void check_disk_usage() {
    struct statvfs stat;

    if (statvfs("/", &stat) != 0) {
        perror("statvfs failed");
        return; // Error occurred
    }

    unsigned long total_size = stat.f_blocks * stat.f_frsize;
    unsigned long free_size = stat.f_bfree * stat.f_frsize;
    unsigned long used_size = total_size - free_size;

    printf("Disk Usage:\n");
    printf("Total Size: %lu MB\n", total_size / (1024 * 1024));
    printf("Used Size: %lu MB\n", used_size / (1024 * 1024));
    printf("Free Size: %lu MB\n", free_size / (1024 * 1024));
    printf("--------------------------------------------------------\n");
}

int main() {
    LogEntry logs[MAX_LOG_ENTRIES];
    int log_count = 0;
    char choice;

    do {
        check_disk_usage();

        if (log_count < MAX_LOG_ENTRIES) {
            logs[log_count].timestamp = time(NULL);
            struct statvfs stat;
            statvfs("/", &stat);
            logs[log_count].total_size = stat.f_blocks * stat.f_frsize;
            logs[log_count].free_size = stat.f_bfree * stat.f_frsize;
            logs[log_count].used_size = logs[log_count].total_size - logs[log_count].free_size;

            log_usage(&logs[log_count], log_count + 1);
            log_count++;
        } else {
            printf("Log limit reached. No more entries will be logged.\n");
        }

        printf("Do you want to check disk usage again? (y/n): ");
        scanf(" %c", &choice);
        printf("--------------------------------------------------------\n");

    } while (choice == 'y' || choice == 'Y');

    print_statistics(logs, log_count);

    return 0;
}