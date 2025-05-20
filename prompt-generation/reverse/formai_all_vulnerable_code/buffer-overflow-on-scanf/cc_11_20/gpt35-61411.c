//FormAI DATASET v1.0 Category: Online Examination System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int q1_answer = 3, q2_answer = 2, q3_answer = 4, q4_answer = 1, q5_answer = 2;
    int student_answer, correct_answers = 0, incorrect_answers = 0, unanswered = 0;
    char name[50];
    printf("Welcome to the C Online Examination System!\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("\nHello %s, please answer the following questions:\n", name);
    printf("\n1. What is the output of the following code snippet?\n");
    printf(" int x = 5;\n printf('The value of x is %d', x);\n Answer: ");
    scanf("%d", &student_answer);
    if(student_answer == q1_answer){
        printf("Correct answer!\n");
        correct_answers++;
    } else if(student_answer == 0){
        printf("You have left the question unanswered.\n");
        unanswered++;
    } else {
        printf("Incorrect answer.\n");
        incorrect_answers++;
    }
    printf("\n2. What is the output of the following code snippet?\n");
    printf(" int a = 10, b = 20;\n printf('Result: %d', a + b);\n Answer: ");
    scanf("%d", &student_answer);
    if(student_answer == q2_answer){
        printf("Correct answer!\n");
        correct_answers++;
    } else if(student_answer == 0){
        printf("You have left the question unanswered.\n");
        unanswered++;
    } else {
        printf("Incorrect answer.\n");
        incorrect_answers++;
    }
    printf("\n3. What is the use of 'sizeof' operator in C?\n Answer: ");
    scanf("%d", &student_answer);
    if(student_answer == q3_answer){
        printf("Correct answer!\n");
        correct_answers++;
    } else if(student_answer == 0){
        printf("You have left the question unanswered.\n");
        unanswered++;
    } else {
        printf("Incorrect answer.\n");
        incorrect_answers++;
    }
    printf("\n4. What is the correct syntax to declare a pointer to an integer variable?\n Answer: ");
    scanf("%d", &student_answer);
    if(student_answer == q4_answer){
        printf("Correct answer!\n");
        correct_answers++;
    } else if(student_answer == 0){
        printf("You have left the question unanswered.\n");
        unanswered++;
    } else {
        printf("Incorrect answer.\n");
        incorrect_answers++;
    }
    printf("\n5. Which header file is required to use the 'malloc' function in C?\n Answer: ");
    scanf("%d", &student_answer);
    if(student_answer == q5_answer){
        printf("Correct answer!\n");
        correct_answers++;
    } else if(student_answer == 0){
        printf("You have left the question unanswered.\n");
        unanswered++;
    } else {
        printf("Incorrect answer.\n");
        incorrect_answers++;
    }
    printf("\nThank you for taking the C Online Examination System!\n");
    printf("\nResults:\n");
    printf("Correct Answers: %d\nIncorrect Answers: %d\nUnanswered Questions: %d\n", correct_answers, incorrect_answers, unanswered);
    return 0;
}