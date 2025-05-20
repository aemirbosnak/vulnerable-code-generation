//FormAI DATASET v1.0 Category: Log analysis ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LINE_LENGTH 1024
#define MAX_TIMESTAMP_LENGTH 25

/* Structure to hold log entries */
typedef struct {
    char timestamp[MAX_TIMESTAMP_LENGTH];
    char message[MAX_LINE_LENGTH];
} log_entry;

/* Function to parse log file and create log entries */
int parse_log_file(char *filename, log_entry *log_entries) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    int num_entries = 0;

    /* Open log file for reading */
    if ((fp = fopen(filename, "r")) == NULL) {
        printf("Error opening file %s\n", filename);
        return -1;
    }

    /* Read each line of the log file */
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        /* Copy timestamp and message to log entry structure */
        sscanf(line, "%s %[^\n]", log_entries[num_entries].timestamp, log_entries[num_entries].message);
        num_entries++;
    }

    /* Close log file */
    fclose(fp);

    return num_entries;
}

/* Function to print log entries */
void print_log_entries(log_entry *log_entries, int num_entries) {
    int i;

    for (i = 0; i < num_entries; i++) {
        printf("%s %s\n", log_entries[i].timestamp, log_entries[i].message);
    }
}

/* Function to find log entries containing specified search string */
void search_log_entries(log_entry *log_entries, int num_entries, char *search_string) {
    int i;

    printf("Log entries containing \"%s\":\n", search_string);

    for (i = 0; i < num_entries; i++) {
        if (strstr(log_entries[i].message, search_string) != NULL) {
            printf("%s %s\n", log_entries[i].timestamp, log_entries[i].message);
        }
    }
}

int main(int argc, char **argv) {
    log_entry log_entries[MAX_LOG_ENTRIES];
    int num_entries;
    char search_string[MAX_LINE_LENGTH];

    if (argc != 2) {
        printf("Usage: %s logfile\n", argv[0]);
        return -1;
    }

    /* Parse log file and create log entries */
    num_entries = parse_log_file(argv[1], log_entries);

    /* Print log entries */
    print_log_entries(log_entries, num_entries);

    /* Get search string from user and search log entries */
    printf("Enter search string: ");
    fgets(search_string, MAX_LINE_LENGTH, stdin);
    search_log_entries(log_entries, num_entries, search_string);

    return 0;
}