//FormAI DATASET v1.0 Category: File handling ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp;
    char filename[50];
    char string[100];
    
    // Read filename from user
    printf("Enter filename: ");
    scanf("%s", filename);
    
    // Open file in write mode
    fp = fopen(filename, "w");
    
    // Check if file opened successfully
    if (fp == NULL) {
        printf("Error: Unable to open file!\n");
        exit(1);
    }
    
    // Read string from user
    printf("Enter string to write to file: ");
    scanf("%s", string);
    
    // Write string to file
    fprintf(fp, "%s", string);
    
    // Close file
    fclose(fp);
    
    // Open file in read mode
    fp = fopen(filename, "r");
    
    // Check if file opened successfully
    if (fp == NULL) {
        printf("Error: Unable to open file!\n");
        exit(1);
    }
    
    // Read and print contents of file
    printf("Contents of file:\n");
    while (fgets(string, 100, fp) != NULL) {
        printf("%s", string);
    }
    
    // Close file
    fclose(fp);
    
    return 0;
}