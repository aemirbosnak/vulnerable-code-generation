//Falcon2-11B DATASET v1.0 Category: Building a CSV Reader ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read a CSV file
void readCSV(const char* filename) {
    // Open the file
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }
    
    // Initialize variables
    int numRows = 0;
    char line[100];
    char* tokens[10];
    int i = 0;
    char* token;
    
    // Read the first line to get the number of rows
    while (fgets(line, 100, fp)!= NULL) {
        line[strcspn(line, "\n")] = '\0';
        sscanf(line, "%s", tokens[i]);
        i++;
    }
    numRows = i;
    
    // Read the rest of the rows
    while (fgets(line, 100, fp)!= NULL) {
        line[strcspn(line, "\n")] = '\0';
        token = strtok(line, ",");
        for (int j = 0; j < numRows; j++) {
            tokens[j] = strtok(NULL, ",");
        }
        
        // Print the row
        printf("%s\n", tokens[0]);
        for (int k = 1; k < numRows; k++) {
            printf(" %s", tokens[k]);
        }
        printf("\n");
    }
    
    // Close the file
    fclose(fp);
}

int main() {
    // Example usage
    readCSV("data.csv");
    return 0;
}