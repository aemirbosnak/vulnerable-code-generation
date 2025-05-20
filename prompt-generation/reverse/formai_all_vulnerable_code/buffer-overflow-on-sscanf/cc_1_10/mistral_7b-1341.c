//MISTRAL-7B DATASET v1.0 Category: Log analysis ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure for storing log data
typedef struct {
    char timestamp[20];
    char level[10];
    char message[256];
} log_entry;

void parse_log_line(char *line, log_entry *entry) {
    sscanf(line, "%s %s %s", entry->timestamp, entry->level, entry->message);
}

int main() {
    FILE *log_file;
    char line[1024];
    log_entry current_entry;
    int entry_count = 0;

    // Open log file
    log_file = fopen("medieval_log.txt", "r");
    if (log_file == NULL) {
        perror("Error opening log file");
        return 1;
    }

    // Analyze log entries
    while (fgets(line, sizeof(line), log_file) != NULL) {
        parse_log_line(line, &current_entry);

        // Medieval-style error reporting
        if (strcmp(current_entry.level, "ERROR") == 0) {
            printf("Oh, woe is me! A %s hath befallen us:\n", current_entry.level);
            printf("%s: %s\n", current_entry.timestamp, current_entry.message);
        } else if (strcmp(current_entry.level, "WARNING") == 0) {
            printf("Beware, kind sir! A %s hath been spotted:\n", current_entry.level);
            printf("%s: %s\n", current_entry.timestamp, current_entry.message);
        } else if (strcmp(current_entry.level, "INFO") != 0) {
            // Ignore unknown log levels
            continue;
        } else {
            printf("A new day hath dawned, and with it, these tidings:\n");
            printf("%s: %s\n", current_entry.timestamp, current_entry.message);
        }

        entry_count++;
    }

    // Medieval-style summary
    printf("Thus endeth the tale of %d entries.\n", entry_count);

    // Close log file
    fclose(log_file);

    return 0;
}

// Example log file format:
// 15:30:12 ERROR: An unexpected guest hath arrived at the castle gate.
// 15:30:15 WARNING: A dragon hath been sighted in the nearby forest.
// 15:30:18 INFO: The sun hath set, and the moon is now shining bright.