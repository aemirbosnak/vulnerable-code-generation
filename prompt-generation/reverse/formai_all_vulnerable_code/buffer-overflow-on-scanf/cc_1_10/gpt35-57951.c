//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void play_game();
void print_boundary();
void print_menu();
void print_story();
void print_clue();
void print_ending();

int main()
{
    printf("\n\n\nWelcome to the Cryptic Adventure Game!\n\n");
    printf("You will be entering a mysterious world filled with puzzles and challenges\n");
    printf("Get ready to exercise your brain and solve the mystery\n\n");

    play_game();

    return 0;
}

void play_game()
{
    int choice;

    print_story();

    while (1)
    {
        print_menu();

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nYou choose wisely.\n\n");
            print_clue();
            break;
        case 2:
            printf("\nYou try to guess the answer, but it's incorrect.\n\n");
            break;
        case 3:
            printf("\nYou give up and leave the game.\n\n");
            exit(0);
        default:
            printf("\nInvalid choice! Try again.\n\n");
            break;
        }

        print_boundary();
    }
}

void print_boundary()
{
    printf("--------------------------------------------------\n");
}

void print_menu()
{
    printf("What would you like to do?\n\n");
    printf("1. Get a clue\n");
    printf("2. Guess the answer\n");
    printf("3. Give up\n\n");
    printf("Enter your choice: ");
}

void print_story()
{
    printf("\n\n\nYou find yourself in a dimly lit room with no memory of how you got here.\n");
    printf("As you take in your surroundings, you notice a note on a table nearby.\n");
    printf("The note reads: 'Welcome to the Cryptic Adventure Game. To escape, you must solve the riddle.'\n");
    printf("You look around and see a single door with a strange symbol etched on it.\n");
    printf("You feel a sense of urgency and apprehension as you realize your only way out is through the door.\n\n");
}

void print_clue()
{
    printf("The riddle goes as follows: \n\n");
    printf("I am taken from a mine, and shut up in a wooden case, from which I am never released, and yet I am used by almost every person. What am I?\n\n");
    printf("To solve the riddle, you must think cryptically...\n");
}

void print_ending()
{
    printf("\n\n\nCongratulations! You have successfully solved the riddle and escaped from the mysterious room!\n");
    printf("You look around and notice that you are now in a lush forest with a clear blue sky above.\n");
    printf("You take a deep breath and feel a sense of freedom and relief.\n\n");
    printf("Thanks for playing the Cryptic Adventure Game. See you again soon!\n\n");
}