//Falcon2-11B DATASET v1.0 Category: Log analysis ; Style: rigorous
#include <stdio.h>
#include <string.h>

// Function to read log file and analyze the data
void analyzeLog(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return;
    }

    // Read the log file line by line
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        // Process each line of the log file
        if (strstr(line, "ERROR")!= NULL) {
            // Print the error message
            printf("Error: %s\n", line);
        } else if (strstr(line, "WARNING")!= NULL) {
            // Print the warning message
            printf("Warning: %s\n", line);
        } else if (strstr(line, "INFO")!= NULL) {
            // Print the informational message
            printf("Info: %s\n", line);
        } else if (strstr(line, "DEBUG")!= NULL) {
            // Print the debug message
            printf("Debug: %s\n", line);
        } else {
            // Ignore other lines
            continue;
        }
    }

    // Close the log file
    fclose(file);
}

int main() {
    // Read log file name from user
    printf("Enter the log file name: ");
    char* filename = (char*)malloc(sizeof(char) * 256);
    scanf("%s", filename);

    // Analyze the log file
    analyzeLog(filename);

    // Free the memory allocated for the log file name
    free(filename);

    return 0;
}