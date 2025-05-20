//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_FILE_NAME 255
#define MAX_LINE_LENGTH 1024
#define MAX_NUM_COLUMNS 100

//Definition of CSV Reader Struct
typedef struct{
    char *columns[MAX_NUM_COLUMNS];
    int num_columns;
    char delimiter;
}CSV_Reader;

//Function to Parse a Line of CSV
int parse_line(CSV_Reader *reader, char *line){
    char *token;
    reader->num_columns = 0;
    token = strtok(line, &reader->delimiter);
    while(token != NULL){
        reader->columns[reader->num_columns++] = token;
        if(reader->num_columns == MAX_NUM_COLUMNS){
            return -1;
        }
        token = strtok(NULL, &reader->delimiter);
    }
    return 0;
}

//Function to Open CSV File
FILE *open_csv_file(){
    char *filename = malloc(sizeof(char) * MAX_FILE_NAME);
    printf("Enter file name: ");
    scanf("%s", filename);
    FILE *fp = fopen(filename, "r");
    if(fp == NULL){
        printf("Unable to open file %s", filename);
        exit(1);
    }
    free(filename);
    return fp;
}

//Function to Read CSV File
void read_csv_file(CSV_Reader *reader, FILE *fp){
    char buffer[MAX_LINE_LENGTH];
    while(fgets(buffer, MAX_LINE_LENGTH, fp) != NULL){
        if(parse_line(reader, buffer) != 0){
            printf("Error: Number of columns exceeded maximum\n");
            exit(1);
        }
        else{
            for(int i=0; i<reader->num_columns; i++){
                printf("%s\t", reader->columns[i]);
            }
            printf("\n");
        }
    }
}

//Function to Close CSV File
void close_csv_file(FILE *fp){
    fclose(fp);
}

int main(){
    CSV_Reader reader;
    reader.delimiter = ',';
    FILE *fp = open_csv_file();
    read_csv_file(&reader, fp);
    close_csv_file(fp);
    return 0;
}