//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void waitForInput() {
    while (getchar() != '\n'); // wait for user input
}

int main() {

    char playerName[50];
    char input[50];
    int ans;

    printf("Welcome to the Paranoia Game.\n\n");
    printf("Enter your name to start playing: ");
    fgets(playerName, sizeof(playerName), stdin);
    playerName[strcspn(playerName, "\n")] = '\0';

    printf("Hello %s.\n\n", playerName);
    printf("Are you ready to play? (1 = yes / 0 = no): ");
    scanf("%d", &ans);

    if (ans == 0) {
        printf("That's too bad %s, maybe next time.\n", playerName);
        exit(0);
    }
    
    printf("Excellent, let's begin.\n");
    printf("You find yourself in a dark alley with two doors in front of you.\n");
    printf("One is red and the other is black. Which one will you choose? (red / black): ");
    
    waitForInput();

    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    if (strcmp(input, "red") == 0) {
        printf("\nYou open the red door and find yourself in a room with no windows and a single chair in the middle.\n");
        printf("As you approach the chair, you notice a note on the seat.\n");
        printf("It reads: 'You have been selected for a top-secret mission. Your life is in danger.\n");
        printf("Do not trust anyone. Get out of this room and find the key to the safe. It contains your next instruction.'\n\n");
        printf("You hear footsteps approaching the door.\n");
        printf("What do you do? (hide / fight): ");

        waitForInput();

        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "hide") == 0) {
            printf("\nYou hide behind the chair as the door opens.\n");
            printf("Two men enter the room and start searching for something.\n");
            printf("They don't seem to notice you and leave after a few minutes.\n");
            printf("You stand up and start searching the room for the key to the safe.\n");
            printf("You find a small key under the chair and locate the safe in the corner of the room.\n");
            printf("You insert the key and the safe opens.\n");
            printf("Inside, you find a note with your next instructions.\n");
            printf("The note reads: 'You must leave the building immediately. Do not trust anyone. The exit is on the third floor.'\n");
            printf("You leave the room and start making your way to the third floor.\n");
            printf("As you climb the stairs, you start to feel paranoid.\n");
            printf("You can't shake the feeling that someone is following you.\n");

            printf("\nWhat do you do? (keep going / go back): ");

            waitForInput();

            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = '\0';

            if (strcmp(input, "keep going") == 0) {
                printf("\nYou climb to the third floor and find the exit.\n");
                printf("As you open the door, you hear a gunshot and feel a sharp pain in your chest.\n");
                printf("You collapse on the ground as the last thing you see is a shadowy figure walking towards you.\n");
                printf("\nGAME OVER. You died from your paranoia.\n");
                exit(0);
            } else {
                printf("\nYou decide to go back down the stairs and try to find another exit.\n");
                printf("As you reach the second floor, you hear footsteps behind you.\n");
                printf("You turn around and see a masked figure with a gun pointed at you.\n");
                printf("'I told you not to trust anyone', the figure says as it pulls the trigger.\n");
                printf("\nGAME OVER. You died from your paranoia.\n");
                exit(0);
            }
        } else {
            printf("\nYou decide to fight the intruders. You grab the chair and swing it at them as they enter the room.\n");
            printf("One of them falls to the ground but the other pulls out a gun and shoots you in the chest.\n");
            printf("\nGAME OVER. You died trying to fight your paranoia.\n");
            exit(0);
        }
    } else {
        printf("\nYou open the black door and find yourself in a brightly lit room with no windows.\n");
        printf("There is a table in the center of the room with a note on it.\n");
        printf("The note reads: 'Congratulations, you have passed the first test. Proceed to the next room.'\n\n");
        printf("You hear a voice coming from the wall behind you.\n");
        printf("'Welcome %s, I hope you are enjoying the game so far.', the voice says.\n", playerName);
        printf("'You have three options. You can either leave this room, or continue and risk everything, or end the game now.'\n");
        printf("What do you choose? (leave / continue / end game): ");

        waitForInput();

        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "leave") == 0) {
            printf("\nYou decide to leave the game. As you approach the door, you hear a loud bang and feel a sharp pain in your back.\n");
            printf("You look behind you and see a dart sticking out of your skin, as you collapse onto the ground.\n");
            printf("'Never leave the game unfinished', the voice says as everything fades to black.\n");
            printf("\nGAME OVER. You died from your paranoia.\n");
            exit(0);
        } else if (strcmp(input, "end game") == 0) {
            printf("\nYou decide to end the game. As you touch the note, the room starts to shake.\n");
            printf("The walls crack and you see a bright light coming through the cracks.\n");
            printf("You feel your body being ripped apart as you are sucked into the light.\n");
            printf("\nGAME OVER. You died from your paranoia.\n");
            exit(0);
        } else {
            printf("\nYou decide to continue the game. You find a door on the other side of the room and open it.\n");
            printf("Inside, you see a long hallway with multiple doors.\n");
            printf("You hear footsteps behind you and turn around, but there is no one there.\n");
            printf("You start walking down the hallway and try to find the right door.\n");
            printf("Every door seems to be locked except for one at the end of the hallway.\n");
            printf("You approach the door and hear a strange noise coming from inside.\n");

            printf("\nWhat do you do? (open the door / go back): ");

            waitForInput();

            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = '\0';

            if (strcmp(input, "open the door") == 0) {
                printf("\nYou open the door and see a large room with a throne in the center.\n");
                printf("On the throne sits a dark figure with its back turned to you.\n");
                printf("'Welcome %s, I have been expecting you', the figure says as it turns around.\n", playerName);
                printf("You see that the figure has a mask on its face and can't make out its features.\n");
                printf("'You have done well so far in this game', the figure continues.\n");
                printf("'But this is where it ends, I'm afraid.'\n");
                printf("The figure stands up and reveals a long sword in its hands.\n");
                printf("'It's time for you to die', the figure says as it raises the sword.\n");
                printf("\nWhat do you do? (fight / run): ");

                waitForInput();

                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = '\0';

                if (strcmp(input, "fight") == 0) {
                    printf("\nYou decide to fight the figure. The figure charges at you with the sword.\n");
                    printf("You dodge the attack and punch the figure in the face, causing its mask to fall off.\n");
                    printf("Underneath the mask, you see your own face staring back at you.\n");
                    printf("You realize that you have been playing against yourself this whole time.\n");
                    printf("'Congratulations %s, you have proven to be the most paranoid person', your own voice says.\n", playerName);
                    printf("'But can you trust me?' you ask yourself as everything fades to black.\n");
                    printf("\nGAME OVER. You died from your paranoia.\n");
                    exit(0);
                } else {
                    printf("\nYou decide to run away. The figure swings the sword at you and misses.\n");
                    printf("You start running down the hallway, but the doors are now open and you can't find your way out.\n");
                    printf("You keep running until you reach the end of the hallway and run into a wall.\n");
                    printf("You turn around and see the figure approaching you with the sword.\n");
                    printf("'I told you not to run', the figure says as it swings the sword at you.\n");
                    printf("\nGAME OVER. You died from your paranoia.\n");
                    exit(0);
                }
            } else {
                printf("\nYou decide to go back. As you turn around, you see a shadowy figure standing in front of you.\n");
                printf("'I told you not to turn back', the figure says as it pulls out a knife.\n");
                printf("You try to run away but the figure catches up to you and stabs you in the back.\n");
                printf("\nGAME OVER. You died from your paranoia.\n");
                exit(0);
            }
        }
    }

    return 0;
}