//FormAI DATASET v1.0 Category: Online Examination System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_QUESTION_LENGTH 200
#define MAX_NAME_LENGTH 50

typedef struct {
    char question[MAX_QUESTION_LENGTH];
    char options[MAX_OPTIONS][MAX_QUESTION_LENGTH];
    char correctOption;
} Question;

Question questions[MAX_QUESTIONS];
int questionCount = 0;

void createQuestion() {
    Question question;
    printf("Enter the question: ");
    fgets(question.question, MAX_QUESTION_LENGTH, stdin);
    printf("Enter the options (A, B, C, D):\n");
    for (int i = 0; i < 4; i++) {
        printf("Option %c: ", 'A' + i);
        fgets(question.options[i], MAX_QUESTION_LENGTH, stdin);
    }
    printf("Enter the answer (A, B, C, D): ");
    scanf("%c", &question.correctOption);
    getchar();
    questions[questionCount++] = question;
}

void displayQuestions() {
    for (int i = 0; i < questionCount; i++) {
        printf("%d. %s\nOptions:\nA. %sB. %sC. %sD. %s\n",
        i+1, questions[i].question, questions[i].options[0], questions[i].options[1], questions[i].options[2], questions[i].options[3]);
    }
}

int runExam() {
    int score = 0;
    printf("\nExam begins now:\n");
    for (int i = 0; i < questionCount; i++) {
        char answer;
        printf("\n%d. %s\nOptions:\nA. %sB. %sC. %sD. %s\nYour answer: ",
        i+1, questions[i].question, questions[i].options[0], questions[i].options[1], questions[i].options[2], questions[i].options[3]);
        scanf("%c", &answer);
        getchar();
        if (toupper(answer) == toupper(questions[i].correctOption)) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Incorrect!\nCorrect answer: %c\n\n", questions[i].correctOption);
        }
    }
    return score;
}

void saveQuestionsToFile() {
    FILE *file;
    file = fopen("questions.txt", "w");
    for (int i = 0; i < questionCount; i++) {
        fprintf(file, "%s\n%s\n%s\n%s\n%c\n", questions[i].question, questions[i].options[0],
        questions[i].options[1], questions[i].options[2], questions[i].options[3], questions[i].correctOption);
    }
    fclose(file);
}

void loadQuestionsFromFile() {
    FILE *file;
    file = fopen("questions.txt", "r");
    if (file != NULL) {
        char line[MAX_QUESTION_LENGTH];
        int index = 0;
        while (fgets(line, MAX_QUESTION_LENGTH, file) != NULL) {
            strcpy(questions[index].question, line);
            fgets(questions[index].options[0], MAX_QUESTION_LENGTH, file);
            fgets(questions[index].options[1], MAX_QUESTION_LENGTH, file);
            fgets(questions[index].options[2], MAX_QUESTION_LENGTH, file);
            fgets(questions[index].options[3], MAX_QUESTION_LENGTH, file);
            fscanf(file, "%c\n", &questions[index].correctOption);
            questionCount++;
            index++;
        }
        fclose(file);
    }
}

int main() {
    int choice;
    printf("Welcome to Online Examination System!\n");
    loadQuestionsFromFile();
    while(1) {
        printf("\n1. Create new question\n2. Display questions\n3. Run exam\n4. Quit\nYour choice: ");
        scanf("%d", &choice);
        getchar();
        switch(choice) {
            case 1:
                createQuestion();
                saveQuestionsToFile();
                break;
            case 2:
                displayQuestions();
                break;
            case 3:
                printf("Your score: %d/%d\n", runExam(), questionCount);
                break;
            case 4:
                printf("Thank you for using our Online Examination System!\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
}