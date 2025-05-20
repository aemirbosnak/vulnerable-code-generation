//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_NAME_LENGTH 50

typedef struct {
    char question[256];
    char options[MAX_OPTIONS][100];
    int answer; // Index of the correct answer
} Question;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Student;

Question questions[MAX_QUESTIONS];
int questionCount = 0;

void addQuestion(char *questionText, char *options[MAX_OPTIONS], int correctAnswer) {
    if (questionCount >= MAX_QUESTIONS) {
        printf("The sky is crying; we cannot add more questions.\n");
        return;
    }
    strcpy(questions[questionCount].question, questionText);
    for (int i = 0; i < MAX_OPTIONS; i++) {
        strcpy(questions[questionCount].options[i], options[i]);
    }
    questions[questionCount].answer = correctAnswer;
    questionCount++;
}

void printQuestion(int index) {
    printf("%s\n", questions[index].question);
    for (int i = 0; i < MAX_OPTIONS; i++) {
        printf("%d: %s\n", i + 1, questions[index].options[i]);
    }
}

int getStudentChoice() {
    int choice;
    printf("In this sea of choices, which will you embrace? (1-%d): ", MAX_OPTIONS);
    scanf("%d", &choice);
    return choice - 1; // Convert to 0-based index
}

void takeExamination(Student *student) {
    for (int i = 0; i < questionCount; i++) {
        printQuestion(i);
        int choice = getStudentChoice();
        
        if (choice == questions[i].answer) {
            printf("Correct! You are a wizard of wisdom.\n");
            student->score++;
        } else {
            printf("Wrong! But don't let gravity weigh you down.\n");
        }
    }
}

void displayResults(Student *student) {
    printf("Student: %s\n", student->name);
    printf("Your score: %d out of %d\n", student->score, questionCount);
    if (student->score == questionCount) {
        printf("You have unraveled the secrets of the universe today!\n");
    } else {
        printf("The clouds hold more answers for you, brave soul.\n");
    }
}

int main() {
    Student student;
    student.score = 0;

    printf("In the beginning, a student emerged—what is your name?\n");
    scanf("%s", student.name);

    // Adding some questions like a painter splashing colors on a canvas
    char *options1[MAX_OPTIONS] = {"The moon", "A spoon", "A balloon", "A raccoon"};
    addQuestion("What hangs in the night, glowing with exquisite delight?", options1, 0);

    char *options2[MAX_OPTIONS] = {"Glass beads", "Figs", "Buttercups", "Tigers"};
    addQuestion("In a world made of dreams, which is the sweetest fruit to taste?", options2, 2);

    char *options3[MAX_OPTIONS] = {"Infinity", "A finite loop", "A circle", "A square"};
    addQuestion("What shape hugs itself endlessly without edges?", options3, 0);

    char *options4[MAX_OPTIONS] = {"Whispers of the wind", "Roses", "Computers", "Mathematics"};
    addQuestion("What dances softly through the streets at dusk?", options4, 0);

    // Engaging into the exam
    takeExamination(&student);
    displayResults(&student);

    printf("The sun sets on today's journey, but tomorrow brings new questions.\n");
    return 0;
}