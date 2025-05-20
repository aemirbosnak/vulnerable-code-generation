//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_LOG_ENTRIES 10000
#define MAX_LOG_ENTRY_SIZE 1024

typedef struct {
    char *ip_address;
    char *request_method;
    char *request_uri;
    int response_code;
} log_entry_t;

log_entry_t log_entries[MAX_LOG_ENTRIES];
int num_log_entries = 0;

void add_log_entry(const char *ip_address, const char *request_method, const char *request_uri, int response_code) {
    if (num_log_entries >= MAX_LOG_ENTRIES) {
        printf("Error: Log is full\n");
        return;
    }

    log_entry_t entry = {
       .ip_address = strdup(ip_address),
       .request_method = strdup(request_method),
       .request_uri = strdup(request_uri),
       .response_code = response_code
    };

    log_entries[num_log_entries++] = entry;
}

void print_log_entries() {
    printf("Log:\n");

    for (int i = 0; i < num_log_entries; i++) {
        log_entry_t entry = log_entries[i];

        printf("IP address: %s\n", entry.ip_address);
        printf("Request method: %s\n", entry.request_method);
        printf("Request URI: %s\n", entry.request_uri);
        printf("Response code: %d\n\n", entry.response_code);
    }
}

int main() {
    add_log_entry("192.168.0.1", "GET", "/index.html", 200);
    add_log_entry("192.168.0.2", "POST", "/login.php", 401);
    add_log_entry("192.168.0.3", "PUT", "/data.json", 403);

    print_log_entries();

    return 0;
}