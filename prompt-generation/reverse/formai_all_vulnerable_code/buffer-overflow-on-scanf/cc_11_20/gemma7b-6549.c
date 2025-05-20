//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

void main()
{
    system("CLS");
    printf("Welcome to the Haunted House of Morrigan Manor!\n");
    printf("Prepare for a spooky adventure...\n");

    // Create a random number between 1 and 10 to determine the haunted item
    int item = rand() % 10 + 1;

    // Display the haunted item
    switch (item)
    {
        case 1:
            printf("You encounter a disembodied hand reaching out from the darkness.\n");
            break;
        case 2:
            printf("A bloodstained letter appears before you, warning of impending doom.\n");
            break;
        case 3:
            printf("A ghostly figure whispers secrets into your ear.\n");
            break;
        case 4:
            printf("A shattered mirror reflects your own terrified image.\n");
            break;
        case 5:
            printf("A creepy doll with an unsettling smile watches you move around.\n");
            break;
        case 6:
            printf("You hear the faint sound of voices whispering your name.\n");
            break;
        case 7:
            printf("A cold wind blows through the halls, carrying the scent of decay.\n");
            break;
        case 8:
            printf("A disembodied head rolls its eyes at you, mocking your fear.\n");
            break;
        case 9:
            printf("A ghostly hand grabs you and drags you towards the abyss.\n");
            break;
        case 10:
            printf("You find a hidden diary detailing the tragic history of Morrigan Manor.\n");
            break;
    }

    // Ask the user if they want to continue
    char answer;
    printf("Do you want to continue your journey? (Y/N): ");
    scanf("%c", &answer);

    // If the user wants to continue, start the process again
    if (answer == 'Y' || answer == 'y')
    {
        main();
    }
    else
    {
        printf("Thank you for visiting the Haunted House of Morrigan Manor. Come again soon!\n");
    }
}