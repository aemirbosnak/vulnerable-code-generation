//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure for CSV data
typedef struct {
    int rows;
    int cols;
    char **data;
} CSV;

// Function to create an empty CSV
CSV *createCSV(int rows, int cols) {
    CSV *csv = (CSV *)malloc(sizeof(CSV));
    csv->rows = rows;
    csv->cols = cols;
    csv->data = (char **)malloc(rows * sizeof(char *));
    for(int i=0; i<rows; i++) {
        csv->data[i] = (char *)malloc(cols * sizeof(char));
        for(int j=0; j<cols; j++) {
            csv->data[i][j] = '\0';
        }
    }
    return csv;
}

// Function to read CSV data from a file
CSV *readCSV(FILE *fp) {
    char ch;
    int rows = 0, cols = 0;
    rewind(fp);
    while((ch = fgetc(fp))!= EOF) {
        if(ch == '\n') {
            rows++;
            cols = 0;
        } else if(ch == ',') {
            cols++;
        }
    }
    rewind(fp);
    CSV *csv = createCSV(rows, cols);
    int i=0, j=0;
    while((ch = fgetc(fp))!= EOF) {
        if(ch == '\n') {
            i++;
            j = 0;
        } else if(ch == ',') {
            j++;
        } else {
            csv->data[i][j] = ch;
            j++;
        }
    }
    return csv;
}

// Function to print CSV data
void printCSV(CSV *csv) {
    for(int i=0; i<csv->rows; i++) {
        for(int j=0; j<csv->cols; j++) {
            printf("%c", csv->data[i][j]);
        }
        printf("\n");
    }
}

// Function to free CSV data
void freeCSV(CSV *csv) {
    for(int i=0; i<csv->rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int main() {
    FILE *fp;
    fp = fopen("data.csv", "r");
    CSV *csv = readCSV(fp);
    printCSV(csv);
    freeCSV(csv);
    fclose(fp);
    return 0;
}