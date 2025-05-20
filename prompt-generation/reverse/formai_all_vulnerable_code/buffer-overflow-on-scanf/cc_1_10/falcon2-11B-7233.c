//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    int age;
    char gender;
} Player;

void main() {
    Player player;
    int choice;

    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("Please enter your name: ");
    fgets(player.name, sizeof(player.name), stdin);
    player.name[strlen(player.name) - 1] = '\0'; // Remove the newline character

    printf("How old are you? ");
    scanf("%d", &player.age);

    printf("Are you a boy or a girl? ");
    scanf(" %c", &player.gender);

    printf("\nWelcome, %s! You are %d years old and %s.\n\n",
           player.name, player.age, player.gender);

    printf("You are standing in a dark forest. To your left is a path and to your right is a river.\n\n");
    printf("What do you want to do? \n");
    printf("1. Go left \n");
    printf("2. Go right \n");
    printf("3. Stay put \n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("You chose to go left. You found a house. You can knock on the door or keep walking.\n");
            printf("1. Knock on the door \n");
            printf("2. Keep walking \n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    printf("You knocked on the door. A friendly old man opens the door. He invites you inside for a cup of tea. You spend the evening chatting with him and learn about the history of the forest.\n");
                    break;
                case 2:
                    printf("You keep walking. You find a cave. You can enter the cave or keep walking.\n");
                    printf("1. Enter the cave \n");
                    printf("2. Keep walking \n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice);

                    switch (choice) {
                        case 1:
                            printf("You enter the cave. It is dark and spooky. You hear strange noises and feel something cold and slimy on your leg. You decide to leave the cave.\n");
                            break;
                        case 2:
                            printf("You keep walking. You stumble upon a hidden treasure chest. You open it and find a magical amulet. You decide to keep it and continue on your adventure.\n");
                            break;
                }
            }
            break;
        case 2:
            printf("You chose to go right. You fall into the river and drown.\n");
            break;
        case 3:
            printf("You chose to stay put. You starve to death.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
}