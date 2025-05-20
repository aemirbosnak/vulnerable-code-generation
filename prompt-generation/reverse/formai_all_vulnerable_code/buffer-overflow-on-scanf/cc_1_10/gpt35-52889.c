//FormAI DATASET v1.0 Category: Online Examination System ; Style: creative
#include <stdio.h>
#include <string.h>

#define MAX_QUESTIONS 10

// Function to display the exam instructions
void displayInstructions()
{
    printf("Welcome to the Online Examination System!\n\n");
    printf("Instructions:\n");
    printf("1. This exam consists of %d multiple choice questions.\n", MAX_QUESTIONS);
    printf("2. Each question has 4 options, out of which only 1 option is correct.\n");
    printf("3. For each correct answer, you will be awarded 1 mark.\n");
    printf("4. There is no negative marking for incorrect answers.\n");
    printf("5. To select an option, enter the corresponding option number (1/2/3/4).\n\n");
}

// Function to ask questions and evaluate answers
void takeExam()
{
    char questions[MAX_QUESTIONS][100] = {
        "What is the capital of India?",
        "Who is the founder of Microsoft?",
        "What is the currency of Japan?",
        "Who wrote the novel 'To Kill a Mockingbird'?",
        "What is the highest mountain peak in Africa?",
        "What is the largest country in the world by area?",
        "Who is the founder of Apple Inc.?",
        "What is the largest organ in the human body?",
        "Which element has the symbol 'Fe'?",
        "In which year did India gain independence from British rule?"
    };

    char options[MAX_QUESTIONS][4][50] = {
        {"(1) Mumbai", "(2) Bangalore", "(3) New Delhi", "(4) Kolkata"},
        {"(1) Bill Gates", "(2) Steve Jobs", "(3) Mark Zuckerberg", "(4) Satya Nadella"},
        {"(1) Euro", "(2) US dollar", "(3) Yen", "(4) Pound sterling"},
        {"(1) Harper Lee", "(2) J.K. Rowling", "(3) Stephen King", "(4) Dan Brown"},
        {"(1) Mount Kilimanjaro", "(2) Mount Everest", "(3) Mount Kenya", "(4) Mount Stanley"},
        {"(1) China", "(2) United States", "(3) Russia", "(4) Canada"},
        {"(1) Bill Gates", "(2) Steve Jobs", "(3) Mark Zuckerberg", "(4) Steve Wozniak"},
        {"(1) Liver", "(2) Brain", "(3) Skin", "(4) Heart"},
        {"(1) Gold", "(2) Iron", "(3) Calcium", "(4) Silver"},
        {"(1) 1945", "(2) 1946", "(3) 1947", "(4) 1948"}
    };

    int answers[MAX_QUESTIONS] = {3, 1, 3, 1, 1, 2, 4, 3, 2, 3};
    int score = 0;
    int selection, i;

    printf("Let's begin with the exam:\n\n");

    for (i=0; i<MAX_QUESTIONS; i++)
    {
        printf("Question %d: %s\n", i+1, questions[i]);
        printf("%s\n%s\n%s\n%s\n", options[i][0], options[i][1], options[i][2], options[i][3]);

        printf("Select your answer: ");
        scanf("%d", &selection);

        if (selection == answers[i])
        {
            printf("Correct answer!\n");
            score++;
        }
        else
        {
            printf("Wrong answer!\n");
        }

        printf("\n");
    }

    printf("Your final score is %d out of %d.\n", score, MAX_QUESTIONS);
}

int main()
{
    displayInstructions();
    takeExam();

    return 0;
}