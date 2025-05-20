//FormAI DATASET v1.0 Category: Data recovery tool ; Style: real-life
#include<stdio.h>
#include<stdlib.h>

typedef struct recovery_tool{
    char file_name[50];
    int file_size;
    char *data;
} Recovery_Tool;

void read_file(Recovery_Tool *tool){
    printf("Enter the file name: ");
    scanf("%s", tool->file_name);

    FILE *fp = fopen(tool->file_name, "rb");

    if(fp == NULL){
        printf("Error: Could not open the file.\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    tool->file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    tool->data = (char *) malloc(tool->file_size + 1);

    if(tool->data == NULL){
        printf("Error: Could not allocate memory.\n");
        exit(1);
    }

    fread(tool->data, 1, tool->file_size, fp);
    fclose(fp);
    printf("\nFile successfully read.\n");
}

void write_file(Recovery_Tool *tool){
    int overwrite_option;
    printf("\nThe file %s already exists. Do you want to overwrite it?\n1. Yes    2. No\n", tool->file_name);
    scanf("%d", &overwrite_option);

    if(overwrite_option == 2){
        printf("File not overwritten.\n");
        return;
    }

    FILE *fp = fopen(tool->file_name, "w");

    if(fp == NULL){
        printf("Error: Could not open the file.\n");
        exit(1);
    }

    fwrite(tool->data, 1, tool->file_size, fp);
    fclose(fp);
    printf("File successfully overwritten.\n");
}

int main(){
    Recovery_Tool tool;

    printf("Data Recovery Tool\n");
    printf("-------------------\n");

    read_file(&tool);
    printf("The file size is: %d bytes.\n", tool.file_size);

    write_file(&tool);
    printf("\nProgram execution complete.\n");

    free(tool.data);
    return 0;
}