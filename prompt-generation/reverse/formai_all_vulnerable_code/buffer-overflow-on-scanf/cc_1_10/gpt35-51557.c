//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int year;
    int population;
    char continent[20];
    float invasion_prob;

    srand(time(0));

    printf("Welcome to the Alien Invasion Probability Calculator!\n");

    printf("Please enter the current year (yyyy): ");
    scanf("%d", &year);

    printf("Please enter the population of the area to be invaded: ");
    scanf("%d", &population);

    printf("Please enter the continent where the area is located: ");
    scanf("%s", continent);

    printf("\nCalculating...\n");

    float pop_factor = (float) population / 1000000000;
    float cont_factor;

    if(strcmp(continent, "Asia") == 0)
        cont_factor = 1.5;
    else if(strcmp(continent, "Europe") == 0)
        cont_factor = 1.2;
    else if(strcmp(continent, "Africa") == 0)
        cont_factor = 1.3;
    else if(strcmp(continent, "North America") == 0)
        cont_factor = 1.1;
    else if(strcmp(continent, "South America") == 0)
        cont_factor = 1.2;
    else if(strcmp(continent, "Australia") == 0)
        cont_factor = 1.4;

    float year_factor = (float) (rand() % 20) / 10;

    invasion_prob = pop_factor * cont_factor * year_factor;

    printf("\nBased on the data entered, the probability of an alien invasion in %d is %.2f %%\n", year, invasion_prob);

    return 0;
}