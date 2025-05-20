//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: romantic
#include <stdio.h>

int main()
{
    char choice;
    int location = 1;
    char name[20];

    printf("Welcome to the Enchanted Forest, %s.\n", name);

    while (location != 5)
    {
        switch (location)
        {
            case 1:
                printf("You are at the Forest's Edge.\n");
                printf("You see a worn stone path leading into the forest.\n");
                printf("What do you want to do? (A) Follow the path, (B) Search for a way around.\n");
                scanf(" %c", &choice);

                switch (choice)
                {
                    case 'a':
                        location = 2;
                        break;
                    case 'b':
                        location = 3;
                        break;
                    default:
                        printf("Invalid input.\n");
                        break;
                }
                break;

            case 2:
                printf("You are deep within the forest.\n");
                printf("You hear the chirping of birds and the rustling of leaves.\n");
                printf("What do you want to do? (C) Continue on the path, (D) Explore the surroundings.\n");
                scanf(" %c", &choice);

                switch (choice)
                {
                    case 'c':
                        location = 4;
                        break;
                    case 'd':
                        location = 3;
                        break;
                    default:
                        printf("Invalid input.\n");
                        break;
                }
                break;

            case 3:
                printf("You have found a clearing.\n");
                printf("In the center of the clearing, you see a sparkling stream.\n");
                printf("What do you want to do? (E) Drink from the stream, (F) Sit down on a rock.\n");
                scanf(" %c", &choice);

                switch (choice)
                {
                    case 'e':
                        printf("You take a refreshing drink of water.\n");
                        location = 1;
                        break;
                    case 'f':
                        printf("You sit down on a rock and enjoy the scenery.\n");
                        location = 1;
                        break;
                    default:
                        printf("Invalid input.\n");
                        break;
                }
                break;

            case 4:
                printf("You have reached a waterfall.\n");
                printf("The water falls gracefully over the rocks.\n");
                printf("What do you want to do? (G) Hike behind the falls, (H) Sit at the top of the falls.\n");
                scanf(" %c", &choice);

                switch (choice)
                {
                    case 'g':
                        location = 1;
                        break;
                    case 'h':
                        location = 3;
                        break;
                    default:
                        printf("Invalid input.\n");
                        break;
                }
                break;

            case 5:
                printf("You have reached the end of the forest.\n");
                printf("Thank you for your journey, %s.\n", name);
                break;
        }
    }

    return 0;
}