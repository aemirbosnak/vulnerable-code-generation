//FormAI DATASET v1.0 Category: Data recovery tool ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>

void recoverData(char* filename)
{
    FILE *fp;
    fp = fopen(filename, "r");
    if(fp == NULL)
    {
        printf("Error opening the file\n");
        return;
    }

    printf("Data recovery tool is processing ... Happy recovering\n\n");
    char c = fgetc(fp);
    while(c != EOF)
    {
        printf("%c", c);
        c = fgetc(fp);
    }
    printf("\n\n");
    fclose(fp);
}

int main()
{
    printf("Welcome to the Data Recovery Tool!\n\n");

    printf("Enter the name of the file to recover data from: ");
    char filename[50];
    scanf("%s", filename);
    printf("\n");

    // Check if the file exists or not
    FILE* file = fopen(filename, "r");
    if(file == NULL)
    {
        printf("The file '%s' does not exist\n", filename);
        exit(0);
    }
    fclose(file);

    printf("Do you want to continue? (Y/N): ");
    char choice;
    scanf(" %c", &choice);
    printf("\n");
    if(choice == 'Y' || choice == 'y')
    {
        recoverData(filename);
    }
    else
    {
        printf("No worries! Run the tool again when you're ready!\n");
    }

    return 0;
}