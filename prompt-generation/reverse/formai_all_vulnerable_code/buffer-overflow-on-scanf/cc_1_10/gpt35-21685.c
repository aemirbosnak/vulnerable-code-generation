//FormAI DATASET v1.0 Category: Online Examination System ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int i, j, score=0, choice, ans, correct=0, incorrect=0;
    char name[50];
    time_t t;
    srand((unsigned) time(&t));
    
    printf("Welcome to the Online Examination System!\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    
    printf("Welcome %s! This is a C programming assessment test consisting of 10 questions.\n", name);
    printf("Each question has 4 options, choose the correct option by entering a number from 1 to 4.\n");
    printf("Press 0 to begin the test: ");
    scanf("%d", &choice);
    
    if(choice == 0)
    {
        for(i=1; i<=10; i++)
        {
            printf("\n%d. ", i);
            switch(rand()%3)
            {
                case 0:
                    printf("What is the output of the following code?\n");
                    printf("\n#include<stdio.h>\n\nint main()\n{\n\tint a=4,b=5;\n\tprintf(\"%%d\", a+b);\n\treturn 0;\n}");
                    ans = 1;
                    printf("\n\n1. 9\n2. 45\n3. 405\n4. 20\n");
                    break;
                    
                case 1:
                    printf("Which of the following is not a storage class in C?\n");
                    ans = 4;
                    printf("\n1. auto\n2. register\n3. static\n4. allocate\n");
                    break;
                    
                case 2:
                    printf("What is the correct way to declare a pointer to an integer variable?\n");
                    ans = 3;
                    printf("\n1. int *a\n2. int a*\n3. int *a;\n4. a* int;\n");
                    break;
                    
                default:
                    printf("Error generating question. Please try again later.");
                    break;
            }
            scanf("%d", &j);
            if(j == ans)
            {
                printf("\nCorrect answer!\n");
                score += 10;
                correct++;
            }
            else
            {
                printf("\nIncorrect answer :(\n");
                incorrect++;
            }
        }
        printf("The test has ended. Your total score is %d out of 100.\n", score);
        printf("You answered %d questions correctly and %d questions incorrectly.\n", correct, incorrect);
    }
    else
        printf("Invalid choice. Please try again later.\n");
    
    return 0;
}