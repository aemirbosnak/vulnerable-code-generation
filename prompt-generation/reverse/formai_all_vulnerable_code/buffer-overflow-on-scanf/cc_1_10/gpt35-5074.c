//FormAI DATASET v1.0 Category: Online Examination System ; Style: automated
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define maximum number of questions
#define MAX_QUESTIONS 100

// Define structure for question
struct Question{
    int id;
    char question[500];
    char option1[50];
    char option2[50];
    char option3[50];
    char option4[50];
    int correct_ans;
};

// Define function to get user input for question
int get_question_input(struct Question *ques){

    // Get id of the question
    printf("Enter question ID: ");
    scanf("%d", &ques->id);

    // Get the question itself
    printf("\nEnter question: ");
    getchar();
    fgets(ques->question, 500, stdin);

    // Get the options for the question
    printf("\nEnter option 1: ");
    fgets(ques->option1, 50, stdin);
    printf("Enter option 2: ");
    fgets(ques->option2, 50, stdin);
    printf("Enter option 3: ");
    fgets(ques->option3, 50, stdin);
    printf("Enter option 4: ");
    fgets(ques->option4, 50, stdin);

    // Get the correct answer for the question
    printf("\nEnter correct answer (1-4): ");
    scanf("%d", &ques->correct_ans);

    return 0;
}

// Define function to print question
int print_question(struct Question ques){

    // Print id and question
    printf("%d. %s", ques.id, ques.question);

    // Print options
    printf("1. %s2. %s3. %s4. %s",ques.option1, ques.option2, ques.option3, ques.option4);

    return 0;
}

int main(){

    // Define array of questions
    struct Question question_array[MAX_QUESTIONS]; 

    // Define variable to keep track of number of questions
    int num_of_questions = 0;

    // Define choice variable for menu
    int choice;

    do{
        // Print main menu
        printf("\n\nOnline Examination System\n");
        printf("*************************\n");
        printf("1. Add New Question\n");
        printf("2. View All Questions\n");
        printf("3. Search Question by ID\n");
        printf("4. Exit\n");

        // Get user's choice
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                // Add new question
                printf("\nAdd New Question\n");
                struct Question new_question;
                get_question_input(&new_question);
                question_array[num_of_questions] = new_question;
                num_of_questions++;
                printf("\nQuestion added successfully!\n");
                break;
            case 2:
                // View all questions
                printf("\nView All Questions\n");
                for(int i=0;i<num_of_questions;i++){
                    print_question(question_array[i]);
                }
                break;
            case 3:
                // Search question by ID
                printf("\nSearch Question by ID\n");
                int search_id;
                printf("Enter question ID: ");
                scanf("%d", &search_id);
                for(int i=0;i<num_of_questions;i++){
                    if(question_array[i].id == search_id){
                        print_question(question_array[i]);
                    }
                }
                break;
            case 4:
                // Exit
                printf("\nGoodbye!");
                break;
            default:
                printf("\nInvalid choice! Please choose again.");
                break;
        }
    }while(choice != 4);

    return 0;
}