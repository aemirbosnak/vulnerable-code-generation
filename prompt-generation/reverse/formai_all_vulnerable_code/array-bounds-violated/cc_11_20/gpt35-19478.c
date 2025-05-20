//FormAI DATASET v1.0 Category: HTML beautifier ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LEN 1024

int main(){

    //Opening the file to be beautified
    FILE* fp;
    fp = fopen("test.html", "r");
    
    //If file does not exist, print error message and exit
    if(fp == NULL){
        printf("Error: Could not open file.\n");
        exit(1);
    }

    //Creating a new file to store the beautified code
    FILE* new_fp;
    new_fp = fopen("beautified.html", "w");

    //Reading the contents of the file line by line
    char line[MAX_LEN];
    int open_tags = 0; //Variable to keep track of open tags
    while(fgets(line, MAX_LEN, fp) != NULL){

        //Loop to remove leading and trailing whitespaces from the line
        int i = 0, j = strlen(line) - 1;
        while(line[i] == ' ' || line[i] == '\t' || line[i] == '\n') i++;
        while(line[j] == ' ' || line[j] == '\t' || line[j] == '\n') j--;
        line[j+1] = '\0'; //Terminating the string
        
        //Detecting and indenting the closing tags
        if(line[0] == '<' && line[1] == '/'){
            open_tags--;
            for(int i=0; i<open_tags; i++){
                fprintf(new_fp, "\t");
            }
        }
        
        //Indenting the opening tags
        else if(line[0] == '<' && line[1] != '/'){
            for(int i=0; i<open_tags; i++){
                fprintf(new_fp, "\t");
            }
            open_tags++;
        }
        
        //Printing the line
        fprintf(new_fp, "%s\n", line);
    }

    //Closing the opened files
    fclose(fp);
    fclose(new_fp);

    printf("Beautification successful!\n");

    return 0;
}