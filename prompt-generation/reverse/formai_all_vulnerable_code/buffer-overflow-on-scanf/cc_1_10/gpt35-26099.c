//FormAI DATASET v1.0 Category: Digital Diary ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int ch;
    char diary[500];
    FILE *fp;

    fp = fopen("my_diary.txt", "a+");

    if(fp == NULL)
    {
        printf("Error opening file");
        exit(1);
    }

    printf("----------------------------------------------\n");
    printf("Welcome to my digital diary\n");
    printf("----------------------------------------------\n");

    printf("Enter 1 to read diary\n");
    printf("Enter 2 to write diary\n");
    printf("Enter 3 to exit\n");

    do
    {
        printf("Enter your choice: \n");
        scanf("%d", &ch);
        getchar(); // to consume newline character

        switch(ch)
        {
            case 1:
                printf("Your Diary:\n");
                printf("----------------------------------------------\n");

                fseek(fp, 0, SEEK_SET);

                while(fgets(diary, 500, fp) != NULL)
                {
                    printf("%s", diary);
                }

                printf("----------------------------------------------\n");

                break;

            case 2:
                printf("Enter your diary (500 characters max):\n");
                fgets(diary, 500, stdin);

                fwrite(diary, sizeof(char), strlen(diary), fp);
                printf("Added to diary.\n");

                break;

            case 3:
                printf("Thank you for using my digital diary.\n");
                break;

            default:
                printf("Invalid option. Please try again.\n");
        }

    } while(ch != 3);

    fclose(fp);

    return 0;
}