//FormAI DATASET v1.0 Category: Ebook reader ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char eBook[50]; //creating an array of 50 characters to input the eBook name
    int chapters;   //creating integer variable for number of chapters
    float version;  //creating float variable for eBook version

    printf("Enter eBook name: ");
    scanf("%s", eBook);

    printf("Enter number of chapters: ");
    scanf("%d", &chapters);

    printf("Enter eBook version: ");
    scanf("%f", &version);

    printf("\n\n\t\tEBOOK READER\n\n");
    printf("\t\t=================\n\n");
    printf("\t\tEBook Name: %s\n", eBook);
    printf("\t\tNumber of Chapters: %d\n", chapters);
    printf("\t\tVersion: %.1f\n", version);
    printf("\n\t\tWould you like to start reading? (y/n)\n");

    char response[1]; //creating a 1 character array for response from user
    scanf("%s", response);

    if(strcmp(response, "y") == 0)
    {
        printf("\n\t\tChapter List\n");
        printf("\t\t============\n\n");

        int i;
        for(i = 1; i <= chapters; i++)
        {
            printf("\t\tChapter %d\n", i);
        }

        printf("\n\t\tPlease enter the chapter number you wish to read: ");
        int chapterNumber;
        scanf("%d", &chapterNumber);

        if(chapterNumber > chapters || chapterNumber < 1)
        {
            printf("\n\t\tInvalid chapter number! Please select a valid chapter.\n");
        }
        else
        {
            printf("\n\t\tChapter %d\n", chapterNumber);
            printf("\t\t===========\n\n");

            //assuming the content of each chapter is stored in a text file with this naming convention
            char fileName[50];
            sprintf(fileName, "%s_chapter%d.txt", eBook, chapterNumber);

            FILE *filePointer;
            filePointer = fopen(fileName, "r"); //opening file in read mode

            if(filePointer == NULL)
            {
                printf("\n\t\tChapter not found! Please select a valid chapter.\n");
            }
            else
            {
                char line[200];
                while(fgets(line, 200, filePointer) != NULL)
                {
                    printf("%s", line);
                }

                fclose(filePointer); //closing the file
            }
        }
    }
    else
    {
        printf("\n\t\tThank you for using our eBook reader!\n");
    }

    return 0;
}