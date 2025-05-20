//FormAI DATASET v1.0 Category: Text processing ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 100
#define MAX_WORD_SIZE 50
#define MAX_LINE_SIZE 100

int main()
{
    char oldWord[MAX_WORD_SIZE], newWord[MAX_WORD_SIZE];
    char fileName[MAX_FILE_NAME], line[MAX_LINE_SIZE];
    FILE *fpR, *fpW;

    printf("Enter the file name: ");
    scanf("%s", fileName);

    printf("Enter the word to replace: ");
    scanf("%s", oldWord);

    printf("Enter the new word: ");
    scanf("%s", newWord);

    fpR = fopen(fileName, "r");
    fpW = fopen("temp.txt", "w");

    if(fpR == NULL || fpW == NULL)
    {
        printf("Unable to open file!");
        exit(1);
    }

    while(fgets(line, MAX_LINE_SIZE, fpR))
    {
        char *position = strstr(line, oldWord);

        while(position)
        {
            int index = position - line;
            memmove(&line[index + strlen(newWord)], &line[index + strlen(oldWord)], strlen(&line[index + strlen(oldWord)]) + 1);
            memcpy(&line[index], newWord, strlen(newWord));
            position = strstr(line + index + strlen(newWord), oldWord);
        }

        fputs(line, fpW);
    }

    fclose(fpR);
    fclose(fpW);

    remove(fileName);
    rename("temp.txt", fileName);

    printf("\n%s replaced with %s in %s\n", oldWord, newWord, fileName);

    return 0;
}