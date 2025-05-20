//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10
#define MAX_OPTIONS 4
#define NAME_LENGTH 30

typedef struct {
    char question[256];
    char options[MAX_OPTIONS][100];
    int answer; // Correct answer index (0 to MAX_OPTIONS-1)
} Question;

void clearScreen() {
    printf("\033[H\033[J"); // ANSI escape codes to clear screen
}

void printWelcome() {
    clearScreen();
    printf("Welcome to the Retro Online Examination System!\n");
    printf("==============================================\n");
    printf("Get ready to test your knowledge!\n\n");
}

void printInstructions() {
    printf("Instructions:\n");
    printf("1. You will be presented with %d multiple-choice questions.\n", MAX_QUESTIONS);
    printf("2. Select the correct option by typing the corresponding number.\n");
    printf("3. Good Luck!\n");
    printf("Press Enter to continue...\n");
    getchar();
}

void displayQuestion(Question q, int questionNumber) {
    printf("%d. %s\n", questionNumber + 1, q.question);
    for (int i = 0; i < MAX_OPTIONS; i++) {
        printf("   %d. %s\n", i + 1, q.options[i]);
    }
}

int getAnswer() {
    int answer;
    printf("Your answer (1-%d): ", MAX_OPTIONS);
    scanf("%d", &answer);
    return answer - 1; // Convert to zero-based index
}

void collectResults(int score) {
    printf("\n==============================================\n");
    printf("Your final score is: %d/%d\n", score, MAX_QUESTIONS);
    printf("Thank you for participating!\n");
    printf("==============================================\n");
}

int main() {
    Question questions[MAX_QUESTIONS] = {
        {"What is the capital of France?", {"Berlin", "Madrid", "Paris", "Rome"}, 2},
        {"Who wrote 'To be, or not to be'?", {"Shakespeare", "Hemingway", "Dickens", "Tolkien"}, 0},
        {"What is 2 + 2?", {"3", "4", "5", "6"}, 1},
        {"Which planet is known as the Red Planet?", {"Earth", "Venus", "Mars", "Jupiter"}, 2},
        {"What is the largest ocean on Earth?", {"Atlantic", "Indian", "Arctic", "Pacific"}, 3},
        {"Who discovered penicillin?", {"Einstein", "Fleming", "Newton", "Curie"}, 1},
        {"What is the smallest prime number?", {"0", "1", "2", "3"}, 2},
        {"What is the boiling point of water?", {"90°C", "100°C", "120°C", "150°C"}, 1},
        {"Who painted the Mona Lisa?", {"Van Gogh", "Monet", "Da Vinci", "Picasso"}, 2},
        {"Which element has the chemical symbol 'O'?", {"Osmium", "Oxygen", "Gold", "Iron"}, 1}
    };

    char name[NAME_LENGTH];
    int score = 0;

    printWelcome();
    printf("Enter your name: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Remove trailing newline

    printInstructions();

    for (int i = 0; i < MAX_QUESTIONS; i++) {
        clearScreen();
        displayQuestion(questions[i], i);
        int answer = getAnswer();

        if (answer == questions[i].answer) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong! The correct answer was: %s\n", questions[i].options[questions[i].answer]);
        }
        printf("Press Enter to continue...\n");
        getchar();
    }

    collectResults(score);
    return 0;
}