//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

void clear_input_buffer() {
    int c = getchar();
    while (c != '\n' && c != EOF) {
        c = getchar();
    }
}

int main() {
    int score = 0;
    char username[20];
    printf("Welcome to the Grateful Adventure Game!\n\n");
    printf("What is your name? ");
    scanf("%19s", username);
    printf("\nHello, %s!\n\n", username);

    printf("You are a wandering adventurer who stumbled upon a village during your travels. As you enter the village, you notice that something is not quite right. The villagers seem to be in a state of distress... What do you do?\n\n");

    printf("a) Approach one of the villagers and ask what's wrong.\n");
    printf("b) Mind your own business and keep walking.\n");

    char answer1 = ' ';
    scanf(" %c", &answer1);
    clear_input_buffer();

    if (tolower(answer1) == 'a') {
        printf("\nThe villager tells you that the village has been plagued by a monster that lives in the nearby forest.\n");
        score += 10;
    }
    else {
        printf("\nYou continue walking and leave the village behind. You don't think much about it and continue on your journey.\n");
        score -= 10;
        printf("Your score is now %d.\n", score);
        printf("\nUnfortunately, you have failed to start the adventure!\n");
        return 0;
    }

    printf("\nWhat do you do now?\n\n");
    printf("a) Head to the forest to investigate.\n");
    printf("b) Stay in the village and try to help out in other ways.\n");

    char answer2 = ' ';
    scanf(" %c", &answer2);
    clear_input_buffer();

    if (tolower(answer2) == 'a') {
        printf("\nYou head into the forest. After a few hours of walking, you come across a clearing and finally see the monster. It is massive and covered in thick, matted fur. You immediately draw your weapon and prepare to fight.\n");
        score += 20;
    }
    else {
        printf("\nYou decide to stay in the village and help out in any way you can. You eventually end up helping a few of the villagers repair their homes. The grateful villagers thank you for your help and reward you with a small sum of money.\n");
        printf("\nCongratulations - You have completed the game!\n");
        printf("Your final score is %d.\n", score);
        return 0;
    }

    printf("\nWhat do you do now?\n\n");
    printf("a) Engage in hand-to-hand combat with the monster.\n");
    printf("b) Try to outsmart the monster and avoid a direct battle.\n");

    char answer3 = ' ';
    scanf(" %c", &answer3);
    clear_input_buffer();

    if (tolower(answer3) == 'a') {
        printf("\nYou charge towards the monster and the fight begins. It's a tough battle, but after a few minutes, you manage to strike the final blow. The monster falls to the ground and the village is saved!\n");
        score += 30;
        printf("\nCongratulations - You have completed the game!\n");
        printf("Your final score is %d.\n", score);
        return 0;
    }
    else {
        printf("\nYou decide to outsmart the monster by luring it into a trap. You create a makeshift pit and cover it with sticks and leaves. When the monster comes towards you, it falls into the pit and becomes trapped. You quickly leave the forest and return to the village to tell the grateful villagers that the monster is no more.\n");
        score += 40;
        printf("\nCongratulations - You have completed the game!\n");
        printf("Your final score is %d.\n", score);
        return 0;
    }
}