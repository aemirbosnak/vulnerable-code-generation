//FormAI DATASET v1.0 Category: Online Examination System ; Style: excited
//Welcome to our Online Examination System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Exam{
    char name[30];
    int question1;
    int question2;
    int question3;
    int total;
};

int main(){
    printf("Welcome to our Online Examination System\n");
    printf("Please enter your name: ");
    char name[30];
    scanf("%s", name);

    struct Exam student;
    strncpy(student.name, name, 30); 
    student.total = 0;

    //Question 1
    printf("Question 1: What is the capital of France?\n");
    printf("a) London \nb) Paris \nc) Madrid \nd) Berlin \n");
    printf("Enter your choice (a/b/c/d): ");
    char choice[2];
    scanf("%s", choice);
    if(choice[0] == 'b'){
        student.total += 10;
        student.question1 = 10;
    }
    else{
        student.question1 = 0;
    }

    //Question 2
    printf("Question 2: What is the largest country by area?\n");
    printf("a) Russia \nb) USA \nc) China \nd) Australia \n");
    printf("Enter your choice (a/b/c/d): ");
    scanf("%s", choice);
    if(choice[0] == 'a'){
        student.total += 10;
        student.question2 = 10;
    }
    else{
        student.question2 = 0;
    }

    //Question 3
    printf("Question 3: What is the currency of Japan?\n");
    printf("a) Yen \nb) Dollar \nc) Euro \nd) Pound \n");
    printf("Enter your choice (a/b/c/d): ");
    scanf("%s", choice);
    if(choice[0] == 'a'){
        student.total += 10;
        student.question3 = 10;
    }
    else{
        student.question3 = 0;
    }

    //Display Result
    printf("\nThank you for taking the test, %s!\n", student.name);
    printf("Your Score:\n");
    printf("Question 1: %d\n", student.question1);
    printf("Question 2: %d\n", student.question2);
    printf("Question 3: %d\n", student.question3);
    printf("Total Score: %d/30\n", student.total);

    return 0;
}

//Thank you for using our Online Examination System!