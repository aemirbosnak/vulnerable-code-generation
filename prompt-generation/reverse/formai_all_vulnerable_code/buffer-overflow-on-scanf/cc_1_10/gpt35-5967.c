//FormAI DATASET v1.0 Category: Online Examination System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the exam
typedef struct Exam {
    int id;
    char name[50];
    float score;
} Exam;

// Define the function to get input for the exam
Exam get_exam_input() {
    Exam exam;
    printf("Enter exam details -\n");
    printf("ID: ");
    scanf("%d", &exam.id);
    printf("Name: ");
    scanf("%s", exam.name);
    printf("Score: ");
    scanf("%f", &exam.score);
    return exam;
}

// Define the function to display the exam details
void display_exam_details(Exam exam) {
    printf("Exam Details -\n");
    printf("ID: %d\n", exam.id);
    printf("Name: %s\n", exam.name);
    printf("Score: %.2f\n", exam.score);
}

// Define the main function
int main() {
    int n, i;
    printf("Welcome to the Online Examination System!\n");
    printf("How many exams do you want to input? ");
    scanf("%d", &n);

    // Initialize the array of exams
    Exam exams[n];

    // Loop through and get input for each exam
    for(i = 0; i < n; i++) {
        exams[i] = get_exam_input();
    }

    // Display the details for each exam
    for(i = 0; i < n; i++) {
        display_exam_details(exams[i]);
    }

    printf("Thank you for using the Online Examination System!\n");

    return 0;
}