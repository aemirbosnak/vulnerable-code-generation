//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char name[20];
    char suspect[20];
    char weapon[20];
    int room_num;
    int i;

    printf("Welcome to 221B Baker Street, Mr./Ms. Detective. Please provide your name: ");
    scanf("%s", name);

    printf("What is the name of the suspect: ");
    scanf("%s", suspect);

    printf("What weapon was used in the crime: ");
    scanf("%s", weapon);

    printf("What room number was the crime committed in: ");
    scanf("%d", &room_num);

    printf("Now, Mr./Ms. %s, let's investigate...", name);

    for (i = 0; i < 10; i++)
    {
        printf("------------------------------------------------------------------------\n");
    }

    printf("We have gathered the following information:\n");
    printf("Name: %s\n", suspect);
    printf("Weapon: %s\n", weapon);
    printf("Room Number: %d\n", room_num);

    if (strcmp(weapon, "A Hunting Knife") == 0)
    {
        printf("The weapon used in this crime was a Hunting Knife, which is a common weapon in our neighborhood.\n");
    }
    else if (strcmp(weapon, "A Sword") == 0)
    {
        printf("The weapon used in this crime was a Sword, which is a less common weapon in our neighborhood.\n");
    }
    else if (strcmp(weapon, "A Gun") == 0)
    {
        printf("The weapon used in this crime was a Gun, which is the most common weapon used in crimes in our neighborhood.\n");
    }

    printf("Based on this information, I have concluded that the suspect is %s and that he committed the crime in room number %d.\n", suspect, room_num);

    return 0;
}