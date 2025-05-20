//FormAI DATASET v1.0 Category: File handling ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fp; //declare file pointer
    char filename[50]; //declare char array to store filename
    int num; //declare integer variable

    //get filename from user
    printf("Enter file name: ");
    scanf("%s", filename);

    //open file for writing
    fp = fopen(filename, "w");

    //check if file is opened successfully
    if(fp == NULL)
    {
        printf("Error in opening file...");
        exit(0);
    }

    //get numbers from user and write to file
    printf("Enter numbers to write to file, enter -1 to stop:\n");
    while(1)
    {
        scanf("%d", &num);

        if(num == -1)
            break;

        fprintf(fp, "%d\n", num);
    }

    //close file
    fclose(fp);

    //open file for reading
    fp = fopen(filename, "r");

    //check if file is opened successfully
    if(fp == NULL)
    {
        printf("Error in opening file...");
        exit(0);
    }

    //read from file and print on screen
    printf("Contents of file %s:\n", filename);
    while(fscanf(fp, "%d", &num) != EOF)
    {
        printf("%d\n", num);
    }

    //close file
    fclose(fp);

    return 0;
}