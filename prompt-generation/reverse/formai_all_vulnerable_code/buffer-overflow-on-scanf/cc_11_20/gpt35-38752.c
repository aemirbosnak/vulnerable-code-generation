//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char name[50];
    char choice[10];
    char answer[10];
    int room = 1;
    int play_again = 1;
    int solved = 0;

    printf("Hello, I am Sherlock Holmes. What is your name?\n");
    scanf("%s", name);
    printf("Welcome, %s. You have been called in to investigate a haunting at an old mansion.\n", name);
    printf("You arrive at the mansion and knock on the door. A butler answers and shows you into the foyer.\n");

    while(play_again)
    {
        switch(room)
        {
            case 1:
                printf("You are in the foyer. There are two doors, one to your left and one to your right. Which do you choose? (left/right)\n");
                scanf("%s", choice);
                if(strcmp(choice, "left") == 0)
                {
                    printf("You enter the left door and find yourself in a dimly lit room. You hear something rattling in the corner. Do you investigate? (yes/no)\n");
                    scanf("%s", answer);
                    if(strcmp(answer, "yes") == 0)
                    {
                        printf("You investigate the noise and find a skeleton chained to the wall. It has a key ring in its hand. You take the key ring and return to the foyer.\n");
                        room = 2;
                    }
                    else
                    {
                        printf("You decide not to investigate and return to the foyer.\n");
                    }
                }
                else if(strcmp(choice, "right") == 0)
                {
                    printf("You enter the right door and find yourself in a library. There are bookcases lining the walls and a desk in the center of the room. You notice a book on the desk with a note attached. Do you read the note? (yes/no)\n");
                    scanf("%s", answer);
                    if(strcmp(answer, "yes") == 0)
                    {
                        printf("You read the note, which says 'The key to solving the mystery is in the painting.' You take note of this and return to the foyer.\n");
                        room = 2;
                    }
                    else
                    {
                        printf("You decide not to read the note and return to the foyer.\n");
                    }
                }
                else
                {
                    printf("Invalid choice. Please choose left or right.\n");
                }
                break;

            case 2:
                printf("You are back in the foyer. There is a painting on the wall in front of you. Do you examine the painting? (yes/no)\n");
                scanf("%s", answer);
                if(strcmp(answer, "yes") == 0)
                {
                    printf("You examine the painting and find a hidden compartment. You open the compartment and find a journal. You begin to read the journal and find a clue to the haunting. You realize that the haunting is a hoax and solve the mystery!\n");
                    solved = 1;
                }
                else
                {
                    printf("You decide not to examine the painting and return to the room you came from.\n");
                }
                break;
        }

        if(solved)
        {
            printf("Congratulations, %s! You have solved the mystery and exposed the hoax.\n", name);
            printf("Would you like to play again? (yes/no)\n");
            scanf("%s", answer);
            if(strcmp(answer, "yes") == 0)
            {
                room = 1;
                solved = 0;
            }
            else
            {
                play_again = 0;
            }
        }
    }

    printf("Thank you for playing, %s. Goodbye!\n", name);

    return 0;
}