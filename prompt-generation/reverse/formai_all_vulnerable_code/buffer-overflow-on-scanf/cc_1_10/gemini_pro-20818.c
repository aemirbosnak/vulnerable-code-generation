//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Create a struct to store the questions and answers
typedef struct question {
    char question[256];
    char answers[4][64];
    int correctAnswer;
} Question;

// Create an array of questions
Question questions[] = {
    {
        "What is the capital of France?",
        {"Paris", "London", "Rome", "Madrid"},
        0
    },
    {
        "Who is the current President of the United States?",
        {"Joe Biden", "Donald Trump", "Barack Obama", "George W. Bush"},
        0
    },
    {
        "What is the chemical symbol for gold?",
        {"Au", "Ag", "Cu", "Fe"},
        0
    },
    {
        "What is the largest ocean in the world?",
        {"Pacific Ocean", "Atlantic Ocean", "Indian Ocean", "Arctic Ocean"},
        0
    },
    {
        "Who painted the Mona Lisa?",
        {"Leonardo da Vinci", "Vincent van Gogh", "Pablo Picasso", "Salvador Dalí"},
        0
    }
};

// Function to print the questions and answers
void printQuestions(Question questions[], int numQuestions) {
    for (int i = 0; i < numQuestions; i++) {
        printf("Question %d:\n", i + 1);
        printf("%s\n", questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("%d. %s\n", j + 1, questions[i].answers[j]);
        }
    }
}

// Function to get the user's answers
int* getAnswers(int numQuestions) {
    int *answers = malloc(sizeof(int) * numQuestions);
    for (int i = 0; i < numQuestions; i++) {
        printf("Enter your answer for question %d (1-4): ", i + 1);
        scanf("%d", &answers[i]);
    }
    return answers;
}

// Function to check the user's answers
int checkAnswers(int answers[], Question questions[], int numQuestions) {
    int score = 0;
    for (int i = 0; i < numQuestions; i++) {
        if (answers[i] == questions[i].correctAnswer) {
            score++;
        }
    }
    return score;
}

// Function to print the results of the exam
void printResults(int score, int numQuestions) {
    printf("Your score is %d out of %d\n", score, numQuestions);
    if (score >= numQuestions / 2) {
        printf("Congratulations, you passed the exam!\n");
    } else {
        printf("Sorry, you failed the exam. Please try again.\n");
    }
}

int main() {
    // Set the random seed
    srand(time(NULL));

    // Shuffle the questions
    for (int i = 0; i < 5; i++) {
        int r1 = rand() % 5;
        int r2 = rand() % 5;
        Question temp = questions[r1];
        questions[r1] = questions[r2];
        questions[r2] = temp;
    }

    // Print the questions and answers
    printQuestions(questions, 5);

    // Get the user's answers
    int *answers = getAnswers(5);

    // Check the user's answers
    int score = checkAnswers(answers, questions, 5);

    // Print the results of the exam
    printResults(score, 5);

    free(answers);
    return 0;
}