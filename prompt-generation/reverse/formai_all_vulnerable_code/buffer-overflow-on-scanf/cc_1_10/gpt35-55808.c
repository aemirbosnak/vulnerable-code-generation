//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: invasive
#include <stdio.h>
#include <string.h>

int main() {
    char name[20], answer[20];
    int choice, points = 0;

    printf("You wake up in an unfamiliar room with no memory of how you got here.\n");
    printf("A voice booms from the speakers: 'Welcome to the game of your life, %s!'\n", name);
    printf("Do you want to play? (1) Yes (2) No\n");
    scanf("%d", &choice);

    if (choice == 2) {
        printf("The voice laughs maniacally and says, 'Too bad, %s. You don't have a choice.'\n", name);
    } else {
        printf("Excellent choice, %s! Let's begin.\n", name);
    }

    printf("You see two doors in front of you. Which one do you choose? (1) Left (2) Right\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("The door locks behind you and you are trapped in a room with no exit.\n");
        printf("The voice says, 'Looks like you don't have the brains to play this game, %s.'\n", name);
        printf("You lose.\n");
        return 0;
    } else {
        printf("You enter a room filled with treasure. How much do you take? (1) A little (2) A lot\n");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("The voice says, 'A wise choice, %s. You gain 10 points.'\n", name);
            points += 10;
        } else {
            printf("The voice says, 'A greedy choice, %s. You lose 10 points.'\n", name);
            points -= 10;
        }

        printf("You see a key on the floor. Do you pick it up? (1) Yes (2) No\n");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("The key unlocks a door to the next level. You gain 20 points, %s!\n", name);
            points += 20;
        } else {
            printf("The voice says, 'Too bad, %s. You missed out on valuable points.'\n", name);
        }

        printf("You hear a loud noise coming from the next room. Do you investigate? (1) Yes (2) No\n");
        scanf("%d", &choice);

        if (choice == 2) {
            printf("The voice says, 'You're not brave enough to play this game, %s. You lose.'\n", name);
            return 0;
        }

        printf("You enter the room and face a monster. What do you do? (1) Fight (2) Run\n");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("You defeat the monster and gain 30 points, %s!\n", name);
            points += 30;
            printf("You win! Your final score is %d.\n", points);
            return 0;
        } else {
            printf("You try to run but the monster catches up to you. You lose, %s.\n", name);
            return 0;
        }
    }
}