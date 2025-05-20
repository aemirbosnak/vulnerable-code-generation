//FormAI DATASET v1.0 Category: Online Examination System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

int main() {
   int noOfQuestions, score = 0, currentAnswer;
   printf("Enter the number of questions in the examination system: ");
   scanf("%d", &noOfQuestions);
   
   // Creating an array for storing answers of each question
   int *answerSheet = (int *) malloc(sizeof(int) * noOfQuestions);
   
   // Taking input from user for each question and storing the correct answer in answerSheet array
   for(int i=0; i<noOfQuestions; i++)
   {
       printf("Enter the correct answer for question %d: ", i+1);
       scanf("%d", &answerSheet[i]);
   }
   
   // Starting the exam
   printf("\n\n---------- STARTING EXAMINATION SYSTEM --------\n\n");

   for(int i=0; i<noOfQuestions; i++)
   {
       printf("Question %d: \n", i+1);
       printf("What is the output of the following code snippet? \n\n");

       // Implementing the questions and code snippets
       switch (i+1)
       {
           case 1:
                printf("int x=3, y; \n");
                printf("y=++x; \n\n");
                printf("A. x=4, y=3 \nB. x=3, y=4 \nC. x=4, y=4 \nD. None of the above \n");
                currentAnswer = getchar() - 'A' + 1;
                getchar();
                break;
            
           case 2:
                printf("int arr[4]={1,2,3,4}; \n");
                printf("printf(\"%d\", *(arr+2)); \n\n");
                printf("A. 1 \nB. 2 \nC. 3 \nD. 4 \n");
                currentAnswer = getchar() - 'A' + 1;
                getchar();
                break;
                
           // Add more cases based on the exam questions 
           // NOTE: The code snippets should be related to C language only for this example
           
           default: 
                printf("Invalid question number. \n");
                currentAnswer = 0;
       }
       
       if(currentAnswer == answerSheet[i])
       {
           printf("Correct Answer! \n\n");
           score++;
       }
       else printf("Incorrect Answer! \n\n");
   }
   
   printf("Exam Completed. \n");
   printf("Your Score is %d out of %d. \n", score, noOfQuestions);
   free(answerSheet);
   return 0;
}