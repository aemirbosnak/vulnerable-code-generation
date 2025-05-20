//GEMINI-pro DATASET v1.0 Category: Arithmetic ; Style: retro
//==============================================================================
//  Retro C Arithmetic Adventure
//==============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//==============================================================================
//  Constants
//==============================================================================

const int MAX_LEVEL = 10;
const int MAX_SCORE = 1000;
const int MAX_TIME = 60;

//==============================================================================
//  Data Structures
//==============================================================================

typedef struct {
    int level;
    int score;
    int time;
} GameState;

typedef struct {
    int operand1;
    int operand2;
    char operator;
    int answer;
} Question;

//==============================================================================
//  Functions
//==============================================================================

//  Generate a random question.
Question generateQuestion(int level) {
    Question question;

    //  Set the operands.
    question.operand1 = rand() % (1000 / level);
    question.operand2 = rand() % (1000 / level);

    //  Set the operator.
    switch (rand() % 4) {
        case 0:
            question.operator = '+';
            break;
        case 1:
            question.operator = '-';
            break;
        case 2:
            question.operator = '*';
            break;
        case 3:
            question.operator = '/';
            break;
    }

    //  Set the answer.
    switch (question.operator) {
        case '+':
            question.answer = question.operand1 + question.operand2;
            break;
        case '-':
            question.answer = question.operand1 - question.operand2;
            break;
        case '*':
            question.answer = question.operand1 * question.operand2;
            break;
        case '/':
            question.answer = question.operand1 / question.operand2;
            break;
    }

    return question;
}

//  Ask the player a question.
int askQuestion(Question question) {
    int answer;

    //  Print the question.
    printf("%d %c %d = ?\n", question.operand1, question.operator, question.operand2);

    //  Get the player's answer.
    scanf("%d", &answer);

    //  Return the player's answer.
    return answer;
}

//  Check if the player's answer is correct.
int checkAnswer(Question question, int answer) {
    //  Return whether the player's answer is correct.
    return answer == question.answer;
}

//  Update the game state.
void updateGameState(GameState *gameState, int answerCorrect) {
    //  Increment the level if the player's answer is correct.
    if (answerCorrect) {
        gameState->level++;
    }

    //  Increment the score if the player's answer is correct.
    if (answerCorrect) {
        gameState->score += 100;
    }

    //  Decrement the time if the player's answer is incorrect.
    if (!answerCorrect) {
        gameState->time--;
    }
}

//  Print the game state.
void printGameState(GameState gameState) {
    //  Print the level.
    printf("Level: %d\n", gameState.level);

    //  Print the score.
    printf("Score: %d\n", gameState.score);

    //  Print the time.
    printf("Time: %d\n", gameState.time);
}

//==============================================================================
//  Main Function
//==============================================================================

int main() {
    //  Initialize the random number generator.
    srand(time(NULL));

    //  Initialize the game state.
    GameState gameState = {
        .level = 1,
        .score = 0,
        .time = MAX_TIME,
    };

    //  Main game loop.
    while (gameState.time > 0) {
        //  Generate a question.
        Question question = generateQuestion(gameState.level);

        //  Ask the player a question.
        int answer = askQuestion(question);

        //  Check if the player's answer is correct.
        int answerCorrect = checkAnswer(question, answer);

        //  Update the game state.
        updateGameState(&gameState, answerCorrect);

        //  Print the game state.
        printGameState(gameState);
    }

    //  Game over.
    printf("Game over!\n");

    //  Print the final score.
    printf("Final score: %d\n", gameState.score);

    return 0;
}