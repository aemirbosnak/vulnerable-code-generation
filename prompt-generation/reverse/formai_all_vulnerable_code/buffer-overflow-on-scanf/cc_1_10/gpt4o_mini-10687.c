//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Question {
    char query[256];
    char options[4][100];
    int correctOption; // 0, 1, 2, or 3
} Question;

typedef struct Examination {
    char name[50];
    Question *questions;
    int totalQuestions;
    int marksObtained;
} Examination;

void displayIntroduction() {
    printf("Welcome, noble candidates, fair as the morning sun!\n");
    printf("Thou art about to partake in a quest of knowledge,\n");
    printf("Wherein lies the fate of thy scholarly reputation.\n");
    printf("Enter thy name, we beseech thee, before the tale unfolds:\n");
}

void startExamination(Examination *exam) {
    printf("\nLet us begin, dear %s, the examination unfolds...\n", exam->name);
    for (int i = 0; i < exam->totalQuestions; i++) {
        printf("\nQuestion %d: %s\n", i + 1, exam->questions[i].query);
        for (int j = 0; j < 4; j++) {
            printf(" %d. %s\n", j + 1, exam->questions[i].options[j]);
        }
        
        int answer;
        printf("Choose the number of thy answer: ");
        scanf("%d", &answer);
        if (answer - 1 == exam->questions[i].correctOption) {
            printf("Thou art correct! A victory for thee!\n");
            exam->marksObtained++;
        } else {
            printf("Alas! That answer doth not please the noble judge.\n");
        }
    }
}

void displayResults(Examination *exam) {
    printf("\nThy examination hath concluded, %s.\n", exam->name);
    printf("Marks Obtained: %d out of %d\n", exam->marksObtained, exam->totalQuestions);
    float percentage = ((float)exam->marksObtained / exam->totalQuestions) * 100;
    printf("Thy percentage: %.2f%%\n", percentage);
}

int main() {
    Examination exam;
    strcpy(exam.name, "Romeo");
    exam.totalQuestions = 5;
    exam.marksObtained = 0;

    Question questions[5] = {
        {"What light through yonder window breaks?", 
            {"The sun", "The moon", "A star", "An angel"}, 0},
        {"Who speaks the famous line, 'A rose by any other name'?", 
            {"Juliet", "Romeo", "Mercutio", "Benvolio"}, 0},
        {"Wherefore art thou Romeo?", 
            {"In the Capulet garden", "In Mantua", "At home", "In Verona"}, 0},
        {"What is the fate of Romeo and Juliet?", 
            {"They live happily ever after", "They perish", "They marry", "They run away"}, 1},
        {"Who kills Mercutio?", 
            {"Tyablt", "Romeo", "Benvolio", "Paris"}, 0}
    };

    exam.questions = questions;

    // Display the introduction
    displayIntroduction();
    // Start the examination
    startExamination(&exam);
    // Display results
    displayResults(&exam);

    return 0;
}