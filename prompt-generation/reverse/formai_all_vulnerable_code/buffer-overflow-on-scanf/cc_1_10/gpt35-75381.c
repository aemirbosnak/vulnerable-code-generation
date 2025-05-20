//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS 20
#define MAX_ROWS 200
#define MAX_DATA 1000

int main(){
    char filename[100];
    printf("Enter CSV file name: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");
    if(fp == NULL){
        printf("File not found\n");
        exit(EXIT_FAILURE);
    }

    char *cols[MAX_COLS];
    char *data[MAX_ROWS][MAX_COLS];
    int num_cols = 0;
    int num_rows = 0;

    char line[MAX_DATA];
    char *token;

    while(fgets(line, MAX_DATA, fp)){
        token = strtok(line, ",");
        while(token != NULL){
            if(num_rows == 0){
                cols[num_cols] = strdup(token);
            }
            else{
                data[num_rows-1][num_cols] = strdup(token);
            }
            num_cols++;
            token = strtok(NULL, ",");
        }
        num_rows++;
        num_cols = 0;
    }

    fclose(fp);

    printf("\nCSV File: %s\n\n", filename);

    for(int i=0; i<num_rows; i++){
        for(int j=0; j<num_cols; j++){
            printf("%s: %s\n", cols[j], data[i][j]);
        }
        printf("\n");
    }

    for(int i=0; i<num_cols; i++){
        free(cols[i]);
    }

    for(int i=0; i<num_rows; i++){
        for(int j=0; j<num_cols; j++){
            free(data[i][j]);
        }
    }

    return 0;
}