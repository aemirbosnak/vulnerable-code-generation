//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ELEMENTS 118
#define MAX_NAME_LEN 25

typedef struct element {
    int atomicNumber;
    char symbol[3];
    char name[MAX_NAME_LEN];
    char classification[20];
    float atomicMass;
} Element;

void loadElements(Element elements[]);
void printPeriodicTable(Element elements[]);
int takeQuiz(Element elements[]);

int main() {
    Element elements[MAX_ELEMENTS];
    loadElements(elements);
    int choice;
    do {
        printf("Welcome to the Periodic Table Quiz!\n");
        printf("1. Learn about the Periodic Table\n");
        printf("2. Take the Quiz\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printPeriodicTable(elements);
                break;
            case 2:
                takeQuiz(elements);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);
    return 0;
}

void loadElements(Element elements[]) {
    FILE *fp;
    fp = fopen("elements.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        fscanf(fp, "%d %s %[^\n] %s %f", &elements[i].atomicNumber, elements[i].symbol, elements[i].name, elements[i].classification, &elements[i].atomicMass);
    }
    fclose(fp);
}

void printPeriodicTable(Element elements[]) {
    printf("------------------------------------------------------\n");
    printf("| Atomic | Symbol |         Name         | Classification | Atomic |\n");
    printf("| Number |        |                     |                |  Mass  |\n");
    printf("------------------------------------------------------\n");
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        printf("|   %3d   |   %2s   | %-20s |  %-12s  | %5.2f  |\n", elements[i].atomicNumber, elements[i].symbol, elements[i].name, elements[i].classification, elements[i].atomicMass);
    }
    printf("------------------------------------------------------\n");
}

int takeQuiz(Element elements[]) {
    char answer[MAX_NAME_LEN];
    int numCorrect = 0;
    int numIncorrect = 0;
    int numSkipped = 0;
    int numQuestions = 0;
    int quizType;
    printf("What type of quiz do you want to take?\n");
    printf("1. Identify element based on symbol\n");
    printf("2. Identify element based on name\n");
    printf("Enter your choice: ");
    scanf("%d", &quizType);
    if (quizType != 1 && quizType != 2) {
        printf("Invalid choice. Quiz cancelled.\n");
        return 0;
    }
    printf("How many questions do you want to answer? (1-%d): ", MAX_ELEMENTS);
    scanf("%d", &numQuestions);
    if (numQuestions < 1 || numQuestions > MAX_ELEMENTS) {
        printf("Invalid number of questions. Quiz cancelled.\n");
        return 0;
    }
    for (int i = 0; i < numQuestions; i++) {
        int randNum = rand() % MAX_ELEMENTS;
        Element e = elements[randNum];
        char* question;
        char* answerString;
        if (quizType == 1) {
            question = e.symbol;
            answerString = e.name;
        } else {
            question = e.name;
            answerString = e.symbol;
        }
        printf("Question %d: What is the %s of the element with atomic number %d?\n", i+1, quizType == 1 ? "name" : "symbol", e.atomicNumber);
        printf("You have 10 seconds to answer.\n");
        printf("%s: ", question);
        fflush(stdout);
        char* res = fgets(answer, sizeof answer, stdin);
        if (res == NULL) {
            // fgets() failed, so let's try again
            printf("Error reading input. Please try again.\n");
            i--;
            continue;
        }
        // Remove any trailing newline character
        answer[strcspn(answer, "\n")] = '\0';
        // Convert answer to uppercase
        for (int i = 0; i < strlen(answer); i++) {
            answer[i] = toupper(answer[i]);
        }
        if (strcmp(answer, answerString) == 0) {
            printf("Correct!\n");
            numCorrect++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", answerString);
            numIncorrect++;
        }
    }
    printf("Quiz complete!\n");
    printf("Number correct: %d\n", numCorrect);
    printf("Number incorrect: %d\n", numIncorrect);
    printf("Number skipped: %d\n", numSkipped);
    return 1;
}