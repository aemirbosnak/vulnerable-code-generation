//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_COLUMNS 100
#define MAX_COLUMN_SIZE 50
#define MAX_ROWS 1000

int main()
{
    int row_count = 0;
    int col_count = 0;
    char *col_headers[MAX_COLUMNS];
    char data[MAX_ROWS][MAX_COLUMNS][MAX_COLUMN_SIZE];
    char *line;
    char *temp;
    char *delim = ",";
    size_t len = 0;
    FILE *fp = fopen("data.csv", "r");

    if(fp == NULL) {
        printf("Unable to open file!\n");
        return 1;
    }

    while(getline(&line, &len, fp) != -1 && row_count < MAX_ROWS){
        temp = strtok(line, delim);
        col_count = 0;
        while(temp != NULL && col_count < MAX_COLUMNS){
            if(row_count == 0){
                col_headers[col_count] = malloc(sizeof(char) * MAX_COLUMN_SIZE);
                strcpy(col_headers[col_count], temp);
            }
            else{
                strcpy(data[row_count - 1][col_count], temp);
            }
            temp = strtok(NULL, delim);
            col_count++;
        }
        row_count++;
    }

    fclose(fp);

    printf("Total Rows: %d\n", row_count - 1);
    printf("Total Columns: %d\n", col_count);
    printf("Column Headers:\n");
    for(int i = 0; i < col_count; i++){
        printf("%s, ", col_headers[i]);
    }
    printf("\nData:\n");
    for(int i = 0; i < row_count - 1; i++){
        for(int j = 0; j < col_count; j++){
            printf("%s, ", data[i][j]);
        }
        printf("\n");
    }

    // Freeing allocated memory
    for(int i = 0; i < col_count; i++){
        free(col_headers[i]);
    }

    return 0;
}