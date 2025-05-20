//FormAI DATASET v1.0 Category: Online Examination System ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define structure to hold Question and its option values
typedef struct Question{
    char* question; // Question string
    char* options[4]; // Array of options
    int answer; // Correct answer index (e.g, 1 for Option A, 2 for Option B, etc)
 } Question;

// Define function to print questions and options
void print_question(Question q, int index) {
    printf("\n%d. %s\n", index, q.question);
    printf("A. %s\n", q.options[0]);
    printf("B. %s\n", q.options[1]);
    printf("C. %s\n", q.options[2]);
    printf("D. %s\n", q.options[3]);
}

int main() {
    int num_questions = 5; // Total Number of questions
    int correct_answers = 0; // Count of Correct Answers
    char choice[2];
    
    // Array to store all questions with their options
    Question questions[5] = {
        {
            "What is the output of 4 + 5?", {"9", "10", "11", "12"}, 1
        },
        {
            "What is the output of 4 * 5?", {"15", "20", "25", "30"}, 2
        },
        {
            "Which is the largest planet in our solar system?", {"Mars", "Jupiter", "Venus", "Mercury"}, 1
        },
        {
            "What is the capital of India?", {"New Delhi", "Mumbai", "Kolkata", "Chennai"}, 0
        },
        {
            "Who is the current Prime Minister of India?", {"Narendra Modi", "Manmohan Singh", "Rahul Gandhi", "Sonia Gandhi"}, 0
        }
    };
    
    //Welcome the user to Exam
    printf("Welcome to our C Programming online exam system\n");
    
    //Provide user with Exam Rules
    printf("Instructions:\n");
    printf("- You will be presented with %d multiple choice questions.\n", num_questions);
    printf("- Select the correct answer (A/B/C/D) and press Enter to submit.\n");
    printf("- Your score will be displayed at the end of the exam.\n");
    printf("- Good Luck!\n");
    
    //Start the Exam loop
    for(int i=0;i<num_questions;i++) {
        printf("\nQuestion %d\n", i+1);
        print_question(questions[i], i+1);
        printf("Your answer: ");
        scanf("%s", choice);
        if(strcmp(choice, "A") == 0 && questions[i].answer == 0) {
            printf("Correct!");
            correct_answers++;
        } else if(strcmp(choice, "B") == 0 && questions[i].answer == 1) {
            printf("Correct!");
            correct_answers++;
        } else if(strcmp(choice, "C") == 0 && questions[i].answer == 2) {
            printf("Correct!");
            correct_answers++;
        } else if(strcmp(choice, "D") == 0 && questions[i].answer == 3) {
            printf("Correct!");
            correct_answers++;
        } else {
            printf("Incorrect.");
        }
    }
    
    //Display Exam Result
    printf("\nThank you for taking this exam. Here is your score:\n");
    int percentage = (correct_answers * 100) / num_questions;
    printf("Total Questions: %d\n", num_questions);
    printf("Correct Answers: %d\n", correct_answers);
    printf("Percentage Score: %d%%\n", percentage);
    
    return 0;
}