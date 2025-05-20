//MISTRAL-7B DATASET v1.0 Category: Metadata Extractor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Custom metadata structure
typedef struct {
    char name[32];
    int value;
} CustomMetadata;

// Function to extract metadata from a given string
CustomMetadata extractMetadata(const char* str) {
    CustomMetadata metadata;
    int i = 0;

    // Skip whitespaces
    while (isspace(str[i])) i++;

    // Copy metadata name
    strncpy(metadata.name, &str[i], sizeof(metadata.name) - 1);
    metadata.name[sizeof(metadata.name) - 1] = '\0';

    // Skip equals sign
    if (str[i + strlen(metadata.name)] != '=') {
        printf("Invalid metadata format: %s\n", str);
        exit(1);
    }
    i += strlen(metadata.name) + 1;

    // Copy metadata value
    int j = 0;
    while (!isspace(str[i + j]) && str[i + j] != ';') {
        metadata.value = metadata.value * 10 + (str[i + j] - '0');
        j++;
    }

    // Add null terminator to value string
    metadata.value = atoi(&str[i + j + 1]);

    return metadata;
}

// Function to print metadata in a human-readable format
void printMetadata(const CustomMetadata* metadata) {
    printf("%s: %d\n", metadata->name, metadata->value);
}

// Main function to extract and print metadata from a given file
int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE* fp = fopen(argv[1], "r");
    if (!fp) {
        perror("Error opening file");
        exit(1);
    }

    char buffer[1024];
    CustomMetadata metadata;

    while (fgets(buffer, sizeof(buffer), fp)) {
        sscanf(buffer, "%s", metadata.name);

        if (strstr(buffer, "Metadata:") || strstr(buffer, "METADATA:")) {
            // Extract metadata value
            metadata = extractMetadata(&buffer[strlen(metadata.name) + 1]);

            // Print metadata
            printMetadata(&metadata);
        }
    }

    fclose(fp);

    return 0;
}