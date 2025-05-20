//FormAI DATASET v1.0 Category: Online Examination System ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

// Global Variables
char questions[10][1000]; // To hold 10 questions
char options[10][4][100]; // To hold 4 options for each question
char answers[10]; // To hold correct answer for each question
int marks[10]; // To hold marks for each question
int total_marks = 0; // Total marks of the exam
char student_answers[10]; // To hold student's answer for each question
int student_marks = 0; // Student's total marks

// Function to read questions and options from file
void readQuestionsFromFile() {
    FILE *fp = fopen("questions.txt", "r");
    if(fp == NULL) { // Check if file is opened successfully
        printf("Error opening file.\n");
        exit(1);
    }
    char line[1000];
    int question_number = 0;
    while(fgets(line, sizeof(line), fp)) {
        if(line[strlen(line)-1] == '\n') {
            line[strlen(line)-1] = '\0'; // Remove newline character
        }
        if(strlen(line) > 2 && line[1] == ')') { // This is option
            strcpy(options[question_number][(int)line[0]-65], line+3); // Store option
        } else { // This is question or answer or marks
            if(line[strlen(line)-1] == ':') { // This is marks
                marks[question_number] = atoi(line+1); // Store marks
                total_marks += marks[question_number]; // Keep track of total marks
            } else if(line[strlen(line)-1] == '?') { // This is question
                strcpy(questions[question_number], line+2); // Store question
            } else { // This is answer
                answers[question_number] = (char)toupper(line[0]); // Store answer
                question_number++;
            }
        }
    }
    fclose(fp);
}

// Function to display questions and options
void displayQuestions() {
    for(int i=0; i<10; i++) {
        printf("%d. %s (%d marks)\n", i+1, questions[i], marks[i]);
        for(int j=0; j<4; j++) {
            printf("%c) %s\n", 65+j, options[i][j]);
        }
    }
}

// Function to take student's answers
void takeStudentAnswers() {
    printf("Enter your answers:\n");
    for(int i=0; i<10; i++) {
        printf("%d. ", i+1);
        scanf(" %c", &student_answers[i]); // Store answer
        student_answers[i] = (char)toupper(student_answers[i]); // Convert to uppercase
    }
}

// Function to grade the exam
void gradeExam() {
    for(int i=0; i<10; i++) {
        if(answers[i] == student_answers[i]) { // Answer is correct
            student_marks += marks[i]; // Add marks
        }
    }
}

int main() {
    readQuestionsFromFile(); // Read questions and options from file
    printf("Welcome to the Online Examination System!\n");
    printf("You will have 10 questions to answer.\n");
    printf("Total marks: %d\n", total_marks);
    printf("Press any key to start the examination.\n");
    getchar(); // Wait for user to press key
    srand(time(NULL)); // Seed random number generator
    int delay = rand() % 11 + 20; // Generate random delay between 20 and 30 seconds
    printf("You have %d seconds to answer each question.\n", delay);
    for(int i=0; i<10; i++) {
        printf("Question %d:\n", i+1);
        printf("%s\n", questions[i]);
        for(int j=0; j<4; j++) {
            printf("%c) %s\n", 65+j, options[i][j]);
        }
        time_t start_time = time(NULL); // Get start time
        do {
            printf("Time remaining: %ld seconds. Answer: ", start_time+delay-time(NULL));
            scanf(" %c", &student_answers[i]); // Store answer
            student_answers[i] = (char)toupper(student_answers[i]); // Convert to uppercase
        } while(time(NULL) - start_time < delay); // Loop until time limit
    }
    gradeExam(); // Grade the exam
    printf("Total marks: %d\n", total_marks);
    printf("Your marks: %d/%d\n", student_marks, total_marks);
    return 0;
}