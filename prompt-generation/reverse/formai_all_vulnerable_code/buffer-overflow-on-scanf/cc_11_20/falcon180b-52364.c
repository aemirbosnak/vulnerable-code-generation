//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Enter the name of the kingdom that you wish to explore:\n");
    char kingdom[100];
    scanf("%s", kingdom);

    printf("Welcome to the land of %s!\n", kingdom);
    printf("Would you like to:\n");
    printf("1. Visit the castle\n");
    printf("2. Explore the forest\n");
    printf("3. Go to the market\n");
    printf("4. Return to your homeland\n");

    int choice;
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("You have arrived at the castle. What would you like to do?\n");
            printf("1. Meet the king\n");
            printf("2. Tour the castle\n");
            printf("3. Leave\n");
            int castleChoice;
            scanf("%d", &castleChoice);

            switch(castleChoice) {
                case 1:
                    printf("You meet the king and he grants you a boon.\n");
                    break;
                case 2:
                    printf("You tour the castle and marvel at its grandeur.\n");
                    break;
                case 3:
                    printf("You leave the castle and continue your journey.\n");
                    break;
            }
            break;
        case 2:
            printf("You enter the forest. What would you like to do?\n");
            printf("1. Hunt for game\n");
            printf("2. Gather herbs\n");
            printf("3. Leave\n");
            int forestChoice;
            scanf("%d", &forestChoice);

            switch(forestChoice) {
                case 1:
                    printf("You hunt for game and catch a deer.\n");
                    break;
                case 2:
                    printf("You gather herbs and make a healing potion.\n");
                    break;
                case 3:
                    printf("You leave the forest and continue your journey.\n");
                    break;
            }
            break;
        case 3:
            printf("You go to the market. What would you like to do?\n");
            printf("1. Buy food\n");
            printf("2. Buy weapons\n");
            printf("3. Leave\n");
            int marketChoice;
            scanf("%d", &marketChoice);

            switch(marketChoice) {
                case 1:
                    printf("You buy food and replenish your supplies.\n");
                    break;
                case 2:
                    printf("You buy weapons and become better equipped.\n");
                    break;
                case 3:
                    printf("You leave the market and continue your journey.\n");
                    break;
            }
            break;
        case 4:
            printf("You return to your homeland.\n");
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}