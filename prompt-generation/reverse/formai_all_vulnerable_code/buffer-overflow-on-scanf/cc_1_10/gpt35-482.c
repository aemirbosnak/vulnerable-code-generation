//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void delay(int seconds) {
    int milli_seconds = 1000 * seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

int main() {
    char name[20];
    int proceed = 1;
    printf("Welcome to the Haunted House Simulator!\n\n");
    printf("Enter your name: ");
    scanf("%s", name);
    printf("\nHello %s, are you ready to enter the haunted house (y/n)? ", name);
    char choice = getchar();
    if (choice == 'y') {
        printf("\nThe door creaks open as you step inside. It's dark and gloomy, but you hear music coming from upstairs...\n");
        delay(3);
        printf("\nAs you reach the top of the stairs, the music suddenly stops. The only sound you can hear is your heartbeat.\n");
        delay(3);
        printf("\nYou see a flicker of light at the end of the long hallway and decide to investigate. As you get closer, you realize it's a candle burning in front of a door.\n");
        delay(3);
        printf("\nDo you want to open the door (y/n)? ");
        char choice_2 = getchar();
        if (choice_2 == 'y') {
            printf("\nYou push open the door and step into a room filled with mirrors. As you look at your reflection, you see something move behind you.\n");
            delay(3);
            printf("\nYou quickly turn around, but there's nothing there. You notice that the mirrors are slowly starting to fog up, forming the words 'GET OUT'.\n");
            delay(3);
            printf("\nYou hear a low growl behind you and turn around to face a ghostly figure. You try to run, but your legs won't move.\n");
            delay(3);
            printf("\n'You shouldn't have come here' the ghostly figure whispers in your ear before everything goes black.\n");
            proceed = 0;
        } else {
            printf("\nYou decide not to open the door and explore another part of the house.\n");
        }
    } else {
        printf("\nYou chicken out and leave the haunted house.\n");
        proceed = 0;
    }
    if (proceed == 1) {
        printf("\nYou continue to explore the house, but every room is empty and silent. You start to feel like you're being watched.\n");
        delay(3);
        printf("\nSuddenly, you hear a loud crash downstairs. You cautiously make your way down, but there's no one there.\n");
        delay(3);
        printf("\nYou start to feel like you're not alone in the house. As you turn around, you see a figure standing in the shadows.\n");
        delay(3);
        printf("\nDo you want to run (y/n)? ");
        char choice_3 = getchar();
        if (choice_3 == 'y') {
            printf("\nYou run as fast as you can, but you feel something grabbing onto your leg, pulling you back.\n");
            delay(3);
            printf("\nYou turn around and see a group of ghouls surrounding you. They drag you to the basement and lock you in a cell.\n");
            delay(3);
            printf("\nYou're trapped in the haunted house forever. GAME OVER.\n");
        } else {
            printf("\nYou stand your ground and confront the figure. As it steps into the light, you realize it's just a harmless old man.\n");
            delay(3);
            printf("\n'This house is cursed, you need to leave. Don't make the same mistake I did', he warns you before vanishing into thin air.\n");
            printf("\nYou make your way out of the haunted house, shaken but unharmed. Congratulations, you've survived the Haunted House Simulator!\n");
        }
    }
    return 0;
}