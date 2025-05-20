//FormAI DATASET v1.0 Category: Log analysis ; Style: energetic
#include <stdio.h> 

int main() { 
    printf("Welcome to our Log Analysis Program!\n");
    printf("This program will analyze a given log file and provide useful information.\n");

    // Prompt the user for the log file name
    char filename[256];
    printf("Enter the name of the log file: ");
    scanf("%s", filename);
    printf("Analyzing file %s...\n", filename);

    // Open the log file
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: could not open file %s\n", filename);
        return 1;
    }

    // Declare variables to hold log information
    int numEntries = 0;
    int numErrors = 0;
    int numWarnings = 0;
    int numInfos = 0;

    // Read each line of the log file
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        numEntries++;
        if (strstr(line, "ERROR")) {
            numErrors++;
        } else if (strstr(line, "WARNING")) {
            numWarnings++;
        } else if (strstr(line, "INFO")) {
            numInfos++;
        }
    }

    // Close the log file
    fclose(file);

    // Output the results
    printf("Results:\n");
    printf("Total entries: %d\n", numEntries);
    printf("Errors: %d\n", numErrors);
    printf("Warnings: %d\n", numWarnings);
    printf("Infos: %d\n", numInfos);

    // Analyze error frequency
    float errorFrequency = (float)numErrors / (float)numEntries;
    printf("Error frequency: %f percent\n", errorFrequency * 100);

    // Analyze warning frequency
    float warningFrequency = (float)numWarnings / (float)numEntries;
    printf("Warning frequency: %f percent\n", warningFrequency * 100);

    // Analyze info frequency
    float infoFrequency = (float)numInfos / (float)numEntries;
    printf("Info frequency: %f percent\n", infoFrequency * 100);

    // Determine overall health of log file
    printf("Overall health: ");
    if (errorFrequency > 0.05) {
        printf("BAD\n");
    } else if (warningFrequency > 0.2) {
        printf("AVERAGE\n");
    } else {
        printf("GOOD\n");
    }

    return 0; 
}