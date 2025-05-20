//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000
#define MAX_ALLOWED_LOGINS 5
#define MAX_BLOCKED_IPS 10

typedef struct {
    char ip[16];
    int num_failed_logins;
} BlockedIP;

void add_blocked_ip(BlockedIP* blocked_ips, int num_blocked_ips, char* ip) {
    int i;
    for (i = 0; i < num_blocked_ips; i++) {
        if (strcmp(blocked_ips[i].ip, ip) == 0) {
            blocked_ips[i].num_failed_logins++;
            return;
        }
    }
    strcpy(blocked_ips[num_blocked_ips].ip, ip);
    blocked_ips[num_blocked_ips].num_failed_logins = 1;
    num_blocked_ips++;
}

int is_ip_blocked(BlockedIP* blocked_ips, int num_blocked_ips, char* ip) {
    int i;
    for (i = 0; i < num_blocked_ips; i++) {
        if (strcmp(blocked_ips[i].ip, ip) == 0) {
            if (blocked_ips[i].num_failed_logins >= MAX_ALLOWED_LOGINS) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    FILE* log_file;
    char line[MAX_LINE_SIZE];
    char ip[16];
    char username[20];
    int num_failed_logins = 0;
    BlockedIP blocked_ips[MAX_BLOCKED_IPS];
    int num_blocked_ips = 0;

    log_file = fopen("log.txt", "r");
    if (log_file == NULL) {
        printf("Error: could not open log file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_SIZE, log_file)!= NULL) {
        if (sscanf(line, "%s %s %d", ip, username, &num_failed_logins)!= 3) {
            continue;
        }
        add_blocked_ip(blocked_ips, num_blocked_ips, ip);
    }

    fclose(log_file);

    printf("Blocked IPs:\n");
    for (int i = 0; i < num_blocked_ips; i++) {
        printf("%s (%d failed logins)\n", blocked_ips[i].ip, blocked_ips[i].num_failed_logins);
    }

    return 0;
}