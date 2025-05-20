//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dispTitle();
int dispIntro();
int dispRules();
void dispResult(int);
int gameLoop();

char table[10][20] = {"Hydrogen", "Helium", "Lithium", "Beryllium", "Boron", "Carbon", "Nitrogen", "Oxygen", "Fluorine", "Neon"};
int shell[10] = {1, 2, 2, 2, 2, 2, 2, 2, 1, 2};
char symbol[10][3] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne"};

int main() {
    dispTitle();
    while (gameLoop());
    return 0;
}

void dispTitle() {
    printf("The C Periodic Table Quiz\n\n");
}

int gameLoop() {
    int score = 0;
    if (dispIntro()) {
        if (dispRules()) {
            for (int i=0; i<10; i++) {
                char input[20];
                printf("\nWhat is the symbol for %s? ", table[i]);
                gets(input);
                if (!strcmp(input, symbol[i])) {
                    printf("Well done! You got it!\n");
                    score++;
                }
                else {
                    printf("Sorry, it's %s.\n", symbol[i]);
                }
            }
            dispResult(score);
        }
    }
    char choice;
    printf("\nWould you like to play again? (Y/N): ");
    scanf("%c", &choice);
    getchar();
    if (choice=='Y' || choice=='y') {
        printf("\n");
        return 1;
    }
    return 0;
}

int dispIntro() {
    printf("Welcome to the Sherlock Holmes C Periodic Table Quiz.\n");
    printf("You have to guess the symbol of each element of the periodic table.\n");
    printf("There are 10 elements to guess.\n");
    char choice;
    printf("\nReady to play? (Y/N): ");
    scanf("%c", &choice);
    getchar();
    if (choice=='Y' || choice=='y') {
        return 1;
    }
    printf("\nThanks for playing! Goodbye!\n");
    return 0;
}

int dispRules() {
    printf("\nHere are the rules:\n");
    printf("- You must guess the symbol for each element of the periodic table.\n");
    printf("- You have to guess 10 elements in total.\n");
    printf("- For each correct answer, you will earn 1 point.\n");
    char choice;
    printf("\nDo you want to read the rules again? (Y/N): ");
    scanf("%c", &choice);
    getchar();
    if (choice=='Y' || choice=='y') {
        dispRules();
    }
    printf("\nGood luck! Let's begin!\n");
    return 1;
}

void dispResult(int score) {
    printf("\nCongratulations! You finished the quiz!\n");
    printf("You got %d out of 10!\n\n", score);
}