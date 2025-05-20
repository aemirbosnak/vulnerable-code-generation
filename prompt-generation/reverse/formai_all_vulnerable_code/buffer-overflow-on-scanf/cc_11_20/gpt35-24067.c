//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    printf("Welcome to the Medieval Resume Parsing System\n\n");
    printf("Please enter the details of the candidate:\n");

    char name[50];
    printf("\nKnight's name: ");
    scanf("%s", name);

    char surname[50];
    printf("Knight's surname: ");
    scanf("%s", surname);

    char skills[200];
    printf("\nList your skills: ");
    scanf("%s", skills);

    char experience[200];
    printf("\nDescribe your previous experience: ");
    scanf("%s", experience);

    char education[200];
    printf("\nList your education: ");
    scanf("%s", education);

    printf("\nDetails entered successfully.\n");
    printf("\nParsing your resume...\n\n");

    //Parsing the resume to extract keywords

    char keywords[5][20] = {"sword fighting", "horsemanship", "archery", "medieval history", "battle strategy"};

    int count = 0;

    char *token = strtok(skills, ", ");
    while (token != NULL)
    {
        for (int i = 0; i < 5; i++)
        {
            if (strcmp(token, keywords[i]) == 0)
            {
                count++;
                break;
            }
        }
        token = strtok(NULL, ", ");
    }

    token = strtok(experience, ", ");
    while (token != NULL)
    {
        for (int i = 0; i < 5; i++)
        {
            if (strcmp(token, keywords[i]) == 0)
            {
                count++;
                break;
            }
        }
        token = strtok(NULL, ", ");
    }

    token = strtok(education, ", ");
    while (token != NULL)
    {
        for (int i = 0; i < 5; i++)
        {
            if (strcmp(token, keywords[i]) == 0)
            {
                count++;
                break;
            }
        }
        token = strtok(NULL, ", ");
    }

    //Printing the result based on the number of keywords matched

    printf("\nResume of Sir %s %s\n", name, surname);

    if (count <= 1)
    {
        printf("You are not qualified for the position of a knight.\n");
    }
    else if (count == 2)
    {
        printf("You are suitable for a position of a squire.\n");
    }
    else if (count == 3)
    {
        printf("You are suitable for a position of a junior knight.\n");
    }
    else if (count == 4)
    {
        printf("You are suitable for a position of a senior knight.\n");
    }
    else
    {
        printf("You are perfectly suited for the position of a knight commander.\n");
    }

    return 0;
}