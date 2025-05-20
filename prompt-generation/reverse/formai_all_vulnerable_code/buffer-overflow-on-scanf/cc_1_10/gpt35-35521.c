//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice, delay;
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are walking down a dark path when you come across a creepy old house. Do you:\n\n");
    printf("1. Approach the house.\n");
    printf("2. Keep walking.\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nAs you approach the house, you hear strange noises coming from inside. Do you:\n\n");
        printf("1. Open the door and walk inside.\n");
        printf("2. Turn around and run back down the path.\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nYou step inside and the door slams shut behind you. It's pitch black and you can't see anything. Suddenly, you hear footsteps.\n");
            printf("Do you:\n\n");
            printf("1. Stay put and hope for the best.\n");
            printf("2. Try to find a light switch.\n\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            if (choice == 1) {
                printf("\nThe footsteps get closer and closer, until you feel something brush against your leg. You scream and run blindly through the darkness, crashing into walls and furniture.\n");
                printf("Finally, you find a door and burst through it. You are outside in the cool night air, safe and away from the haunted house.\n");
            } else {
                printf("\nYou grope around in the darkness and eventually find a light switch. You flick it on, and the room is illuminated by a dim bulb hanging from the ceiling.\n");
                printf("You look around and see that you are in a musty old living room, filled with cobweb-covered furniture and strange antiques.\n");
                printf("Suddenly, a ghostly voice whispers in your ear: 'Get out...before it's too late.'\n");
                printf("You shudder and run for the door, heart pounding.\n");
            }
        } else {
            printf("\nYou turn and run down the path as fast as you can. As you look back over your shoulder, you see a figure standing in the doorway of the haunted house.\n");
            printf("You keep running until you are safely back in your own home, heart pounding and hands shaking.\n");
        }
    } else {
        printf("\nYou keep walking down the path, feeling relieved that you didn't go into the haunted house. But as you walk farther and farther away, you hear strange noises behind you.\n");
        printf("You turn around and see that the haunted house has followed you, hovering ominously over your shoulder.\n");
        printf("Do you:\n\n");
        printf("1. Run as fast as you can.\n");
        printf("2. Confront the haunted house.\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nYou run down the path as fast as you can, but the haunted house keeps gaining on you. Finally, you trip over a root and fall to the ground.\n");
            printf("You look up and see the haunted house looming over you, creaking and groaning ominously.\n");
            printf("Suddenly, a shadowy figure steps out of the doorway and reaches for you...\n");
        } else {
            printf("\nYou turn and face the haunted house, your heart racing with fear. The front door slowly creaks open, and a dark figure steps out.\n");
            printf("You take a step back, but the figure beckons you forward. As you approach, you see that it is a friendly ghost, who just wants to chat.\n");
            printf("You spend the next few hours talking to the ghost, learning about its life and experiences. When it's time to go, the ghost sees you off with a friendly wave.\n");
        }
    }
    return 0;
}