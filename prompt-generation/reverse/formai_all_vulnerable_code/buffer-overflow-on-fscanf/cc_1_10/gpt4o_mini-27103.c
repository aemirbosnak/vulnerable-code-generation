//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOG_FILE "drone_logs.txt"
#define MAX_LOG_ENTRIES 1000
#define MAX_LINE_LENGTH 256

typedef struct {
    char droneID[20];
    char timestamp[30];
    float energyConsumed;
    float distanceTravelled;
    int trafficStatus; // 0: clear, 1: congested
} DroneLogEntry;

DroneLogEntry logs[MAX_LOG_ENTRIES];
int logCount = 0;

void readLogFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open log file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    while (fgets(logs[logCount].droneID, sizeof(logs[logCount].droneID), file)) {
        // Remove newline character from the drone ID
        strtok(logs[logCount].droneID, "\n");

        // Read timestamp
        fgets(logs[logCount].timestamp, sizeof(logs[logCount].timestamp), file);
        strtok(logs[logCount].timestamp, "\n");

        // Read energy consumed
        fscanf(file, "%f\n", &logs[logCount].energyConsumed);

        // Read distance travelled
        fscanf(file, "%f\n", &logs[logCount].distanceTravelled);

        // Read traffic status
        fscanf(file, "%d\n", &logs[logCount].trafficStatus);

        logCount++;
        if (logCount >= MAX_LOG_ENTRIES) {
            break;
        }
    }

    fclose(file);
}

void analyzeLogs() {
    float totalEnergy = 0.0;
    float totalDistance = 0.0;
    int clearTrafficCount = 0, congestedTrafficCount = 0;

    for (int i = 0; i < logCount; i++) {
        totalEnergy += logs[i].energyConsumed;
        totalDistance += logs[i].distanceTravelled;

        if (logs[i].trafficStatus == 0) {
            clearTrafficCount++;
        } else {
            congestedTrafficCount++;
        }
    }

    printf("=== Log Analysis Result ===\n");
    printf("Total Log Entries: %d\n", logCount);
    printf("Total Energy Consumed: %.2f units\n", totalEnergy);
    printf("Total Distance Travelled: %.2f km\n", totalDistance);
    printf("Traffic Conditions: Clear %d, Congested %d\n", clearTrafficCount, congestedTrafficCount);
    printf("============================\n");
}

void generateSummaryReport(const char *outputFile) {
    FILE *file = fopen(outputFile, "w");
    if (!file) {
        fprintf(stderr, "Error: Could not create output file %s\n", outputFile);
        exit(EXIT_FAILURE);
    }

    fprintf(file, "=== Summary Report ===\n");
    fprintf(file, "Total Log Entries: %d\n", logCount);
    fprintf(file, "======================\n");

    for (int i = 0; i < logCount; i++) {
        fprintf(file, "DroneID: %s, Timestamp: %s, Energy: %.2f, Distance: %.2f, Traffic: %s\n",
                logs[i].droneID,
                logs[i].timestamp,
                logs[i].energyConsumed,
                logs[i].distanceTravelled,
                logs[i].trafficStatus == 0 ? "Clear" : "Congested");
    }

    fclose(file);
}

int main() {
    readLogFile(LOG_FILE);
    analyzeLogs();
    generateSummaryReport("drone_summary_report.txt");

    printf("Summary report generated: drone_summary_report.txt\n");
    return 0;
}