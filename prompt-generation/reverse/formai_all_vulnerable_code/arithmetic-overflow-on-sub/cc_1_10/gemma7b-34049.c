//Gemma-7B DATASET v1.0 Category: Procedural Space Adventure ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int x = 0, y = 0, z = 0;
    char c;

    printf("Enter 'n' to navigate, 's' to surrender:\n");
    scanf("%c", &c);

    switch (c)
    {
        case 'n':
            printf("Enter coordinates (x, y, z):\n");
            scanf("%d %d %d", &x, &y, &z);

            printf("You are at (%d, %d, %d). Press 'w' to go west, 'e' to go east, 's' to go south, 'n' to go north:\n", x, y, z);
            scanf("%c", &c);

            switch (c)
            {
                case 'w':
                    x--;
                    printf("You moved west to (%d, %d, %d).\n", x, y, z);
                    break;
                case 'e':
                    x++;
                    printf("You moved east to (%d, %d, %d).\n", x, y, z);
                    break;
                case 's':
                    y--;
                    printf("You moved south to (%d, %d, %d).\n", x, y, z);
                    break;
                case 'n':
                    y++;
                    printf("You moved north to (%d, %d, %d).\n", x, y, z);
                    break;
                default:
                    printf("Invalid input.\n");
            }

            break;
        case 's':
            printf("Surrendering.\n");
            exit(0);
            break;
        default:
            printf("Invalid input.\n");
    }

    main();
}