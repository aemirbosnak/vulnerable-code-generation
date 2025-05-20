//FormAI DATASET v1.0 Category: Online Examination System ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Function to generate random questions
char* generate_question()
{
    char* questions[5] = {"What is the capital of France?", "Who is the founder of Tesla Motors?", "What is the square root of 144?", "What is the official language of Brazil?", "What is the name of the world's largest desert?"};
    srand(time(NULL));
    int index = rand() % 5;
    return questions[index];
}

//Function to check if the answer is correct
int check_answer(char* q, char* a)
{
    char* answers[5] = {"Paris", "Elon Musk", "12", "Portuguese", "Sahara"};
    for(int i=0; i<5; i++)
    {
        if(strcmp(q, answers[i]) == 0)
        {
            if(strcmp(a, answers[i]) == 0)
                return 1;
            else
                return 0;
        }
    }
    return -1;
}

//Main function
int main()
{
    char name[50], answer[50], choice;
    int score = 0, total_questions = 5, result;
    
    printf("Welcome to the Online Examination System!\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Hello, %s! Are you ready to take the test? (y/n): ", name);
    scanf(" %c", &choice);
    
    if(choice == 'y' || choice == 'Y')
    {
        printf("\n---Instructions---\n");
        printf("1. There will be 5 multiple choice questions.\n");
        printf("2. Each question carries 1 mark.\n");
        printf("3. There is no time limit.\n");
        printf("4. Type the answer and press enter to submit.\n");
        printf("\nPress enter to start the test...");
        getchar();
        
        for(int i=1; i<=total_questions; i++)
        {
            printf("\nQuestion %d: %s\n", i, generate_question());
            printf("Answer: ");
            scanf("%s", answer);
            
            result = check_answer(generate_question(), answer);
            
            if(result == 1)
            {
                score++;
                printf("Correct answer!\n");
            }
            else if(result == 0)
                printf("Incorrect answer!\n");
            else
                printf("Error: answer not found!\n");
        }
        
        printf("\n---Result---\n");
        printf("Name: %s\n", name);
        printf("Score: %d/%d\n", score, total_questions);
        printf("Thank you for taking the test!\n");
    }
    else
    {
        printf("\nGoodbye, %s!\n", name);
    }
    
    return 0;
}