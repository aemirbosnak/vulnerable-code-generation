//Falcon2-11B DATASET v1.0 Category: File Backup System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to backup files
void backup_files() {
    FILE* fp;
    char file_name[100];
    
    // Ask user for input
    printf("Enter file name to backup: ");
    scanf("%s", file_name);
    
    // Open the file in read mode
    fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }
    
    // Read the contents of the file
    fseek(fp, 0L, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    char buffer[size];
    fread(buffer, 1, size, fp);
    
    // Close the file
    fclose(fp);
    
    // Ask user for output file name
    printf("Enter output file name: ");
    scanf("%s", file_name);
    
    // Open the output file in write mode
    fp = fopen(file_name, "w");
    if (fp == NULL) {
        printf("Error opening output file.\n");
        return;
    }
    
    // Write the contents of the file to the output file
    fwrite(buffer, 1, size, fp);
    
    // Close the output file
    fclose(fp);
    
    printf("File backup successful.\n");
}

int main() {
    // Call the backup_files function
    backup_files();
    
    return 0;
}