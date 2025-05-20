//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void wait() {
    fflush(stdin);
    getchar();
}

int main() {
    char playerName[50];
    int coins = 0;

    printf("Welcome, adventurer! What is your name?\n");
    scanf("%s", playerName);

    printf("Greetings, %s! You start your journey with %d coins.\n", playerName, coins);
    wait();

    printf("You find yourself on a deserted island. You look around and find a sign that says 'Choose Your Path'.\n");
    printf("Would you like to take the left path or the right path? (L/R)\n");
    char choice1[3];
    scanf("%s", choice1);

    if (strcmp(choice1, "L") == 0) {
        printf("You have chosen the left path. As you walk, you notice a treasure chest on the side of the road. Do you want to open it? (Y/N)\n");
        char choice2[3];
        scanf("%s", choice2);

        if (strcmp(choice2, "Y") == 0) {
            printf("You open the chest and find 50 coins! Your adventure is off to a good start!\n");
            coins += 50;
        } else {
            printf("You decide to leave the chest where it is and continue along the path.\n");
        }

        printf("As you keep walking, you come across a group of bandits. They demand that you give them all of your coins. What do you do? (Fight/Run)\n");
        char choice3[10];
        scanf("%s", choice3);

        if (strcmp(choice3, "Fight") == 0) {
            printf("You bravely attack the bandits, but unfortunately you are outnumbered and defeated.\n");
            printf("GAME OVER\n");
            exit(0);
        } else {
            printf("You sprint away from the bandits and escape. However, you drop 20 coins in the process.\n");
            coins -= 20;
        }

        printf("After that close call, you continue on the path until you reach a fork in the road. Will you go left or right? (L/R)\n");
        char choice4[3];
        scanf("%s", choice4);

        if (strcmp(choice4, "L") == 0) {
            printf("You have chosen the left path. As you walk, you notice a mysterious man who offers to sell you a map for 30 coins. Do you buy it? (Y/N)\n");
            char choice5[3];
            scanf("%s", choice5);

            if (strcmp(choice5, "Y") == 0) {
                printf("You buy the map for 30 coins. It shows the shortest route to your destination!\n");
                coins -= 30;
            } else {
                printf("You decide to save your money and continue without the map.\n");
            }
        } else {
            printf("You have chosen the right path. As you walk, you notice a beautiful necklace on the ground. Do you take it? (Y/N)\n");
            char choice6[3];
            scanf("%s", choice6);

            if (strcmp(choice6, "Y") == 0) {
                printf("You take the necklace, but suddenly a trap door opens and you fall into a pit. You lose 25 coins in the process.\n");
                coins -= 25;
            } else {
                printf("You decide to leave the necklace where it is and continue on the path.\n");
            }
        }

        printf("You finally reach your destination, but you realize you need to cross a river. There is a bridge in good condition, but it costs 40 coins to cross. Do you pay the toll? (Y/N)\n");
        char choice7[3];
        scanf("%s", choice7);

        if (strcmp(choice7, "Y") == 0) {
            printf("You pay the toll and cross the bridge. Congratulations, you have completed your adventure with %d coins!\n", coins - 40);
        } else {
            printf("You decide to swim across, but the current is too strong and you lose all of your coins in the process.\n");
            printf("GAME OVER\n");
            exit(0);
        }
    } else {
        printf("You have chosen the right path. As you walk, you notice a strange object on the ground. Do you investigate it? (Y/N)\n");
        char choice8[3];
        scanf("%s", choice8);

        if (strcmp(choice8, "Y") == 0) {
            printf("You investigate the object and find a magical amulet! It increases your strength in battle!\n");
        } else {
            printf("You decide to leave the object where it is and continue on the path.\n");
        }

        printf("As you keep walking, you come across a group of trolls. They demand that you give them all of your coins. What do you do? (Fight/Run)\n");
        char choice9[10];
        scanf("%s", choice9);

        if (strcmp(choice9, "Fight") == 0) {
            printf("You bravely attack the trolls and use your newfound strength to defeat them!\n");
            printf("CONGRATULATIONS! You have completed your adventure with %d coins!\n", coins + 100);
        } else {
            printf("You sprint away from the trolls and escape, but you drop 10 coins in the process.\n");
            coins -= 10;
            printf("After that close call, you continue on the path until you reach a fork in the road. Will you go left or right? (L/R)\n");
            char choice10[3];
            scanf("%s", choice10);

            if (strcmp(choice10, "L") == 0) {
                printf("You have chosen the left path. As you walk, you notice a mysterious man who offers to sell you a map for 30 coins. Do you buy it? (Y/N)\n");
                char choice11[3];
                scanf("%s", choice11);

                if (strcmp(choice11, "Y") == 0) {
                    printf("You buy the map for 30 coins. It shows the shortest route to your destination!\n");
                    coins -= 30;
                } else {
                    printf("You decide to save your money and continue without the map.\n");
                }
            } else {
                printf("You have chosen the right path. As you walk, you notice a beautiful necklace on the ground. Do you take it? (Y/N)\n");
                char choice12[3];
                scanf("%s", choice12);

                if (strcmp(choice12, "Y") == 0) {
                    printf("You take the necklace, but suddenly a trap door opens and you fall into a pit. You lose 25 coins in the process.\n");
                    coins -= 25;
                } else {
                    printf("You decide to leave the necklace where it is and continue on the path.\n");
                }
            }

            printf("You finally reach your destination, but you realize you need to cross a river. There is a bridge in good condition, but it costs 40 coins to cross. Do you pay the toll? (Y/N)\n");
            char choice13[3];
            scanf("%s", choice13);

            if (strcmp(choice13, "Y") == 0) {
                printf("You pay the toll and cross the bridge. Congratulations, you have completed your adventure with %d coins!\n", coins - 40);
            } else {
                printf("You decide to swim across, but the current is too strong and you lose all of your coins in the process.\n");
                printf("GAME OVER\n");
                exit(0);
            }
        }
    }

    return 0;
}