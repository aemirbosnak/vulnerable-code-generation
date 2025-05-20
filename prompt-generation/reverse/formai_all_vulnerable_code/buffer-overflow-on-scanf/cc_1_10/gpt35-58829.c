//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char name[20];
    int age;
    printf("Welcome to the mind-bending adventure game! What is your name? ");
    scanf("%s", name);
    printf("Hello, %s! How old are you? ", name);
    scanf("%d", &age);
    
    if(age < 18) {
        printf("I'm sorry, %s. You are too young to play this game.\n", name);
        return 0;
    }
    
    printf("Great! You are old enough to take on the challenge. You find yourself in a dark room. The only light comes from a small candle that flickers on a table next to you. There is a door on the other side of the room. What do you do?\n");
    printf("1. Walk to the door.\n");
    printf("2. Blow out the candle.\n");
    printf("3. Look around the room.\n");
    
    int choice;
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            printf("You walk to the door and try the handle. It's locked.\n");
            printf("1. Knock on the door.\n");
            printf("2. Search the room for a key.\n");
            printf("3. Try to break down the door.\n");
            scanf("%d", &choice);
            switch(choice) {
                case 1:
                    printf("You knock on the door, but there is no answer.\n");
                    break;
                case 2:
                    printf("You search the room and find a key in a drawer.\n");
                    printf("1. Try the key in the door.\n");
                    printf("2. Use the key on the chest in the corner.\n");
                    scanf("%d", &choice);
                    switch(choice) {
                        case 1:
                            printf("The key fits and the door unlocks. You escape the room.\n");
                            break;
                        case 2:
                            printf("You use the key on the chest and it creaks open. Inside is a small creature with tentacles for a face. It latches onto you and you feel your mind being probed. You scream as you lose control of your thoughts and actions.\n");
                            break;
                        default:
                            printf("That's not a valid choice. You lose your chance to escape the room.\n");
                            break;
                    }
                    break;
                case 3:
                    printf("You kick and punch the door, but it won't budge. Your efforts are futile.\n");
                    break;
                default:
                    printf("That's not a valid choice. You lose your chance to escape the room.\n");
                    break;
            }
            break;
        case 2:
            printf("You blow out the candle and the room is plunged into darkness. Suddenly, you feel a cold hand grab your shoulder. You scream as the hand pulls you into an abyss.\n");
            break;
        case 3:
            printf("You look around the room and see strange symbols etched into the walls. As you study them, you hear a whisper in your ear. You can't make out what it's saying, but it sends shivers down your spine.\n");
            break;
        default:
            printf("That's not a valid choice. You lose your chance to escape the room.\n");
            break;
    }
    
    printf("Thanks for playing, %s! Your mind-bending adventure has come to an end.\n", name);
    return 0;
}