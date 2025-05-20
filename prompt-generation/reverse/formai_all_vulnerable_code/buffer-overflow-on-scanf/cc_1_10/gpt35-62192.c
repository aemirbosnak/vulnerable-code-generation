//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: real-life
#include <stdio.h>
#include <string.h>

int game() {

    printf("Welcome to Real Life Adventure!\n\n");
  
    printf("You wake up in a dark room, your head pounding and your vision blurry.\n");
    printf("You feel around and discover a piece of paper in your pocket.\n");
    printf("It reads: 'You have been kidnapped. Find a way to escape.'\n\n");
  
    printf("What do you do?\n\n");
    printf("A) Look for a light switch.\n");
    printf("B) Check the door.\n");
    printf("C) Try to break the window.\n");
  
    char choice1;
    scanf(" %c", &choice1);
    if(choice1 == 'A') {
        printf("You feel along the wall and find a light switch.\n");
        printf("You turn it on and see that you are in a small, empty room.\n");
        printf("You also notice a keyhole on the door.\n");
      
        printf("What do you do?\n\n");
        printf("A) Look for the key.\n");
        printf("B) Try to pick the lock.\n");
        printf("C) Use brute force.\n");
      
        char choice2;
        scanf(" %c", &choice2);
        if(choice2 == 'A') {
            printf("You look around the room and find the key under the mattress.\n");
            printf("You use the key to open the door and make your escape.\n");
            printf("Congratulations, you have won the game!\n");
            return 0;
        }
        else if(choice2 == 'B') {
            printf("You try to pick the lock, but you lack the necessary skills.\n");
            printf("You hear footsteps outside and realize you are out of time.\n");
            printf("The kidnapper comes into the room and captures you.\n");
            printf("Sorry, you have lost the game.\n");
            return 0;
        }
        else if(choice2 == 'C') {
            printf("You try to break down the door, but it is too strong.\n");
            printf("You hear footsteps outside and realize you are out of time.\n");
            printf("The kidnapper comes into the room and captures you.\n");
            printf("Sorry, you have lost the game.\n");
            return 0;
        }
        else {
            printf("Invalid choice.\n");
            return game();
        }
    }
    else if(choice1 == 'B') {
        printf("You try the door, but it is locked.\n");
        printf("You notice a keypad next to the door.\n");
      
        printf("What do you do?\n\n");
        printf("A) Guess the code.\n");
        printf("B) Look for clues.\n");
        printf("C) Try to break the keypad.\n");
      
        char choice3;
        scanf(" %c", &choice3);
        if(choice3 == 'A') {
            printf("You try to guess the code, but you are unsuccessful.\n");
            printf("You hear footsteps outside and realize you are out of time.\n");
            printf("The kidnapper comes into the room and captures you.\n");
            printf("Sorry, you have lost the game.\n");
            return 0;
        }
        else if(choice3 == 'B') {
            printf("You search the room and find a note.\n");
            printf("It reads: 'The code is the year of my birth.'\n");
            printf("You enter the year and hear a click.\n");
            printf("The door opens and you make your escape.\n");
            printf("Congratulations, you have won the game!\n");
            return 0;
        }
        else if(choice3 == 'C') {
            printf("You try to break the keypad, but it is too sturdy.\n");
            printf("You hear footsteps outside and realize you are out of time.\n");
            printf("The kidnapper comes into the room and captures you.\n");
            printf("Sorry, you have lost the game.\n");
            return 0;
        }
        else {
            printf("Invalid choice.\n");
            return game();
        }
    }
    else if(choice1 == 'C') {
        printf("You try to break the window, but it is too thick.\n");
        printf("You hear footsteps outside and realize you are out of time.\n");
        printf("The kidnapper comes into the room and captures you.\n");
        printf("Sorry, you have lost the game.\n");
        return 0;
    }
    else {
        printf("Invalid choice.\n");
        return game();
    }
}

int main() {

    game();

    return 0;
}