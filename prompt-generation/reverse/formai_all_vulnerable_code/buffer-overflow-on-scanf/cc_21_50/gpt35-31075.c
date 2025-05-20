//FormAI DATASET v1.0 Category: Online Examination System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int count = 0;
    int score = 0;

    //Generating random numbers for the exam questions
    srand(time(0));
    int num1 = rand() % 10;
    int num2 = rand() % 10;
    int num3 = rand() % 10;
    int num4 = rand() % 10;
    int num5 = rand() % 10;

    printf("\n****Welcome to the Online C Exam****\n\n");
    printf("There will be 5 multiple choice questions.\n");
    printf("You will have 30 seconds to answer each question.\n");

    clock_t start = clock();

    //First question
    printf("\nQ1: What is the output of the following code?\n");
    printf("\nint x = 5;\nprintf(\"%d\",++x);\n\n");
    printf("A. 5\nB. 6\nC. 7\nD. Compile error\n\n");
    char answer1;
    printf("Enter your answer: ");
    scanf(" %c", &answer1);
    if(answer1 == 'B' || answer1 == 'b'){
        printf("Correct!\n");
        score++;
    }
    else{
        printf("Incorrect!\n");
    }
    count++;

    if (((float)clock() - start) / CLOCKS_PER_SEC > 30.0) {
        printf("\nTime's up for Question 1!\n");
        printf("Moving on to next question...\n");
    }

    //Second question
    printf("\nQ2: What is the output of the following code?\n");
    printf("\nint a = 10, b = 20;\nint tmp;\ntmp = a;\na = b;\nb = tmp;\n");
    printf("\nA. a: 10, b: 20\nB. a: 10, b: 10\nC. a: 20, b: 10\nD. a: 20, b: 20\n\n");
    char answer2;
    printf("Enter your answer: ");
    scanf(" %c", &answer2);
    if(answer2 == 'C' || answer2 == 'c'){
        printf("Correct!\n");
        score++;
    }
    else{
        printf("Incorrect!\n");
    }
    count++;

    if (((float)clock() - start) / CLOCKS_PER_SEC > 60.0) {
        printf("\nTime's up for Question 2!\n");
        printf("Moving on to next question...\n");
    }

    //Third question
    printf("\nQ3: What is the output of the following code?\n");
    printf("\nint i = 0;\nwhile(i < 5)\n{\n    printf(\"%d \", i);\n    i++;\n}\n");
    printf("\nA. 0 1 2 3 4\nB. 1 2 3 4 5\nC. 0 1 2 3 4 5\nD. Compile error\n\n");
    char answer3;
    printf("Enter your answer: ");
    scanf(" %c", &answer3);
    if(answer3 == 'A' || answer3 == 'a'){
        printf("Correct!\n");
        score++;
    }
    else{
        printf("Incorrect!\n");
    }
    count++;

    if (((float)clock() - start) / CLOCKS_PER_SEC > 90.0) {
        printf("\nTime's up for Question 3!\n");
        printf("Moving on to next question...\n");
    }

    //Fourth question
    printf("\nQ4: What is the output of the following code?\n");
    printf("\nint n = %d;\nfor(int i = 2; i <= n/2; i++)\n{\n    if(n %% i == 0)\n        printf(\"Not Prime\");\n}\n", num4);
    printf("\nA. Not Prime\nB. Prime\nC. Compile error\nD. Depends on the value of n\n\n");
    char answer4;
    printf("Enter your answer: ");
    scanf(" %c", &answer4);
    //Checking if the entered answer is a valid choice
    if(answer4 == 'A' || answer4 == 'a' || answer4 == 'B' || answer4 == 'b' || answer4 == 'D' || answer4 == 'd'){
        if(answer4 == 'B' || answer4 == 'b'){
            printf("Correct!\n");
            score++;
        }
        else{
            printf("Incorrect!\n");
        }
    }
    else{
        printf("Invalid choice!\n");
    }
    count++;

    if (((float)clock() - start) / CLOCKS_PER_SEC > 120.0) {
        printf("\nTime's up for Question 4!\n");
        printf("Moving on to next question...\n");
    }

    //Fifth question
    printf("\nQ5: What is the output of the following code?\n");
    printf("\nint arr[5] = {%d, %d, %d, %d, %d};\nfor(int i = 0; i < 5; i++)\n{\n    printf(\"%d \", *(arr+i));\n}\n", num1, num2, num3, num4, num5);
    printf("\nA. 0 1 2 3 4\nB. 5 6 7 8 9\nC. Random numbers\nD. Runtime error\n\n");
    char answer5;
    printf("Enter your answer: ");
    scanf(" %c", &answer5);
    if(answer5 == 'C' || answer5 == 'c'){
        printf("Correct!\n");
        score++;
    }
    else{
        printf("Incorrect!\n");
    }
    count++;

    if (((float)clock() - start) / CLOCKS_PER_SEC > 150.0) {
        printf("\nTime's up for Question 5!\n");
    }

    //Calculating the overall score and printing the result
    float percentage = ((float)score/count) * 100;
    printf("\n****Exam Completed!****\n");
    printf("You scored %d out of %d.\n", score, count);
    if(percentage >= 60){
        printf("Congratulations! You have passed the exam.\n");
    }
    else{
        printf("Sorry, you failed the exam.\nPlease try again!\n");
    }

    return 0;
}