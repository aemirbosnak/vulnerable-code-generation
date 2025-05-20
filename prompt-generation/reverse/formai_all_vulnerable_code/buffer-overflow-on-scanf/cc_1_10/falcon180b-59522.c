//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int choice;
    char name[20];

    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    printf("\n%s, you find yourself in a dark, damp dungeon. You have no idea how you got here, but you know you must find a way out.\n", name);

    while (1) {
        printf("\nYou see three doors in front of you. Which one do you choose?\n");
        printf("1. Door on the left\n");
        printf("2. Door in the middle\n");
        printf("3. Door on the right\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nYou open the door on the left and find a long hallway. You decide to follow it.\n");
                printf("After walking for what seems like hours, you finally see a light at the end of the hallway.\n");
                printf("As you get closer, you realize it's a torch. You pick it up and continue on your journey.\n");
                break;
            case 2:
                printf("\nYou open the door in the middle and find a small room with a table and a note.\n");
                printf("The note reads: 'To whoever finds this, I have left a key under the table. It will unlock the door to your freedom.'\n");
                printf("You look under the table and find the key. You now have a way out!\n");
                break;
            case 3:
                printf("\nYou open the door on the right and find yourself face-to-face with a ferocious dragon.\n");
                printf("The dragon breathes fire at you, but you manage to dodge it. You notice a sword lying on the ground nearby.\n");
                printf("You pick up the sword and fight the dragon. After a long and grueling battle, you finally defeat the dragon.\n");
                printf("As the dragon takes its last breath, it reveals a hidden passage behind it.\n");
                printf("You enter the passage and find yourself outside the dungeon, free at last!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }

        if (choice == 2 || choice == 3) {
            printf("\nCongratulations, %s! You have escaped the dungeon!\n", name);
            break;
        }
    }

    return 0;
}