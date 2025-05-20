//FormAI DATASET v1.0 Category: Online Examination System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Welcome message
    printf("**********************************************\n");
    printf("*      Welcome to the C Online Exam System    *\n");
    printf("*         Are you ready to have some fun?     *\n");
    printf("**********************************************\n\n");
    
    // Get the student's name
    char name[50];
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("\nHello, %s! Let's get started with the exam!\n\n", name);
    
    // Set the random number seed
    srand(time(NULL));
    
    // Generate the questions
    int questions[10][2];
    for (int i = 0; i < 10; i++) {
        int a = rand() % 10 + 1;
        int b = rand() % 10 + 1;
        questions[i][0] = a;
        questions[i][1] = b;
    }
    
    // Give the instructions
    printf("Here are your instructions:\n");
    printf("- There are 10 questions in total.\n");
    printf("- Each question will contain two random numbers between 1 and 10.\n");
    printf("- You need to input the correct answer within 10 seconds.\n");
    printf("- You will get 1 point for correct answer, and 0 point for incorrect answer or timeout\n\n");
    
    // Start the exam
    int score = 0;
    for (int i = 0; i < 10; i++) {
        printf("Question %d: %d + %d = ", i+1, questions[i][0], questions[i][1]);
        fflush(stdout);
        
        // Set the timer
        time_t start_time = time(NULL);
        time_t cur_time = time(NULL);
        
        // Get the answer from the user
        int answer;
        scanf("%d", &answer);
        
        // Calculate the time taken
        while (answer != questions[i][0] + questions[i][1] && difftime(cur_time, start_time) < 10) {
            printf("Wrong answer! Please try again: ");
            fflush(stdout);
            scanf("%d", &answer);
            cur_time = time(NULL);
        }
        
        // Check if the answer is correct and increment the score
        if (answer == questions[i][0] + questions[i][1]) {
            printf("Correct! You get 1 point.\n");
            score++;
        } else {
            printf("Time's up! You get 0 point.\n");
        }
    }
    
    // Display the results
    printf("\n\n**********************************************\n");
    printf("*          Congratulations, %s!              *\n", name);
    printf("*      You have completed the exam!           *\n");
    printf("*             Your final score is:            *\n");
    printf("*                    %d/10                     *\n", score);
    printf("**********************************************\n\n");
    
    // Get the grade
    char grade;
    switch(score) {
        case 10:
        case 9:
            grade = 'A';
            break;
        case 8:
            grade = 'B';
            break;
        case 7:
            grade = 'C';
            break;
        case 6:
            grade = 'D';
            break;
        default:
            grade = 'F';
            break;
    }
    
    printf("Your grade is: %c\n\n", grade);
    
    return 0;
}