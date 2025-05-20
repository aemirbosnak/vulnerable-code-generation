//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to extract metadata
void extract_metadata(char* file_path){

    // Open file
    FILE* fp = fopen(file_path, "r");
    if(fp == NULL){
        printf("Error opening file!\n");
        exit(1);
    }

    // Get file size
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    rewind(fp);

    // Allocate buffer for file content
    char* buffer = (char*) malloc(sizeof(char) * file_size);
    if(buffer == NULL){
        printf("Error allocating memory!\n");
        exit(1);
    }

    // Read file content into buffer
    fread(buffer, sizeof(char), file_size, fp);

    // Extract metadata from buffer
    char author[100], date[100], description[1000];
    time_t current_time = time(NULL);
    struct tm* time_info = localtime(&current_time);
    strftime(date, sizeof(date), "%Y-%m-%d %H:%M:%S", time_info);
    strcpy(author, "Anonymous");
    strcpy(description, "No description available");

    // Print metadata
    printf("Metadata for file %s:\n", file_path);
    printf("Author: %s\n", author);
    printf("Date: %s\n", date);
    printf("Description: %s\n", description);

    // Free memory and close file
    free(buffer);
    fclose(fp);
}

int main(){
    char file_path[100];
    printf("Enter file path: ");
    scanf("%s", file_path);
    extract_metadata(file_path);
    return 0;
}