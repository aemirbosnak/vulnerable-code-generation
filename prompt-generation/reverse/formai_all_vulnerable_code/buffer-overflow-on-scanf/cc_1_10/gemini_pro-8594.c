//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: relaxed
// Hey there exam-takers! Welcome to our funky online exam system!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Let's define some cool data structures for our questions and answers.
typedef struct Question {
    char *question;
    char *answer;
} Question;

typedef struct Exam {
    Question *questions;
    int num_questions;
} Exam;

// Here's our question and answer database. Feel free to add more if you're feeling brainy!
Question questions[] = {
    {"What's the capital of France?", "Paris"},
    {"Who painted the Mona Lisa?", "Leonardo da Vinci"},
    {"What's the meaning of life?", "42 (according to Douglas Adams)"},
    {"What color is the sky?", "Blue (most of the time)"},
    {"How many planets are there in our solar system?", "8"}
};

// Time to create our exam.
Exam exam = {
    .questions = questions,
    .num_questions = sizeof(questions) / sizeof(Question)
};

// Let's start the exam!
int main() {
    // Greet the user and give them some instructions.
    printf("Welcome to the Funky Exam System!\n\n");
    printf("You will be presented with a series of questions.\n");
    printf("Type in your answers and hit enter to submit each one.\n\n");

    // Loop through the questions and get the user's answers.
    for (int i = 0; i < exam.num_questions; i++) {
        printf("Question %d: %s\n", i + 1, exam.questions[i].question);
        char answer[100];
        scanf(" %s", answer);

        // Check if the user's answer is correct.
        if (strcmp(answer, exam.questions[i].answer) == 0) {
            printf("Correct!\n\n");
        } else {
            printf("Oops, that's not quite right! The correct answer is %s.\n\n", exam.questions[i].answer);
        }
    }

    // Thank the user for taking the exam and show them their score.
    printf("Thanks for taking the exam! You scored %d out of %d.\n", 0, exam.num_questions);

    return 0;
}