//FormAI DATASET v1.0 Category: Log analysis ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file;
    char *filepath, *line = NULL;
    size_t len = 0;
    ssize_t read;
    int count = 0;
    
    // Ask for file path
    printf("Enter file path: ");
    scanf("%s", filepath);
    
    // Open file
    file = fopen(filepath, "r");
    if (!file) {
        printf("Failed to open file.");
        return 1;
    }
    
    // Read lines from file
    while ((read = getline(&line, &len, file)) != -1) {
        char *timestamp = strtok(line, " ");
        char *level = strtok(NULL, " ");
        char *message = strtok(NULL, "\n");
        
        // Parse timestamp
        int hour, minute, second;
        if (sscanf(timestamp, "[%d:%d:%d]", &hour, &minute, &second) != 3) {
            printf("Failed to parse timestamp.");
            continue;
        }
        
        // Determine level
        int error = 0, warning = 0, info = 0;
        if (strcmp(level, "ERROR") == 0) {
            error = 1;
        } else if (strcmp(level, "WARNING") == 0) {
            warning = 1;
        } else if (strcmp(level, "INFO") == 0) {
            info = 1;
        } else {
            printf("Unknown level: %s", level);
            continue;
        }
        
        // Analyze message
        if (error) {
            if (strstr(message, "memory") != NULL) {
                printf("Memory error at %02d:%02d:%02d\n", hour, minute, second);
                count++;
            }
        } else if (warning) {
            if (strstr(message, "deprecated") != NULL) {
                printf("Deprecated warning at %02d:%02d:%02d\n", hour, minute, second);
                count++;
            }
        }
    }
    
    // Clean up
    free(filepath);
    if (line) {
        free(line);
    }
    fclose(file);
    
    // Report results
    if (count == 0) {
        printf("No matches found.");
    } else {
        printf("Found %d matches.", count);
    }
    
    return 0;
}