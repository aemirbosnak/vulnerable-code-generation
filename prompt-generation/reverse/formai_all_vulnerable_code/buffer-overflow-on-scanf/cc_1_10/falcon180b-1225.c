//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 1000

int count=0;

void count_aliens(int x, int y, int depth)
{
    if(depth==0)
    {
        printf("\n");
        for(int i=0; i<y; i++)
        {
            for(int j=0; j<x; j++)
            {
                printf("* ");
            }
            printf("\n");
        }
        count++;
    }
    else
    {
        int dx=0;
        int dy=0;
        srand(time(NULL));
        int num=rand()%3;
        if(num==0)
        {
            dx=1;
        }
        else if(num==1)
        {
            dy=1;
        }
        else
        {
            dx=1;
            dy=1;
        }

        for(int i=0; i<y; i++)
        {
            for(int j=0; j<x; j++)
            {
                if(i+dx<y && j+dy<x)
                {
                    if(depth%2==0)
                    {
                        if(j+dx>=0 && j+dx<x && i+dy>=0 && i+dy<y)
                        {
                            count_aliens(x, y, depth-1);
                        }
                    }
                    else
                    {
                        if(j+dy>=0 && j+dy<x && i+dx>=0 && i+dx<y)
                        {
                            count_aliens(x, y, depth-1);
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    int x, y;
    printf("\nEnter the size of the grid: ");
    scanf("%d %d", &x, &y);
    count_aliens(x, y, 4);
    printf("\nTotal number of aliens: %d", count);
    return 0;
}