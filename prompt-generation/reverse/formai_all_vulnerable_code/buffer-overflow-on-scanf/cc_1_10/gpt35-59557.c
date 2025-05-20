//FormAI DATASET v1.0 Category: Online Examination System ; Style: decentralized
#include<stdio.h>

//Function for showing the Questions and Answers
void showQuestion(int qCount, char *question, char *optionA, char *optionB, char *optionC, char *optionD, char correctAns)
{
    printf("\n%d. %s\n", qCount, question);
    printf("A. %s\n", optionA);
    printf("B. %s\n", optionB);
    printf("C. %s\n", optionC);
    printf("D. %s\n", optionD);
}

//Function for checking the answers
void checkAnswer(char selected, char correctAns, int *score)
{
    if(selected == correctAns)
        {
            printf("\nCorrect Answer!\n");
            *score += 1;
        }
    else
        printf("\nWrong Answer!\n");
}

//Main function
int main()
{
    int totalScore = 0;
    int questionCount = 1;
    int optionCount = 1;
    char selectedOption;
    char correctAnswer;
    
    //Question 1
    showQuestion(questionCount, "What is the capital of India?", "Mumbai", "New Delhi", "Bangalore", "Chennai", 'B');
    printf("Enter your answer (A, B, C, or D): ");
    scanf(" %c", &selectedOption);
    checkAnswer(selectedOption, 'B', &totalScore);
    questionCount ++;
    
    //Question 2
    showQuestion(questionCount, "What is the highest mountain peak in the world?", "Mt. Everest", "Mt. Kilimanjaro", "Mt. Denali", "Mt. Aconcagua", 'A');
    printf("Enter your answer (A, B, C, or D): ");
    scanf(" %c", &selectedOption);
    checkAnswer(selectedOption, 'A', &totalScore);
    questionCount ++;
    
    //Question 3
    showQuestion(questionCount, "What is the scientific name for the human brain?", "Hippocampus", "Cerebellum", "Cerebrum", "Medulla Oblongata", 'C');
    printf("Enter your answer (A, B, C, or D): ");
    scanf(" %c", &selectedOption);
    checkAnswer(selectedOption, 'C', &totalScore);
    questionCount ++;

    //Outro
    printf("\nYour Total Score is: %d out of %d\n", totalScore, questionCount-1);
    return 0;
}