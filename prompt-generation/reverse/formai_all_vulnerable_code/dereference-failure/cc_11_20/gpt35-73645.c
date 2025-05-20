//FormAI DATASET v1.0 Category: Online Examination System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declare variables
    int numQuestions, numOptions, numCorrectAnswers;
    char examTitle[50];
    
    // Get exam details from user
    printf("Enter Exam Title: ");
    scanf("%s", examTitle);
    printf("\nEnter Number of Questions: ");
    scanf("%d", &numQuestions);
    printf("\nEnter Number of Options per Question: ");
    scanf("%d", &numOptions);
    printf("\nEnter Number of Correct Answers per Question: ");
    scanf("%d", &numCorrectAnswers);
    
    // Create exam array dynamically
    int** exam = (int**)malloc(numQuestions * sizeof(int*));
    for(int i = 0; i < numQuestions; i++){
        exam[i] = (int*)malloc(numOptions * sizeof(int));
    }
    
    // Fill exam array with random digit answers
    for(int i = 0; i < numQuestions; i++){
        for(int j = 0; j < numOptions; j++){
            exam[i][j] = rand()%10;
        }
    }
    
    // Print exam title and questions with options
    printf("\n\n%s\n\n", examTitle);
    for(int i = 0; i < numQuestions; i++){
        printf("%d. ", i+1);
        for(int j = 0; j < numOptions; j++){
            printf("%d ", exam[i][j]);
        }
        printf("\n\n");
    }
    
    // Create answer array dynamically
    int* answers = (int*)malloc(numQuestions * sizeof(int));
    
    // Get answers from user
    for(int i = 0; i < numQuestions; i++){
        printf("Enter Answer for Question %d: ", i+1);
        scanf("%d", &answers[i]);
    }
    
    // Check answers and give result
    int correctAnswers = 0;
    for(int i = 0; i < numQuestions; i++){
        int count = 0;
        for(int j = 0; j < numOptions; j++){
            if(exam[i][j] == answers[i]){
                count++;
            }
        }
        if(count == numCorrectAnswers){
            correctAnswers++;
        }
    }
    printf("\n\nResult: %d/%d", correctAnswers, numQuestions);
    
    // Free dynamically allocated memory
    for(int i = 0; i < numQuestions; i++){
        free(exam[i]);
    }
    free(answers);
    free(exam);
    
    return 0;
}