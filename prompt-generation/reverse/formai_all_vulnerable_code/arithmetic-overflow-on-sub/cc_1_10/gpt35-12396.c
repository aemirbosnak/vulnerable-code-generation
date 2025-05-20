//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: optimized
#include <stdio.h>

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1)
    {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main()
{
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);

    //Disk position.
    int pos[n][3];

    for(int i=0;i<n;i++)
    {
        pos[i][0]=i+1;
        pos[i][1]=0;
        pos[i][2]=0;
    }

    //Assigning columns.
    pos[0][1]=1;
    pos[0][2]=0;

    //Printing the initial configuration of Tower of Hanoi.
    printf("\nInitial configuration of the tower of Hanoi:\n\n");
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<3;j++)
        {
            if(pos[i][j] == 0) printf("     |     ");
            else printf("     %d     ", pos[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are names of rods

    //Printing the final configuration of Tower of Hanoi.
    printf("\nFinal configuration of the tower of Hanoi:\n\n");
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<3;j++)
        {
            if(pos[i][j] == 0) printf("     |     ");
            else printf("     %d     ", pos[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}