//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int main()
{
    char filename[20];
    printf("Enter the name of the file: ");
    scanf("%s",filename);
    FILE *fp=fopen(filename,"r"); //Opening the file

    if(fp==NULL) //If file does not exist
    {
        printf("The file does not exist.");
        exit(0);
    }

    char c, buffer[512];
    int i=0, virusCount=0, found=0;

    while((c=getc(fp))!=EOF) //Reading the file character by character
    {
        if(isalnum(c)) //If character is alphanumeric, store it in buffer
        {
            buffer[i++]=c;
        }
        else //If it's not alphanumeric character, check if it's a virus
        {
            buffer[i]='\0'; //Terminating the buffer with '\0'
            i=0; //Resetting the buffer index

            //List of viruses
            char virus1[]="kill";
            char virus2[]="crash";
            char virus3[]="destroy";

            if(strcmp(buffer,virus1)==0 || strcmp(buffer,virus2)==0 || strcmp(buffer,virus3)==0) //If virus found
            {
                found=1;
                virusCount++;
            }
        }
    }

    if(found==1) //If any virus is found
    {
        printf("Virus found! %d virus detected.\n",virusCount);
    }
    else //If no virus is found
    {
        printf("No virus found.\n");
    }

    fclose(fp); //Closing the file

    return 0;
}