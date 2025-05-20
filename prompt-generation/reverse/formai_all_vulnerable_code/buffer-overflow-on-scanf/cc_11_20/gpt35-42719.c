//FormAI DATASET v1.0 Category: Online Examination System ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int main()
{
    //Welcome Screen
    printf("\n\n\n\t\tWelcome to C Online Examination System\n");
    printf("\n\nEnter to Continue\n\n");
    getchar();

    //Instructions Screen
    printf("\n\n\n\t\tInstructions for the Exam:\n");
    printf("\n\t1. There will be 10 MCQs.\n");
    printf("\t2. Each MCQ has only one correct answer.\n");
    printf("\t3. Each correct answer gives you one point, and each wrong answer gives you negative one point.\n");
    printf("\n\nEnter to Continue\n\n");
    getchar();

    //Questions and Answers
    int score=0;
    char answer[10][1] = {"2", "1", "4", "2", "3", "1", "2", "4", "3", "1"};
    printf("\n\n\n\t\tQuestion 1:\n");
    printf("\n\t1. What is the output of this code:\n\n\t\tint a=5, b=3, c=2;\n\t\tprintf(\"%%d\\n\", b*c+a);");
    printf("\n\n\tA) 13\tB) 15\tC) 11\tD) 7\n");
    char choice1[1];
    scanf("%s", choice1);
    if(strcmp(choice1, answer[0])==0)
        score++;
    else
        score--;

    printf("\n\n\n\t\tQuestion 2:\n");
    printf("\n\t2. Which of these is a valid variable name in C:\n");
    printf("\n\tA) num1\tB) 2num\tC) num-1\tD) num_1\n");
    char choice2[1];
    scanf("%s", choice2);
    if(strcmp(choice2, answer[1])==0)
        score++;
    else
        score--;

    printf("\n\n\n\t\tQuestion 3:\n");
    printf("\n\t3. What is the output of this code:\n\n\t\tint count=1;\n\t\twhile(count<=3)\n\t\t{\n\t\tprintf(\"%%d\\n\",count);\n\t\tcount++;\n\t\t}");
    printf("\n\n\tA) 1 2\tB) 1 2 3\tC) 2 3\tD) 3 2 1\n");
    char choice3[1];
    scanf("%s", choice3);
    if(strcmp(choice3, answer[2])==0)
        score++;
    else
        score--;

    printf("\n\n\n\t\tQuestion 4:\n");
    printf("\n\t4. What is the output of this code:\n\n\t\tfor(int i=0;i<5;i++)\n\t\t{\n\t\tif(i==2)\n\t\tcontinue;\n\t\tprintf(\"%%d\",i);\n\t\t}");
    printf("\n\n\tA) 01234\tB) 0123\tC) 012\tD) 1234\n");
    char choice4[1];
    scanf("%s", choice4);
    if(strcmp(choice4, answer[3])==0)
        score++;
    else
        score--;

    printf("\n\n\n\t\tQuestion 5:\n");
    printf("\n\t5. What is the output of this code:\n\n\t\tint a=10, b=5;\n\t\tprintf(\"%%d\\n\",a+=b*=2);");
    printf("\n\n\tA) 30\tB) 40\tC) 50\tD) 60\n");
    char choice5[1];
    scanf("%s", choice5);
    if(strcmp(choice5, answer[4])==0)
        score++;
    else
        score--;

    printf("\n\n\n\t\tQuestion 6:\n");
    printf("\n\t6. What is the output of this code:\n\n\t\tint a=1, b=1;\n\t\tdo{\n\t\tprintf(\"%%d \",a);\n\t\ta++;\n\t\t}while(a++<b--);\n\t\tprintf(\"%%d\\n\",b);");
    printf("\n\n\tA) 1 2 1\tB) 1\t\tC) 1 2\t\tD) 1 2 -1\n");
    char choice6[1];
    scanf("%s", choice6);
    if(strcmp(choice6, answer[5])==0)
        score++;
    else
        score--;

    printf("\n\n\n\t\tQuestion 7:\n");
    printf("\n\t7. What is the output of this code:\n\n\t\tint a=3, b=3;\n\t\tif(a=5 && b==3)\n\t\t{\n\t\tprintf(\"yes\");\n\t\t}\n\t\telse\n\t\t{\n\t\tprintf(\"no\");\n\t\t}");
    printf("\n\n\tA) yes\tB) no\tC) Nothing Printed\tD) Run time error\n");
    char choice7[1];
    scanf("%s", choice7);
    if(strcmp(choice7, answer[6])==0)
        score++;
    else
        score--;

    printf("\n\n\n\t\tQuestion 8:\n");
    printf("\n\t8. What is the output of this code:\n\n\t\tint a,b;\n\t\tfor(a=0,b=-1;b=0;a++)\n\t\tif(b=a/2)\n\t\tprintf(\"%%d\",b);\n");
    printf("\n\n\tA) 12345\tB) 01234\tC) 012345\tD) Run time error\n");
    char choice8[1];
    scanf("%s", choice8);
    if(strcmp(choice8, answer[7])==0)
        score++;
    else
        score--;

    printf("\n\n\n\t\tQuestion 9:\n");
    printf("\n\t9. What is the output of this code:\n\n\t\tprintf(\"%%s\\n\",printf(\"%%s\",\"Hello World!\"));");
    printf("\n\n\tA) Hello World!\tB) 12\tC) Compile time error\tD) Run time error\n");
    char choice9[1];
    scanf("%s", choice9);
    if(strcmp(choice9, answer[8])==0)
        score++;
    else
        score--;

    printf("\n\n\n\t\tQuestion 10:\n");
    printf("\n\t10. What is a function pointer in C?\n");
    printf("\n\tA) A pointer to a function\t\tB) A pointer to a variable storing a function name\n\tC) A pointer to a variable containing the address of a function\tD) All of the above\n");
    char choice10[1];
    scanf("%s", choice10);
    if(strcmp(choice10, answer[9])==0)
        score++;
    else
        score--;

    printf("\n\n");

    //Score Screen
    printf("\n\n\n\t\tYour Score: %d/10\n", score);
    if(score>=6)
        printf("\n\tCongratulations! You passed the exam!\n");
    else
        printf("\n\tSorry! You failed the exam. Better luck next time!\n");
    printf("\n\n\t\tThank you for taking the Exam\n");

    return 0;
}