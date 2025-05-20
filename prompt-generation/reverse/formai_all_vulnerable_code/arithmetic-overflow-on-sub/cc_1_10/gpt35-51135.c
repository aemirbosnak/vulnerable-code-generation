//FormAI DATASET v1.0 Category: Robot movement control ; Style: brave
#include<stdio.h>
#include<stdlib.h>

int main()

{
    int n;
    printf("Enter the number of moves required: ");
    scanf("%d",&n);

    int i,a[n],b[n];
    char c[n];

    for(i=0;i<n;i++){
        printf("Enter the direction (U, D, L, R) for move %d: ",i+1);
        scanf(" %c",&c[i]);
    }

    for(i=0;i<n;i++){
        printf("Enter the distance for move %d: ",i+1);
        scanf("%d",&a[i]);
    }

    for(i=0;i<n;i++){
        switch(c[i]){
        case 'U':
            b[i]=b[i-1]+a[i];
            break;

        case 'D':
            b[i]=b[i-1]-a[i];
            break;
            
        case 'L':
            b[i]=b[i-1]-a[i];
            break;
            
        case 'R':
            b[i]=b[i-1]+a[i];
            break;
            
        default:
            printf("Invalid input");
            return 0;
            break;
        }
    }

    printf("Final position of the robot is (%d,%d)",b[n-1],b[n-1]);

    return 0;
}