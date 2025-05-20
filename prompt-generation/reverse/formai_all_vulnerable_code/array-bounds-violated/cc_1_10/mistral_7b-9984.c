//MISTRAL-7B DATASET v1.0 Category: Metadata Extractor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Metadata structure definition
typedef struct {
    char experiment_name[100];
    float temperature;
    int pressure;
    char timestamp[20];
} Metadata;

// Function to read metadata from .dat file
Metadata read_metadata(FILE *file) {
    Metadata metadata;
    fscanf(file, "%s %f %d", metadata.experiment_name, &metadata.temperature, &metadata.pressure);
    fgets(metadata.timestamp, sizeof(metadata.timestamp), file);
    metadata.timestamp[strlen(metadata.timestamp) - 1] = '\0'; // Remove newline character
    return metadata;
}

// Function to write metadata to .txt file
void write_metadata(const Metadata *metadata, FILE *file) {
    fprintf(file, "Experiment Name: %s\n", metadata->experiment_name);
    fprintf(file, "Temperature: %.2f\n", metadata->temperature);
    fprintf(file, "Pressure: %d\n", metadata->pressure);
    fprintf(file, "Timestamp: %s\n", metadata->timestamp);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s input.dat output.txt\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (!input_file) {
        perror("Error opening input file");
        return 1;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (!output_file) {
        perror("Error opening output file");
        fclose(input_file);
        return 1;
    }

    Metadata metadata = read_metadata(input_file);
    write_metadata(&metadata, output_file);

    fclose(input_file);
    fclose(output_file);

    return 0;
}