//FormAI DATASET v1.0 Category: Online Examination System ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char question[200];
    char options[4][50];
    char answer;
}Question;

void quiz(char* student_name, int num_questions, int curr_question, int score){
    Question q1 = {"What is the capital of India?", {"A. Mumbai", "B. New Delhi", "C. Kolkata", "D. Chennai"}, 'B'};
    Question q2 = {"Which is the world's largest ocean?", {"A. Atlantic Ocean", "B. Indian Ocean", "C. Arctic Ocean", "D. Pacific Ocean"}, 'D'};
    Question q3 = {"What is the full form of RAM?", {"A. Random Access Memory", "B. Read Access Memory", "C. Read And Modify", "D. Remote Access Memory"}, 'A'};

    Question questions[] = {q1, q2, q3};

    // Base case
    if(curr_question == num_questions){
        printf("Congratulations %s, your final score is: %d/%d\n", student_name, score, num_questions);
        return;
    }

    printf("Question %d: %s\n", curr_question+1, questions[curr_question].question);

    for(int i=0; i<4; i++){
        printf("%s\n", questions[curr_question].options[i]);
    }

    printf("Enter your answer (A/B/C/D): ");
    char ans;
    scanf("%c", &ans);
    getchar(); // Clearing input buffer

    // Checking answer
    if(ans == questions[curr_question].answer){
        score++;
        printf("Correct Answer\n");
    }
    else{
        printf("Wrong Answer. Correct answer is %c\n", questions[curr_question].answer);
    }

    // Recursive call
    quiz(student_name, num_questions, curr_question+1, score);
}

int main(){
    printf("Welcome to the Online Exam System\n");
    printf("Enter your name: ");
    char student_name[30];
    scanf("%s", student_name);
    int num_questions = 3; // Total number of questions
    quiz(student_name, num_questions, 0, 0); // Initial call
    return 0;
}