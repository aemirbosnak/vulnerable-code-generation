//FormAI DATASET v1.0 Category: Online Examination System ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int no_of_questions, i, answer, user_answer, score=0;
    clock_t start, end;
    double time_taken;

    printf("Welcome to the online C examination system!\n\n");
    printf("Enter the number of questions you want to attempt: ");
    scanf("%d",&no_of_questions);

    printf("\n");

    start = clock();

    for(i=1;i<=no_of_questions;i++)
    {
        switch(i)
        {
            case 1:
                printf("Question %d: The keyword 'break' is used in which statement?\n",i);
                printf("a) switch\nb) for loop\nc) do-while\nd) if-else\n"); 
                answer = 'a';
                break;

            case 2:
                printf("Question %d: Which of the following is NOT a data type in C?\n",i);
                printf("a) int\nb) float\nc) bool\nd) char\n");
                answer = 'c';
                break;

            case 3:
                printf("Question %d: What will be the output of the following code?\n",i);
                printf("int a = 10; float b = 10.5; printf(\"%d \\n\",a+b);\n");
                answer = 'a';
                printf("a) Compiler Error\nb) 20\nc) 10\n");
                break;

            case 4:
                printf("Question %d: What is the output of the following code?\n",i);
                printf("int i = 0; while(i<5)\n{\n   printf(\"%d \",i);\n   i++;\n}\n");
                answer = 'd';
                printf("a) 0 1 2 3\nb) 0 1 2 3 4\nc) 1 2 3 4 5\n");
                break;

            case 5:
                printf("Question %d: Which of the following is not a logical operator in C?\n",i);
                printf("a) &&\nb) !\nc) &\nd) ||\n");
                answer = 'c';
                break;

            default:
                printf("Error: Invalid question number!\n");
                exit(0);
        }

        printf("Please enter your answer: ");
        scanf(" %c",&user_answer);

        if(answer == user_answer)
        {
            printf("That's the correct answer!\n\n");
            score++;
        }

        else
        {
            printf("Oops, that's the wrong answer!\n\n");
        }
    }

    end = clock();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Congratulations! You have completed the examination.\n\n");
    printf("Your score is %d/%d\n\n",score,no_of_questions);
    printf("Time taken: %lf seconds\n\n",time_taken);

    return 0;
}