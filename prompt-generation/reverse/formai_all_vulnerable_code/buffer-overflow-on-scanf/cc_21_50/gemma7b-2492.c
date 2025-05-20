//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char name[20];
    printf("Please tell me your name: ");
    scanf("%s", name);

    printf("Hello, %s! Welcome to the Curious Castle of Quibble.\n", name);

    int room = 1;
    while (room != 5)
    {
        switch (room)
        {
            case 1:
                printf("You are in the Grand Hall. There is a sparkling fountain in the center.\n");
                printf("What do you want to do? (1) Go north, (2) Go south, (3) Go east, (4) Go west\n");
                int choice = scanf("Enter your choice: ");
                switch (choice)
                {
                    case 1:
                        room = 2;
                        break;
                    case 2:
                        room = 3;
                        break;
                    case 3:
                        room = 4;
                        break;
                    case 4:
                        room = 5;
                        break;
                    default:
                        printf("Invalid choice.\n");
                        break;
                }
                break;
            case 2:
                printf("You are in the Secret Library. There are many books on the shelves.\n");
                printf("What do you want to do? (1) Read a book, (2) Go north, (3) Go east\n");
                choice = scanf("Enter your choice: ");
                switch (choice)
                {
                    case 1:
                        printf("You read a book and learned a lot of things.\n");
                        room = 1;
                        break;
                    case 2:
                        room = 3;
                        break;
                    case 3:
                        room = 4;
                        break;
                    default:
                        printf("Invalid choice.\n");
                        break;
                }
                break;
            case 3:
                printf("You are in the Garden. There are many flowers and plants.\n");
                printf("What do you want to do? (1) Go north, (2) Go south, (3) Go east, (4) Go west\n");
                choice = scanf("Enter your choice: ");
                switch (choice)
                {
                    case 1:
                        room = 2;
                        break;
                    case 2:
                        room = 5;
                        break;
                    case 3:
                        room = 4;
                        break;
                    case 4:
                        room = 1;
                        break;
                    default:
                        printf("Invalid choice.\n");
                        break;
                }
                break;
            case 4:
                printf("You are in the Tower. There is a view of the entire castle.\n");
                printf("What do you want to do? (1) Go north, (2) Go south, (3) Go east, (4) Go west\n");
                choice = scanf("Enter your choice: ");
                switch (choice)
                {
                    case 1:
                        room = 3;
                        break;
                    case 2:
                        room = 5;
                        break;
                    case 3:
                        room = 4;
                        break;
                    case 4:
                        room = 1;
                        break;
                    default:
                        printf("Invalid choice.\n");
                        break;
                }
                break;
            case 5:
                printf("You have reached the top of the castle. You have won!\n");
                break;
        }
    }

    return 0;
}