//Gemma-7B DATASET v1.0 Category: Ebook reader ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("cls");
    printf("Welcome to the wacky ebook reader!\n");

    // Declare a bunch of wacky ebook titles
    char *ebook_titles[] = {"The Cat Who Saved the World", "The Rainbow Unicorn", "The Exploding Avocado", "The Talking Tomato", "The Curious Case of the Missing Sock"};

    // Display the ebook titles
    printf("Here are the available ebooks:\n");
    for(int i = 0; i < 5; i++)
    {
        printf("%d. %s\n", i + 1, ebook_titles[i]);
    }

    // Get the user's choice
    int choice = 0;
    printf("Please choose a book number: ");
    scanf("%d", &choice);

    // Open the chosen ebook
    char *ebook_content = NULL;
    switch(choice)
    {
        case 1:
            ebook_content = "Once upon a time, there was a cat named Fluffy who saved the world from a bunch of evil aliens.";
            break;
        case 2:
            ebook_content = "The rainbow unicorn was a magical creature who could talk to humans and fly faster than a jet plane.";
            break;
        case 3:
            ebook_content = "The exploding avocado was a fruit that could explode when it was ripe.";
            break;
        case 4:
            ebook_content = "The talking tomato was a tomato that could speak human words.";
            break;
        case 5:
            ebook_content = "The curious case of the missing sock was a mystery about a sock that mysteriously disappeared.";
            break;
    }

    // Display the ebook content
    printf("Here is the ebook content:\n");
    printf("%s", ebook_content);

    // Close the ebook
    free(ebook_content);

    // Play a wacky song
    system("start wow.mp3");

    return 0;
}