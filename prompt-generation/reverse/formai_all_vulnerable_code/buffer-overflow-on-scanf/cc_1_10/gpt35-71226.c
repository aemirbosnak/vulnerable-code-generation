//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct metadata{
    char* name;
    int size;
    char* type;
};

int main(){
    char input[100];
    printf("Enter the name of the file: ");
    scanf("%s", input);
    printf("\n");

    FILE *fp;
    fp = fopen(input, "r");

    if(fp == NULL){
        perror("Error opening file.");
        exit(EXIT_FAILURE);
    }

    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    int count = 0;
    struct metadata meta[100];

    printf("Metadata:\n");

    while((read = getline(&line, &len, fp)) != -1){
        char* token;
        token = strtok(line, ",");
        while(token != NULL){
            if(strcmp(token, "Name:") == 0){
                count++;
                meta[count].name = strtok(NULL, ",");
                meta[count].name = strtok(meta[count].name, "\n");
                printf("Name: %s\n", meta[count].name);
            }
            if(strcmp(token, "Size:") == 0){
                meta[count].size = atoi(strtok(NULL, ","));
                printf("Size: %d\n", meta[count].size);
            }
            if(strcmp(token, "Type:") == 0){
                meta[count].type = strtok(NULL, ",");
                meta[count].type = strtok(meta[count].type, "\n");
                printf("Type: %s\n", meta[count].type);
            }
            token = strtok(NULL, ",");
        }
    }

    fclose(fp);
    if(line)
      free(line);
    exit(EXIT_SUCCESS);
}