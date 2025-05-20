//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_THREATS 1000
#define MAX_THREAT_LEN 100

typedef struct {
    char ip[16];
    char threat[MAX_THREAT_LEN];
    time_t timestamp;
} threat_t;

void log_threat(const char* ip, const char* threat) {
    FILE* log = fopen("intrusion_log.txt", "a");
    if (log == NULL) {
        printf("Error: Could not open log file.\n");
        return;
    }

    threat_t threat_record;
    strcpy(threat_record.ip, ip);
    strcpy(threat_record.threat, threat);
    time_t now = time(NULL);
    threat_record.timestamp = now;

    fprintf(log, "%s - %s - %ld\n", threat_record.ip, threat_record.threat, now);
    fclose(log);
}

int main() {
    char input[MAX_THREAT_LEN];
    char ip[16];
    int count = 0;

    FILE* threats = fopen("threats.txt", "r");
    if (threats == NULL) {
        printf("Error: Could not open threats file.\n");
        return 1;
    }

    while (fscanf(threats, "%s", input)!= EOF) {
        if (count >= MAX_THREATS) {
            printf("Error: Reached maximum number of threats.\n");
            fclose(threats);
            return 1;
        }

        strcpy(ip, "192.168.1.1"); // Replace this with code to get the IP address of the threat
        log_threat(ip, input);
        count++;
    }

    fclose(threats);
    return 0;
}