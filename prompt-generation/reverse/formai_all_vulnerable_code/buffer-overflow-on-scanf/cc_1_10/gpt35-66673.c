//FormAI DATASET v1.0 Category: Online Examination System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10
#define MAX_ANSWERS 4

typedef struct {
    char question[100];
    char answers[MAX_ANSWERS][50];
    int correct_answer;
} Question;

Question exam_questions[MAX_QUESTIONS] = {
    {"What is the capital of Australia?", {"Sydney", "Canberra", "Melbourne", "Brisbane"}, 1},
    {"What is the symbol for sodium on the periodic table?", {"Na", "So", "Sd", "Nu"}, 0},
    {"Who painted the Mona Lisa?", {"Leonardo da Vinci", "Michelangelo", "Vincent van Gogh", "Pablo Picasso"}, 0},
    {"What is the highest mountain in the world?", {"Mount Kilimanjaro", "Mount Kilroy", "Mount Everest", "Mount Rushmore"}, 2},
    {"What is the largest ocean?", {"Atlantic Ocean", "Indian Ocean", "Southern Ocean", "Pacific Ocean"}, 3},
    {"Who is the current president of the United States?", {"Barack Obama", "Hillary Clinton", "Donald Trump", "Joe Biden"}, 3},
    {"What is the largest mammal on earth?", {"Giraffe", "Lion", "Blue Whale", "Elephant"}, 2},
    {"What is the smallest continent on earth?", {"South America", "Asia", "Antarctica", "Australia"}, 3},
    {"What is the largest country in the world?", {"Russia", "China", "Canada", "United States"}, 0},
    {"What is the capital of Egypt?", {"Cairo", "Alexandria", "Giza", "Luxor"}, 0}
};

int score = 0;

void print_question(Question q)
{
    printf("%s\n", q.question);
    for (int i = 0; i < MAX_ANSWERS; i++) {
        printf("%d: %s\n", i + 1, q.answers[i]);
    }
    printf("Enter your answer (1-4): ");
}

void take_exam()
{
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        print_question(exam_questions[i]);
        int user_answer;
        scanf("%d", &user_answer);
        if (user_answer == exam_questions[i].correct_answer + 1) { 
            score++;
            printf("Correct!\n");
        }
        else {
            printf("Incorrect! The correct answer is %d: %s\n", exam_questions[i].correct_answer + 1, exam_questions[i].answers[exam_questions[i].correct_answer]);
        }
    }
}

int main()
{
    printf("Welcome to the Online Exam System\n");
    printf("You will be presented with %d multiple choice questions\n", MAX_QUESTIONS);
    printf("Answer each question by entering the number of the correct answer (1-4)\n");
    printf("Press enter to start the exam\n");
    getchar();
    take_exam();
    printf("Your score is: %d/%d\n", score, MAX_QUESTIONS);
    if (score < 5) {
        printf("You have failed the exam\n");
    }
    else {
        printf("Congratulations, you have passed the exam!\n");
    }
    return 0;
}