//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: lively
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to create a database indexing system
void createIndex(char *filename) {
    // Open the file for writing
    FILE *fp = fopen(filename, "w");
    
    // If the file cannot be opened, print an error message and exit
    if (fp == NULL) {
        printf("Error: Could not open file %s for writing\n", filename);
        exit(1);
    }
    
    // Iterate through the lines of the file
    char line[1000];
    while (fgets(line, sizeof(line), stdin)!= NULL) {
        // Split the line into words
        char *words[100];
        char *word = strtok(line, " ");
        int i = 0;
        while (word!= NULL) {
            words[i] = word;
            word = strtok(NULL, " ");
            i++;
        }
        
        // Remove any duplicate words from the list
        int j = 0;
        while (j < i) {
            int k = 0;
            while (k < i - j - 1) {
                if (strcmp(words[k], words[k + 1]) == 0) {
                    free(words[k]);
                    i--;
                    j--;
                }
                k++;
            }
            j++;
        }
        
        // Print the list of words to the file
        fprintf(fp, "%s\n", line);
    }
    
    // Close the file
    fclose(fp);
}

int main() {
    char filename[100];
    printf("Enter the name of the file to create the database indexing system: ");
    scanf("%s", filename);
    createIndex(filename);
    return 0;
}