//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOGS 1000
#define MAX_MSG_LEN 100

struct logEntry {
    char msg[MAX_MSG_LEN];
    int timestamp;
};

struct intrusionDetectionSystem {
    struct logEntry logs[MAX_LOGS];
    int logCount;
} IDS;

void logEvent(char* msg) {
    struct logEntry newEntry;
    strcpy(newEntry.msg, msg);
    newEntry.timestamp = time(NULL);
    IDS.logs[IDS.logCount++] = newEntry;
}

void checkForIntrusion() {
    int recentLogIndex = IDS.logCount - 1;
    int recentTimestamp = IDS.logs[recentLogIndex].timestamp;
    int i;

    for (i = 0; i < IDS.logCount; i++) {
        if ((recentTimestamp - IDS.logs[i].timestamp) < 300) {
            printf("Possible intrusion detected!\n");
            printf("Recent log message: %s\n", IDS.logs[recentLogIndex].msg);
            printf("Previous log message: %s\n", IDS.logs[i].msg);
        }
    }
}

int main() {
    IDS.logCount = 0;

    logEvent("Normal behavior");
    logEvent("Normal behavior");
    logEvent("Normal behavior");
    logEvent("Normal behavior");
    logEvent("Normal behavior");

    logEvent("Suspicious activity detected");
    logEvent("Normal behavior");
    logEvent("Normal behavior");
    logEvent("Normal behavior");
    logEvent("Normal behavior");

    checkForIntrusion();

    return 0;
}