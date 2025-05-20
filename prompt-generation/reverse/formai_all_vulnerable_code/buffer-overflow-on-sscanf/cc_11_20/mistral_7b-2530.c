//MISTRAL-7B DATASET v1.0 Category: Log analysis ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

typedef struct {
    char ip[16];
    int status_code;
    int size;
} log_entry;

typedef struct {
    char ip[16];
    int count;
} unique_ip;

int main() {
    FILE *log_file;
    char line[1024];
    log_entry entry;
    unique_ip ips[65536];
    int unique_ips_count = 0;
    int total_requests = 0;
    long long total_size = 0;

    log_file = fopen("access.log", "r");

    if (log_file == NULL) {
        perror("Error opening log file");
        return 1;
    }

    while (fgets(line, sizeof(line), log_file) != NULL) {
        sscanf(line, "%s %s %s %d %d", entry.ip, entry.ip + sizeof(entry.ip) - 1, entry.ip + sizeof(entry.ip) - 14, &entry.status_code, &entry.size);

        // Convert IP to binary and extract unique bits
        int ip_binary[32];
        int ip_index = 0;
        for (int i = 0; i < strlen(entry.ip) && ip_index < 32; i++) {
            if (isdigit(entry.ip[i])) {
                ip_binary[ip_index++] = atoi(&entry.ip[i]);
            } else if (entry.ip[i] == '.') {
                ip_index++;
            }
        }

        int ip_hash = 0;
        for (int i = 0; i < 32; i++) {
            ip_hash ^= ip_binary[i] << (i % 4);
        }

        // Find unique IPs and update their counters
        bool ip_found = false;
        for (int i = 0; i < unique_ips_count && !ip_found; i++) {
            if (memcmp(ips[i].ip, &ip_hash, sizeof(ips[i].ip)) == 0) {
                ip_found = true;
                ips[i].count++;
            }
        }

        if (!ip_found) {
            strcpy(ips[unique_ips_count].ip, &ip_hash);
            unique_ips_count++;
            total_requests++;
            total_size += entry.size;
        }
    }

    fclose(log_file);

    printf("Unique IPs: %d\n", unique_ips_count);
    printf("Total requests: %d\n", total_requests);
    printf("Average response size: %.2f bytes\n", (float)total_size / total_requests);

    return 0;
}