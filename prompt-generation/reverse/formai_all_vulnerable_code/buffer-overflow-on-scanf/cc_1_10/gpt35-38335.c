//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_ELEMENTS 118

typedef struct
{
    int atomic_number;
    char symbol[3];
    char name[20];
} element;

//define the structure for a question
typedef struct
{
    element e;
    int correct_answer;
    int user_answer;
} question;

//function prototypes
void load_elements(element *elements);
void clear_screen();
void show_menu();
void start_quiz(element *elements);
void display_question(question ques);
void generate_question(question *ques, element *elements);
void check_answer(question *ques);

int main()
{
    element elements[MAX_ELEMENTS];

    load_elements(elements);

    while(1)
    {
        clear_screen();

        show_menu();

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                start_quiz(elements);
                break;
            case 2:
                printf("\nThanks for playing! Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }

        printf("\nPress enter to continue...");
        getchar();
        getchar();
    }

    return 0;
}

//load the elements from the file
void load_elements(element *elements)
{
    FILE *fp;

    fp = fopen("elements.txt", "r");

    int i = 0;
    while(!feof(fp) && i < MAX_ELEMENTS)
    {
        fscanf(fp, "%d %s %[^\n]%*c", &elements[i].atomic_number, elements[i].symbol, elements[i].name);

        i++;
    }

    fclose(fp);
}

//clear the console screen
void clear_screen()
{
    system("clear||cls");
}

//show the main menu
void show_menu()
{
    printf("Welcome to the Periodic Table Quiz!\n\n");
    printf("1. Start Quiz\n");
    printf("2. Exit\n");
}

//start the quiz
void start_quiz(element *elements)
{
    clear_screen();

    printf("Quiz Starting...\n");

    srand(time(NULL));

    int correct_answers = 0;
    int incorrect_answers = 0;

    for(int i = 0; i < 10; i++)
    {
        question ques;
        generate_question(&ques, elements);
        display_question(ques);
        check_answer(&ques);

        if(ques.correct_answer == ques.user_answer)
        {
            printf("\nCorrect Answer! Well done!\n");
            correct_answers++;
        }
        else
        {
            printf("\nIncorrect Answer! Better luck next time.\n");
            incorrect_answers++;
        }
    }

    printf("\nQuiz Complete! You answered %d questions correctly and %d questions incorrectly.\n", correct_answers, incorrect_answers);
}

//display the question
void display_question(question ques)
{
    printf("\nWhat is the atomic number of %s?\n\n", ques.e.name);
}

//generate a random question
void generate_question(question *ques, element *elements)
{
    int index = rand() % MAX_ELEMENTS;
    ques->e = elements[index];
    ques->correct_answer = ques->e.atomic_number;
}

//check the user's answer
void check_answer(question *ques)
{
    printf("Enter your answer: ");
    scanf("%d", &ques->user_answer);
}