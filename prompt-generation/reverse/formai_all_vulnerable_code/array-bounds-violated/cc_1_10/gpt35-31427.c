//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELDS 10
#define MAX_FIELD_LEN 50

int countFields(char *line, char delim){
    int count = 0;

    for (int i=0; i<strlen(line); i++){
        if (line[i] == delim){
            count++;
        }
    }

    return count+1;
}

void splitLine(char *line, char **fields, char delim){
    int i = 0;
    char *token = strtok(line, &delim);
    while (token != NULL && i < MAX_FIELDS){
        fields[i++] = token;
        token = strtok(NULL, &delim);
    }
}

void printFields(char **fields, int numFields){
    for (int i=0; i<numFields; i++){
        printf("%s,", fields[i]);
    }
    printf("\n");
}

int main(){
    FILE *fp;
    char line[MAX_FIELD_LEN * MAX_FIELDS];
    char delim = ',';
    char *fields[MAX_FIELDS];
    int numFields = 0;

    fp = fopen("data.csv", "r");
    if (fp == NULL){
        printf("Error opening file!\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp) != NULL){
        // Remove the newline character from the end of the line
        line[strlen(line)-1] = '\0';

        // Get the number of fields in the line
        numFields = countFields(line, delim);

        // Split the line into fields
        splitLine(line, fields, delim);

        // Print out the fields
        printFields(fields, numFields);
    }

    fclose(fp);
    return 0;
}