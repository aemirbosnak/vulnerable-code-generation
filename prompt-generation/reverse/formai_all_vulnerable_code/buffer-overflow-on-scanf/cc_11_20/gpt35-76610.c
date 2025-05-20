//FormAI DATASET v1.0 Category: Online Examination System ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

int main()
{
    int score = 0;

    printf("***Welcome to the C Online Exam***\n\n");
    printf("There are 10 multiple choice questions.\n");
    printf("Each question is worth 10 points.\n");
    printf("Good luck!\n\n");

    char ans1, ans2, ans3, ans4, ans5, ans6, ans7, ans8, ans9, ans10;

    printf("Question 1: What is the output of the following code?\n");
    printf("           int i = 3; \n           printf('%d\\n', i++ + ++i);\n");
    printf("           a. 5\n           b. 7\n           c. 9\n           d. 11\n");
    printf("Answer: ");
    scanf(" %c", &ans1);

    if (tolower(ans1) == 'b')
        score += 10;

    printf("Question 2: Which of the following is not a data type in C?\n");
    printf("           a. int\n           b. char\n           c. boolean\n           d. float\n");
    printf("Answer: ");
    scanf(" %c", &ans2);

    if (tolower(ans2) == 'c')
        score += 10;

    printf("Question 3: What is the output of the following code?\n");
    printf("           int i, j;\n           for (i=1; i<=5; i++)\n           {\n                for (j=1; j<=i; j++)\n                    printf('*');\n                printf('\\n');\n           }\n");
    printf("           a. *\n              **\n              ***\n              ****\n              *****\n           b. *****\n              ****\n              ***\n              **\n              *\n           c. *\n              ***\n              *****\n              *******\n              *********\n           d. None of the above\n");
    printf("Answer: ");
    scanf(" %c", &ans3);

    if (tolower(ans3) == 'a')
        score += 10;

    printf("Question 4: Which keyword is used to exit from a loop?\n");
    printf("           a. end\n           b. break\n           c. exit\n           d. terminate\n");
    printf("Answer: ");
    scanf(" %c", &ans4);

    if (tolower(ans4) == 'b')
        score += 10;

    printf("Question 5: Which of the following operators has the highest precedence?\n");
    printf("           a. ++\n           b. &&\n           c. *\n           d. sizeof\n");
    printf("Answer: ");
    scanf(" %c", &ans5);

    if (tolower(ans5) == 'd')
        score += 10;

    printf("Question 6: What is the output of the following code?\n");
    printf("           int arr[] = {1, 2, 3, 4, 5};\n           int *p = arr+2;\n           printf('%d\\n', *++p);\n");
    printf("           a. 2\n           b. 3\n           c. 4\n           d. 5\n");
    printf("Answer: ");
    scanf(" %c", &ans6);

    if (tolower(ans6) == 'c')
        score += 10;

    printf("Question 7: Which of the following is a correct way to define a macro?\n");
    printf("           a. #DEFINE PI 3.14\n           b. #define PI 3.14\n           c. #define PI = 3.14\n           d. #Define PI 3.14\n");
    printf("Answer: ");
    scanf(" %c", &ans7);

    if (tolower(ans7) == 'b')
        score += 10;

    printf("Question 8: What is the output of the following code?\n");
    printf("           char str[] = 'hello';\n           str[2] = 'P';\n           printf('%s\\n', str);\n");
    printf("           a. hello\n           b. hePlo\n           c. error\n           d. hPllo\n");
    printf("Answer: ");
    scanf(" %c", &ans8);

    if (tolower(ans8) == 'b')
        score += 10;

    printf("Question 9: What is the output of the following code?\n");
    printf("           int i = 0;\n           for (i; i<=10; i+=2)\n               printf('%d ', i++);\n");
    printf("           a. 0 2 4 6 8\n           b. 0 2 4 6 8 10\n           c. 0 2 4 6 8 10 12\n           d. None of the above\n");
    printf("Answer: ");
    scanf(" %c", &ans9);

    if (tolower(ans9) == 'a')
        score += 10;

    printf("Question 10: What is the output of the following code?\n");
    printf("            int i;\n            for (i=0; i<10; i++)\n            {\n                if (i == 3)\n                    continue;\n                printf('%d ', i);\n            }\n");
    printf("            a. 0 1 2 3 4 5 6 7 8 9\n            b. 0 1 2 4 5 6 7 8 9\n            c. 0 1 2 4 5 6 7 8\n            d. None of the above\n");
    printf("Answer: ");
    scanf(" %c", &ans10);

    if (tolower(ans10) == 'c')
        score += 10;

    printf("\n\nCongratulations! You have completed the exam.\n");
    printf("Your score is %d/100.\n", score);

    return 0;
}