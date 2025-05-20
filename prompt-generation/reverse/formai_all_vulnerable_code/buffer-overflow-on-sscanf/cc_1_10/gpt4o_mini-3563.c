//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_LOG_LEVELS 3

typedef struct LogEntry {
    char level[10];
    char message[200];
} LogEntry;

typedef struct LogSummary {
    int info_count;
    int warning_count;
    int error_count;
} LogSummary;

void initialize_summary(LogSummary *summary) {
    summary->info_count = 0;
    summary->warning_count = 0;
    summary->error_count = 0;
}

void parse_log_file(const char *filename, LogSummary *summary) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening log file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        LogEntry entry;
        
        // Example log file format: [INFO] Some log message
        sscanf(line, "[%9[^]]] %[^\n]", entry.level, entry.message);

        if (strcmp(entry.level, "INFO") == 0) {
            summary->info_count++;
        } else if (strcmp(entry.level, "WARNING") == 0) {
            summary->warning_count++;
        } else if (strcmp(entry.level, "ERROR") == 0) {
            summary->error_count++;
        }
    }

    fclose(file);
}

void display_summary(const LogSummary *summary) {
    printf("Log Summary:\n");
    printf("INFO Count: %d\n", summary->info_count);
    printf("WARNING Count: %d\n", summary->warning_count);
    printf("ERROR Count: %d\n", summary->error_count);
}

void generate_report(const char* output_filename, const LogSummary *summary) {
    FILE *output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        perror("Error opening output file");
        return;
    }

    fprintf(output_file, "Log Summary Report:\n");
    fprintf(output_file, "INFO Count: %d\n", summary->info_count);
    fprintf(output_file, "WARNING Count: %d\n", summary->warning_count);
    fprintf(output_file, "ERROR Count: %d\n", summary->error_count);

    fclose(output_file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <logfile> <outputfile>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *logfile = argv[1];
    const char *outputfile = argv[2];

    LogSummary summary;
    initialize_summary(&summary);

    parse_log_file(logfile, &summary);
    display_summary(&summary);
    generate_report(outputfile, &summary);

    return EXIT_SUCCESS;
}