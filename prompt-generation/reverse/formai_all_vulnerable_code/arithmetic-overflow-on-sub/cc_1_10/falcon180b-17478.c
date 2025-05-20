//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_LINE_LENGTH 1024
#define MAX_ALLOWED_FAILURES 5
#define FAILURE_THRESHOLD_SECONDS 60

int failures = 0;
time_t last_failure_time = 0;

void log_failure() {
    time_t current_time = time(NULL);
    if (current_time - last_failure_time > FAILURE_THRESHOLD_SECONDS) {
        last_failure_time = current_time;
        failures = 1;
    } else {
        failures++;
    }
    printf("Possible intrusion attempt detected at %s\n", ctime(&current_time));
}

int is_valid_ip(char *ip) {
    int parts = 0;
    char *token = strtok(ip, ".");
    while (token!= NULL) {
        if (atoi(token) < 0 || atoi(token) > 255) {
            return 0;
        }
        parts++;
        token = strtok(NULL, ".");
    }
    return parts == 4? 1 : 0;
}

int main() {
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, stdin)!= NULL) {
        char *ip = strtok(line, " ");
        if (ip == NULL) {
            continue;
        }
        if (!is_valid_ip(ip)) {
            log_failure();
        }
    }
    return 0;
}