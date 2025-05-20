//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: excited
#include <stdio.h> 

int main() {
    printf("Welcome to the exciting world of Adventure Games!\n");
    printf("You are about to embark on a journey full of mystery and wonder!\n");
    printf("Are you ready? [y/n]\n");

    char ans;
    scanf("%c", &ans);

    if (ans == 'y') {
        printf("Great! Let's begin.\n");
        printf("You find yourself lost in a deep, dark forest. Your task is to find the way back home.\n");
        printf("You come across a fork in the road. Which direction will you take? [left/right]\n");

        char choice1[10];
        scanf("%s", choice1);

        if (strcmp(choice1, "left") == 0) {
            printf("You have stumbled upon a clearing with a small pond in the center.\n");
            printf("The water is crystal clear. Do you want to take a drink? [y/n]\n");

            char choice2;
            scanf(" %c", &choice2);

            if (choice2 == 'y') {
                printf("As you drink from the pond, you grow stronger and more alert.\n");
                printf("You also notice a small key at the bottom of the pond. Do you take it? [y/n]\n");

                char choice3;
                scanf(" %c", &choice3);

                if (choice3 == 'y') {
                    printf("You now have a key! It could be useful later on in your journey.\n");
                } else {
                    printf("You leave the key where it is and continue on your way.\n");
                }

                printf("As you walk, you hear the sound of a river up ahead. Will you cross it? [y/n]\n");

                char choice4;
                scanf(" %c", &choice4);

                if (choice4 == 'y') {
                    printf("You successfully cross the river and continue on your way.\n");
                } else {
                    printf("You decide not to risk crossing the river and find another way around.\n");
                }

                printf("You have come to a clearing with a cottage in the center. Do you go inside? [y/n]\n");

                char choice5;
                scanf(" %c", &choice5);

                if (choice5 == 'y') {
                    printf("As you enter the cottage, you find a map to help guide you on your journey.\n");
                    printf("It also appears that no one has lived here for ages. You decide to leave and continue on your way.\n");
                } else {
                    printf("You decide not to enter the cottage and continue on your way.\n");
                }

                printf("You have reached the edge of the forest! Hooray! Congratulations on completing your journey!\n");

            } else {
                printf("You decide not to drink from the pond and continue on your way.\n");
            }

        } else {
            printf("You have come across a cave entrance. Do you go inside? [y/n]\n");

            char choice6;
            scanf(" %c", &choice6);

            if (choice6 == 'y') {
                printf("As you enter the cave, you are greeted by a group of trolls. Oh no!\n");
                printf("You must fight them off in order to escape. Do you use your sword or your bow and arrows? [sword/bow]\n");

                char choice7[10];
                scanf("%s", choice7);

                if (strcmp(choice7, "sword") == 0) {
                    printf("You fight off the trolls with your trusty sword and continue on your way.\n");
                } else {
                    printf("You use your bow and arrows, but unfortunately they don't do much damage. You must retreat and find another way around.\n");
                }

                printf("You have come to a clearing with a river in the center. Do you cross it? [y/n]\n");

                char choice8;
                scanf(" %c", &choice8);

                if (choice8 == 'y') {
                    printf("You struggle but manage to make it across the river. You continue on your way.\n");
                } else {
                    printf("You decide not to risk crossing the river and find another way around.\n");
                }

                printf("You have come across a field with a farmer working. Do you ask for directions? [y/n]\n");

                char choice9;
                scanf(" %c", &choice9);

                if (choice9 == 'y') {
                    printf("The farmer gives you directions and wishes you good luck on your journey!\n");
                    printf("You continue on your way.\n");
                } else {
                    printf("You decide not to bother the farmer and continue on your way.\n");
                }

                printf("You have reached the edge of the forest! Hooray! Congratulations on completing your journey!\n");

            } else {
                printf("You decide not to enter the cave and continue on your way.\n");
            }
        }

    } else {
        printf("Okay then. Come back when you're ready for adventure!\n");
    }

    return 0;
}