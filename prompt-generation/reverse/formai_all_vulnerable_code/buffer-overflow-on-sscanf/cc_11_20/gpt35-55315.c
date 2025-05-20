//FormAI DATASET v1.0 Category: Log analysis ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100000
#define MAX_LEN 1024

// A struct to store the data of a single log entry
typedef struct LogEntry {
    char date[20];
    char time[20];
    char ip[20];
    char method[10];
    char path[100];
    int status;
    int size;
} LogEntry;

// Parse a single log entry from a string and return a LogEntry data structure
LogEntry parseEntry(char* line) {
    LogEntry entry;
    sscanf(line, "%s %s %s %s %s %d %d", entry.date, entry.time, entry.ip, entry.method, entry.path, &entry.status, &entry.size);
    return entry;
}

int main() {
    FILE* fp;
    char line[MAX_LEN];
    LogEntry entries[MAX_LINES];
    int numEntries = 0;
    
    // Open the log file for reading
    fp = fopen("example.log", "r");
    if (fp == NULL) {
        printf("Error opening log file\n");
        return 1;
    }

    // Read the log file line by line and parse each entry
    while (fgets(line, sizeof(line), fp) != NULL) {
        // Parse the entry and store it in the 'entries' array
        entries[numEntries] = parseEntry(line);
        numEntries++;
    }

    fclose(fp);

    // Print some information about the log file
    printf("Log file analysis\n");
    printf("==================\n\n");
    printf("Number of entries: %d\n\n", numEntries);

    // Count the number of entries with each method (GET, POST, etc.)
    int numGet = 0, numPost = 0, numHead = 0, numPut = 0, numDelete = 0;
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(entries[i].method, "GET") == 0) {
            numGet++;
        } else if (strcmp(entries[i].method, "POST") == 0) {
            numPost++;
        } else if (strcmp(entries[i].method, "HEAD") == 0) {
            numHead++;
        } else if (strcmp(entries[i].method, "PUT") == 0) {
            numPut++;
        } else if (strcmp(entries[i].method, "DELETE") == 0) {
            numDelete++;
        }
    }
    printf("Number of GET requests: %d\n", numGet);
    printf("Number of POST requests: %d\n", numPost);
    printf("Number of HEAD requests: %d\n", numHead);
    printf("Number of PUT requests: %d\n", numPut);
    printf("Number of DELETE requests: %d\n\n", numDelete);

    // Find the average file size of entries with status codes between 200 and 299
    int numValidEntries = 0;
    int totalSize = 0;
    for (int i = 0; i < numEntries; i++) {
        if (entries[i].status >= 200 && entries[i].status < 300) {
            numValidEntries++;
            totalSize += entries[i].size;
        }
    }
    printf("Average file size of successful requests: %.2f bytes\n\n", (float)totalSize / numValidEntries);

    // Find the IP addresses that made the greatest number of requests
    char ips[MAX_LINES][20];
    int requestCounts[MAX_LINES];
    int numIps = 0;
    // Initialize requestCounts to 0
    for (int i = 0; i < MAX_LINES; i++) {
        requestCounts[i] = 0;
    }
    // Count the number of requests for each IP address
    for (int i = 0; i < numEntries; i++) {
        int existingIndex = -1;
        // Check if this IP address already exists in the 'ips' array
        for (int j = 0; j < numIps; j++) {
            if (strcmp(entries[i].ip, ips[j]) == 0) {
                existingIndex = j;
                break;
            }
        }
        if (existingIndex == -1) {
            // Add this IP address to the 'ips' array
            strcpy(ips[numIps], entries[i].ip);
            requestCounts[numIps]++;
            numIps++;
        } else {
            // Increment the request count for this IP address
            requestCounts[existingIndex]++;
        }
    }
    // Find the IP addresses with the highest request count
    int maxRequests = 0;
    for (int i = 0; i < numIps; i++) {
        if (requestCounts[i] > maxRequests) {
            maxRequests = requestCounts[i];
        }
    }
    printf("IP addresses with the most requests (%d requests):\n", maxRequests);
    for (int i = 0; i < numIps; i++) {
        if (requestCounts[i] == maxRequests) {
            printf("%s\n", ips[i]);
        }
    }
    
    return 0;
}