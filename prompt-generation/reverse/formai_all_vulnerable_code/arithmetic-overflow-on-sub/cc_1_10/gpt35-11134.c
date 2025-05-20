//FormAI DATASET v1.0 Category: Pattern printing ; Style: Romeo and Juliet
/* Romeo and Juliet Pattern Printing */

#include <stdio.h>

int main()
{
    int rows, i, j, k, sp=1;

    printf("Oh Romeo, how art thou?\n\n");

    printf("Speak, fair maid. What wilt thou have me do?\n\n");

    printf("I would have thee print a pattern, kind sir.\n\n");

    printf("A pattern, thou sayeth? Of what manner?\n\n");

    printf("In the manner of thy heart, dear Romeo. A pattern of love and passion.\n\n");

    printf("As thou commandeth, my lady. Behold the pattern of our hearts:\n\n");

    printf("How many rows shall this pattern of love have, fair maiden?\n\n");

    scanf("%d", &rows);

    printf("\n");

    sp = rows - 1;

    for (i = 1; i <= rows; i++)
    {
        for (j = 1; j <= sp; j++)
        {
            printf(" ");
        }

        sp--;

        for (j = 1; j <= 2*i-1; j++)
        {
            printf("*");
        }

        printf("\n");
    }

    sp = 1;

    for (i = 1; i <= rows-1; i++)
    {
        for (j = 1; j <= sp; j++)
        {
            printf(" ");
        }

        sp++;

        for (j = 1; j <= 2*(rows-i)-1; j++)
        {
            printf("*");
        }

        printf("\n");
    }

    printf("\n");

    printf("Oh Juliet, how my heart beats for thee.\n\n");

    printf("And with this pattern of our love before us, let us be inseparable forevermore.\n\n");

    printf("Forevermore, my sweet, sweet Romeo.\n\n");

    printf("And with that, let us end our tale of love and heartache. The end.\n");

    return 0;
}