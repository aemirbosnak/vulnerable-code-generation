//FormAI DATASET v1.0 Category: Online Examination System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the student's information
typedef struct {
    char name[50];
    int roll;
} Student;

// Define the questions and correct answers
char questions[5][200] = {
    "What is the capital of India?",
    "How many states are there in India?",
    "What is the national animal of India?",
    "Who is the current Prime Minister of India?",
    "What is the national language of India?"
};
char answers[5][50] = {
    "New Delhi",
    "28",
    "Tiger",
    "Narendra Modi",
    "Hindi"
};

// Define the main function
int main() {
    
    // Initialize the variables required
    Student student;
    int i, j, marks = 0;
    char answer[50];
    
    printf("\nWelcome to the Online Examination System!\n");
    
    // Ask the student's name
    printf("\nEnter your name: ");
    scanf("%[^\n]", student.name);
    
    // Ask the student's roll number
    printf("Enter your roll number: ");
    scanf("%d", &student.roll);
    
    // Display the instructions for the exam
    printf("\nWelcome %s (Roll Number: %d)!\n\n", student.name, student.roll);
    printf("Instructions:\n");
    printf(" - The exam has 5 multiple choice questions.\n");
    printf(" - Each question has only one correct answer.\n");
    printf(" - You will be awarded 2 marks for each correct answer.\n");
    printf(" - There is no negative marking for incorrect answers.\n");
    printf(" - Good luck and have fun!\n\n");
    
    // Start the exam
    for(i=0; i<5; i++) {
        printf("%d. %s\n", i+1, questions[i]);
        printf("   Enter your answer: ");
        scanf("%s", answer);
        if(strcmp(answer, answers[i]) == 0) {
            marks += 2;
        }
    }
    
    // Display the results
    printf("\nYour total marks: %d\n", marks);
    if(marks >= 8) {
        printf("Congratulations %s! You have passed the exam!\n", student.name);
    } else {
        printf("Sorry %s, you have failed the exam. Better luck next time!\n", student.name);
    }
    
    return 0;
}