//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char name[20];
    int room = 1, choice = 0;
    srand(time(NULL));
    
    printf("Welcome to the Haunted House Simulator\n");
    printf("What is your name? ");
    scanf("%s", name);
    printf("Hello, %s. Your adventure starts now!\n\n", name);
    
    while (room <= 10 && choice != 4) {
        switch (room) {
            case 1:
                printf("You enter the front door and see a dimly lit hallway. What do you do?\n");
                printf("1) Proceed down the hallway\n");
                printf("2) Turn back and leave the house\n");
                scanf("%d", &choice);
                if (choice == 1) {
                    printf("You continue down the hallway and see a staircase leading up.\n\n");
                    room++;
                }
                else {
                    printf("You chicken out and leave the haunted house. Game over, %s!\n", name);
                    return 0;
                }
                break;
            case 2:
                printf("You climb up the staircase and find yourself in a room with a flickering candle.\n");
                printf("1) Pick up the candle\n");
                printf("2) Ignore the candle and proceed to the next room\n");
                scanf("%d", &choice);
                if (choice == 1) {
                    printf("You pick up the candle and proceed to the next room.\n\n");
                    room++;
                }
                else {
                    printf("You move on to the next room, hoping to find a source of light.\n\n");
                    room++;
                }
                break;
            case 3:
                printf("You enter a dark room and see a shadow in the corner. What do you do?\n");
                printf("1) Investigate the shadow\n");
                printf("2) Ignore the shadow and move to the next room\n");
                scanf("%d", &choice);
                if (choice == 1) {
                    int roll = rand() % 3;
                    if (roll == 0) {
                        printf("You investigate the shadow and realize it's just a coat hanging on a hook.\n\n");
                        room++;
                    }
                    else {
                        printf("You investigate the shadow and jump as a cat runs out from the corner.\n\n");
                        room = 1;
                    }
                }
                else {
                    printf("You decide to play it safe and move on to the next room.\n\n");
                    room++;
                }
                break;
            case 4:
                printf("You enter a room with a mirror and see a reflection of yourself.\n");
                printf("1) Look at yourself in the mirror\n");
                printf("2) Smash the mirror and run out of the room\n");
                scanf("%d", &choice);
                if (choice == 1) {
                    printf("You look at yourself in the mirror and see a ghostly figure standing behind you.\n\n");
                    room = 1;
                }
                else {
                    printf("You smash the mirror and run out of the room, but bump into a tall figure in the hallway.\n\n");
                    room = 1;
                }
                break;
            case 5:
                printf("You enter a room with a large wardrobe in the center. What do you do?\n");
                printf("1) Open the wardrobe\n");
                printf("2) Ignore the wardrobe and move to the next room\n");
                scanf("%d", &choice);
                if (choice == 1) {
                    printf("You open the wardrobe and screams come from inside, scaring you out of the room.\n\n");
                    room++;
                }
                else {
                    printf("You move on to the next room, hoping to find an escape.\n\n");
                    room++;
                }
                break;
            case 6:
                printf("You enter a room with three doors: red, blue, and green. Which door do you choose?\n");
                printf("1) Red door\n");
                printf("2) Blue door\n");
                printf("3) Green door\n");
                scanf("%d", &choice);
                if (choice == 1) {
                    printf("You open the red door and find yourself in a room with no windows.\n\n");
                    room++;
                }
                else if (choice == 2) {
                    printf("You open the blue door and find yourself in the basement of the haunted house.\n\n");
                    room++;
                }
                else if (choice == 3) {
                    printf("You open the green door and find yourself outside of the haunted house.\n\n");
                    room = 1;
                }
                else {
                    printf("You can't decide and stay in the same room.\n\n");
                }
                break;
            case 7:
                printf("You enter a room with a rocking chair and a fireplace. What do you do?\n");
                printf("1) Sit in the rocking chair\n");
                printf("2) Light a fire in the fireplace\n");
                printf("3) Ignore the furniture and move to the next room\n");
                scanf("%d", &choice);
                if (choice == 1) {
                    printf("You sit in the rocking chair and feel a cold breath on the back of your neck.\n\n");
                    room = 1;
                }
                else if (choice == 2) {
                    printf("You light a fire in the fireplace and warm up by the flames.\n\n");
                    room++;
                }
                else {
                    printf("You move on to the next room, hoping to find a way out.\n\n");
                    room++;
                }
                break;
            case 8:
                printf("You enter a room with a piano in the center. Suddenly, the piano starts playing by itself.\n");
                printf("1) Investigate the piano\n");
                printf("2) Run out of the room\n");
                scanf("%d", &choice);
                if (choice == 1) {
                    printf("You investigate the piano and realize it's an old player piano. You try to stop it, but can't.\n\n");
                    room = 1;
                }
                else {
                    printf("You run out of the room and bump into a figure in the hallway.\n\n");
                    room = 1;
                }
                break;
            case 9:
                printf("You enter a room with a bookshelf in the center. What do you do?\n");
                printf("1) Check out the books\n");
                printf("2) Ignore the bookshelf and move to the next room\n");
                scanf("%d", &choice);
                if (choice == 1) {
                    printf("You check out the books and find a diary with entries from the previous residents of the haunted house.\n\n");
                    room++;
                }
                else {
                    printf("You move on to the next room, hoping to find a way out.\n\n");
                    room++;
                }
                break;
            case 10:
                printf("You enter the final room and see a figure in a cloak standing in the middle of the room.\n");
                printf("1) Approach the figure\n");
                printf("2) Back away slowly\n");
                scanf("%d", &choice);
                if (choice == 1) {
                    printf("You approach the figure and it disappears into thin air.\n\n");
                    printf("Congratulations, %s! You have survived the Haunted House Simulator.\n", name);
                    return 0;
                }
                else {
                    printf("You back away from the figure and hear its cold breathing on the back of your neck.\n\n");
                    room = 1;
                }
                break;
        }
    }
    return 0;
}