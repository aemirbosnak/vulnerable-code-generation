//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int prob;
    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");
    printf("Please answer the following questions to determine your planet's chance of experiencing an alien invasion.\n\n");
    printf("1. In the past year, have there been any unexplained sightings or encounters that could potentially be extraterrestrial in nature?\n");
    printf("Press 1 for Yes and 0 for No: ");
    int answer1;
    scanf("%d", &answer1);
    if (answer1 == 1)
    {
        prob += 30;
    }
    else
    {
        prob -= 5;
    }
    printf("\n");

    printf("2. Does your planet have any known valuable resources that could attract alien species?\n");
    printf("Press 1 for Yes and 0 for No: ");
    int answer2;
    scanf("%d", &answer2);
    if (answer2 == 1)
    {
        prob += 20;
    }
    else
    {
        prob -= 10;
    }
    printf("\n");

    printf("3. Has your planet sent any signals or messages into outer space that could have been intercepted by alien species?\n");
    printf("Press 1 for Yes and 0 for No: ");
    int answer3;
    scanf("%d", &answer3);
    if (answer3 == 1)
    {
        prob += 15;
    }
    else
    {
        prob -= 5;
    }
    printf("\n");

    printf("4. Has your planet recently made any significant technological advances that could potentially draw alien attention?\n");
    printf("Press 1 for Yes and 0 for No: ");
    int answer4;
    scanf("%d", &answer4);
    if (answer4 == 1)
    {
        prob += 25;
    }
    else
    {
        prob -= 10;
    }
    printf("\n");

    printf("5. Has your planet had any conflicts or acts of aggression towards other planets or species?\n");
    printf("Press 1 for Yes and 0 for No: ");
    int answer5;
    scanf("%d", &answer5);
    if (answer5 == 1)
    {
        prob += 5;
    }
    else
    {
        prob -= 10;
    }
    printf("\n");

    printf("Calculating probability...\n");
    printf("The chance of an alien invasion for your planet is %d%%\n", prob);

    if (prob >= 50)
    {
        printf("Based on our calculations, your planet is at a moderate to high risk of experiencing an alien invasion. It is recommended that you take precautions and establish a defense plan.\n");
    }
    else
    {
        printf("Based on our calculations, your planet is at a low risk of experiencing an alien invasion. However, it never hurts to be prepared. Stay vigilant and keep an eye on the skies!\n");
    }

    return 0;
}