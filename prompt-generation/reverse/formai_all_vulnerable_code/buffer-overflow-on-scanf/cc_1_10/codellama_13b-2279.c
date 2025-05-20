//Code Llama-13B DATASET v1.0 Category: Terminal Based Game ; Style: calm
/*
 *  A simple terminal-based game
 *  Author: [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the game instructions
void print_instructions() {
    printf("Welcome to the game!\n");
    printf("You are a detective and you have to solve a murder case.\n");
    printf("You will be given a series of clues and you have to use them to find the killer.\n");
    printf("You have 10 chances to solve the case.\n");
}

// Function to print the game over message
void print_game_over(int score) {
    if (score == 10) {
        printf("Congratulations, you solved the case!\n");
    } else {
        printf("Sorry, you didn't solve the case. The killer was not caught.\n");
    }
    printf("Thanks for playing!\n");
}

// Function to print the clue
void print_clue(int clue) {
    switch (clue) {
        case 1:
            printf("The murder happened in a house with a white door.\n");
            break;
        case 2:
            printf("The victim was a woman and she was found dead in the bedroom.\n");
            break;
        case 3:
            printf("The killer had a bloody knife.\n");
            break;
        case 4:
            printf("The victim was killed by a sharp object.\n");
            break;
        case 5:
            printf("The killer was not caught by the police.\n");
            break;
        default:
            printf("Invalid clue!\n");
    }
}

// Function to generate a random clue
int generate_clue() {
    int clue = rand() % 5 + 1;
    return clue;
}

// Function to check the answer
int check_answer(int answer) {
    int correct_answer = 3;
    if (answer == correct_answer) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int score = 0;
    int clue = 0;
    int answer = 0;

    srand(time(NULL));

    print_instructions();

    while (score < 10) {
        clue = generate_clue();
        print_clue(clue);
        printf("Enter your answer: ");
        scanf("%d", &answer);
        if (check_answer(answer)) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect.\n");
        }
    }

    print_game_over(score);

    return 0;
}