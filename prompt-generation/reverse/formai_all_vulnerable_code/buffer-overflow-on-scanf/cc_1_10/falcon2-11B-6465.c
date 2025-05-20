//Falcon2-11B DATASET v1.0 Category: Periodic Table Quiz ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    // initialize variables
    int correct = 0;
    int tries = 0;
    char answer[3];

    // generate a random element from the periodic table
    char element[3];
    int random_number = rand() % 118;
    int index = 0;
    while (index < 118)
    {
        if (random_number == index)
        {
            strcpy(element, "He");
            break;
        }
        index++;
    }

    // prompt the user to enter the answer
    printf("What is the element %s?\n", element);
    scanf("%s", answer);

    // check if the answer is correct
    if (strcmp(answer, element) == 0)
    {
        printf("Correct!\n");
        correct++;
    }
    else
    {
        printf("Incorrect.\n");
        tries++;
    }

    // prompt the user to continue or quit
    printf("Do you want to try another element? (y/n): ");
    char response;
    scanf(" %c", &response);

    // continue or quit the quiz
    if (response == 'y')
    {
        return main(argc, argv);
    }
    else
    {
        printf("You scored %d/%d correct.\n", correct, tries);
        return 0;
    }
}