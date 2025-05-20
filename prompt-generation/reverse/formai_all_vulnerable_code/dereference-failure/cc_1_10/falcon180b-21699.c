//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read data from file
void read_file(char *filename, char **data, int *size) {
    FILE *fp;
    char ch;
    int i = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    *data = (char *) malloc(100000); // Allocate memory for data

    while ((ch = fgetc(fp))!= EOF) {
        (*data)[i] = ch;
        i++;
    }

    (*size) = i;

    fclose(fp);
}

// Function to write data to file
void write_file(char *filename, char *data, int size) {
    FILE *fp;

    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        fputc(data[i], fp);
    }

    fclose(fp);
}

// Function to recover data from corrupted file
void recover_data(char *filename) {
    char *data;
    int size;

    read_file(filename, &data, &size);

    for (int i = 0; i < size; i++) {
        if (data[i] == '\0') {
            printf("Corrupted data found at position %d\n", i);
            exit(1);
        }
    }

    printf("Data recovery successful\n");
}

int main() {
    char filename[100];
    printf("Enter the name of the file: ");
    scanf("%s", filename);

    recover_data(filename);

    return 0;
}