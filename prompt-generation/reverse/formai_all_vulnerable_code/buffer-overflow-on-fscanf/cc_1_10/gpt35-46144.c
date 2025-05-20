//FormAI DATASET v1.0 Category: Online Examination System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Structure for the questions
struct Question {
    int id;
    char prompt[100];
    char options[4][50];
    char answer;
};

//Structure for the submitted answers
struct Answer {
    int id;
    char answer;
};

//Function to load questions from file
int load_questions(struct Question *questions) {
    FILE *file = fopen("questions.txt", "r");
    int question_count = 0;

    //Read each line from file and store in question structure
    while(!feof(file)) {
        fscanf(file,"%d\n", &questions[question_count].id);
        fgets(questions[question_count].prompt, 100, file);
        for(int i=0;i<4;i++) {
            fgets(questions[question_count].options[i], 50, file);
        }
        fscanf(file, "%c\n", &questions[question_count].answer);
        question_count++;
    }
    fclose(file);
    return question_count;
}

//Function to display questions and get answers from user
void take_exam(struct Question *questions, int question_count, struct Answer *answers) {
    printf("Welcome to the C Online Examination System!\n");
    printf("You will be presented with %d questions. Please select the option (A/B/C/D) for each question.\n\n", question_count);

    //Loop through each question
    for(int i=0;i<question_count;i++) {
        printf("Question %d:\n%s\n", questions[i].id, questions[i].prompt);
        printf("%s", questions[i].options[0]);
        printf("%s", questions[i].options[1]);
        printf("%s", questions[i].options[2]);
        printf("%s", questions[i].options[3]);
        printf("Answer: ");
        scanf("%c", &answers[i].answer);
        answers[i].id = questions[i].id;
        printf("\n");
    }
}

//Function to grade the exam
void grade_exam(struct Question *questions, int question_count, struct Answer *answers) {
    printf("Grading Exam...\n\n");
    int score = 0;

    //Loop through each question and check if answer is correct
    for(int i=0;i<question_count;i++) {
        if(answers[i].answer == questions[i].answer) {
            printf("Question %d: Correct!\n", questions[i].id);
            score++;
        } else {
            printf("Question %d: Incorrect!\n", questions[i].id);
        }
    }
    printf("Your final score is %d/%d", score, question_count);
}

int main() {
    struct Question questions[50];
    struct Answer answers[50];
    int question_count = load_questions(questions);
    take_exam(questions, question_count, answers);
    grade_exam(questions, question_count, answers);
    return 0;
}