//FormAI DATASET v1.0 Category: System administration ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a file exists
int fileExists(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file) {
        fclose(file);
        return 1;
    }
    return 0;
}

int main() {
    char filename[50];
    printf("Please enter the filename: ");
    scanf("%s", filename);

    // Check if file exists
    if (!fileExists(filename)) {
        printf("The file %s does not exist.\n", filename);
        return 0;
    }

    // Open file
    FILE* file = fopen(filename, "r");

    // Read file line by line
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        // Search for IP addresses
        char* token;
        char* rest = line;
        
        while ((token = strtok_r(rest, " ", &rest))) {
            if (strlen(token) > 6 && token[0] != '#') {
                // IP address found
                printf("IP address found: %s\n", token);
            }
        }
    }

    // Close file
    fclose(file);

    printf("Finished searching for IP addresses.\n");

    return 0;
}