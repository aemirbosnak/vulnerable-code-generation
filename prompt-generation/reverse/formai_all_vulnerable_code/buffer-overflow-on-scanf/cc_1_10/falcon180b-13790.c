//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int choice;
    printf("Welcome to the world of romance!\n");
    printf("You find yourself in a beautiful garden filled with roses and lilies.\n");
    printf("The sun is setting, casting a warm golden glow on everything around you.\n");
    printf("In the distance, you see a handsome stranger walking towards you.\n");
    printf("What do you do?\n");
    printf("1. Smile at him\n");
    printf("2. Look away shyly\n");
    printf("3. Run away\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("You smile at the stranger and he smiles back.\n");
            printf("He introduces himself as Alex and asks if he can join you for a walk.\n");
            printf("Do you accept?\n");
            printf("1. Yes\n");
            printf("2. No\n");
            scanf("%d", &choice);

            switch(choice) {
                case 1:
                    printf("You accept Alex's offer and the two of you start walking together.\n");
                    printf("As you stroll through the garden, you feel a connection growing between you.\n");
                    printf("Alex turns to you and says, 'I know we just met, but I feel like I've known you forever.'\n");
                    printf("How do you respond?\n");
                    printf("1. I feel the same way\n");
                    printf("2. That's sweet, but let's take things slow\n");
                    scanf("%d", &choice);

                    switch(choice) {
                        case 1:
                            printf("You tell Alex that you feel the same way and he takes your hand.\n");
                            printf("The two of you continue walking, enjoying each other's company.\n");
                            break;
                        case 2:
                            printf("You tell Alex that you want to take things slow and he respects your decision.\n");
                            printf("The two of you continue walking and talking, getting to know each other better.\n");
                            break;
                    }
                    break;
                case 2:
                    printf("You decline Alex's offer and he nods understandingly.\n");
                    printf("He tells you that he respects your decision and walks away.\n");
                    break;
            }
            break;
        case 2:
            printf("You look away shyly and Alex walks past you without saying anything.\n");
            break;
        case 3:
            printf("You turn around and run away as fast as you can.\n");
            break;
    }

    return 0;
}