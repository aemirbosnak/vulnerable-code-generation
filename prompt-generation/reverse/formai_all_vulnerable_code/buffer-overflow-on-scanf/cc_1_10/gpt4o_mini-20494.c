//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_QUESTIONS 5
#define MAX_NAME_LENGTH 30
#define FILENAME "scores.txt"

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Player;

typedef struct {
    char question[256];
    char options[4][100];
    char answer; // a, b, c, or d
} TriviaQuestion;

// Function prototypes
void displayScores();
void playGame();
void loadQuestions(TriviaQuestion questions[]);
void saveScore(Player players[], int playerCount);

int main() {
    int choice;
    
    while (1) {
        printf("\n=== Trivia Quiz Game ===\n");
        printf("1. Play Game\n");
        printf("2. View Scores\n");
        printf("3. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                playGame();
                break;
            case 2:
                displayScores();
                break;
            case 3:
                printf("Thank you for playing!\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }
    return 0;
}

void loadQuestions(TriviaQuestion questions[]) {
    // Sample questions
    strcpy(questions[0].question, "What is the capital of France?");
    strcpy(questions[0].options[0], "a. Berlin");
    strcpy(questions[0].options[1], "b. Madrid");
    strcpy(questions[0].options[2], "c. Paris");
    strcpy(questions[0].options[3], "d. Rome");
    questions[0].answer = 'c';

    strcpy(questions[1].question, "Which planet is known as the Red Planet?");
    strcpy(questions[1].options[0], "a. Earth");
    strcpy(questions[1].options[1], "b. Mars");
    strcpy(questions[1].options[2], "c. Jupiter");
    strcpy(questions[1].options[3], "d. Saturn");
    questions[1].answer = 'b';

    strcpy(questions[2].question, "Who wrote 'Hamlet'?");
    strcpy(questions[2].options[0], "a. Charles Dickens");
    strcpy(questions[2].options[1], "b. William Shakespeare");
    strcpy(questions[2].options[2], "c. Mark Twain");
    strcpy(questions[2].options[3], "d. Ernest Hemingway");
    questions[2].answer = 'b';

    strcpy(questions[3].question, "What is the smallest prime number?");
    strcpy(questions[3].options[0], "a. 0");
    strcpy(questions[3].options[1], "b. 1");
    strcpy(questions[3].options[2], "c. 2");
    strcpy(questions[3].options[3], "d. 3");
    questions[3].answer = 'c';

    strcpy(questions[4].question, "Which element has the chemical symbol 'O'?");
    strcpy(questions[4].options[0], "a. Gold");
    strcpy(questions[4].options[1], "b. Oxygen");
    strcpy(questions[4].options[2], "c. Silver");
    strcpy(questions[4].options[3], "d. Iron");
    questions[4].answer = 'b';
}

void playGame() {
    Player players[MAX_PLAYERS];
    TriviaQuestion questions[MAX_QUESTIONS];
    int playerCount = 0;
    char morePlayers;

    loadQuestions(questions);

    do {
        if (playerCount >= MAX_PLAYERS) {
            printf("Maximum player limit reached.\n");
            break;
        }
        printf("Enter player name: ");
        scanf("%s", players[playerCount].name);
        players[playerCount].score = 0;

        for (int i = 0; i < MAX_QUESTIONS; ++i) {
            printf("\nQ%d: %s\n", i + 1, questions[i].question);
            for (int j = 0; j < 4; ++j) {
                printf("%s\n", questions[i].options[j]);
            }
            printf("Your answer (a/b/c/d): ");
            char answer;
            scanf(" %c", &answer);
            if (answer == questions[i].answer) {
                printf("Correct!\n");
                players[playerCount].score++;
            } else {
                printf("Wrong! The correct answer was %c.\n", questions[i].answer);
            }
        }

        playerCount++;
        printf("Would you like to add another player? (y/n): ");
        scanf(" %c", &morePlayers);
    } while (morePlayers == 'y' || morePlayers == 'Y');

    saveScore(players, playerCount);
}

void saveScore(Player players[], int playerCount) {
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }
    
    fprintf(file, "Scores:\n");
    for (int i = 0; i < playerCount; ++i) {
        fprintf(file, "%s: %d\n", players[i].name, players[i].score);
    }
    fclose(file);
    printf("Scores saved to %s\n", FILENAME);
}

void displayScores() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("No scores found!\n");
        return;
    }
    
    char line[256];
    printf("\n=== Scores ===\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}