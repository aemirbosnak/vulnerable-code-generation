//Gemma-7B DATASET v1.0 Category: Dice Roller ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int roll_number = 0;
    int result = 0;
    char case_name[20];

    printf("Please provide the name of the case: ");
    scanf("%s", case_name);

    printf("Welcome to the Case of: %s\n", case_name);

    // Loop to simulate rolling the dice
    while (roll_number < 3)
    {
        roll_number++;
        result = rand() % 6 + 1;
        printf("Roll number %d: %d\n", roll_number, result);
    }

    // Analyze the results and draw conclusions
    if (result == 1)
    {
        printf("It appears that the suspect is hiding in the kitchen.\n");
    }
    else if (result == 2)
    {
        printf("The suspect is probably in the living room.\n");
    }
    else if (result == 3)
    {
        printf("The suspect is in the study.\n");
    }
    else if (result == 4)
    {
        printf("The suspect is in the bedroom.\n");
    }
    else if (result == 5)
    {
        printf("The suspect is in the hallway.\n");
    }
    else if (result == 6)
    {
        printf("The suspect is in the garden.\n");
    }

    printf("Thank you for participating in the Case of: %s\n", case_name);

    return 0;
}