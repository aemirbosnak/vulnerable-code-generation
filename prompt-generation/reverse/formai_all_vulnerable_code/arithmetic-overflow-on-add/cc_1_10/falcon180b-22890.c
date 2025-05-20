//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 1000 // maximum size of QR code

// function to generate QR code
void generateQRCode(int size, char* input, char* output) {
    int i, j, k, count = 0;
    bool isBlack = true;
    for(i = 0; i < size; i++) {
        for(j = 0; j < size; j++) {
            if((i + j) % 2 == 0) {
                isBlack =!isBlack;
            }
            if(isBlack) {
                output[count++] = '1';
            } else {
                output[count++] = '0';
            }
        }
        output[count++] = '\n';
    }
    output[count] = '\0';
}

// function to read input file
void readInputFile(char* filename, char* input) {
    FILE* file;
    file = fopen(filename, "r");
    if(file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    rewind(file);
    input = malloc(size + 1);
    fread(input, sizeof(char), size, file);
    fclose(file);
    input[size] = '\0';
}

// function to write output file
void writeOutputFile(char* filename, char* output) {
    FILE* file;
    file = fopen(filename, "w");
    if(file == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }
    fwrite(output, sizeof(char), strlen(output), file);
    fclose(file);
}

// main function
int main(int argc, char** argv) {
    if(argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }
    char* input_file = argv[1];
    char* output_file = argv[2];
    char* input = NULL;
    char* output = NULL;
    readInputFile(input_file, input);
    generateQRCode(MAX_SIZE, input, output);
    writeOutputFile(output_file, output);
    free(input);
    free(output);
    return 0;
}