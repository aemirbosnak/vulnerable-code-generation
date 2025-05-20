//FormAI DATASET v1.0 Category: Online Examination System ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to generate random question set
int* generate_questions()
{
    static int questions[10];
    int i, random_num, flag;
    srand(time(NULL));
    // Generate 10 random numbers between 1 to 50 without repetition
    for(i=0; i<10; i++)
    {
        flag = 0;
        random_num = (rand() % 50) + 1;
        // Check if the number is already present in the set
        for(int j=0; j<i; j++)
        {
            if(random_num == questions[j])
            {
                flag = 1;
                break;
            }
        }
        if(flag == 1)
        {
            i--;
            continue;
        }
        questions[i] = random_num;
    }
    return questions;
}

int main()
{
    int* questions = NULL;
    int marks = 0, choice, answer;
    printf("\nWelcome to the Online Examination System!\n");
    printf("In the post-apocalyptic world, knowledge is power!\n");
    printf("You have 10 multiple choice questions to answer.\n");
    printf("Each correct answer will give you 10 points.\n");
    printf("Let's start the test!\n\n");
    
    questions = generate_questions();

    // Question 1
    printf("1) What is the capital city of Australia?\n");
    printf("a) Sydney\tb) Melbourne\tc) Canberra\td) Perth\n");
    printf("Enter your choice (a/b/c/d): ");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1: answer = 'c';
                marks += 10;
                break;
        default: printf("Wrong answer!\n");
                 break;
    }

    // Question 2
    printf("2) Which is the largest mammal in the world?\n");
    printf("a) Elephant\tb) Whale\t\tc) Rhino\td) Hippopotamus\n");
    printf("Enter your choice (a/b/c/d): ");
    scanf("%d", &choice);
    switch(choice)
    {
        case 2: answer = 'b';
                marks += 10;
                break;
        default: printf("Wrong answer!\n");
                 break;
    }
    // Question 3
    printf("3) Who wrote the book 'To Kill a Mockingbird'?\n");
    printf("a) Harper Lee\tb) J.K. Rowling\tc) Stephen King\td) Dan Brown\n");
    printf("Enter your choice (a/b/c/d): ");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1: answer = 'a';
                marks += 10;
                break;
        default: printf("Wrong answer!\n");
                 break;
    }

    // Rest of the questions follow the same format

    printf("\nCongratulations on completing the test!\n");
    printf("Your total score is %d out of 100.\n", marks);
    printf("Thanks for participating in this post-apocalyptic knowledge test!\n");

    return 0;
}