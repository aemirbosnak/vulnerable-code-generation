//FormAI DATASET v1.0 Category: Log analysis ; Style: multivariable
#include <stdio.h>
#include <string.h>
#define MAX_ENTRIES 100

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    char level[10];
    char message[80];
} LogEntry;

int main() {
    FILE *logFile;
    char filename[20];
    printf("Enter the name of the log file to be analyzed: ");
    scanf("%s", filename);

    logFile = fopen(filename, "r"); //open the log file for reading
    if (logFile == NULL) {
        printf("Error! Could not open file");
        return 0;
    }

    LogEntry entries[MAX_ENTRIES];
    int numEntries = 0;
    char line[100];

    //read each line of the log file, creating a LogEntry for each one
    while (fgets(line, sizeof(line), logFile)) {
        LogEntry newEntry;

        //parse the date/time from the log entry string
        sscanf(line, "%d-%d-%d %d:%d:%d %s %s", &newEntry.year, &newEntry.month, &newEntry.day,
            &newEntry.hour, &newEntry.minute, &newEntry.second, newEntry.level, newEntry.message);

        entries[numEntries] = newEntry;
        numEntries++;
    }

    //Print out the number of entries
    printf("Number of log entries: %d\n", numEntries);

    //Find out which log level occurs most frequently
    char levels[3][10] = {"ERROR", "WARNING", "INFORMATION"};
    int levelCount[3] = {0, 0, 0};

    for (int i = 0; i < numEntries; i++) {
        if (strcmp(entries[i].level, levels[0]) == 0) {
            levelCount[0]++;
        } else if (strcmp(entries[i].level, levels[1]) == 0) {
            levelCount[1]++;
        } else if (strcmp(entries[i].level, levels[2]) == 0) {
            levelCount[2]++;
        }
    }

    //Print out the level that occurs most frequently
    int maxCount = levelCount[0];
    int maxIndex = 0;
    for (int i = 1; i < 3; i++) {
        if (levelCount[i] > maxCount) {
            maxCount = levelCount[i];
            maxIndex = i;
        }
    }

    printf("Most frequent level: %s\n", levels[maxIndex]);

    //Find the first and last entries in the log file
    LogEntry firstEntry = entries[0];
    LogEntry lastEntry = entries[numEntries - 1];

    printf("First Log Entry:\n");
    printf("%d-%d-%d %d:%d:%d %s %s\n", firstEntry.year, firstEntry.month, firstEntry.day,
        firstEntry.hour, firstEntry.minute, firstEntry.second, firstEntry.level, firstEntry.message);

    printf("Last Log Entry:\n");
    printf("%d-%d-%d %d:%d:%d %s %s\n", lastEntry.year, lastEntry.month, lastEntry.day,
        lastEntry.hour, lastEntry.minute, lastEntry.second, lastEntry.level, lastEntry.message);

    fclose(logFile);

    return 0;
}