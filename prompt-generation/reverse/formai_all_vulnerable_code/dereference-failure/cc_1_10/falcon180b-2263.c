//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 100
#define CHECKSUM_VALUE 0x7F

// Function to calculate the checksum value
unsigned char calculate_checksum(char *data) {
    int i, sum = 0;
    for (i = 0; i < strlen(data); i++) {
        sum += data[i];
    }
    return (unsigned char) (sum % CHECKSUM_VALUE);
}

// Function to validate the checksum value
int validate_checksum(char *data, unsigned char checksum) {
    int i, sum = 0;
    char checksum_value = 0;
    for (i = 0; i < strlen(data); i++) {
        sum += data[i];
    }
    checksum_value = (char) (sum % CHECKSUM_VALUE);
    if (checksum_value == checksum) {
        return 1;
    } else {
        return 0;
    }
}

// Function to read input data
char *read_input_data(FILE *fp) {
    char *data = (char *) malloc(MAX_LENGTH * sizeof(char));
    if (fgets(data, MAX_LENGTH, fp) == NULL) {
        printf("Error: Input data is empty.\n");
        exit(1);
    }
    return data;
}

// Function to write output data
void write_output_data(FILE *fp, char *data) {
    fprintf(fp, "Input data: %s\n", data);
    char checksum = calculate_checksum(data);
    fprintf(fp, "Checksum value: %d\n", checksum);
    if (validate_checksum(data, checksum)) {
        fprintf(fp, "Checksum validation: Passed\n");
    } else {
        fprintf(fp, "Checksum validation: Failed\n");
    }
}

int main() {
    FILE *fp;
    char *data;

    // Open input file
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error: Input file not found.\n");
        exit(1);
    }

    // Read input data
    data = read_input_data(fp);

    // Calculate checksum value
    unsigned char checksum = calculate_checksum(data);

    // Validate checksum value
    int validation_result = validate_checksum(data, checksum);

    // Write output data
    write_output_data(fp, data);

    // Close input file
    fclose(fp);

    return 0;
}