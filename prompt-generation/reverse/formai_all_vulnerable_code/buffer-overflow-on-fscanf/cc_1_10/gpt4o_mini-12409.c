//GPT-4o-mini DATASET v1.0 Category: System boot optimizer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define FILENAME "boot_times.csv"

typedef struct {
    char timestamp[20];
    double boot_time; // in seconds
} BootEntry;

BootEntry entries[MAX_ENTRIES];
int entry_count = 0;

// Function prototypes
void record_boot_time();
void load_boot_times();
void save_boot_times();
void display_statistics();
void calculate_and_display_average();
void sort_boot_times();
void write_csv_header(FILE *file);
void display_sorted_boot_times();

int main() {
    load_boot_times();

    int choice;

    while (1) {
        printf("\n--- Boot Time Optimizer ---\n");
        printf("1. Record Boot Time\n");
        printf("2. Display Statistics\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                record_boot_time();
                break;
            case 2:
                display_statistics();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void record_boot_time() {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    double boot_time;

    // Get boot time from user
    printf("Enter your boot time in seconds: ");
    scanf("%lf", &boot_time);

    // Record the timestamp and boot time
    snprintf(entries[entry_count].timestamp, sizeof(entries[entry_count].timestamp),
             "%04d-%02d-%02d %02d:%02d:%02d",
             t->tm_year + 1900, t->tm_mon + 1, t->tm_mday,
             t->tm_hour, t->tm_min, t->tm_sec);
    entries[entry_count].boot_time = boot_time;
    entry_count++;

    // Save the new entry to the file
    save_boot_times();
}

void load_boot_times() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("No previous boot time records found. Starting fresh.\n");
        return;
    }

    while (fscanf(file, "%19[^,],%lf\n", entries[entry_count].timestamp, &entries[entry_count].boot_time) == 2) {
        entry_count++;
    }
    fclose(file);
}

void save_boot_times() {
    FILE *file = fopen(FILENAME, "w");
    if (!file) {
        printf("Error saving boot times.\n");
        return;
    }

    write_csv_header(file);
    for (int i = 0; i < entry_count; i++) {
        fprintf(file, "%s,%.2f\n", entries[i].timestamp, entries[i].boot_time);
    }
    fclose(file);
}

void write_csv_header(FILE *file) {
    fprintf(file, "Timestamp,Boot Time (seconds)\n");
}

void calculate_and_display_average() {
    double total_time = 0.0;
    for (int i = 0; i < entry_count; i++) {
        total_time += entries[i].boot_time;
    }
    double average_time = (entry_count > 0) ? total_time / entry_count : 0;

    printf("Average Boot Time: %.2f seconds\n", average_time);
}

void display_statistics() {
    calculate_and_display_average();
    sort_boot_times();
    display_sorted_boot_times();
}

void sort_boot_times() {
    for (int i = 0; i < entry_count - 1; i++) {
        for (int j = i + 1; j < entry_count; j++) {
            if (entries[i].boot_time > entries[j].boot_time) {
                // Swap entries
                BootEntry temp = entries[i];
                entries[i] = entries[j];
                entries[j] = temp;
            }
        }
    }
}

void display_sorted_boot_times() {
    printf("\n--- Sorted Boot Times ---\n");
    for (int i = 0; i < entry_count; i++) {
        printf("Record %d: Timestamp: %s, Boot Time: %.2f seconds\n", 
               i + 1, entries[i].timestamp, entries[i].boot_time);
    }
}