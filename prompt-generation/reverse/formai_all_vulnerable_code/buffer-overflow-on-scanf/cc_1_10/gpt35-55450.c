//FormAI DATASET v1.0 Category: Online Examination System ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//function to shuffle the questions 
void shuffle(int arr[], int n) 
{ 
    srand(time(NULL)); 

    for (int i = n - 1; i > 0; i--) 
    { 
        int j = rand() % (i + 1); 
        int temp = arr[i]; 
        arr[i] = arr[j]; 
        arr[j] = temp; 
    } 
}

//main function
int main()
{
    int q_count = 5;
    int q_numbers[q_count];
    int score = 0;
    char answer;

    printf("Welcome to the Online C Examination System. You will be given 5 multiple choice questions. \n");

    for (int i = 0; i < q_count; i++)
    {
        q_numbers[i] = i+1;
    }

    shuffle(q_numbers, q_count);
    
    for (int i = 0; i < q_count; i++)
    {
        if(q_numbers[i] == 1)
        {
            printf("\n\nWhat is the difference between a float and a double? \n");
            printf("A) They are the same \nB) Doubles are more precise than floats \nC) Floats are more precise than doubles \nD) Doubles can store larger values than floats \n");
            printf("Enter your answer: ");
            scanf(" %c", &answer);

            if(answer == 'D' || answer == 'd')
            {
                printf("Well done! That's correct.\n");
                score += 1;
            }
            else
            {
                printf("Sorry, the correct answer is D.\n");
            }
        }
        else if(q_numbers[i] == 2)
        {
            printf("\n\nWhat is the output of the following code? \n");
            printf("int a = 5; \nint b = 7; \nprintf(\"%%d\", a+b); \n");
            printf("A) 11 \nB) 12 \nC) 13 \nD) 14 \n");
            printf("Enter your answer: ");
            scanf(" %c", &answer);

            if(answer == 'A' || answer == 'a')
            {
                printf("Well done! That's correct.\n");
                score += 1;
            }
            else
            {
                printf("Sorry, the correct answer is A.\n");
            }
        }
        else if(q_numbers[i] == 3)
        {
            printf("\n\nWhat is the output of the following code? \n");
            printf("int a = 7; \nif(a > 5) \n{ \nprintf(\"Hello\"); \n} \nelse \n{ \nprintf(\"World\"); \n} \n");
            printf("A) Hello \nB) World \nC) Hello World \nD) None of the above \n");
            printf("Enter your answer: ");
            scanf(" %c", &answer);

            if(answer == 'A' || answer == 'a')
            {
                printf("Well done! That's correct.\n");
                score += 1;
            }
            else
            {
                printf("Sorry, the correct answer is A.\n");
            }
        }
        else if(q_numbers[i] == 4)
        {
            printf("\n\nWhat is the output of the following code? \n");
            printf("int i; \nfor(i = 0; i < 5; i++) \n{ \nprintf(\"%%d \", i); \n} \n");
            printf("A) 01234 \nB) 43210 \nC) 12345 \nD) None of the above \n");
            printf("Enter your answer: ");
            scanf(" %c", &answer);

            if(answer == 'C' || answer == 'c')
            {
                printf("Well done! That's correct.\n");
                score += 1;
            }
            else
            {
                printf("Sorry, the correct answer is C.\n");
            }
        }
        else if(q_numbers[i] == 5)
        {
            printf("\n\nWhat is the output of the following code? \n");
            printf("int a = 10, b = 20; \nprintf(\"The sum of %%d and %%d is %%d\", a, b, a+b); \n");
            printf("A) The sum of 10 and 20 is 30 \nB) The sum of a and b is ab \nC) The sum of 10 and 20 is ab \nD) None of the above \n");
            printf("Enter your answer: ");
            scanf(" %c", &answer);

            if(answer == 'A' || answer == 'a')
            {
                printf("Well done! That's correct.\n");
                score += 1;
            }
            else
            {
                printf("Sorry, the correct answer is A.\n");
            }
        }

        
    }

    printf("\n\nYour final score is %d out of %d.\n", score, q_count);

    return 0;

}