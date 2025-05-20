//FormAI DATASET v1.0 Category: File handling ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fp;
    char filename[30],ch;
    int choice,total_chars=0,total_words=0,total_lines=0;

    printf("Enter the filename to read: ");
    scanf("%s",filename);

    fp=fopen(filename,"r"); //Opening the file in read mode.

    if(fp==NULL)
    {
        printf("File not found or could not be opened.");
        exit(1);
    }

    printf("Select the option:\n1. Count Total Characters\n2. Count Total Words\n3. Count Total Lines\n4. Count All (Characters, Words, and Lines)\n5. Exit\n\nChoice: ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1: //Counting Total Characters.
                while((ch=fgetc(fp))!=EOF)
                {
                    total_chars++;
                }
                printf("\nTotal Characters: %d",total_chars);
                break;

        case 2: //Counting Total Words.
                while((ch=fgetc(fp))!=EOF)
                {
                    if(ch==' '|| ch=='\n' || ch=='\t')
                    {
                        total_words++;
                    }
                }
                printf("\nTotal Words: %d",total_words+1);
                break;

        case 3: //Counting Total Lines.
                while((ch=fgetc(fp))!=EOF)
                {
                    if(ch=='\n')
                    {
                        total_lines++;
                    }
                }
                printf("\nTotal Lines: %d",total_lines+1);
                break;

        case 4: //Counting All (Characters, Words, and Lines).
                while((ch=fgetc(fp))!=EOF)
                {
                    total_chars++;
                    if(ch==' '|| ch=='\n' || ch=='\t')
                    {
                        total_words++;
                    }
                    if(ch=='\n')
                    {
                        total_lines++;
                    }
                }
                printf("\nTotal Characters: %d",total_chars);
                printf("\nTotal Words: %d",total_words+1);
                printf("\nTotal Lines: %d",total_lines+1);
                break;

        case 5: exit(0); //Exiting the program.

        default: printf("Invalid Choice."); //If the user enters the wrong choice.
    }

    fclose(fp); //Closing the file.

    return 0;
}