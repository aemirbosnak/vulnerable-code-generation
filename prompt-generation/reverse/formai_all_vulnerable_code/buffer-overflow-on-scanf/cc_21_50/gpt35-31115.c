//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: inquisitive
#include <stdio.h>

int main() {
    // introduction
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You find yourself in the middle of a dense forest. You need to find your way out to return home. There are many dangers in this forest, so be careful!\n");

    // variables
    int choice;
    int hasMap = 0;
    int encounterLions = 0;
    int encounterWolves = 0;

    // first decision
    printf("You come to a fork in the road. Do you go left (1) or right (2)?\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("You chose to go left. You come across a lake. Do you swim across (1) or find a boat (2)?\n");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("You begin to swim across the lake, but you encounter a group of hungry lions who were drinking water at the lake. They attack you and you die.\n");
            return 0;
        } else if (choice == 2) {
            printf("You search around and find a small boat on the shore of the lake! You get in and begin to row to the other side.\n");
            printf("When you reach the other side, you see an old lady who offers you a map to help you find your way out of the forest. Do you take the map (1) or refuse (2)?\n");
            scanf("%d", &choice);

            if (choice == 1) {
                printf("You take the map and continue on your journey. You now have a map in your inventory.\n");
                hasMap = 1;
            } else if (choice == 2) {
                printf("You refuse the old woman's offer and continue on your journey.\n");
            }
        }
    } else if (choice == 2) {
        printf("You chose to go right. You come across a pack of wolves. Do you run away (1) or try to fight them off (2)?\n");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("You start running away from the wolves, but they are faster and catch up to you. You are killed by the wolves.\n");
            return 0;
        } else if (choice == 2) {
            printf("You find a stick and try to fend off the wolves. You successfully fight them off and continue on your journey.\n");
        }
    }

    // second decision
    printf("You continue on your journey and come across a bridge. Do you cross the bridge (1) or follow the river (2)?\n");
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("You cross the bridge and come across a group of lions. They don't attack you, but they follow you wherever you go. Do you try to outrun them (1) or try to find a way to scare them off (2)?\n");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("You try to outrun the lions, but they are much faster than you. They eventually catch up and kill you.\n");
            return 0;
        } else if (choice == 2) {
            printf("You look around and see a cliff nearby. You come up with a plan to scare the lions off by making a loud noise. You throw a rock off the cliff, which makes a loud noise and scares the lions away.\n");
            printf("You continue on your journey and come across a river. Do you swim across (1) or look for a bridge (2)?\n");
            scanf("%d", &choice);

            if (choice == 1) {
                printf("You try to swim across the river, but you encounter a group of hungry wolves who were waiting for prey. They attack you and you die.\n");
                return 0;
            } else if (choice == 2) {
                printf("You search around and find a bridge over the river. You cross the bridge and come to a road that leads out of the forest!\n");
                printf("Congratulations, you have successfully escaped the forest!\n");
                return 0;
            }
        }
    } else if (choice == 2) {
        printf("You follow the river and find a waterfall. Do you climb up the waterfall (1) or try to go around it (2)?\n");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("You start climbing up the waterfall, but you encounter a group of hungry lions who were taking a shower at the waterfall. They attack you and you die.\n");
            return 0;
        } else if (choice == 2) {
            printf("You go around the waterfall and come across a group of wolves. Do you try to sneak past them (1) or try to fight them off (2)?\n");
            scanf("%d", &choice);

            if (choice == 1) {
                printf("You try to sneak past the wolves, but they catch your scent and attack you. You are killed by the wolves.\n");
                return 0;
            } else if (choice == 2) {
                printf("You find a sharp rock and successfully fight the wolves off. You continue on your journey and come across a river. Do you swim across (1) or look for a bridge (2)?\n");
                scanf("%d", &choice);

                if (choice == 1) {
                    printf("You try to swim across the river, but you encounter a group of hungry crocodiles who were waiting for prey. They attack you and you die.\n");
                    return 0;
                } else if (choice == 2) {
                    printf("You search around and find a bridge over the river. You cross the bridge and come to a road that leads out of the forest!\n");
                    printf("Congratulations, you have successfully escaped the forest!\n");
                    return 0;
                }
            }
        }
    }

    return 0;
}