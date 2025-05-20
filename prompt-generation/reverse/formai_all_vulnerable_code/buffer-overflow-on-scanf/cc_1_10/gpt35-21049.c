//FormAI DATASET v1.0 Category: Online Examination System ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// function prototypes
void initialize();      // to initialize the questions
void startExam();       // to start the exam
void displayMenu();     // to display the menu
void displayRules();    // to display the rules
void displayResult();   // to display the result
int checkAnswer(int, char); // to check the answer

// global variables
char questions[5][100] = {"What is the capital of India?", 
                          "Who invented telephone?", 
                          "What is the name of smallest continent?", 
                          "Who is the father of computer?", 
                          "What is the smallest planet in solar system?"};
char options[5][4][50] = {{"A. New Delhi", "B. Mumbai", "C. Kolkata", "D. Chennai"},
                          {"A. Thomas Alva Edison", "B. Graham Bell", "C. Isaac Newton", "D. Albert Einstein"},
                          {"A. Asia", "B. Antarctica", "C. Europe", "D. Australia"},
                          {"A. Charles Babbage", "B. John Atanasoff", "C. Blaise Pascal", "D. Steve Jobs"},
                          {"A. Venus", "B. Pluto", "C. Mercury", "D. Mars"}};
char answers[5] = {'A', 'B', 'D', 'A', 'C'};
char studentAnswers[5];

int main()
{
    initialize();
    displayMenu();
    return 0;
}

// function to initialize the questions
void initialize()
{
    printf("Initializing the questions...");
    // some code to fetch questions from database or a file
    printf("Questions initialized successfully!\n\n");
}

// function to display the menu
void displayMenu()
{
    printf("Welcome to the Online Examination System!\n");
    printf("1. Start Exam\n");
    printf("2. Rules\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            startExam();
            break;
        case 2:
            displayRules();
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("Invalid choice!");
            displayMenu();
    }
}

// function to display the rules
void displayRules()
{
    printf("Rules:\n");
    printf("1. The exam consists of 5 multiple choice questions.\n");
    printf("2. Each question carries 1 mark.\n");
    printf("3. There is no negative marking.\n");
    printf("4. Once you start the exam, you cannot stop it until you complete all the questions.\n\n");
    displayMenu();
}

// function to start the exam
void startExam()
{
    printf("Starting the exam...\n");
    for(int i=0; i<5; i++)
    {
        printf("\nQuestion %d: %s\n", i+1, questions[i]);
        for(int j=0; j<4; j++)
        {
            printf("%s\n", options[i][j]);
        }
        printf("Enter your answer: ");
        char ans;
        scanf(" %c", &ans);
        studentAnswers[i] = ans;
        if(checkAnswer(i, ans))
        {
            printf("Correct answer!\n");
        }
        else
        {
            printf("Wrong answer!\n");
        }
    }
    printf("\nExam completed!\n");
    displayResult();
}

// function to check the answer
int checkAnswer(int qno, char ans)
{
    if(ans == answers[qno])
    {
        return 1;
    }
    return 0;
}

// function to display the result
void displayResult()
{
    int score = 0;
    for(int i=0; i<5; i++)
    {
        if(studentAnswers[i] == answers[i])
        {
            score++;
        }
    }
    printf("\nYour score: %d/5\n", score);
    displayMenu();
}