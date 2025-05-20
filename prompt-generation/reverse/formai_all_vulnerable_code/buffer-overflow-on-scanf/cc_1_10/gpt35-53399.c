//FormAI DATASET v1.0 Category: Funny ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    printf("Welcome to the gladiator arena, brave warrior.\n");
    printf("Enter your name to begin your journey: ");
    char name[50];
    scanf("%s", name);
    printf("Welcome %s, let's see if you're a true fighter.\n", name);
    printf("Your task is to survive three rounds of combat.\n");
    printf("Are you ready to begin? (y/n): ");
    char choice;
    scanf(" %c", &choice);
    if (choice != 'y' && choice != 'Y') {
        printf("Then leave, coward.\n");
        return 0;
    }
    int round = 1;
    int health = 100, enemy_health = 100;
    char weapons[3][10] = {"sword", "axe", "mace"};
    srand(time(NULL));
    while (round <= 3) {
        printf("\nRound %d begins...\n", round);
        int weapon = rand() % 3;
        printf("You have been given a %s.\n", weapons[weapon]);
        int enemy_weapon = rand() % 3;
        printf("Your enemy has a %s.\n", weapons[enemy_weapon]);
        printf("Let the battle begin!\n");
        while (health > 0 && enemy_health > 0) {
            int damage = rand() % 25 + 1;
            enemy_health -= damage;
            printf("You hit your enemy for %d damage. Enemy health: %d\n", damage, enemy_health);
            if (enemy_health <= 0) {
                printf("You have defeated your enemy in Round %d.\n", round);
                health = 100;
                enemy_health = 100;
                round++;
                break;
            }
            damage = rand() % 25 + 1;
            health -= damage;
            printf("Your enemy hits you for %d damage. Your health: %d\n", damage, health);
            if (health <= 0) {
                printf("You have been defeated by your enemy in Round %d. Game over!\n", round);
                return 0;
            }
        }
    }
    printf("\nCongratulations %s, you have survived the gladiator arena!\n", name);
    return 0;
}