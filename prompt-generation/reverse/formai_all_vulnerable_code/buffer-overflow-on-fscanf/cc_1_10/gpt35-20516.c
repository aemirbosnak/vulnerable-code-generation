//FormAI DATASET v1.0 Category: File handling ; Style: modular
#include <stdio.h>
#include <stdlib.h>

/* Function declarations */
void read_data(FILE *fp, int *data, int size);
void sort_data(int *data, int size);
void write_data(FILE *fp, int *data, int size);

/* Main function */
int main() {
    FILE *fp;
    int *data;
    int size;

    /* Open the file for reading */
    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    /* Get the size of the data */
    fscanf(fp, "%d", &size);

    /* Allocate memory for the data */
    data = (int *) malloc(size * sizeof(int));
    if (data == NULL) {
        printf("Error allocating memory.\n");
        exit(1);
    }

    /* Read the data from the file */
    read_data(fp, data, size);

    /* Close the file */
    fclose(fp);

    /* Sort the data */
    sort_data(data, size);

    /* Open the file for writing */
    fp = fopen("data.txt", "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    /* Write the sorted data to the file */
    write_data(fp, data, size);

    /* Close the file */
    fclose(fp);

    /* Free the memory used by the data */
    free(data);

    return 0;
}

/* Function definitions */

/* Reads data from a file into an array */
void read_data(FILE *fp, int *data, int size) {
    int i;
    for (i = 0; i < size; i++) {
        fscanf(fp, "%d", &data[i]);
    }
}

/* Sorts an array of integers in ascending order */
void sort_data(int *data, int size) {
    int i, j, temp;
    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            if (data[i] > data[j]) {
                temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}

/* Writes an array of integers to a file */
void write_data(FILE *fp, int *data, int size) {
    int i;
    /* Write the size of the data to the file */
    fprintf(fp, "%d\n", size);
    /* Write the data to the file */
    for (i = 0; i < size; i++) {
        fprintf(fp, "%d ", data[i]);
    }
    fprintf(fp, "\n");
}