//FormAI DATASET v1.0 Category: File handling ; Style: protected
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr;

    char filename[50];
    char sentence[100];

    printf("Enter filename: ");
    scanf("%s", filename);

    //open file in write mode
    fptr = fopen(filename, "w");

    //check if file opened successfully
    if(fptr == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    //ask user to enter sentence
    printf("Enter a sentence to write in file: \n");
    fgets(sentence, 100, stdin);

    //write sentence to file
    fputs(sentence, fptr);

    //close file
    fclose(fptr);

    //open file in read mode
    fptr = fopen(filename, "r");

    //check if file opened successfully
    if(fptr == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    //print contents of the file
    printf("Contents of the file:\n");

    char ch;
    while((ch = fgetc(fptr)) != EOF)
        printf("%c", ch);

    //close file
    fclose(fptr);

    return 0;
}