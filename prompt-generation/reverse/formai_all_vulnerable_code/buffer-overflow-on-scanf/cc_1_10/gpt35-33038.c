//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: mind-bending
#include <stdio.h>

void move(int count, char source, char aux, char target)
{
    if (count == 1)
    {
        printf("Move disk 1 from %c to %c\n", source, target);
        return;
    }

    move(count-1, source, target, aux);
    printf("Move disk %d from %c to %c\n", count, source, target);
    move(count-1, aux, source, target);
}

int main()
{
    int n;

    printf("Welcome to the Tower of Hanoi Problem!\n\n");

    while (1)
    {
        printf("Enter the number of disks (1-8): ");
        scanf("%d", &n);

        if (n < 1 || n > 8)
        {
            printf("Invalid input. Please try again.\n\n");
            continue;
        }

        printf("\n");

        move(n, 'A', 'B', 'C');

        printf("\n");

        printf("Do you want to play again? (Y/N): ");

        char answer;
        scanf(" %c", &answer);

        if (answer == 'N' || answer == 'n')
        {
            printf("\nThanks for playing. Goodbye!\n");
            break;
        }

        printf("\n");
    }

    return 0;
}