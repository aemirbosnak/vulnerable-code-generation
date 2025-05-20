//FormAI DATASET v1.0 Category: Data recovery tool ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Welcome to our unique C data recovery tool!\n");
    printf("Please enter the filename you want to recover:\n");

    char filename[100];
    scanf("%s", filename);

    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Sorry, we can't open the file %s\n", filename);
        return 1;
    }

    fseek(fp, 0L, SEEK_END);
    int file_size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    char *buffer = (char*) malloc(file_size * sizeof(char));
    fread(buffer, sizeof(char), file_size, fp);

    printf("Please enter the keyword you want us to search for in the file:\n");

    char keyword[100];
    scanf("%s", keyword);

    char* p = strstr(buffer, keyword);
    if (p != NULL)
    {
        printf("We have found the keyword %s in the file %s\n", keyword, filename);
        printf("Do you want us to recover the data?\n");
        printf("Enter Y for Yes and N for No:\n");

        char answer;
        scanf(" %c", &answer);

        if (answer == 'Y')
        {
            printf("-----------------------\n");
            printf("Recovered data:\n");
            printf("-----------------------\n");
            printf("%s\n", p);
            printf("-----------------------\n");
            printf("Thank you for using our service!\n");
        }
        else if (answer == 'N')
        {
            printf("We are sorry we couldn't help you this time.\n");
            printf("Goodbye!\n");
        }
        else
        {
            printf("Invalid input, please try again and enter either Y or N.\n");
        }
    }
    else
    {
        printf("We are sorry, we couldn't find the keyword %s in the file %s\n", keyword, filename);
        printf("Goodbye!\n");
    }

    free(buffer);
    fclose(fp);

    return 0;
}