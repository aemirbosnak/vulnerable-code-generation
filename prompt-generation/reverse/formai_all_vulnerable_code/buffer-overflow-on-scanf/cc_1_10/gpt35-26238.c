//FormAI DATASET v1.0 Category: Online Examination System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for questions
struct question {
    char question_text[100];
    char option1[50];
    char option2[50];
    char option3[50];
    char option4[50];
    int correct_option;
};

// Function to display menu options
void display_menu() {
    printf("Welcome to the Medieval Online Examination System!\n");
    printf("1. Take the Exam\n");
    printf("2. View Exam Results\n");
    printf("3. Exit\n");
}

int main() {
    // Creating a file pointer for exam questions
    FILE *fp;
    fp = fopen("exam_questions.txt", "r");

    // If file is not opened, terminate program
    if(fp == NULL) {
        printf("Error in opening the file.\n");
        exit(1);
    }

    // Creating an array of questions
    struct question q[10];
    int q_index = 0, option, answer, score = 0;

    // Reading questions from file and storing them in the array
    while(!feof(fp)) {
        fscanf(fp, "%[^\n]%*c", q[q_index].question_text);
        fscanf(fp, "%s", q[q_index].option1);
        fscanf(fp, "%s", q[q_index].option2);
        fscanf(fp, "%s", q[q_index].option3);
        fscanf(fp, "%s", q[q_index].option4);
        fscanf(fp, "%d", &q[q_index].correct_option);
        q_index++;
    }
    fclose(fp); // Closing the file pointer

    // Loop to display menu and perform actions based on user choice
    while(1) {
        display_menu();
        printf("Enter your option: ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                printf("\n--- Starting Exam ---\n");

                // Loop to display each question and record user's answer
                for(int i=0;i<10;i++) {
                    printf("\nQ%d. %s\n", i+1, q[i].question_text);
                    printf("1. %s\n", q[i].option1);
                    printf("2. %s\n", q[i].option2);
                    printf("3. %s\n", q[i].option3);
                    printf("4. %s\n", q[i].option4);
                    printf("Enter your answer: ");
                    scanf("%d", &answer);

                    // Checking if answer is correct
                    if(answer == q[i].correct_option) {
                        printf("Correct Answer!\n");
                        score++;
                    } else {
                        printf("Incorrect Answer! The correct answer is option %d\n", q[i].correct_option);
                    }
                }
                printf("\n--- Exam Finished ---\n");
                printf("Your score is %d/10\n", score);
                break;
            case 2:
                printf("\n--- Viewing Exam Results ---\n");

                // Showing user's score and correct answers for each questions
                for(int i=0;i<10;i++) {
                    printf("\nQ%d. %s\n", i+1, q[i].question_text);
                    printf("1. %s\n", q[i].option1);
                    printf("2. %s\n", q[i].option2);
                    printf("3. %s\n", q[i].option3);
                    printf("4. %s\n", q[i].option4);
                    printf("Correct answer: %d\n", q[i].correct_option);
                }
                printf("\n--- End of Results ---\n");
                break;
            case 3:
                printf("\n--- Exiting Program ---\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}