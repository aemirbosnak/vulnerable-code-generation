//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 118
#define MAX_NAME_LENGTH 20

typedef struct Element
{
    char symbol[3];
    char name[MAX_NAME_LENGTH];
    int atomicNumber;
    float atomicWeight;
} Element;

void printWelcomeMessage();
void loadElements(Element *elements);
int checkAnswer(int correctAnswer, int userAnswer);
void printQuestion(Element *elements);
int playGame(Element *elements);

int main()
{
    Element elements[MAX_ELEMENTS];
    loadElements(elements);
    printWelcomeMessage();
    int score = playGame(elements);
    printf("Your final score is %d/10. Thanks for playing!\n", score);
    return 0;
}

void printWelcomeMessage()
{
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be shown 10 elements and you need to guess their symbol.\n");
    printf("Let's get started!\n");
}

void loadElements(Element *elements)
{
    FILE *file = fopen("periodic_table.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        exit(1);
    }
    int count = 0;
    while (!feof(file) && count < MAX_ELEMENTS)
    {
        char line[MAX_NAME_LENGTH * 3];
        fgets(line, MAX_NAME_LENGTH * 3, file);
        sscanf(line, "%d %s %s %f", &elements[count].atomicNumber, elements[count].symbol, elements[count].name, &elements[count].atomicWeight);
        count++;
    }
    fclose(file);
}

int checkAnswer(int correctAnswer, int userAnswer)
{
    if (correctAnswer == userAnswer)
    {
        printf("Correct!\n");
        return 1;
    }
    else
    {
        printf("Incorrect. The correct answer is %d.\n", correctAnswer);
        return 0;
    }
}

void printQuestion(Element *elements)
{
    int randomIndex = rand() % MAX_ELEMENTS;
    printf("What is the symbol of %s (atomic number %d)?\n", elements[randomIndex].name, elements[randomIndex].atomicNumber);
    printf("Options:\n");
    for (int i = 0; i < 4; i++)
    {
        int randomAtomicNumber = rand() % MAX_ELEMENTS + 1;
        printf("%d. %s\n", i + 1, elements[randomAtomicNumber].symbol);
    }
}

int playGame(Element *elements)
{
    int score = 0;
    for (int i = 0; i < 10; i++)
    {
        printQuestion(elements);
        int userAnswer;
        while (1)
        {
            printf("Enter your answer (1-4): ");
            scanf("%d", &userAnswer);
            if (userAnswer >= 1 && userAnswer <= 4)
            {
                break;
            }
            else
            {
                printf("Invalid input. Please enter a number between 1 and 4.\n");
            }
        }
        if (checkAnswer(elements[rand() % MAX_ELEMENTS].atomicNumber, userAnswer))
        {
            score++;
        }
    }
    return score;
}