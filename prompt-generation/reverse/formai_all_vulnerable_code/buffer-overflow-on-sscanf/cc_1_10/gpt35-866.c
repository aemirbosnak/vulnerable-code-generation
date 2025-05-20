//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: imaginative
#include <stdio.h>

// Define the maximum length of the metadata string
#define MAX_METADATA_LENGTH 500

// Define a structure to hold the extracted metadata fields
typedef struct {
    char title[100];
    char author[50];
    int year;
    char format[10];
} Metadata;

// Define a function to extract the metadata from a file
Metadata extract_metadata(char* filename) {
    // Open the file in read mode
    FILE* file = fopen(filename, "r");
    
    // Define a buffer to hold the metadata string
    char metadata[MAX_METADATA_LENGTH];
    
    // Read the entire file into the buffer
    fread(metadata, sizeof(char), MAX_METADATA_LENGTH, file);
    
    // Close the file
    fclose(file);
    
    // Define variables to hold the extracted metadata fields
    char title[100];
    char author[50];
    int year;
    char format[10];
    
    // Parse the metadata string and extract the fields
    sscanf(metadata, "Title: %[^\n]\nAuthor: %[^\n]\nYear: %d\nFormat: %[^\n]", title, author, &year, format);
    
    // Create a Metadata struct and populate it with the extracted fields
    Metadata extracted_metadata;
    strcpy(extracted_metadata.title, title);
    strcpy(extracted_metadata.author, author);
    extracted_metadata.year = year;
    strcpy(extracted_metadata.format, format);
    
    // Return the extracted metadata
    return extracted_metadata;
}

int main() {
    // Set the filename of the file to extract metadata from
    char filename[] = "book.txt";
    
    // Extract the metadata from the file
    Metadata metadata = extract_metadata(filename);
    
    // Print the extracted metadata
    printf("Title: %s\n", metadata.title);
    printf("Author: %s\n", metadata.author);
    printf("Year: %d\n", metadata.year);
    printf("Format: %s\n", metadata.format);
    
    return 0;
}