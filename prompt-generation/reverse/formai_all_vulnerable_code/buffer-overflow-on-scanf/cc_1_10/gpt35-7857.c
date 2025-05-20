//FormAI DATASET v1.0 Category: File handling ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char file_name[20];
    int num;

    printf("Enter file name: "); //Asks for file name to the user
    scanf("%s", file_name);

    fp = fopen(file_name, "w"); //Opens the file for writing

    if(fp == NULL) //If file is not able to open.
    {
        printf("Error opening file. \n");
        exit(1);
    }

    printf("Enter how many numbers you would like to write to the file: "); //Asks how many numbers will be written to the file.
    scanf("%d", &num);

    int arr[num];

    printf("\n");

    for(int i = 0; i < num; i++)
    {
        printf("Enter number %d: ", i+1); //Asks for integers from the user to write to the file.
        scanf("%d", &arr[i]);
        fprintf(fp, "%d ", arr[i]); //Writes the numbers to the file
    }

    fclose(fp); //Closes the file

    printf("\nSuccessfully wrote to the file %s\n", file_name);

    fp = fopen(file_name, "r"); //Opens the file for reading

    if(fp == NULL) //If file is not able to open.
    {
        printf("Error opening file. \n");
        exit(1);
    }

    printf("\nThe contents of the file are: \n");

    while(fscanf(fp, "%d", &num) != EOF) //Reads the contents of the file and prints them to the console.
    {
        printf("%d ", num);
    }

    fclose(fp); //Closes the file

    return 0;
}