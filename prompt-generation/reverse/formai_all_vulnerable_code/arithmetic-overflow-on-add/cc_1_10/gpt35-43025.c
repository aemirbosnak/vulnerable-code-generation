//FormAI DATASET v1.0 Category: System event logger ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    // Logger configuration
    char logFile[50] = "/var/log/system.log";
    char event[100];
    time_t rawtime;
    struct tm *timeinfo;

    // Open log file
    FILE *fp = fopen(logFile, "a");

    // Check for write permission
    if (fp == NULL) {
        printf("ERROR: Unable to open the log file.\n");
        exit(1);
    }

    // Get current time
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    // Write to log file
    sprintf(event, "[%04d-%02d-%02d %02d:%02d:%02d] Paranoid event occurred!\n", timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
    fprintf(fp, "%s", event);

    // Close log file
    fclose(fp);

    // Delete log file after 24 hours
    char deleteCmd[100];
    sprintf(deleteCmd, "find %s -mtime +1 -delete", logFile);
    system(deleteCmd);

    // Sleep for a random time between 1 and 5 seconds
    srand(time(NULL));
    int randSleep = rand() % 5 + 1;
    sleep(randSleep);

    // Check log file size
    long fileSize;
    fp = fopen(logFile, "r");
    fseek(fp, 0L, SEEK_END);
    fileSize = ftell(fp);
    fclose(fp);

    // If file size is greater than 10KB, delete it and start over
    if (fileSize > 10240) {
        remove(logFile);

        // Write to log file
        fp = fopen(logFile, "a");
        sprintf(event, "[%04d-%02d-%02d %02d:%02d:%02d] Paranoid event occurred! (deleted log file)\n", timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
        fprintf(fp, "%s", event);
        fclose(fp);
    }

    // Exit program
    return 0;
}