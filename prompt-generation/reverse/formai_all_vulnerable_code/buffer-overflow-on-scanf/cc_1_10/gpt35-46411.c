//FormAI DATASET v1.0 Category: Online Examination System ; Style: light-weight
#include <stdio.h>

#define MAX_QUESTIONS 10
#define MAX_OPTIONS 4

/* defining structure variables */
struct question {
    char text[100];
    char options[MAX_OPTIONS][100];
    int correct_option;
};

/* global variables */
struct question questions[MAX_QUESTIONS];
int total_questions;

/* function prototypes */
void add_question();
void display_all_questions();
void quiz();

int main() {
    int choice;
    
    do {
        printf("\n--MENU--\n");
        printf("1. Add question\n");
        printf("2. Display all questions\n");
        printf("3. Start quiz\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                add_question();
                break;
            case 2:
                display_all_questions();
                break;
            case 3:
                quiz();
                break;
            case 4:
                printf("Thank you for using the program!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 4);
    
    return 0;
}

/* function to add a new question */
void add_question() {
    if (total_questions == MAX_QUESTIONS) {
        printf("Cannot add more questions!\n");
        return;
    }
    
    struct question new_question;
    
    printf("Enter question text: ");
    scanf(" %[^\n]s", new_question.text);
    
    printf("Enter option 1: ");
    scanf(" %[^\n]s", new_question.options[0]);
    
    printf("Enter option 2: ");
    scanf(" %[^\n]s", new_question.options[1]);
    
    printf("Enter option 3: ");
    scanf(" %[^\n]s", new_question.options[2]);
    
    printf("Enter option 4: ");
    scanf(" %[^\n]s", new_question.options[3]);
    
    printf("Enter correct option (1-4): ");
    scanf("%d", &new_question.correct_option);
    
    questions[total_questions] = new_question;
    total_questions++;
    
    printf("Question added successfully!\n");
}

/* function to display all questions */
void display_all_questions() {
    if (total_questions == 0) {
        printf("No questions added!\n");
        return;
    }
    
    printf("\n--List of Questions--\n");
    for (int i = 0; i < total_questions; i++) {
        printf("%d. %s\n", i+1, questions[i].text);
        printf("    1. %s\n", questions[i].options[0]);
        printf("    2. %s\n", questions[i].options[1]);
        printf("    3. %s\n", questions[i].options[2]);
        printf("    4. %s\n", questions[i].options[3]);
    }
}

/* function to start quiz */
void quiz() {
    if (total_questions < 5) {
        printf("Not enough questions to start quiz!\n");
        return;
    }
    
    int score = 0;
    
    printf("\n--Quiz started--\n");
    for (int i = 0; i < 5; i++) {
        int rnd = rand() % total_questions;
        
        printf("Question %d: %s\n", i+1, questions[rnd].text);
        printf("1. %s\n", questions[rnd].options[0]);
        printf("2. %s\n", questions[rnd].options[1]);
        printf("3. %s\n", questions[rnd].options[2]);
        printf("4. %s\n", questions[rnd].options[3]);
        
        int choice;
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        
        if (choice == questions[rnd].correct_option) {
            printf("Correct answer!\n");
            score++;
        } else {
            printf("Incorrect answer! The correct answer is %d. %s\n", questions[rnd].correct_option, questions[rnd].options[questions[rnd].correct_option-1]);
        }
    }
    
    printf("\n--Quiz ended--\n");
    printf("Your score: %d/5\n", score);
}