//Falcon-180B DATASET v1.0 Category: File handling ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

#define MAX_FILE_NAME_SIZE 100
#define MAX_LINE_SIZE 1000

int main()
{
    char file_name[MAX_FILE_NAME_SIZE], line[MAX_LINE_SIZE];
    FILE *fp;
    int file_size;
    char *file_content = NULL;

    //get file name from user
    printf("Enter file name: ");
    scanf("%s", file_name);

    //open file in read mode
    fp = fopen(file_name, "r");

    //check if file is opened successfully
    if(fp == NULL)
    {
        printf("Error: File not found\n");
        exit(0);
    }

    //get file size
    fseek(fp, 0L, SEEK_END);
    file_size = ftell(fp);
    rewind(fp);

    //allocate memory to file content
    file_content = (char*)malloc(file_size + 1);

    //read file content
    fread(file_content, sizeof(char), file_size, fp);

    //close file
    fclose(fp);

    //remove new line character
    file_content[file_size - 1] = '\0';

    //reverse file content
    for(int i=0; i<strlen(file_content)/2; i++)
    {
        char temp = file_content[i];
        file_content[i] = file_content[strlen(file_content) - i - 1];
        file_content[strlen(file_content) - i - 1] = temp;
    }

    //write reversed content to new file
    strcat(file_name, "_reversed");
    fp = fopen(file_name, "w");

    if(fp == NULL)
    {
        printf("Error: File not found\n");
        exit(0);
    }

    fwrite(file_content, sizeof(char), strlen(file_content), fp);

    //close file
    fclose(fp);

    //print reversed content
    printf("Reversed content:\n");
    fp = fopen(file_name, "r");

    if(fp == NULL)
    {
        printf("Error: File not found\n");
        exit(0);
    }

    while(fgets(line, MAX_LINE_SIZE, fp)!= NULL)
    {
        printf("%s", line);
    }

    //close file
    fclose(fp);

    return 0;
}