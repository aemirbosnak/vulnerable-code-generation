//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Characters
    char name[20];
    char occupation[20];
    int age;

    // Setting the scene
    printf("You wake up in a dimly lit room, the smell of pipe tobacco and old books filling your senses.\n");

    // Gathering information about the player
    printf("Please tell me your name: ");
    scanf("%s", name);

    printf("What is your occupation: ");
    scanf("%s", occupation);

    printf("How old are you: ");
    scanf("%d", &age);

    // Clues and suspects
    char clue1[50] = "A locked letter on the desk, with a single page missing.";
    char suspect1[50] = "Mr. Moriarty, a wealthy businessman with a mysterious past.";
    char suspect2[50] = "Mr. Watson, a loyal detective, known for his sharp wit and deduction skills.";
    char suspect3[50] = "Mrs. Hudson, the housekeeper, a kind but suspicious character.";

    // Investigation begins
    printf("You begin to investigate the room, searching for clues.\n");

    // Check if the player has found the first clue
    if (strcmp(clue1, name) == 0)
    {
        printf("You have found the first clue: %s\n", clue1);
    }

    // Identify the suspect
    if (strcmp(suspect1, name) == 0)
    {
        printf("You have identified the suspect: %s\n", suspect1);
    }
    else if (strcmp(suspect2, name) == 0)
    {
        printf("You have identified the suspect: %s\n", suspect2);
    }
    else if (strcmp(suspect3, name) == 0)
    {
        printf("You have identified the suspect: %s\n", suspect3);
    }

    // Conclusion
    printf("Congratulations, %s, you have solved the case!\n", name);

    return 0;
}