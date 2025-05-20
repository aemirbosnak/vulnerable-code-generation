//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void displayIntro();
void nameInput(char* playerName);
int calculateScore(int correctAnswers);
int askQuestion(int questionNumber);
int generateQuestionSet(int questionSet[]);
void displayEnding(int score, char* playerName);

int main() {
    srand(time(NULL));
    char playerName[20];
    int questionSet[5], correctAnswers = 0, score;
    
    displayIntro();
    nameInput(playerName);
    generateQuestionSet(questionSet);
    for (int i = 0; i < 5; i++) {
        correctAnswers += askQuestion(questionSet[i]);
    }
    score = calculateScore(correctAnswers);
    displayEnding(score, playerName);
    
    return 0;
}

void displayIntro() {
    printf("Welcome to the Procedural Space Adventure Quiz!\n");
    printf("You will be asked a series of questions about space exploration and astronomy.\n");
    printf("Each correct answer will earn you points, and at the end your score will be calculated.\n\n");
}

void nameInput(char* playerName) {
    printf("First, please enter your name: ");
    scanf("%s", playerName);
    printf("\nHello, %s! Are you ready to begin the quiz?\n\n", playerName);
}

int calculateScore(int correctAnswers) {
    return correctAnswers * 100;
}

int askQuestion(int questionNumber) {
    char answer[20];
    int correctAnswer;
    switch (questionNumber) {
        case 1:
            printf("What is the name of the largest planet in our solar system?\n");
            printf("A. Saturn\nB. Jupiter\nC. Neptune\n");
            scanf("%s", answer);
            if (strcmp(answer, "B") == 0 || strcmp(answer, "Jupiter") == 0) {
                printf("Correct!\n\n");
                return 1;
            } else {
                printf("Incorrect. The correct answer is Jupiter.\n\n");
                return 0;
            }
        case 2:
            printf("What is the closest star to our own sun?\n");
            printf("A. Sirius\nB. Proxima Centauri\nC. Betelgeuse\n");
            scanf("%s", answer);
            if (strcmp(answer, "B") == 0 || strcmp(answer, "Proxima Centauri") == 0) {
                printf("Correct!\n\n");
                return 1;
            } else {
                printf("Incorrect. The correct answer is Proxima Centauri.\n\n");
                return 0;
            }
        case 3:
            printf("What is the name of the mission that sent the first humans to the moon?\n");
            printf("A. Apollo 11\nB. Gemini 4\nC. Shuttle Endeavor\n");
            scanf("%s", answer);
            if (strcmp(answer, "A") == 0 || strcmp(answer, "Apollo 11") == 0) {
                printf("Correct!\n\n");
                return 1;
            } else {
                printf("Incorrect. The correct answer is Apollo 11.\n\n");
                return 0;
            }
        case 4:
            printf("What is the name of the largest volcano in our solar system?\n");
            printf("A. Olympus Mons\nB. Mauna Kea\nC. Mount Everest\n");
            scanf("%s", answer);
            if (strcmp(answer, "A") == 0 || strcmp(answer, "Olympus Mons") == 0) {
                printf("Correct!\n\n");
                return 1;
            } else {
                printf("Incorrect. The correct answer is Olympus Mons.\n\n");
                return 0;
            }
        case 5:
            printf("What is the name of the first artificial satellite launched into orbit?\n");
            printf("A. Sputnik 1\nB. Explorer 1\nC. Vanguard 1\n");
            scanf("%s", answer);
            if (strcmp(answer, "A") == 0 || strcmp(answer, "Sputnik 1") == 0) {
                printf("Correct!\n\n");
                return 1;
            } else {
                printf("Incorrect. The correct answer is Sputnik 1.\n\n");
                return 0;
            }
    }
}

int generateQuestionSet(int questionSet[]) {
    int tempSet[10];
    for (int i = 0; i < 10; i++) {
        tempSet[i] = i + 1;
    }
    for (int i = 0; i < 5; i++) {
        int randomIndex = rand() % 10;
        int randomQuestion = tempSet[randomIndex];
        questionSet[i] = randomQuestion;
        for (int j = randomIndex; j < 9; j++) {
            tempSet[j] = tempSet[j + 1];
        }
    }
}

void displayEnding(int score, char* playerName) {
    printf("Congratulations, %s! You have completed the quiz.\n", playerName);
    printf("Your final score is: %d\n", score);
    printf("Thank you for playing the Procedural Space Adventure Quiz!\n");
}