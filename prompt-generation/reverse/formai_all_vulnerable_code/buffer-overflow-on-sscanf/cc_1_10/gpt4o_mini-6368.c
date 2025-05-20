//GPT-4o-mini DATASET v1.0 Category: Syntax parsing ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256
#define MAX_STATISTICS 100

typedef struct {
    char variableName[MAX_LINE_LENGTH];
    double total;
    int count;
    double mean;
    double variance;
} Statistic;

Statistic statistics[MAX_STATISTICS];
int statsCount = 0;

void processLine(char *line) {
    char variableName[MAX_LINE_LENGTH];
    double value;

    // Scan variable and value from the line
    if (sscanf(line, "%s %lf", variableName, &value) == 2) {
        // Check if the variable exists and update statistics
        for (int i = 0; i < statsCount; i++) {
            if (strcmp(statistics[i].variableName, variableName) == 0) {
                statistics[i].total += value;
                statistics[i].count++;
                double oldMean = statistics[i].mean;
                statistics[i].mean = statistics[i].total / statistics[i].count;
                statistics[i].variance += (value - oldMean) * (value - statistics[i].mean);
                return;
            }
        }
        
        // If variable not found, create new statistic entry
        if (statsCount < MAX_STATISTICS) {
            strcpy(statistics[statsCount].variableName, variableName);
            statistics[statsCount].total = value;
            statistics[statsCount].count = 1;
            statistics[statsCount].mean = value;
            statistics[statsCount].variance = 0.0;
            statsCount++;
        } else {
            printf("Maximum number of statistics reached. Cannot add more variables.\n");
        }
    } else {
        printf("Error parsing line: %s\n", line);
    }
}

void printStatistics() {
    printf("\nVariable Statistics:\n");
    printf("%-20s %-10s %-10s %-10s %-10s\n", "Variable", "Total", "Count", "Mean", "Variance");
    for (int i = 0; i < statsCount; i++) {
        printf("%-20s %-10.2f %-10d %-10.2f %-10.2f\n", 
               statistics[i].variableName,
               statistics[i].total,
               statistics[i].count,
               statistics[i].mean,
               statistics[i].count > 1 ? statistics[i].variance / (statistics[i].count - 1) : 0.0);
    }
}

int main() {
    char line[MAX_LINE_LENGTH];
    printf("Enter variable statistics (variable value), type 'exit' to stop:\n");

    while (1) {
        printf("> ");
        if (fgets(line, sizeof(line), stdin) == NULL) {
            break;
        }

        // Remove newline character
        line[strcspn(line, "\n")] = 0;

        if (strcmp(line, "exit") == 0) {
            break;
        }

        processLine(line);
    }

    printStatistics();
    return 0;
}