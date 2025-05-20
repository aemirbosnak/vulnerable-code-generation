//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of questions and options
#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4

// Define the structure of a question
typedef struct {
    char question[100];
    char options[MAX_OPTIONS][100];
    int answer;
} Question;

// Define the structure of a student
typedef struct {
    char name[100];
    int score;
} Student;

// Function to read questions from a file
void readQuestions(char* filename, Question* questions) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        exit(1);
    }
    int count = 0;
    while (fscanf(file, "%s", questions[count].question)!= EOF) {
        questions[count].answer = 0;
        int optionCount = 0;
        while (fscanf(file, "%s", questions[count].options[optionCount])!= EOF) {
            optionCount++;
            if (optionCount >= MAX_OPTIONS) {
                break;
            }
        }
        count++;
        if (count >= MAX_QUESTIONS) {
            break;
        }
    }
    fclose(file);
}

// Function to evaluate a student's answer
int evaluateAnswer(Question* question, int answer) {
    if (answer == question->answer) {
        return 1;
    } else {
        return 0;
    }
}

// Function to print a question
void printQuestion(Question* question) {
    printf("%s\n", question->question);
    for (int i = 0; i < MAX_OPTIONS; i++) {
        if (question->options[i][0]!= '\0') {
            printf("%d. %s\n", i+1, question->options[i]);
        }
    }
}

// Function to conduct the exam
void exam(Question* questions, int numQuestions, Student* students, int numStudents) {
    int correctAnswers = 0;
    for (int i = 0; i < numQuestions; i++) {
        for (int j = 0; j < numStudents; j++) {
            printf("Student %d's answer for question %d: ", j+1, i+1);
            scanf("%d", &students[j].score);
            if (evaluateAnswer(&questions[i], students[j].score)) {
                correctAnswers++;
            }
        }
    }
    printf("Total correct answers: %d\n", correctAnswers);
}

// Main function
int main() {
    Question questions[MAX_QUESTIONS];
    readQuestions("questions.txt", questions);
    int numQuestions = 0;
    while (questions[numQuestions].question[0]!= '\0') {
        numQuestions++;
        if (numQuestions >= MAX_QUESTIONS) {
            break;
        }
    }
    Student students[MAX_QUESTIONS];
    for (int i = 0; i < numQuestions; i++) {
        strcpy(students[i].name, "Student");
        sprintf(&students[i].name[7], "%d", i+1);
        students[i].score = 0;
    }
    exam(questions, numQuestions, students, numQuestions);
    return 0;
}