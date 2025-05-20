//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: enthusiastic
//Welcome to the Amazing CSV Reader Program!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define constant variables
#define MAX_ROW_LENGTH 1024 
#define MAX_COL_NUM 256

int main() {
    
    printf("Want to read in a CSV file? This program can do that for you!\n");

    //declare variables
    char fileName[50];
    FILE *filePointer; 
    char row[MAX_ROW_LENGTH];
    char *col[MAX_COL_NUM];

    printf("Enter the name of your CSV file (make sure its in the same directory as the program): ");
    scanf("%s", fileName);

    //try to open the file
    filePointer = fopen(fileName, "r");

    //if file opening failed, throw error and exit program
    if(filePointer == NULL) {
        printf("Error: Could not open file");
        exit(EXIT_FAILURE);
    }

    //if file opening successful, read the file
    else {
        int currentRow = 0;

        while(fgets(row, MAX_ROW_LENGTH, filePointer) != NULL) {
            
            //tokenize the read row by comma
            char *token = strtok(row, ",");
            int currentCol = 0;

            //store the tokens in a 2D array of columns
            while(token != NULL) {
                col[currentRow][currentCol++] = token;
                token = strtok(NULL, ",");
            }

            //increment row number
            currentRow++;
        }

        //close the file after reading
        fclose(filePointer);

        //print out the read in CSV data
        printf("\n-------CSV Data-------\n");
        for(int i = 0; i < currentRow; i++) {
            printf("Row %d: ", i+1);

            for(int j = 0; j < MAX_COL_NUM; j++) {
                if(col[i][j] != NULL)
                    printf("[%s] ", col[i][j]);
                else
                    break;
            }

            printf("\n");
        }
    }

    printf("\nThank you for using the Amazing CSV Reader Program!");
    return 0;
}