//MISTRAL-7B DATASET v1.0 Category: Log analysis ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_LOG_FILES 10
#define LOG_FILE_NAME_LENGTH 50

typedef struct {
    char timestamp[32];
    char client_ip[16];
    char request[256];
    char status[16];
    char size[16];
    char referer[128];
    char user_agent[128];
} log_entry;

void process_line(char *line, log_entry *entry) {
    sscanf(line, "%s %s %s %s %s %s %s", entry->timestamp, entry->client_ip, entry->request, entry->status, entry->size, entry->referer, entry->user_agent);
    for (int i = 0; i < strlen(entry->client_ip); i++) {
        entry->client_ip[i] = toupper(entry->client_ip[i]);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        perror("Error opening file");
        return 1;
    }

    log_entry log_entries[MAX_LOG_FILES];
    int entry_count = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        log_entry entry;
        process_line(line, &entry);
        log_entries[entry_count++] = entry;
    }

    fclose(fp);

    printf("===========\n");
    printf("POST-APOCALYPSE LOG ANALYSIS\n");
    printf("===========\n");

    int survivors = 0;
    int infected = 0;

    for (int i = 0; i < entry_count; i++) {
        if (strstr(log_entries[i].user_agent, "Zombie") || strstr(log_entries[i].user_agent, "Walker")) {
            infected++;
        } else {
            survivors++;
        }
    }

    printf("===========\n");
    printf("STATS:\n");
    printf("===========\n");
    printf("Survivors: %d\n", survivors);
    printf("Infected: %d\n", infected);
    printf("===========\n");

    return 0;
}