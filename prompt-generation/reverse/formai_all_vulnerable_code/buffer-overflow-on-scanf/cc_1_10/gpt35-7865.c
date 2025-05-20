//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: safe
#include<stdio.h>
#include<stdlib.h>

void TowerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1)
    {
        printf("\n Move disk 1 from rod %c to rod %c", from_rod, to_rod);
        return;
    }
    TowerOfHanoi(n-1, from_rod, aux_rod, to_rod);
    printf("\n Move disk %d from rod %c to rod %c", n, from_rod, to_rod);
    TowerOfHanoi(n-1, aux_rod, to_rod, from_rod);
}

int main()
{
    int n;
    char start, end, mid;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("\nEnter the start rod (A, B, C): ");
    scanf(" %c", &start);
    printf("\nEnter the end rod (A, B, C): ");
    scanf(" %c", &end);
    printf("\nEnter the middle rod (A, B, C): ");
    scanf(" %c", &mid);
  
    if(start=='C' && end=='A'){
        char temp=end;
        end=start;
        start=temp;
    } else if(start=='B' && end=='C'){
        char temp=end;
        end=start;
        start=temp;
    } else if(start=='C' && end=='B'){
        char temp=mid;
        mid=start;
        start=temp;
    } else if(start=='B' && end=='A'){
        char temp=mid;
        mid=end;
        end=temp;
    } else if(start=='A' && end=='C'){
        char temp=mid;
        mid=end;
        end=temp;
    }
  
    printf("\n\nSolution:\n");
    TowerOfHanoi(n, start, end, mid);
    printf("\n");
    return 0;
}