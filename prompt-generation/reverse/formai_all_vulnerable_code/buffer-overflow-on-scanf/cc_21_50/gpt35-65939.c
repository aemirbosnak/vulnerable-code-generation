//FormAI DATASET v1.0 Category: Online Examination System ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student {
    char name[30];
    int id;
    int score;
};

struct question {
    char question[100];
    char option1[30];
    char option2[30];
    char option3[30];
    char option4[30];
    int correct_ans;
};

void print_question(struct question q) {
    printf("%s\n", q.question);
    printf("A. %s\n", q.option1);
    printf("B. %s\n", q.option2);
    printf("C. %s\n", q.option3);
    printf("D. %s\n", q.option4);
}

int main() {
    struct student s;
    struct question q1, q2, q3, q4, q5;
    int score = 0;

    // set student information
    printf("Enter your name: ");
    scanf("%s", s.name);
    printf("Enter your ID: ");
    scanf("%d", &s.id);

    // set questions and answers
    strcpy(q1.question, "What is the capital of India?");
    strcpy(q1.option1, "Mumbai");
    strcpy(q1.option2, "Delhi");
    strcpy(q1.option3, "Chennai");
    strcpy(q1.option4, "Kolkata");
    q1.correct_ans = 2;

    strcpy(q2.question, "Who invented the telephone?");
    strcpy(q2.option1, "Thomas Edison");
    strcpy(q2.option2, "Alexander Graham Bell");
    strcpy(q2.option3, "Nikola Tesla");
    strcpy(q2.option4, "Eli Whitney");
    q2.correct_ans = 2;

    strcpy(q3.question, "What is the largest planet in our solar system?");
    strcpy(q3.option1, "Mars");
    strcpy(q3.option2, "Jupiter");
    strcpy(q3.option3, "Saturn");
    strcpy(q3.option4, "Venus");
    q3.correct_ans = 2;

    strcpy(q4.question, "Which country is the largest producer of coffee in the world?");
    strcpy(q4.option1, "Brazil");
    strcpy(q4.option2, "Colombia");
    strcpy(q4.option3, "Vietnam");
    strcpy(q4.option4, "Indonesia");
    q4.correct_ans = 1;

    strcpy(q5.question, "What is the top-ranked university in the world according to QS World University Rankings 2021?");
    strcpy(q5.option1, "Harvard University");
    strcpy(q5.option2, "Massachusetts Institute of Technology (MIT)");
    strcpy(q5.option3, "Stanford University");
    strcpy(q5.option4, "University of Oxford");
    q5.correct_ans = 4;

    // display questions and take answers
    printf("----------------------------------------\n");
    printf("Welcome %s, Your Exam Has Begun.\n", s.name);
    printf("----------------------------------------\n");
    printf("\n");
    printf("Question 1:\n");
    print_question(q1);

    char ans1;
    printf("Enter your answer (A/B/C/D): ");
    scanf("%s", &ans1);
    if (ans1 == 'A' || ans1 == 'a') {
        printf("Incorrect\n");
    } else if (ans1 == 'B' || ans1 == 'b') {
        printf("Correct\n");
        score += 10;
    } else if (ans1 == 'C' || ans1 == 'c') {
        printf("Incorrect\n");
    } else if (ans1 == 'D' || ans1 == 'd') {
        printf("Incorrect\n");
    } else {
        printf("Invalid input\n");
    }

    printf("----------------------------------------\n");
    printf("Question 2:\n");
    print_question(q2);

    char ans2;
    printf("Enter your answer (A/B/C/D): ");
    scanf("%s", &ans2);
    if (ans2 == 'A' || ans2 == 'a') {
        printf("Incorrect\n");
    } else if (ans2 == 'B' || ans2 == 'b') {
        printf("Correct\n");
        score += 10;
    } else if (ans2 == 'C' || ans2 == 'c') {
        printf("Incorrect\n");
    } else if (ans2 == 'D' || ans2 == 'd') {
        printf("Incorrect\n");
    } else {
        printf("Invalid input\n");
    }

    printf("----------------------------------------\n");
    printf("Question 3:\n");
    print_question(q3);

    char ans3;
    printf("Enter your answer (A/B/C/D): ");
    scanf("%s", &ans3);
    if (ans3 == 'A' || ans3 == 'a') {
        printf("Incorrect\n");
    } else if (ans3 == 'B' || ans3 == 'b') {
        printf("Correct\n");
        score += 10;
    } else if (ans3 == 'C' || ans3 == 'c') {
        printf("Incorrect\n");
    } else if (ans3 == 'D' || ans3 == 'd') {
        printf("Incorrect\n");
    } else {
        printf("Invalid input\n");
    }

    printf("----------------------------------------\n");
    printf("Question 4:\n");
    print_question(q4);

    char ans4;
    printf("Enter your answer (A/B/C/D): ");
    scanf("%s", &ans4);
    if (ans4 == 'A' || ans4 == 'a') {
        printf("Correct\n");
        score += 10;
    } else if (ans4 == 'B' || ans4 == 'b') {
        printf("Incorrect\n");
    } else if (ans4 == 'C' || ans4 == 'c') {
        printf("Incorrect\n");
    } else if (ans4 == 'D' || ans4 == 'd') {
        printf("Incorrect\n");
    } else {
        printf("Invalid input\n");
    }

    printf("----------------------------------------\n");
    printf("Question 5:\n");
    print_question(q5);

    char ans5;
    printf("Enter your answer (A/B/C/D): ");
    scanf("%s", &ans5);
    if (ans5 == 'A' || ans5 == 'a') {
        printf("Incorrect\n");
    } else if (ans5 == 'B' || ans5 == 'b') {
        printf("Incorrect\n");
    } else if (ans5 == 'C' || ans5 == 'c') {
        printf("Incorrect\n");
    } else if (ans5 == 'D' || ans5 == 'd') {
        printf("Correct\n");
        score += 10;
    } else {
        printf("Invalid input\n");
    }

    printf("----------------------------------------\n");

    // display scorecard
    printf("Your score: %d/50\n", score);
    if (score >= 30) {
        printf("Congratulations! You passed the exam.\n");
    } else {
        printf("Sorry, you failed the exam. Better luck next time.\n");
    }

    return 0;
}