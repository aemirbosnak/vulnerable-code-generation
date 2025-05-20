//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOGS 10000        // maximum number of logs
#define MAX_IP_LEN 16         // maximum IP address length
#define MAX_TIME_LEN 20       // maximum timestamp length
#define MAX_MSG_LEN 256       // maximum log message length

typedef struct {
    char ip[MAX_IP_LEN];
    char timestamp[MAX_TIME_LEN];
    char message[MAX_MSG_LEN];
} Log;

typedef struct {
    char ip[MAX_IP_LEN];
    int count;
} Suspicious;

int is_suspicious(Log log, Suspicious susp[], int num_suspicious) {
    // check if log is from a suspicious IP address
    for (int i = 0; i < num_suspicious; i++) {
        if (strcmp(log.ip, susp[i].ip) == 0) {
            susp[i].count++;
            if (susp[i].count >= 10) {
                return 1;   // return true if IP has exceeded threshold
            }
        }
    }
    return 0;   // return false if IP is not suspicious
}

int main() {
    Log logs[MAX_LOGS];
    Suspicious suspicious[MAX_LOGS];
    int num_logs = 0;           // number of logs
    int num_suspicious = 0;     // number of suspicious IPs

    // read logs from file and store them in logs array
    FILE *file = fopen("logs.txt", "r");
    if (file) {
        char line[MAX_MSG_LEN];
        while (fgets(line, sizeof(line), file)) {
            sscanf(line, "%s %s %[^\n]", logs[num_logs].ip, logs[num_logs].timestamp, logs[num_logs].message);
            if (is_suspicious(logs[num_logs], suspicious, num_suspicious)) {
                printf("Intrusion detected from IP address %s at %s\n", logs[num_logs].ip, logs[num_logs].timestamp);
            }
            num_logs++;
        }
        fclose(file);
    } else {
        printf("File not found\n");
        return 1;
    }

    // print report of suspicious IPs
    printf("\nSuspicious IP Addresses:\n");
    for (int i = 0; i < num_logs; i++) {
        int found = 0;
        for (int j = 0; j < num_suspicious; j++) {
            if (strcmp(logs[i].ip, suspicious[j].ip) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            strncpy(suspicious[num_suspicious].ip, logs[i].ip, MAX_IP_LEN);
            suspicious[num_suspicious].count = 1;
            num_suspicious++;
        }
    }
    for (int i = 0; i < num_suspicious; i++) {
        printf("%s: %d\n", suspicious[i].ip, suspicious[i].count);
    }

    return 0;
}