//FormAI DATASET v1.0 Category: Online Examination System ; Style: excited
#include<stdio.h>
#include<stdlib.h>

// Declaration of functions
void instructions();
void exam(char name[], int age, int roll_no);

int main(){
    char name[50], ans;
    int age, roll_no;

    printf("\n\t\tWelcome to C Online Examination System!\n");
    printf("\n\t\tEnter your name: ");
    scanf("%s", name);

    printf("\n\t\tEnter your age: ");
    scanf("%d", &age);

    printf("\n\t\tEnter your Roll Number: ");
    scanf("%d", &roll_no);

    printf("\n\t\tDear %s, Are you ready to start the exam? (Y/N): ",name);
    scanf(" %c", &ans);

    if (ans =='Y' || ans=='y'){
        instructions();
        exam(name, age, roll_no);
    }
    else{
        printf("\n\t\tGoodbye %s\n", name); // If the user doesn't want to start
        exit(0);
    }
    return 0;
}

void instructions(){
    printf("\n\n\t\tINSTRUCTIONS:\n\n\t\t1. The duration of the exam is 20 minutes.\n\t\t2. The Exam consists of 10 Multiple Choice Questions.\n\t\t3. Each question carries 5 points.\n\t\t4. There is no negative marking for wrong answers.\n\t\t5. Press any key to start the exam. \n\t\t   The timer will begin as soon as you press any key.\n\n\n");
    getchar();
}

void exam(char name[], int age, int roll_no){
    char answer;
    int marks = 0;
    printf("\n\n\n\t\t\t  STARTS IN 3 SECONDS...");
    sleep(3);
    system("cls");

    printf("\n\n\n\t\t\t\tWELCOME %s!\n", name);
    printf("\n\t\t\t\tID Number: %d", roll_no);
    printf("\n\t\t\t\tAge: %d\n\n", age);

    printf("\n\t\t1. What is the size of int in bytes?\n");
    printf("\n\t\tA. 2 bytes\t\tB. 4 bytes\n");
    printf("\n\t\tC. 8 bytes\t\tD. None of the above\n");
    printf("\n\t\tYour answer: ");
    scanf(" %c", &answer);

    if(answer == 'B' || answer == 'b'){
        printf("\n\t\tCorrect Answer!\n");
        marks += 5;
    }
    else{
        printf("\n\t\tWrong Answer!\n");
    }

    printf("\n\t\t2. Which of the following is not a loop statement?\n");
    printf("\n\t\tA. for\t\tB. while\n");
    printf("\n\t\tC. loop\t\tD. do-while\n");
    printf("\n\t\tYour answer: ");
    scanf(" %c", &answer);

    if(answer == 'C' || answer == 'c'){
        printf("\n\t\tCorrect Answer!\n");
        marks += 5;
    }
    else{
        printf("\n\t\tWrong Answer!\n");
    }
    // And so on for the rest of the questions....

    printf("\n\n\n\t\t\t\tTHANKS FOR PARTICIPATING!");
    printf("\n\n\t\t\t\tYOUR MARKS: %d/50\n", marks);
}