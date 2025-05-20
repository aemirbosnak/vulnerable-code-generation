//FormAI DATASET v1.0 Category: Data mining ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Battle
{
    char name[50];
    int year;
    char location[50];
    int casualties;
};

int main()
{
    struct Battle battles[10]; //Array to store battle data
    int i = 0, j = 0, total_casualties = 0, min_year = 9999, max_year = 0;
    char search_location[50];

    //Inputting data of 10 historical battles
    for(i=0; i<10; i++)
    {
        printf("Enter Battle Name: \n");
        scanf("%s", battles[i].name);
        printf("Enter Year of Battle (between 500-1500 AD): \n");
        scanf("%d", &battles[i].year);
        printf("Enter Battle Location: \n");
        scanf("%s", battles[i].location);
        printf("Enter Casualties: \n");
        scanf("%d", &battles[i].casualties);

        total_casualties += battles[i].casualties;

        if(battles[i].year < min_year)
        {
            min_year = battles[i].year;
        }

        if(battles[i].year > max_year)
        {
            max_year = battles[i].year;
        }
    }

    printf("\nData Mining Results:");
    printf("\nTotal Casualties in 10 Battles: %d", total_casualties);
    printf("\nEarliest Battle Year: %d", min_year);
    printf("\nLatest Battle Year: %d", max_year);

    //Inputting location to search for battles and calculating casualties in that location
    printf("\nEnter Battle Location to search for Casualties: \n");
    scanf("%s", search_location);
    for(i=0; i<10; i++)
    {
        if(strcmp(search_location, battles[i].location) == 0)
        {
            j++;
            printf("Battle Name: %s\n", battles[i].name);
            printf("Casualties: %d\n", battles[i].casualties);
        }
    }

    if(j==0)
    {
        printf("No Battles took place in '%s' location.\n", search_location);
    }

    return 0;
}