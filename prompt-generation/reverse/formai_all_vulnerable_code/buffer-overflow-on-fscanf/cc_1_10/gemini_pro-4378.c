//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Linus Torvalds-style cursing macros
#define FCK(x)  fprintf(stderr, "F**k %s!\n", (x))
#define SHIT   fprintf(stderr, "SHIT!\n")
#define WTF     fprintf(stderr, "WTF?!\n")

// Data mining functions
int load_data(char *filename, int **data, int *num_rows, int *num_cols) {
    // Open the file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        FCK("fopen");
        return -1;
    }

    // Read the number of rows and columns from a first line
    if (fscanf(fp, "%d %d", num_rows, num_cols) != 2) {
        FCK("fscanf");
        fclose(fp);
        return -1;
    }

    // Allocate memory for the data
    *data = (int *)malloc(*num_rows * *num_cols * sizeof(int));
    if (*data == NULL) {
        FCK("malloc");
        fclose(fp);
        return -1;
    }

    // Read the data from the file
    for (int i = 0; i < *num_rows; i++) {
        for (int j = 0; j < *num_cols; j++) {
            if (fscanf(fp, "%d", &(*data)[i * *num_cols + j]) != 1) {
                FCK("fscanf");
                fclose(fp);
                free(*data);
                return -1;
            }
        }
    }

    // Close the file
    fclose(fp);

    return 0;
}

void print_data(int *data, int num_rows, int num_cols) {
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            printf("%d ", data[i * num_cols + j]);
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    // Check the command line arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Load the data
    int *data;
    int num_rows, num_cols;
    if (load_data(argv[1], &data, &num_rows, &num_cols) != 0) {
        return EXIT_FAILURE;
    }

    // Print the data
    print_data(data, num_rows, num_cols);

    // Free the data
    free(data);

    return EXIT_SUCCESS;
}