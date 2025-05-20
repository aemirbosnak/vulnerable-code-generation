//FormAI DATASET v1.0 Category: File handling ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;

    char name[20], mood[20];
    int num, i;
    float rating;

    fp = fopen("love_letter.txt", "w");

    if(fp == NULL)
    {
        printf("Unable to create file.");
        exit(1);
    }

    printf("Write a letter to your love:\n");
    printf("Name: ");
    scanf("%[^\n]", name);

    printf("Mood (happy/sad/romantic): ");
    scanf("%s", mood);

    printf("Number of reasons why you love them: ");
    scanf("%d", &num);

    printf("How much do you rate your love out of 10: ");
    scanf("%f", &rating);

    fprintf(fp, "Dear %s,\n\n", name);
    fprintf(fp, "I am writing this letter to express my %s feelings for you.\n\n", mood);

    char buffer[100];
    for(i = 1; i <= num; i++)
    {
        printf("Reason %d: ", i);
        scanf("%[^\n]", buffer);
        fprintf(fp, "%d. %s\n", i, buffer);
        getchar();
    }

    fprintf(fp, "\nOverall, I rate my love for you as %.1f/10.\n", rating);
    fprintf(fp, "You are the most special person in my life, and I promise to always cherish and love you.\n");

    printf("\n");
    printf("Your love letter has been written and saved to the file love_letter.txt.\n");
    fclose(fp);

    return 0;
}