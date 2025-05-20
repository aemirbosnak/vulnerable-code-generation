//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: imaginative
#include <stdio.h>

int main()
{
    int n, curr = 0, prev1 = 0, prev2 = 1;

    printf("Enter the number of terms you want in the Fibonacci sequence: ");
    scanf("%d", &n);

    printf("\nHere is the Fibonacci sequence upto %d terms:\n\n", n);

    for(int i = 1; i <= n; i++)
    {
        if(i == 1)
            printf("%d \n", prev1); // prints 0
        else if(i == 2)
            printf("%d \n", prev2); // prints 1
        else
        {
            curr = prev1 + prev2;
            prev1 = prev2;
            prev2 = curr;
            printf("%d \n", curr); // prints the next number in the sequence
        }
    }

    printf("\nAnd here is the same sequence displayed using ASCII art:\n\n");

    // clear the terminal screen
    system("clear");

    // ASCII art code for displaying the sequence as a spiral
    int x = 0, y = 0, dx = 0, dy = -1;
    for(int i = 1; i <= n; i++) 
    {
        // calculate the position of the current number in the sequence
        int bx = 4 * x + 2 * dx;
        int by = 2 * y + dy;
        printf("\033[%d;%dH  %d  ", by+1, bx+1, curr);

        // update the position and direction of the next number
        if(x == y || (x < 0 && x == -y) || (x > 0 && x == 1-y)) 
        {
            int buffer = dx;
            dx = -dy;
            dy = buffer;
        }
        x += dx;
        y += dy;

        // update the current number in the sequence
        if(i == 1)
            curr = prev1; // set to 0
        else if(i == 2)
            curr = prev2; // set to 1
        else
        {
            curr = prev1 + prev2;
            prev1 = prev2;
            prev2 = curr;
        }
    }

    return 0;
}