//GPT-4o-mini DATASET v1.0 Category: System boot optimizer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#define MAX_BOOT_ENTRIES 100
#define MAX_CMD_LENGTH 256
#define MAX_NAME_LENGTH 50
#define CONFIG_FILE "boot_config.txt"

typedef struct {
    char name[MAX_NAME_LENGTH];
    char command[MAX_CMD_LENGTH];
    int priority;
} BootEntry;

typedef struct {
    BootEntry entries[MAX_BOOT_ENTRIES];
    int count;
} BootConfig;

int load_boot_config(BootConfig *config) {
    FILE *file = fopen(CONFIG_FILE, "r");
    if (!file) {
        perror("Failed to open boot configuration file");
        return -1;
    }
    
    char line[512];
    while (fgets(line, sizeof(line), file) && config->count < MAX_BOOT_ENTRIES) {
        BootEntry *entry = &config->entries[config->count];
        sscanf(line, "%s %s %d", entry->name, entry->command, &entry->priority);
        config->count++;
    }
    
    fclose(file);
    return 0;
}

int compare_entries(const void *a, const void *b) {
    return ((BootEntry *)b)->priority - ((BootEntry *)a)->priority;
}

void optimize_boot_entries(BootConfig *config) {
    qsort(config->entries, config->count, sizeof(BootEntry), compare_entries);
}

void display_boot_entries(const BootConfig *config) {
    printf("Boot Entries:\n");
    for (int i = 0; i < config->count; i++) {
        printf("%d: %s -> %s (Priority: %d)\n", i + 1, config->entries[i].name, config->entries[i].command, config->entries[i].priority);
    }
}

void execute_boot_entries(const BootConfig *config) {
    for (int i = 0; i < config->count; i++) {
        printf("Executing: %s\n", config->entries[i].command);
        int ret = system(config->entries[i].command);
        if (ret != 0) {
            fprintf(stderr, "Failed to execute command: %s\n", config->entries[i].command);
        }
    }
}

void log_execution_time(double duration) {
    FILE *log_file = fopen("boot_log.txt", "a");
    if (log_file) {
        time_t t = time(NULL);
        fprintf(log_file, "[%s] Boot execution time: %.2f seconds\n", ctime(&t), duration);
        fclose(log_file);
    } else {
        perror("Failed to log execution time");
    }
}

int main() {
    BootConfig config;
    config.count = 0;

    if (load_boot_config(&config) != 0) {
        return EXIT_FAILURE;
    }

    optimize_boot_entries(&config);
    display_boot_entries(&config);

    clock_t start_time = clock();
    execute_boot_entries(&config);
    clock_t end_time = clock();

    double duration = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    log_execution_time(duration);

    return EXIT_SUCCESS;
}