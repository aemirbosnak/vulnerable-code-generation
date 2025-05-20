//FormAI DATASET v1.0 Category: Game ; Style: curious
#include <stdio.h>

int main() {
    printf("Welcome, adventurer! You have come to a mysterious dungeon in search of treasure!\n");
    printf("You enter the dark hallway and find three doors. You must choose which door to enter to continue your adventure.\n");

    int choice;
    printf("Choose Door 1, 2, or 3: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("You open Door 1 and find a room full of gold coins! ");
            printf("You stuff your pockets with as many coins as you can carry and continue on your adventure.\n");
            break;
        case 2:
            printf("You open Door 2 and find yourself in a room with a hungry dragon! ");
            printf("You must fight the dragon to continue your adventure. Choose your weapon: ");
            printf("1. Sword\n2. Bow and arrow\n3. Magic spell\n");
            int weapon_choice;
            scanf("%d", &weapon_choice);
            switch (weapon_choice) {
                case 1:
                    printf("You equip your sword and charge towards the dragon! ");
                    printf("With your strength and courage, you slay the dragon and continue on your adventure.\n");
                    break;
                case 2:
                    printf("You equip your bow and arrow and take aim at the dragon! ");
                    printf("With your precision and accuracy, you defeat the dragon and continue on your adventure.\n");
                    break;
                case 3:
                    printf("You cast a powerful magic spell at the dragon! ");
                    printf("With your intelligence and wit, you vanquish the dragon and continue on your adventure.\n");
                    break;
                default:
                    printf("You wield nothing and the dragon eats you. Game over.\n");
                    return 0;
            }
            break;
        case 3:
            printf("You open Door 3 and find yourself in a maze! ");
            printf("You must navigate your way through the maze to continue your adventure.\n");
            int move;
            for (int i = 0; i < 5; i++) {
                printf("Move %d - Choose your direction: \n", i+1);
                printf("1. Up\n2. Down\n3. Left\n4. Right\n");
                scanf("%d", &move);
                switch (move) {
                    case 1:
                        printf("You move up.\n");
                        break;
                    case 2:
                        printf("You move down.\n");
                        break;
                    case 3:
                        printf("You move left.\n");
                        break;
                    case 4:
                        printf("You move right.\n");
                        break;
                    default:
                        printf("Invalid move. You are lost forever. Game over.\n");
                        return 0;
                }
            }
            printf("Congratulations! You have successfully navigated the maze and continue on your adventure.\n");
            break;
        default:
            printf("Wrong door choice. You fall into a pit. Game over.\n");
            return 0;
    }
    printf("Thanks for playing!\n");
    return 0;
}