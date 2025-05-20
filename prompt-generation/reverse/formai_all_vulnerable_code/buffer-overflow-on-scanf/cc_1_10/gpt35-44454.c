//FormAI DATASET v1.0 Category: Online Examination System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct question {
    char question[100];
    char optionA[50];
    char optionB[50];
    char optionC[50];
    char optionD[50];
    char correctAnswer;
};

struct student {
    char name[50];
    int score;
};

void displayInstructions();
int displayMenu();
void addQuestionsToFile();
void takeExamFromFile();
void printResults(struct student[], int);

int main() {
    displayInstructions();
    int choice = displayMenu();
    switch(choice) {
        case 1:
            addQuestionsToFile();
            break;
        case 2:
            takeExamFromFile();
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}

void displayInstructions() {
    printf("\t\t\t---------------------------\n");
    printf("\t\t\t RETRO STYLE ONLINE EXAMINATION SYSTEM\n");
    printf("\t\t\t---------------------------\n\n");

    printf("Welcome to the Retro Style Online Examination System!\n");
    printf("In this program, you can either add questions to the question bank or take an exam from the existing question bank.\n\n");
}

int displayMenu() {
    int choice;
    printf("Please choose from the following options:\n");
    printf("1. Add questions to the question bank\n");
    printf("2. Take an exam\n");
    printf("Your choice: ");

    scanf("%d", &choice);
    printf("\n");

    return choice;
}

void addQuestionsToFile() {
    FILE *fp;

    fp = fopen("questions.txt", "a");
    if(fp == NULL) {
        perror("Error opening file.");
        exit(1);
    }

    struct question q;
    char input;
    do {
        printf("Enter the question: ");
        getchar();
        fgets(q.question, 100, stdin);

        printf("Enter option A: ");
        fgets(q.optionA, 50, stdin);

        printf("Enter option B: ");
        fgets(q.optionB, 50, stdin);

        printf("Enter option C: ");
        fgets(q.optionC, 50, stdin);

        printf("Enter option D: ");
        fgets(q.optionD, 50, stdin);

        printf("Enter the correct answer (A, B, C, D): ");
        scanf("%c", &q.correctAnswer);

        fwrite(&q, sizeof(struct question), 1, fp);

        printf("\nDo you want to add another question? (Y/N) ");
        getchar();
        scanf("%c", &input);
        printf("\n");
    } while(input == 'Y' || input == 'y');

    fclose(fp);
}

void takeExamFromFile() {
    FILE *fp;
    int totalQuestions = 0;
    struct question q;
    struct student students[50];
    int studentCount = 0;

    fp = fopen("questions.txt", "r");
    if(fp == NULL) {
        perror("Error opening file.");
        exit(1);
    }

    while(fread(&q, sizeof(struct question), 1, fp) == 1) {
        printf("Question %d\n", totalQuestions+1);
        printf("%s", q.question);
        printf("A) %s", q.optionA);
        printf("B) %s", q.optionB);
        printf("C) %s", q.optionC);
        printf("D) %s", q.optionD);

        char answer;
        printf("Your answer (A, B, C, D): ");
        scanf("%c", &answer);
        getchar();

        if(answer == q.correctAnswer) {
            students[studentCount].score += 1;
        }

        totalQuestions++;
    }

    printf("You have answered %d out of %d questions correctly!\n", students[studentCount].score, totalQuestions);
    studentCount++;

    printResults(students, totalQuestions);
    fclose(fp);
}

void printResults(struct student students[], int totalQuestions) {
    printf("------------------------------------------------------\n");
    printf("Results\n");
    printf("------------------------------------------------------\n");
    for(int i=0; i<totalQuestions; i++) {
        printf("%s: %d/%d\n", students[i].name, students[i].score, totalQuestions);
    }
    printf("------------------------------------------------------\n");
}