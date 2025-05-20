//FormAI DATASET v1.0 Category: Online Examination System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for questions
typedef struct {
    char question[1000];
    char answer1[100];
    char answer2[100];
    char answer3[100];
    char answer4[100];
    int correct_answer;
} Question;

// Function to display and validate menu choices
int display_menu() {
    int choice;
    printf("Welcome to the Online Examination System!\n");
    printf("1. Take Exam\n");
    printf("2. Add Question\n");
    printf("3. Exit\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);
    
    // Validate input
    while(choice < 1 || choice > 3) {
        printf("Invalid choice! Please enter a valid choice (1-3): ");
        scanf("%d", &choice);
    }
    
    return choice;
}

// Function to take exam
void take_exam(Question *questions, int num_questions) {
    int score = 0;
    int answer;
    
    // Loop through each question and ask it
    for(int i = 0; i < num_questions; i++) {
        printf("\nQuestion %d: %s\n", i+1, questions[i].question);
        printf("1. %s\n", questions[i].answer1);
        printf("2. %s\n", questions[i].answer2);
        printf("3. %s\n", questions[i].answer3);
        printf("4. %s\n", questions[i].answer4);
        printf("Enter your answer (1-4): ");
        scanf("%d", &answer);
        
        // Validate input
        while(answer < 1 || answer > 4) {
            printf("Invalid choice! Please enter a valid choice (1-4): ");
            scanf("%d", &answer);
        }
        
        // Check if answer is correct
        if(answer == questions[i].correct_answer) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect! The correct answer is %d.\n", questions[i].correct_answer);
        }
    }
    
    // Display final score
    printf("\nYour final score is %d out of %d.\n\n", score, num_questions);
}

// Function to add question
void add_question(Question *questions, int *num_questions) {
    printf("Enter the question: ");
    getchar(); // Clear input buffer
    fgets(questions[*num_questions].question, 1000, stdin);
    
    printf("Enter answer 1: ");
    fgets(questions[*num_questions].answer1, 100, stdin);
    
    printf("Enter answer 2: ");
    fgets(questions[*num_questions].answer2, 100, stdin);
    
    printf("Enter answer 3: ");
    fgets(questions[*num_questions].answer3, 100, stdin);
    
    printf("Enter answer 4: ");
    fgets(questions[*num_questions].answer4, 100, stdin);
    
    printf("Enter the correct answer (1-4): ");
    scanf("%d", &questions[*num_questions].correct_answer);
    
    // Validate input
    while(questions[*num_questions].correct_answer < 1 || questions[*num_questions].correct_answer > 4) {
        printf("Invalid choice! Please enter a valid choice (1-4): ");
        scanf("%d", &questions[*num_questions].correct_answer);
    }
    
    printf("Question added successfully!\n");
    (*num_questions)++;
}

int main() {
    Question questions[100];
    int num_questions = 0;
    int choice;
    
    // Display menu and take action based on user choice
    do {
        choice = display_menu();
        
        switch(choice) {
            case 1:
                if(num_questions > 0) {
                    take_exam(questions, num_questions);
                } else {
                    printf("There are no questions in the system. Please add a question first.\n");
                }
                break;
            case 2:
                add_question(questions, &num_questions);
                break;
            case 3:
                printf("Exiting...\n");
                break;
        }
    } while(choice != 3);
    
    return 0;
}