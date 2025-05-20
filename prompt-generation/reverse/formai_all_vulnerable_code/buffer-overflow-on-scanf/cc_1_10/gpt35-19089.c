//FormAI DATASET v1.0 Category: Digital Diary ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

FILE* diary;
char file_name[20];
char input[100];

int main()
{
    printf("Welcome to your Digital Diary!\n\n");
    printf("Please enter a name for your diary: ");
    scanf("%s", file_name);
    strcat(file_name, ".txt");
    diary = fopen(file_name, "a+");

    if(diary == NULL)
    {
        printf("Failed to create diary. Please try again.\n");
        exit(1);
    }

    else
    {
        printf("\nDiary created successfully! You can start writing.\n");
    }

    time_t now;
    time(&now);

    fprintf(diary, "\n%s\n", ctime(&now));

    while(1)
    {
        printf("\nEnter your thoughts:\n");
        fgets(input, 100, stdin);
        fprintf(diary, "entry: %s", input);

        if(strcmp(input, "exit\n") == 0)
        {
            break;
        }

        memset(input, 0, sizeof(input));
    }

    fclose(diary);

    printf("\nGoodbye! Your diary has been saved.\n");

    return 0;
}