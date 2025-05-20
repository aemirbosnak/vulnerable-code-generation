//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024 // size of the buffer to read in data

typedef struct {
    FILE *fp; // file pointer to the CSV file
    char delimiter; // delimiter character for the CSV file
    char *buffer; // buffer to hold the CSV data
} CSVReader;

// Function to initialize a CSVReader object
CSVReader *csv_init(FILE *fp, char delimiter) {
    CSVReader *reader = (CSVReader*)malloc(sizeof(CSVReader));
    if (reader == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    reader->fp = fp;
    reader->delimiter = delimiter;
    reader->buffer = (char*)malloc(BUFFER_SIZE * sizeof(char));
    if (reader->buffer == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    memset(reader->buffer, 0, BUFFER_SIZE);
    return reader;
}

// Function to read in a line of data from the CSV file
int csv_read_line(CSVReader *reader) {
    int bytes_read = 0;
    char *ptr = reader->buffer;
    while ((bytes_read < BUFFER_SIZE - 1) && (fgetc(reader->fp)!= EOF)) {
        if (fgetc(reader->fp) == reader->delimiter) {
            *ptr = 0;
            break;
        }
        else {
            *ptr++ = fgetc(reader->fp);
            bytes_read++;
        }
    }
    if (bytes_read == 0) {
        return 0; // end of file reached
    }
    else {
        return 1;
    }
}

// Function to read in a field of data from the CSV file
char *csv_read_field(CSVReader *reader) {
    int i = 0;
    char *ptr = reader->buffer;
    while (*ptr!= 0 && *ptr!= reader->delimiter) {
        i++;
        ptr++;
    }
    return ptr;
}

// Function to close a CSVReader object
void csv_close(CSVReader *reader) {
    free(reader->buffer);
    free(reader);
}

// Example usage of CSVReader object
int main() {
    FILE *fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Error: Could not open file\n");
        exit(1);
    }
    CSVReader *reader = csv_init(fp, ',');
    if (reader == NULL) {
        exit(1);
    }
    int row = 0;
    int col = 0;
    char *field;
    while (csv_read_line(reader)) {
        row++;
        col = 0;
        field = csv_read_field(reader);
        while (field!= NULL) {
            printf("%d,%d: %s\n", row, col++, field);
            field = csv_read_field(reader);
        }
    }
    csv_close(reader);
    fclose(fp);
    return 0;
}