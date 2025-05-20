//FormAI DATASET v1.0 Category: Data mining ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_COUNT 100
#define MAX_FIELD_COUNT 10

int main()
{
    FILE *fp;
    char line[MAX_FIELD_COUNT][50];
    char lines[MAX_LINE_COUNT][MAX_FIELD_COUNT][50];
    int i=0, j=0, l=0;

    fp=fopen("data.csv","r");

    if(fp==NULL)
    {
        printf("Cannot open file\n");
        exit(1);
    }

    while(fgets(line[j], 50, fp) != NULL)
    {
        line[j][strlen(line[j]) - 1] = '\0'; // remove newline character
        j++;
    }

    fclose(fp);

    for(i = 0; i < j; i++)
    {
        char *token = strtok(line[i], ",");
        l = 0;

        while(token != NULL)
        {
            strcpy(lines[i][l], token);
            token = strtok(NULL, ",");
            l++;
        }
    }

    for(i = 1; i < j; i++)
    {
        int age = atoi(lines[i][1]); // convert string to integer
        int score = atoi(lines[i][2]);
        printf("Name: %s\n", lines[i][0]);
        printf("Age: %d\n", age);
        printf("Score: %d\n", score);

        if(score > 80)
        {
            printf("Student %s has a high score!\n", lines[i][0]);
        }
    }

    return 0;
}