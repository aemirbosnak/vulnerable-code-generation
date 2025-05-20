//FormAI DATASET v1.0 Category: File handling ; Style: romantic
#include<stdio.h>

int main()
{
    FILE *fp;
    char ch, name[20], message[100];
    int i;

    printf("Enter the file name: ");
    scanf("%s", name);

    fp=fopen(name, "w"); //Opening file in write mode

    if(fp==NULL) //Checking if file exists
    {
        printf("File does not exist or could not be created.\n");
    }
    else
    {
        printf("File created successfully!\nEnter your romantic message: ");
        scanf(" %[^\n]s", message); //Taking input of romantic message

        for(i=0; message[i]!='\0'; i++) //Writing romantic message to file one by one
        {
            fputc(message[i], fp);
        }

        printf("\nYour message has been saved to %s.\n", name);
        fclose(fp); //Closing the file
    }

    fp=fopen(name, "r"); //Opening file in read mode

    if(fp==NULL) //Checking if file exists
    {
        printf("File does not exist or could not be opened.\n");
    }
    else
    {
        printf("Here's your romantic message:\n");
        while((ch=getc(fp))!=EOF) //Reading file until end of file
        {
            printf("%c", ch); //Printing the romantic message
        }

        fclose(fp); //Closing the file
    }

    return 0;
}