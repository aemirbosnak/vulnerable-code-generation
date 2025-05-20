//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: innovative
/* Intrusion Detection System Program */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LOG_ENTRIES 100
#define MAX_IP_LENGTH 20

typedef struct {
    char ip_address[MAX_IP_LENGTH];
    char date[20];
    char time[20];
    char message[100];
} log_entry;

log_entry logs[MAX_LOG_ENTRIES];
int num_logs;

int add_log_entry(char* ip_address, char* date, char* time, char* message) {
    if (num_logs == MAX_LOG_ENTRIES) {
        return 0;
    }

    strcpy(logs[num_logs].ip_address, ip_address);
    strcpy(logs[num_logs].date, date);
    strcpy(logs[num_logs].time, time);
    strcpy(logs[num_logs].message, message);

    num_logs++;

    return 1;
}

int check_for_intrusion(char* ip_address) {
    int i, count = 0;

    for (i = 0; i < num_logs; i++) {
        if (strcmp(logs[i].ip_address, ip_address) == 0) {
            count++;
        }
    }

    if (count > 10) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char ip_address[MAX_IP_LENGTH];
    char date[20];
    char time[20];
    char message[100];

    num_logs = 0;

    add_log_entry("192.168.1.1", "2021-01-01", "12:00:00", "Failed login attempt");
    add_log_entry("192.168.1.1", "2021-01-01", "12:01:00", "Failed login attempt");
    add_log_entry("192.168.1.2", "2021-01-01", "12:02:00", "Failed login attempt");

    printf("Enter IP address: ");
    scanf("%s", ip_address);

    if (check_for_intrusion(ip_address)) {
        printf("Intrusion detected!\n");
    } else {
        printf("No intrusion detected.\n");
    }

    return 0;
}