//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_ROWS 1000
#define MAX_COLS 100
#define MAX_CELL_SIZE 100

typedef struct{
    char delimiter;
    FILE *file;
    int num_rows;
    int num_cols;
    char **data;
}CSVReader;

CSVReader *create_csv_reader(char delimiter, char *filename){
    CSVReader *reader = (CSVReader *)malloc(sizeof(CSVReader));
    reader->delimiter = delimiter;
    reader->file = fopen(filename, "r");
    reader->num_rows = 0;
    reader->num_cols = 0;
    reader->data = (char **)malloc(MAX_ROWS*sizeof(char *));
    for(int i=0; i<MAX_ROWS; i++){
        reader->data[i] = (char *)malloc(MAX_COLS*sizeof(char));
    }
    return reader;
}

void destroy_csv_reader(CSVReader *reader){
    fclose(reader->file);
    for(int i=0; i<MAX_ROWS; i++){
        free(reader->data[i]);
    }
    free(reader->data);
    free(reader);
}

int read_csv_file(CSVReader *reader){
    char line[MAX_CELL_SIZE];
    char *cell = NULL;
    int row = 0;
    int col = 0;
    while(fgets(line, MAX_CELL_SIZE, reader->file)!= NULL){
        cell = strtok(line, reader->delimiter);
        while(cell!= NULL){
            if(row >= MAX_ROWS){
                printf("Error: Maximum number of rows exceeded.\n");
                destroy_csv_reader(reader);
                exit(1);
            }
            if(col >= MAX_COLS){
                printf("Error: Maximum number of columns exceeded.\n");
                destroy_csv_reader(reader);
                exit(1);
            }
            strcpy(reader->data[row][col], cell);
            col++;
            cell = strtok(NULL, reader->delimiter);
        }
        row++;
        col = 0;
    }
    reader->num_rows = row;
    reader->num_cols = col;
    return 0;
}

int print_csv_data(CSVReader *reader){
    for(int i=0; i<reader->num_rows; i++){
        for(int j=0; j<reader->num_cols; j++){
            printf("%s ", reader->data[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int main(){
    CSVReader *reader = create_csv_reader(',', "data.csv");
    read_csv_file(reader);
    print_csv_data(reader);
    destroy_csv_reader(reader);
    return 0;
}