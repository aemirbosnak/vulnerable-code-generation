//Gemma-7B DATASET v1.0 Category: Ebook reader ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");
    printf("A parchment unfolds before you, the ink smoldering. You find yourself amidst the pages of a worn leather book, its contents tantalizing.\n");

    char input;
    int page = 1;

    while (1)
    {
        // Display the text for the current page
        switch (page)
        {
            case 1:
                printf("The tattered cover reveals a tale of ancient times, of a hero named Aric and his journey to save the world from a tyrannical force.\n");
                break;
            case 2:
                printf("Aric encounters a mysterious character named Morgana, a sorceress with a wicked reputation. She offers him a deal, one that he cannot refuse.\n");
                break;
            case 3:
                printf("With the help of his newfound allies, Aric battles the evil force and begins to unravel the secrets of the past.\n");
                break;
            case 4:
                printf("Aric's journey leads him to a final confrontation with the mastermind behind the tyranny. A battle of wits and strength ensues.\n");
                break;
            case 5:
                printf("In the end, Aric triumphs over evil, and the peace is restored to the world.\n");
                break;
            default:
                printf("The book comes to an end. You have reached the final page.\n");
                break;
        }

        // Get the user's input
        printf("Please press any key to continue... ");
        scanf("%c", &input);

        // Turn to the next page
        page++;

        // Clear the screen
        system("clear");

        // Start the story from the beginning
        if (input == 'c' || input == 'C')
            page = 1;
    }

    return 0;
}