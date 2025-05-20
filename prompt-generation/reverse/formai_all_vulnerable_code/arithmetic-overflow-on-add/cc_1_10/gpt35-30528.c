//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to simulate a wait time
void wait(int seconds) {
    clock_t endwait;
    endwait = clock() + seconds * CLOCKS_PER_SEC;
    while (clock() < endwait) {}
}

int main() {
    printf("Welcome to the Haunted House Simulator!\n");
    printf("Press any key to begin...\n");
    getchar();
    system("clear"); // clear the screen for a new scene

    // Enter the Foyer
    printf("You enter the foyer. The door slams shut behind you.\n");
    wait(2);
    printf("You hear eerie creaking noises coming from the darkness.\n");
    wait(2);
    printf("You notice a lantern hanging on the wall.\n");
    printf("Do you want to take the lantern? (y/n)\n");
    char lantern_choice;
    scanf("%c", &lantern_choice);
    getchar(); // clear the input buffer
    if (lantern_choice == 'y') {
        printf("You take the lantern. It flickers on and off, casting spooky shadows on the walls.\n");
        wait(2);
    } else {
        printf("You leave the lantern. It's too dark to see anything.\n");
        wait(2);
    }

    // Enter the Dining Room
    printf("You make your way to the dining room. The table is set with rotten food.\n");
    wait(2);
    printf("You hear a faint whisper coming from the kitchen.\n");
    wait(2);
    printf("Do you want to investigate? (y/n)\n");
    char kitchen_choice;
    scanf("%c", &kitchen_choice);
    getchar(); // clear the input buffer
    if (kitchen_choice == 'y') {
        printf("You cautiously enter the kitchen. The pots and pans start clanging on their own.\n");
        wait(2);
        printf("You see a ghostly apparition in the corner. You turn and run back to the dining room.\n");
        wait(2);
    } else {
        printf("You decide not to investigate. You hear footsteps coming from the kitchen and run back to the foyer.\n");
        wait(2);
    }

    // Enter the Drawing Room
    printf("You enter the drawing room. The fireplace is lit but there's no one around.\n");
    wait(2);
    printf("You hear a loud knocking noise coming from the front door.\n");
    wait(2);
    printf("Do you want to answer the door? (y/n)\n");
    char door_choice;
    scanf("%c", &door_choice);
    getchar(); // clear the input buffer
    if (door_choice == 'y') {
        printf("You open the door. No one is there and the wind suddenly picks up.\n");
        wait(2);
        printf("The candles blow out and you hear a menacing laughter echoing through the halls.\n");
        wait(2);
    } else {
        printf("You ignore the knocking. Suddenly a shadowy figure appears and chases you back to the foyer.\n");
        wait(2);
    }

    // Enter the Library
    printf("You enter the library. The shelves are filled with ancient books and scrolls.\n");
    wait(2);
    printf("You see a small chest on the desk. Do you want to open it? (y/n)\n");
    char chest_choice;
    scanf("%c", &chest_choice);
    getchar(); // clear the input buffer
    if (chest_choice == 'y') {
        printf("You open the chest. A swarm of bats fly out and attack you!\n");
        wait(2);
    } else {
        printf("You decide not to open the chest. Suddenly the lights go out and you hear strange whispering voices.\n");
        wait(2);
    }

    // Enter the Bedroom
    printf("You make your way to the bedroom. There's a dusty bed and a dresser in the corner.\n");
    wait(2);
    printf("You notice a small key on the dresser. Do you want to take it? (y/n)\n");
    char key_choice;
    scanf("%c", &key_choice);
    getchar(); // clear the input buffer
    if (key_choice == 'y') {
        printf("You take the key. Suddenly the bed sheets start moving on their own.\n");
        wait(2);
        printf("You hear a distant scream and run back to the foyer, feeling like something is following you...\n");
        wait(2);
    } else {
        printf("You leave the key. The room suddenly goes cold and you hear a ghostly sigh behind you.\n");
        wait(2);
    }

    // Enter the Basement
    printf("You make your way to the basement. The air is damp and moldy.\n");
    wait(2);
    printf("You hear a faint whisper coming from the darkness. Do you want to investigate? (y/n)\n");
    char basement_choice;
    scanf("%c", &basement_choice);
    getchar(); // clear the input buffer
    if (basement_choice == 'y') {
        printf("You slowly descend the stairs. You feel a cold breeze and see your breath in the air.\n");
        wait(2);
        printf("You hear a voice whispering in your ear, 'get out'. You turn around and sprint back up the stairs to the foyer.\n");
        wait(2);
    } else {
        printf("You decide not to investigate. Suddenly you feel a hand grab your ankle and you fall down the stairs in terror...\n");
        wait(2);
    }

    // Escape the Haunted House
    printf("You run back to the foyer. The door is locked!\n");
    wait(2);
    printf("You remember the key in the bedroom and get it out of your pocket.\n");
    wait(2);
    printf("The key doesn't fit the lock!\n");
    wait(2);
    printf("You suddenly hear a voice: 'You can't escape me'.\n");
    wait(2);
    printf("But you keep trying different keys until one finally opens the door.\n");
    wait(2);
    printf("You burst through the door and run outside, never looking back.\n");
    wait(2);
    printf("Congratulations! You made it out alive!\n");

    return 0;
}