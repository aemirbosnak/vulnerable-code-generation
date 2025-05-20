//Falcon-180B DATASET v1.0 Category: Game ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int choice;
    int romeoHealth = 100;
    int julietHealth = 100;

    printf("Romeo and Juliet - The Game\n");
    printf("Choose your character:\n1. Romeo\n2. Juliet\n");
    scanf("%d", &choice);

    if(choice == 1) {
        printf("You are Romeo. Press enter to begin.\n");
        getchar();
    } else if(choice == 2) {
        printf("You are Juliet. Press enter to begin.\n");
        getchar();
    } else {
        printf("Invalid choice. Exiting...\n");
        return 0;
    }

    int round = 1;
    while(romeoHealth > 0 && julietHealth > 0) {
        printf("\nRound %d:\n", round);
        printf("Romeo's health: %d\n", romeoHealth);
        printf("Juliet's health: %d\n", julietHealth);

        printf("What would you like to do?\n");
        printf("1. Attack\n2. Defend\n3. Use item\n");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("You attack! Juliet loses 10 health.\n");
            julietHealth -= 10;
        } else if(choice == 2) {
            printf("You defend! You lose 5 health.\n");
            romeoHealth -= 5;
        } else if(choice == 3) {
            printf("You use an item! You regain 20 health.\n");
            romeoHealth += 20;
        } else {
            printf("Invalid choice. Skipping turn.\n");
        }

        if(romeoHealth <= 0) {
            printf("\nJuliet wins! Romeo is dead.\n");
            return 0;
        } else if(julietHealth <= 0) {
            printf("\nRomeo wins! Juliet is dead.\n");
            return 0;
        }

        round++;
    }

    if(romeoHealth > 0 && julietHealth <= 0) {
        printf("\nRomeo wins! Juliet is dead.\n");
    } else if(julietHealth > 0 && romeoHealth <= 0) {
        printf("\nJuliet wins! Romeo is dead.\n");
    } else {
        printf("\nIt's a tie. Both are alive.\n");
    }

    return 0;
}