//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_DATA 1000000
#define MAX_STRING_LENGTH 100

typedef struct {
    char *filename;
    int num_entries;
    int total_bytes;
} LogFile;

void read_log_file(LogFile *log_file) {
    FILE *fp;
    char buff[MAX_STRING_LENGTH];
    int num_entries = 0;
    int total_bytes = 0;

    fp = fopen(log_file->filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", log_file->filename);
        exit(1);
    }

    while (fgets(buff, MAX_STRING_LENGTH, fp)!= NULL) {
        total_bytes += strlen(buff);
        num_entries++;
    }

    fclose(fp);

    log_file->num_entries = num_entries;
    log_file->total_bytes = total_bytes;
}

void analyze_log_file(LogFile *log_file) {
    double avg_bytes_per_entry;

    avg_bytes_per_entry = (double)log_file->total_bytes / log_file->num_entries;

    printf("Filename: %s\n", log_file->filename);
    printf("Number of entries: %d\n", log_file->num_entries);
    printf("Total bytes: %d\n", log_file->total_bytes);
    printf("Average bytes per entry: %.2f\n", avg_bytes_per_entry);
}

int main() {
    LogFile log_file;

    printf("Enter filename: ");
    scanf("%s", log_file.filename);

    read_log_file(&log_file);
    analyze_log_file(&log_file);

    return 0;
}