//FormAI DATASET v1.0 Category: Recursive ; Style: Romeo and Juliet
// Romeo and Juliet in C Recursive Example Program

#include <stdio.h>
#include <stdlib.h>

void love(int count)
{
    if(count > 0)
    {
        love(count-1);
        printf("Juliet: My dear Romeo, I love you more than ever before.\n");
        love(count-1);
    }
}

void sacrifice(int count)
{
    if(count > 0)
    {
        sacrifice(count-1);
        printf("Romeo: My dear Juliet, I am willing to sacrifice anything for you.\n");
        sacrifice(count-1);
    }
}

void separation(int count)
{
    if(count > 0)
    {
        separation(count-1);
        printf("Juliet: Romeo, why must we be apart?\n");
        separation(count-1);
    }
}

int main()
{
    int loveCount, sacrificeCount, separationCount;

    printf("Romeo: My love for you grows stronger with each passing day.\n");
    printf("Juliet: And my love for you is stronger than the strongest oak.\n");

    printf("Romeo: I am willing to express my love for you %d times.\n", loveCount);
    scanf("%d", &loveCount);
    love(loveCount);

    printf("Juliet: I am willing to sacrifice for you %d times.\n", sacrificeCount);
    scanf("%d", &sacrificeCount);
    sacrifice(sacrificeCount);

    printf("Romeo: We must endure this separation %d times.\n", separationCount);
    scanf("%d", &separationCount);
    separation(separationCount);

    printf("Juliet: Romeo, we will overcome all obstacles and be together forever.\n");
    printf("Romeo: Yes, my love. We will conquer all obstacles and be together forever.\n");

    return 0;
}