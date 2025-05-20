//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024
#define CONFIG_FILE "config.txt"

typedef struct {
    char inputFileName[MAX_BUFFER_SIZE];
    char outputFileName[MAX_BUFFER_SIZE];
    int enableLogging;
} Config;

void readConfig(Config *config) {
    FILE *file = fopen(CONFIG_FILE, "r");
    if (file == NULL) {
        perror("Failed to open config file");
        exit(EXIT_FAILURE);
    }
    
    fgets(config->inputFileName, MAX_BUFFER_SIZE, file);
    strtok(config->inputFileName, "\n"); // Remove newline character
    
    fgets(config->outputFileName, MAX_BUFFER_SIZE, file);
    strtok(config->outputFileName, "\n"); // Remove newline character
    
    fscanf(file, "%d", &config->enableLogging);
    
    fclose(file);
}

unsigned short calculateChecksum(const unsigned char *data, size_t length) {
    unsigned short checksum = 0;
    
    for (size_t i = 0; i < length; i++) {
        checksum += data[i];
    }
    
    return checksum;
}

void logMessage(const char *message) {
    printf("[LOG] %s\n", message);
}

void processFile(const Config *config) {
    FILE *inputFile = fopen(config->inputFileName, "rb");
    if (inputFile == NULL) {
        perror("Failed to open input file");
        exit(EXIT_FAILURE);
    }
    
    fseek(inputFile, 0, SEEK_END);
    long fileSize = ftell(inputFile);
    fseek(inputFile, 0, SEEK_SET);
    
    unsigned char *data = (unsigned char *)malloc(fileSize);
    if (data == NULL) {
        perror("Failed to allocate memory");
        fclose(inputFile);
        exit(EXIT_FAILURE);
    }
    
    fread(data, 1, fileSize, inputFile);
    fclose(inputFile);
    
    unsigned short checksum = calculateChecksum(data, fileSize);
    
    FILE *outputFile = fopen(config->outputFileName, "w");
    if (outputFile == NULL) {
        perror("Failed to open output file");
        free(data);
        exit(EXIT_FAILURE);
    }
    
    fprintf(outputFile, "Checksum: %04X\n", checksum);
    fclose(outputFile);
    
    if (config->enableLogging) {
        char logMessageBuffer[MAX_BUFFER_SIZE];
        snprintf(logMessageBuffer, sizeof(logMessageBuffer), 
                 "Processed file: %s, Checksum: %04X", 
                 config->inputFileName, checksum);
        logMessage(logMessageBuffer);
    }
    
    free(data);
}

int main() {
    Config config;
    readConfig(&config);
    
    if (config.enableLogging) {
        logMessage("Starting checksum calculation...");
    }
    
    processFile(&config);

    if (config.enableLogging) {
        logMessage("Checksum calculation completed successfully.");
    }
    
    return 0;
}