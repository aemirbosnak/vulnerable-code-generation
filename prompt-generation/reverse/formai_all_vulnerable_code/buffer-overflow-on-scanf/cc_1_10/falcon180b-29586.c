//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int choice;
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You find yourself in a dark, damp dungeon with only a torch to light your way.\n");
    printf("What will you do?\n");
    printf("1. Move forward\n");
    printf("2. Turn back\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("You take a step forward and suddenly hear a loud crash behind you.\n");
        printf("The entrance has collapsed, trapping you inside!\n");
        printf("What will you do now?\n");
        printf("1. Panic\n");
        printf("2. Stay calm and look for another way out\n");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("You start panicking and running around frantically, but it only makes things worse.\n");
            printf("You trip over a rock and hit your head, losing consciousness.\n");
            printf("Game Over.\n");
            return 0;
        } else if (choice == 2) {
            printf("You take a deep breath and start exploring the dungeon, looking for another way out.\n");
            printf("After hours of searching, you finally find a hidden passage that leads to safety.\n");
            printf("Congratulations! You have escaped the dungeon.\n");
            return 0;
        }
    } else if (choice == 2) {
        printf("You turn back and head towards the entrance, but suddenly hear a loud growl.\n");
        printf("A ferocious dragon blocks your path, breathing fire and smoke!\n");
        printf("What will you do?\n");
        printf("1. Fight the dragon\n");
        printf("2. Try to sneak past it\n");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("You draw your sword and charge at the dragon, but it's too powerful for you.\n");
            printf("The dragon breathes fire at you, burning you alive.\n");
            printf("Game Over.\n");
            return 0;
        } else if (choice == 2) {
            printf("You try to sneak past the dragon, but it spots you and chases after you.\n");
            printf("You run as fast as you can, but the dragon is gaining on you.\n");
            printf("Just when you think it's all over, you see a glimmer of light ahead.\n");
            printf("It's the entrance! You make a final dash and escape the dungeon.\n");
            printf("Congratulations! You have escaped the dungeon.\n");
            return 0;
        }
    } else {
        printf("Invalid choice. Please try again.\n");
        return 0;
    }
}