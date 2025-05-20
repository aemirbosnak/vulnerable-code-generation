//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 10
#define MAX_ELEMENTS 118
#define MAX_NAME_LENGTH 20

typedef struct
{
    int atomic_number;
    char symbol[3];
    char name[MAX_NAME_LENGTH];
    char category[20];
} Element;

void load_elements(Element elements[]);
void shuffle(int array[], int size);
void print_question(Element element, int options[], int correct_answer);

int main()
{
    Element elements[MAX_ELEMENTS];
    load_elements(elements);

    srand(time(NULL));

    printf("Welcome to the Periodic Table Quiz!\n\n");

    int score = 0;

    for (int i = 0; i < MAX_QUESTIONS; i++)
    {
        int options[4] = {i, -1, -1, -1};
        shuffle(options, 4);

        print_question(elements[i], options, options[0]);

        int answer;
        printf("Enter your answer (1-4): ");
        scanf("%d", &answer);

        if (answer == 1 && options[0] == i + 1 ||
            answer == 2 && options[1] == i + 1 ||
            answer == 3 && options[2] == i + 1 ||
            answer == 4 && options[3] == i + 1)
        {
            printf("Correct!\n");
            score++;
        }
        else
        {
            printf("Incorrect! The correct answer was %d. %s\n", i + 1, elements[i].name);
        }

        printf("\n");
    }

    printf("Quiz complete! Your score is %d/%d\n", score, MAX_QUESTIONS);

    return 0;
}

void load_elements(Element elements[])
{
    FILE* file = fopen("elements.txt", "r");

    if (file)
    {
        int count = 0;
        char line[100];

        while (fgets(line, 100, file))
        {
            sscanf(line, "%d,%[^,],%[^,],%[^\n]", &elements[count].atomic_number, 
                elements[count].symbol, elements[count].name, elements[count].category);

            count++;
        }

        fclose(file);
    }
}

void shuffle(int array[], int size)
{
    for (int i = size - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

void print_question(Element element, int options[], int correct_answer)
{
    printf("Question %d: What is the symbol for %s?\n", correct_answer, element.name);
    printf("1. %s\n", element.symbol);
    printf("2. %s\n", element.symbol);
    printf("3. %s\n", element.symbol);
    printf("4. %s\n", element.symbol);
}