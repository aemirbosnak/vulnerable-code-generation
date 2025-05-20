//Falcon2-11B DATASET v1.0 Category: Log analysis ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

// Function to calculate the time difference between two timestamps
double getTimeDifference(struct timeval* t1, struct timeval* t2) {
    struct timeval diff;
    gettimeofday(&diff, NULL);
    diff.tv_sec -= t1->tv_sec;
    diff.tv_usec -= t1->tv_usec;
    if (diff.tv_usec < 0) {
        diff.tv_sec -= 1;
        diff.tv_usec += 1000000;
    }
    return diff.tv_sec + diff.tv_usec * 1e-6;
}

// Function to analyze log entries and calculate the time difference between each pair
int analyzeLogEntries(char* logFile, int numEntries) {
    FILE* file = fopen(logFile, "r");
    if (file == NULL) {
        printf("Error: Unable to open log file\n");
        return -1;
    }

    char line[100];
    for (int i = 0; i < numEntries; i++) {
        if (fgets(line, sizeof(line), file) == NULL) {
            printf("Error: Unable to read log file\n");
            return -1;
        }

        struct timeval timestamp;
        sscanf(line, "%ld.%06ld", &timestamp.tv_sec, &timestamp.tv_usec);

        for (int j = i + 1; j < numEntries; j++) {
            if (fgets(line, sizeof(line), file) == NULL) {
                printf("Error: Unable to read log file\n");
                return -1;
            }

            struct timeval timestamp2;
            sscanf(line, "%ld.%06ld", &timestamp2.tv_sec, &timestamp2.tv_usec);

            double timeDifference = getTimeDifference(&timestamp, &timestamp2);
            printf("Log entry %d and %d: Time difference is %f seconds\n", i, j, timeDifference);
        }
    }

    fclose(file);
    return 0;
}

int main() {
    char* logFile = "log.txt";
    int numEntries = 5;

    analyzeLogEntries(logFile, numEntries);

    return 0;
}