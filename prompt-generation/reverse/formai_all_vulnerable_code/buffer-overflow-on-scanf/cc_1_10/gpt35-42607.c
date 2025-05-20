//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

void displayMenu();
void displayTable();
void startQuiz();
void displayScore();

int score = 0;

int main()
{
    char choice;
    printf("Hello, welcome to the C Periodic Table Quiz!\n");
    displayMenu();

    do
    {
        printf("\nPlease enter your choice: ");
        scanf(" %c", &choice);

        switch(choice)
        {
            case '1':
                displayTable();
                break;
            case '2':
                startQuiz();
                break;
            case '3':
                displayScore();
                break;
            case '4':
                printf("\nThank you for playing the quiz!\n");
                break;
            default:
                printf("\nInvalid choice, please try again.\n");
                break;
        }

    }while(choice != '4');

    return 0;
}

void displayMenu()
{
    printf("\n----------- MENU -----------\n");
    printf("1. Display Periodic Table \n");
    printf("2. Start Quiz \n");
    printf("3. Display Score \n");
    printf("4. Exit Quiz \n");
    printf("-----------------------------\n");
}

void displayTable()
{
    printf("\n-------------------------------------------------------------\n");
    printf("| Element | Symbol | Atomic Number | Atomic Mass | Group | Period |\n");
    printf("---------------------------------------------------------------\n");
    printf("| Hydrogen |   H    |       1       |    1.008    |   1   |   1    |\n");
    printf("| Helium   |   He   |       2       |    4.003    |  18   |   1    |\n");
    printf("| Lithium  |   Li   |       3       |    6.941    |   1   |   2    |\n");
    printf("| Beryllium|   Be   |       4       |    9.012    |   2   |   2    |\n");
    printf("| Boron    |   B    |       5       |    10.81    |  13   |   2    |\n");
    printf("| Carbon   |   C    |       6       |    12.01    |  14   |   2    |\n");
    printf("| Nitrogen |   N    |       7       |    14.01    |  15   |   2    |\n");
    printf("| Oxygen   |   O    |       8       |    16.00    |  16   |   2    |\n");
    printf("| Fluorine |   F    |       9       |    19.00    |  17   |   2    |\n");
    printf("| Neon     |   Ne   |       10      |    20.18    |  18   |   2    |\n");
    printf("-----------------------------------------------------------------\n");
}

void startQuiz()
{
    printf("\n--------------------- QUIZ! ---------------------\n");
    printf("Instructions: Type in the symbol of the element\n");
    printf("Press 'q' to quit the quiz.\n");
    printf("--------------------------------------------------\n");

    char answer[10];
    char response;

    // Question 1
    printf("\n1. What is the symbol for Hydrogen?\n");
    scanf("%s", answer);

    if(strcmp(answer, "H") == 0)
    {
        printf("Correct answer!\n");
        score++;
    }
    else
    {
        printf("Incorrect answer!\n");
    }

    // Question 2
    printf("\n2. What is the symbol for Iron?\n");
    scanf("%s", answer);

    if(strcmp(answer, "Fe") == 0)
    {
        printf("Correct answer!\n");
        score++;
    }
    else
    {
        printf("Incorrect answer!\n");
    }

    // Question 3
    printf("\n3. What is the symbol for Sodium?\n");
    scanf("%s", answer);

    if(strcmp(answer, "Na") == 0)
    {
        printf("Correct answer!\n");
        score++;
    }
    else
    {
        printf("Incorrect answer!\n");
    }

    printf("\nQuiz has ended. Your score is %d out of 3.\n", score);
}

void displayScore()
{
    printf("\nYour current score is %d.\n", score);
}