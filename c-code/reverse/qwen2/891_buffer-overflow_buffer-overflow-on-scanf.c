#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
    char playerName[50];
    int health = 100;
    int choice;

    printf("Welcome to the Haunted House Adventure Game!\n");
    printf("Enter your name: ");
    scanf("%s", playerName);

    printf("\n%s, you find yourself at the entrance of a dark and eerie house.\n", playerName);
    printf("Do you enter the house? (1) Yes, (2) No\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nYou step inside the house. It's cold and spooky.\n");
        printf("Suddenly, you hear a loud noise coming from the kitchen. Do you investigate? (1) Yes, (2) No\n");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nYou cautiously approach the kitchen. The noise turns out to be just an old clock ticking.\n");
            printf("You feel relieved but slightly shaken. Your health decreases by 10.\n");
            health -= 10;
        } else {
            printf("\nYou decide not to investigate and continue exploring the house.\n");
        }

        printf("\nAs you explore further, you come across a locked door. Do you try to open it? (1) Yes, (2) No\n");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nThe door creaks open with difficulty. Inside, you find a treasure chest!\n");
            printf("Congratulations, %s! You've won the game!\n", playerName);
        } else {
            printf("\nYou decide not to open the door and leave the house.\n");
            printf("Game Over. Better luck next time, %s!\n", playerName);
        }
    } else {
        printf("\nYou wisely choose not to enter the house and leave the area.\n");
        printf("Game Over. Maybe next time, %s!\n", playerName);
    }

    return 0;
}
