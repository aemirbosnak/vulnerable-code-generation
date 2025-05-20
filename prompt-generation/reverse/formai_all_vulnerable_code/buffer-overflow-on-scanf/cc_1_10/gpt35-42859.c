//FormAI DATASET v1.0 Category: Data recovery tool ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void recoverData(char* fileName)
{
    FILE *fp; // file pointer
    int size = 0; // variable to track the size of file
    char* data = NULL; // initializing data as null
    
    // opening the file in binary mode
    fp = fopen(fileName, "rb");
    
    // check if the file is opened successfully
    if(fp == NULL)
    {
        printf("Unable to open file!\n");
        exit(1);
    }
    
    // finding the size of the file
    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    
    // allocating memory to read the data
    data = (char*)malloc(sizeof(char) * size);
    
    // check if memory is allocated successfully
    if(data == NULL)
    {
        printf("Unable to allocate memory!\n");
        exit(1);
    }
    
    // reading the data from the file
    fread(data, sizeof(char), size, fp);
    
    // printing the recovered data
    printf("Recovered data: %s\n", data);
    
    // freeing the memory and closing the file
    free(data);
    fclose(fp);
}

int main()
{
    char* fileName; // variable to store the file name
    
    // taking the file name from the user
    printf("Enter the file name: ");
    scanf("%s", fileName);
    
    // check if the file name is valid or not
    if(fileName == NULL || strlen(fileName) <= 0)
    {
        printf("Invalid file name!\n");
        exit(1);
    }
    
    // calling the recoverData function to recover the data from the file
    recoverData(fileName);
    
    return 0;
}