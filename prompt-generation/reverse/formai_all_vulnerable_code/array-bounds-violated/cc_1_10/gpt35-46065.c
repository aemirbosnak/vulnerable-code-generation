//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRY 100
#define MAX_NAME_LENGTH 50
#define MAX_IP_LENGTH 15

// Structure to represent an IP entry
typedef struct IPEntry {
    char name[MAX_NAME_LENGTH];
    char ip[MAX_IP_LENGTH];
} IPEntry;

// Function to check if an IP is malicious
int isMalicious(char *ip) {
    // Check if the IP is in the blacklist
    char *blacklist[] = {"10.0.0.1", "192.168.1.1", "172.16.0.1"};
    for (int i=0; i<3; i++) {
        if (strcmp(ip, blacklist[i]) == 0)
            return 1;
    }
    return 0;
}

// Function to log an IP entry
void logEntry(IPEntry *entry) {
    // Open the log file
    FILE *file;
    file = fopen("ips.log", "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    
    // Write the entry to the file
    fprintf(file, "%s %s\n", entry->name, entry->ip);
    
    // Close the file
    fclose(file);
}

int main() {
    IPEntry entries[MAX_ENTRY];
    int numEntries = 0;
    printf("Welcome to the Intrusion Detection System.\n");
    printf("Enter 'exit' to quit.\n");
    while (1) {
        // Get input from the user
        char input[MAX_IP_LENGTH+MAX_NAME_LENGTH+2];
        printf("Enter name and IP address (separated by a space): ");
        fgets(input, sizeof(input), stdin);
        input[strlen(input)-1] = '\0'; // Remove the newline character
        
        // Check if the user wants to exit
        if (strcmp(input, "exit") == 0)
            break;
        
        // Parse the input
        char *name = strtok(input, " ");
        char *ip = strtok(NULL, " ");
        
        // Check if the IP is malicious
        if (isMalicious(ip)) {
            printf("The IP address %s is malicious.\n", ip);
            continue; // Skip to the next iteration of the loop
        }
        
        // Create an IP entry
        IPEntry entry;
        strcpy(entry.name, name);
        strcpy(entry.ip, ip);
        
        // Log the entry
        logEntry(&entry);
        
        // Add the entry to the list
        entries[numEntries++] = entry;
        
        printf("Entry logged successfully.\n");
    }
    printf("Exiting program.\n");
    return 0;
}