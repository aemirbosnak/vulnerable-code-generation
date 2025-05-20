//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_LINE_LENGTH 1024
#define MAX_STRING_LENGTH 1024
#define MAX_LOG_ENTRIES 1000

typedef struct {
    char ip[16];
    char method[10];
    char url[1024];
    char user_agent[1024];
    time_t timestamp;
} log_entry_t;

log_entry_t log_entries[MAX_LOG_ENTRIES];
int num_entries = 0;

void add_log_entry(char* ip, char* method, char* url, char* user_agent) {
    strncpy(log_entries[num_entries].ip, ip, 16);
    strncpy(log_entries[num_entries].method, method, 10);
    strncpy(log_entries[num_entries].url, url, 1024);
    strncpy(log_entries[num_entries].user_agent, user_agent, 1024);
    log_entries[num_entries].timestamp = time(NULL);
    num_entries++;
}

void print_log_entries() {
    for(int i=0; i<num_entries; i++) {
        printf("IP: %s\n", log_entries[i].ip);
        printf("Method: %s\n", log_entries[i].method);
        printf("URL: %s\n", log_entries[i].url);
        printf("User-Agent: %s\n", log_entries[i].user_agent);
        printf("Timestamp: %ld\n\n", log_entries[i].timestamp);
    }
}

void analyze_log() {
    FILE* fp = fopen("access.log", "r");
    char line[MAX_LINE_LENGTH];
    while(fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        char* ip = strtok(line, " ");
        char* method = strtok(NULL, " ");
        char* url = strtok(NULL, " ");
        char* user_agent = strtok(NULL, " ");
        add_log_entry(ip, method, url, user_agent);
    }
    fclose(fp);
}

int main() {
    analyze_log();
    print_log_entries();
    return 0;
}