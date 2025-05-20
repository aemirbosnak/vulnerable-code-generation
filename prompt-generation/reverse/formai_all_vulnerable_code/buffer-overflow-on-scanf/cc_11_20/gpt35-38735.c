//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define MAX_QUESTIONS 10
#define MAX_ATTEMPTS 3

// function declarations
int generateQuestion();
int validateAnswer(char answer[], int correct_choice);
void shuffleArray(int *array, int size);

int main() {
    char restart_game = 'n';
    int question_number, correct_choice, attempts, score, i;
    score = 0;

    // seed the random number generator
    srand(time(NULL));

    printf("\n--- Welcome to the Periodic Table Quiz! ---\n");
    printf("\nIn this quiz, you will be given %d random questions from the periodic table.", MAX_QUESTIONS);
    printf("\nFor each question, you will have %d attempts to answer correctly.", MAX_ATTEMPTS);
    printf("\nYour score will be calculated based on the number of correct answers you give.");
    printf("\nAre you ready to begin? (Press 'y' to start): ");

    // get user input to start the game
    scanf("%c", &restart_game);

    while (restart_game == 'y') {
        score = 0;

        // generate random questions
        for (i = 0; i < MAX_QUESTIONS; i++) {
            question_number = generateQuestion();
            correct_choice = (question_number % 4) + 1;
            attempts = 0;

            printf("\nQuestion %d:\n\n", i+1);
            switch (question_number) {
                case 0:
                    printf("Which element has the symbol 'He'?\n");
                    printf("1. Helium\n");
                    printf("2. Hydrogen\n");
                    printf("3. Neon\n");
                    printf("4. Lithium\n");
                    break;
                case 1:
                    printf("Which element has the atomic number 11?\n");
                    printf("1. Sodium\n");
                    printf("2. Potassium\n");
                    printf("3. Calcium\n");
                    printf("4. Magnesium\n");
                    break;
                case 2:
                    printf("Which element has the symbol 'O'?\n");
                    printf("1. Oxygen\n");
                    printf("2. Hydrogen\n");
                    printf("3. Carbon\n");
                    printf("4. Nitrogen\n");
                    break;
                case 3:
                    printf("Which element has the atomic number 29?\n");
                    printf("1. Copper\n");
                    printf("2. Iron\n");
                    printf("3. Gold\n");
                    printf("4. Silver\n");
                    break;
                case 4:
                    printf("Which element has the symbol 'Ca'?\n");
                    printf("1. Calcium\n");
                    printf("2. Carbonate\n");
                    printf("3. Carbon\n");
                    printf("4. Cesium\n");
                    break;
                case 5:
                    printf("Which element has the atomic number 17?\n");
                    printf("1. Chlorine\n");
                    printf("2. Fluorine\n");
                    printf("3. Oxygen\n");
                    printf("4. Nitrogen\n");
                    break;
                case 6:
                    printf("Which element has the symbol 'K'?\n");
                    printf("1. Potassium\n");
                    printf("2. Calcium\n");
                    printf("3. Sodium\n");
                    printf("4. Magnesium\n");
                    break;
                case 7:
                    printf("Which element has the atomic number 23?\n");
                    printf("1. Vanadium\n");
                    printf("2. Iron\n");
                    printf("3. Chromium\n");
                    printf("4. Titanium\n");
                    break;
                case 8:
                    printf("Which element has the symbol 'Fe'?\n");
                    printf("1. Iron\n");
                    printf("2. Lead\n");
                    printf("3. Copper\n");
                    printf("4. Gold\n");
                    break;
                case 9:
                    printf("Which element has the atomic number 19?\n");
                    printf("1. Potassium\n");
                    printf("2. Sodium\n");
                    printf("3. Magnesium\n");
                    printf("4. Calcium\n");
                    break;
                default:
                    break;
            }
            // shuffle the answer choices
            int choices[] = {1, 2, 3, 4};
            shuffleArray(choices, 4);

            // print the shuffled answer choices
            printf("\nChoice 1: ");
            switch (choices[0]) {
                case 1:
                    printf("A");
                    break;
                case 2:
                    printf("B");
                    break;
                case 3:
                    printf("C");
                    break;
                case 4:
                    printf("D");
                    break;
                default:
                    break;
            }

            printf("\nChoice 2: ");
            switch (choices[1]) {
                case 1:
                    printf("A");
                    break;
                case 2:
                    printf("B");
                    break;
                case 3:
                    printf("C");
                    break;
                case 4:
                    printf("D");
                    break;
                default:
                    break;
            }

            printf("\nChoice 3: ");
            switch (choices[2]) {
                case 1:
                    printf("A");
                    break;
                case 2:
                    printf("B");
                    break;
                case 3:
                    printf("C");
                    break;
                case 4:
                    printf("D");
                    break;
                default:
                    break;
            }

            printf("\nChoice 4: ");
            switch (choices[3]) {
                case 1:
                    printf("A");
                    break;
                case 2:
                    printf("B");
                    break;
                case 3:
                    printf("C");
                    break;
                case 4:
                    printf("D");
                    break;
                default:
                    break;
            }

            // get user input for their answer choice
            char answer[1];
            printf("\nEnter your answer (A, B, C, or D): ");
            scanf("%s", answer);

            // validate the user's answer
            if (validateAnswer(answer, correct_choice)) {
                printf("\nCorrect! You have earned 1 point.");
                score++;
            }
            else {
                attempts++;
                while (attempts < MAX_ATTEMPTS) {
                    printf("\nIncorrect. Please try again (%d attempts remaining): ", MAX_ATTEMPTS-attempts);
                    scanf("%s", answer);

                    if (validateAnswer(answer, correct_choice)) {
                        printf("\nCorrect! You have earned 1 point.");
                        score++;
                        break;
                    }
                    attempts++;
                }

                if (attempts == MAX_ATTEMPTS) {
                    printf("\nIncorrect. The correct answer was Choice %d.", correct_choice);
                }
            }
        }

        printf("\n--- Game Over ---\n");
        printf("\nYou scored %d out of %d possible points.", score, MAX_QUESTIONS);
        printf("\nWould you like to play again? (Press 'y' to restart or any other key to quit): ");
        scanf("%c", &restart_game);
    }

    printf("\nThank you for playing the Periodic Table Quiz!\n");

    return 0;
}

// function to generate a random question number
int generateQuestion() {
    return rand() % 10;
}

// function to validate the user's answer
int validateAnswer(char answer[], int correct_choice) {
    if (strcmp(answer, "A") == 0 && correct_choice == 1) {
        return 1;
    }
    else if (strcmp(answer, "B") == 0 && correct_choice == 2) {
        return 1;
    }
    else if (strcmp(answer, "C") == 0 && correct_choice == 3) {
        return 1;
    }
    else if (strcmp(answer, "D") == 0 && correct_choice == 4) {
        return 1;
    }
    else {
        return 0;
    }
}

// function to shuffle an array
void shuffleArray(int *array, int size) {
    int i;
    for (i = size-1; i > 0; i--) {
        int j = rand() % (i+1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}