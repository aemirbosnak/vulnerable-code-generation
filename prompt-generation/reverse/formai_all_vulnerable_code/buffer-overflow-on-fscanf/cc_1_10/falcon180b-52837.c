//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 1000
#define BLACK 0
#define WHITE 1
#define DEBUG 0

// Function to initialize the matrix
void init_matrix(int matrix[MAX_SIZE][MAX_SIZE]) {
    int i, j;
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            matrix[i][j] = WHITE;
        }
    }
}

// Function to print the matrix
void print_matrix(int matrix[MAX_SIZE][MAX_SIZE]) {
    int i, j;
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to get the module value
int get_module(int value, int module_size) {
    return value % module_size;
}

// Function to convert a string to uppercase
void strtoupper(char *str) {
    int i, len = strlen(str);
    for (i = 0; i < len; i++) {
        str[i] = toupper(str[i]);
    }
}

// Function to read a QR code from a file
int read_qrcode(char *filename, int matrix[MAX_SIZE][MAX_SIZE]) {
    FILE *fp;
    int i, j, value, module_size;
    char line[1024];
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        return 0;
    }
    fscanf(fp, "%d", &module_size);
    init_matrix(matrix);
    while (fgets(line, sizeof(line), fp)!= NULL) {
        strtoupper(line);
        for (i = 0; i < strlen(line); i++) {
            if (line[i] == '1') {
                value = 1;
            } else {
                value = 0;
            }
            matrix[get_module(i, module_size)][get_module(j, module_size)] = value;
        }
    }
    fclose(fp);
    return 1;
}

// Function to print the decoded message
void print_message(int matrix[MAX_SIZE][MAX_SIZE]) {
    int i, j;
    char message[1024];
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            if (matrix[i][j] == BLACK) {
                message[i * MAX_SIZE + j] = '1';
            } else {
                message[i * MAX_SIZE + j] = '0';
            }
        }
    }
    message[strcspn(message, "\n")] = '\0';
    printf("Decoded message: %s\n", message);
}

// Main function
int main(int argc, char *argv[]) {
    int matrix[MAX_SIZE][MAX_SIZE];
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 0;
    }
    read_qrcode(argv[1], matrix);
    print_matrix(matrix);
    print_message(matrix);
    return 0;
}