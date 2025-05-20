//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function declarations
void game();
int mathQuestion();
void battle(int enemyHealth, int enemyAttack);
void victory();
void defeat();

int main() {
    printf("Welcome to Math Quest!\n");
    printf("To play, you must correctly answer math questions to defeat enemies.\n");
    printf("Good luck!\n\n");
    game();
    return 0;
}

void game() {
    int playerHealth = 100;
    int playerAttack = 20;
    int enemyHealth = 50;
    int enemyAttack = 10;
    int enemyDefeated = 0;
    int difficulty = 1;
    int score = 0;
    srand(time(NULL));

    while (playerHealth > 0 && enemyDefeated < 5) { // player must defeat 5 enemies to win
        int x = mathQuestion(difficulty);
        if (x == 1) {
            printf("Correct!\n\n");
            enemyDefeated++;
            difficulty++;
            printf("You defeated the enemy!\n");
            victory();
        } else {
            printf("Incorrect. The enemy attacks!\n");
            battle(enemyHealth, enemyAttack);
            playerHealth -= enemyAttack;
        }
        printf("Your health: %d\n", playerHealth);

        if (enemyDefeated == 5) {
            printf("Congratulations, you have won Math Quest!\n");
            printf("Your score is: %d\n", score);
            break;
        }
    }

    if (playerHealth <= 0) {
        defeat();
    }
}

int mathQuestion(int difficulty) {
    int x = rand() % (10 * difficulty);
    int y = rand() % (10 * difficulty);
    int solution = x + y;
    int answer;

    printf("What is %d + %d?\n", x, y);
    scanf("%d", &answer);

    if (answer == solution) {
        return 1;
    } else {
        return 0;
    }
}

void battle(int enemyHealth, int enemyAttack) {
    int playerAttack;

    while (enemyHealth > 0) {
        printf("Enemy health: %d\n", enemyHealth);
        printf("Your attack: ");
        scanf("%d", &playerAttack);
        enemyHealth -= playerAttack;
        if (enemyHealth <= 0) {
            printf("You defeated the enemy!\n");
            break;
        }
        printf("The enemy attacks! You lose %d health.\n", enemyAttack);
    }
}

void victory() {
    int randScore = rand() % 100;
    printf("You gain %d points!\n", randScore);
}

void defeat() {
    printf("Game over. You have lost.\n");
}