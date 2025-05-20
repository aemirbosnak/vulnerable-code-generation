//FormAI DATASET v1.0 Category: File Synchronizer ; Style: Claude Shannon
/*
 *  C File Synchronizer program
 *  Based on Claude Shannon's information theory principles
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024

// Function to calculate the entropy of a given file
double entropy(char* filename) {
    FILE *file;
    int i, freq[256] = {0}, count = 0;
    double ent = 0.0;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error reading file %s", filename);
        exit(1);
    }

    while ((i = fgetc(file)) != EOF) {
        freq[i]++;
        count++;
    }

    for (i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            double p = (double) freq[i] / count;
            ent -= p * log2(p);
        }
    }

    fclose(file);
    return ent;
}

int main(int argc, char* argv[]) {

    // Check command-line arguments
    if (argc != 3) {
        printf("Usage: %s [file1] [file2]\n", argv[0]);
        exit(1);
    }

    char* file1 = argv[1];
    char* file2 = argv[2];

    // Calculate entropy of files
    double ent1 = entropy(file1);
    double ent2 = entropy(file2);

    if (ent1 > ent2) {
        printf("%s is more complex than %s\n", file1, file2);
        // Copy file2 to file1
        FILE *in_file, *out_file;
        char data[MAX_FILE_SIZE];

        in_file = fopen(file2, "r");
        if (in_file == NULL) {
            printf("Error reading file %s", file2);
            exit(1);
        }

        out_file = fopen(file1, "w");
        if (out_file == NULL) {
            printf("Error writing file %s", file1);
            exit(1);
        }

        while(fgets(data, MAX_FILE_SIZE, in_file) != NULL) {
            fputs(data, out_file);
        }

        fclose(in_file);
        fclose(out_file);
    }
    else if (ent2 > ent1) {
        printf("%s is more complex than %s\n", file2, file1);
        // Copy file1 to file2
        FILE *in_file, *out_file;
        char data[MAX_FILE_SIZE];

        in_file = fopen(file1, "r");
        if (in_file == NULL) {
            printf("Error reading file %s", file1);
            exit(1);
        }

        out_file = fopen(file2, "w");
        if (out_file == NULL) {
            printf("Error writing file %s", file2);
            exit(1);
        }

        while(fgets(data, MAX_FILE_SIZE, in_file) != NULL) {
            fputs(data, out_file);
        }

        fclose(in_file);
        fclose(out_file);
    }
    else {
        printf("%s and %s have the same complexity\n", file1, file2);
    }

    return 0;
}