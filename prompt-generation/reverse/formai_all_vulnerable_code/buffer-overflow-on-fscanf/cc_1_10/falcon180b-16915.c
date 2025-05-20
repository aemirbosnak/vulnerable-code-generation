//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for each question
typedef struct {
    char question[100];
    char option1[50];
    char option2[50];
    char option3[50];
    char option4[50];
    char answer[10];
} Question;

// Function to read questions from a file and store them in an array
void readQuestions(Question questions[], int numQuestions, FILE *fp) {
    int i = 0;
    while (i < numQuestions && fscanf(fp, "%s %s %s %s %s", questions[i].question, questions[i].option1, questions[i].option2, questions[i].option3, questions[i].option4)!= EOF) {
        i++;
    }
    fclose(fp);
}

// Function to display a question and its options
void displayQuestion(Question question) {
    printf("%s\n", question.question);
    printf("A) %s\n", question.option1);
    printf("B) %s\n", question.option2);
    printf("C) %s\n", question.option3);
    printf("D) %s\n", question.option4);
}

// Function to check if the selected option is correct
int checkAnswer(char answer[], char correctAnswer[]) {
    if (strcmp(answer, correctAnswer) == 0) {
        return 1;
    } else {
        return 0;
    }
}

// Function to evaluate the score based on the number of correct answers
float evaluateScore(int numQuestions, int numCorrectAnswers) {
    return (float)numCorrectAnswers / numQuestions * 100;
}

int main() {
    int numQuestions, numCorrectAnswers = 0;
    Question questions[100];

    // Read questions from a file
    FILE *fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }
    readQuestions(questions, 10, fp);
    fclose(fp);

    // Display each question and its options
    for (int i = 0; i < 10; i++) {
        displayQuestion(questions[i]);
        char answer[10];
        scanf("%s", answer);

        // Check if the selected option is correct
        if (checkAnswer(answer, questions[i].answer)) {
            numCorrectAnswers++;
        }
    }

    // Evaluate the score
    float score = evaluateScore(10, numCorrectAnswers);
    printf("Your score is %.2f%%\n", score);

    return 0;
}