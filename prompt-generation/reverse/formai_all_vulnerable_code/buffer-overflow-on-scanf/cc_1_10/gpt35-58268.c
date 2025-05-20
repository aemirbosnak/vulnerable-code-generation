//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 118
#define MAX_SYMBOL_LENGTH 3

typedef struct 
{
    char symbol[MAX_SYMBOL_LENGTH];
    char name[20];
    int number;
    float weight;
} Element;

int main()
{
    Element elements[MAX_ELEMENTS];

    strcpy(elements[0].symbol, "H");
    strcpy(elements[0].name, "Hydrogen");
    elements[0].number = 1;
    elements[0].weight = 1.008;

    strcpy(elements[1].symbol, "He");
    strcpy(elements[1].name, "Helium");
    elements[1].number = 2;
    elements[1].weight = 4.003;

    strcpy(elements[2].symbol, "Li");
    strcpy(elements[2].name, "Lithium");
    elements[2].number = 3;
    elements[2].weight = 6.941;

    // Fill in remaining elements

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Enter the correct symbol for each element.\n");
    printf("Enter 'exit' to quit.\n");

    char answer[MAX_SYMBOL_LENGTH];
    int score = 0;

    while (1)
    {
        int random_index = rand() % MAX_ELEMENTS;
        Element current_element = elements[random_index];

        printf("%s (Element %d, Weight %.3f): ", current_element.name, current_element.number, current_element.weight);
        scanf("%s", answer);

        if (strcmp(answer, "exit") == 0)
        {
            break;
        }

        if (strcmp(answer, current_element.symbol) == 0)
        {
            printf("Correct!\n");
            score++;
        }
        else
        {
            printf("Incorrect. The correct symbol is %s.\n", current_element.symbol);
        }
    }

    printf("You got %d out of %d.\n", score, MAX_ELEMENTS);

    return 0;
}