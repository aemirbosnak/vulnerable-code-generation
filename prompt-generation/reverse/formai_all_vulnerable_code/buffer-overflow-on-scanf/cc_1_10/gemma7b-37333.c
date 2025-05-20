//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 10

int main()
{
    int choice, i, score = 0, crime_scene = 1, detective_mode = 1;
    char name[MAX_NUM];

    printf("Welcome to 221B Baker Street, Mr. Sherlock Holmes.\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    while (detective_mode)
    {
        printf("\nYou are in the grand hall of the wealthy Mr. Bartholomew's estate.\n");
        printf("Three suspects are present: Mr. Bartholomew, his butler, Mr. Jennings, and the maid, Miss Jennings.\n");

        printf("What would you like to do? (1) Examine the suspects, (2) Search the room, (3) Question Mr. Bartholomew, (4) Question Miss Jennings, (5) Question Mr. Jennings: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("You meticulously examine the suspects, but find no evidence of foul play.\n");
                break;
            case 2:
                printf("You search the room for clues, but discover nothing out of the ordinary.\n");
                break;
            case 3:
                printf("You question Mr. Bartholomew, but he insists that he is innocent.\n");
                break;
            case 4:
                printf("You question Miss Jennings, and she reveals a secret relationship with Mr. Bartholomew.\n");
                break;
            case 5:
                printf("You question Mr. Jennings, but he offers no information about the case.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        // Deduction logic based on the player's choices
        if (score >= 5)
        {
            printf("Congratulations, Mr. Holmes. You have solved the case. Mr. Bartholomew was the murderer.\n");
            detective_mode = 0;
        }
        else
        {
            printf("Continue your investigation, Mr. Holmes. More clues to be found.\n");
        }
    }

    printf("Thank you for playing, %s. May you solve many more mysteries.\n", name);

    return 0;
}