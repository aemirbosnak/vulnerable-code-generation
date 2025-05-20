//FormAI DATASET v1.0 Category: Data recovery tool ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Oh no! Your data has been lost\n");
    printf("But don't worry, we have just the tool you need\n");
    printf("Introducing the unique C data recovery tool!\n");
    
    char filename[50];
    printf("Please enter the name of the file you want to recover: ");
    scanf("%s", filename);
    
    FILE *fp = fopen(filename, "r");
    if(fp == NULL)
    {
        printf("File not found. Sorry, we can't recover what isn't there.\n");
        exit(0);
    }
    
    char recovered_data[1000];
    int i = 0;
    while(!feof(fp))
    {
        char c = fgetc(fp);
        if(c == EOF)
            break;
        recovered_data[i] = c;
        i++;
    }
    fclose(fp);
    
    printf("Your data has been recovered! Here it is:\n");
    printf("%s\n", recovered_data);
    
    printf("Would you like to save the recovered data to a new file? (y/n)");
    char answer[5];
    scanf("%s", answer);
    if(strcmp(answer, "y") == 0)
    {
        char new_filename[50];
        printf("Please enter the name of the new file: ");
        scanf("%s", new_filename);
        FILE *fp2 = fopen(new_filename, "w");
        if(fp2 == NULL)
        {
            printf("Error creating new file.\n");
            exit(0);
        }
        fprintf(fp2, "%s", recovered_data);
        fclose(fp2);
    }
    else
    {
        printf("Okay, your recovered data has not been saved.\n");
    }
    
    printf("Thanks for using our C data recovery tool! We hope your data is safe from now on.\n");
    
    return 0;
}