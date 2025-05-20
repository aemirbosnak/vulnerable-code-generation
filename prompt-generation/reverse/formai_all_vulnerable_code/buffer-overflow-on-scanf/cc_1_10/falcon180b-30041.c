//Falcon-180B DATASET v1.0 Category: Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of players
#define MAX_PLAYERS 4

// Define the maximum number of questions
#define MAX_QUESTIONS 10

// Define the structure for a question
typedef struct {
    char question[51];
    int answer;
    int difficulty;
} Question;

// Define the structure for a player
typedef struct {
    char name[21];
    int score;
} Player;

// Function to initialize a question
void initQuestion(Question* q) {
    q->answer = rand() % 101;
    q->difficulty = rand() % 4;
    sprintf(q->question, "What is %d + %d? ", q->answer, q->difficulty * 25);
}

// Function to ask a question to a player
int askQuestion(Question q, Player* p) {
    printf("%s, what is the answer? ", p->name);
    int answer;
    scanf("%d", &answer);
    if (answer == q.answer) {
        printf("%s got it right!\n", p->name);
        return 1;
    } else {
        printf("%s got it wrong.\n", p->name);
        return 0;
    }
}

// Function to generate a new question
Question generateQuestion() {
    Question q;
    initQuestion(&q);
    return q;
}

// Function to play the game with multiple players
void playGame(Player players[], int numPlayers) {
    int i, j, correctAnswers[MAX_PLAYERS];
    for (i = 0; i < numPlayers; i++) {
        correctAnswers[i] = 0;
    }
    int round = 0;
    while (round < MAX_QUESTIONS) {
        Question q = generateQuestion();
        for (i = 0; i < numPlayers; i++) {
            if (askQuestion(q, &players[i])) {
                correctAnswers[i]++;
            }
        }
        round++;
    }
    for (i = 0; i < numPlayers; i++) {
        printf("%s got %d out of %d correct.\n", players[i].name, correctAnswers[i], round);
    }
}

int main() {
    srand(time(NULL));
    Player players[MAX_PLAYERS];
    int numPlayers;
    printf("How many players will be playing? ");
    scanf("%d", &numPlayers);
    if (numPlayers > MAX_PLAYERS || numPlayers < 1) {
        printf("Invalid number of players.\n");
        return 1;
    }
    for (int i = 0; i < numPlayers; i++) {
        printf("Enter the name of player %d: ", i+1);
        scanf("%s", players[i].name);
    }
    playGame(players, numPlayers);
    return 0;
}