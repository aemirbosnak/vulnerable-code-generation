//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define clearScreen() printf("\033[H\033[J")

int main() 
{
    int curr = 1, prev = 1, temp, count = 0, input;

    printf("Welcome to the Brave Fibonacci Sequence Visualizer\n\n");
    printf("How many terms do you want to generate? ");
    scanf("%d", &input);
    
    system("clear");

    printf("Generating Fibonacci Sequence...Please Wait...\n\n");

    sleep(2);

    for (int i = 1; i <= input; i++)
    {
        temp = curr;
        curr = prev + curr;
        prev = temp;

        if (curr < 0) // Integer overflow prevention
        {
            printf("Sorry, Integer Overflow Occured\n");
            printf("Please choose a smaller number of terms\n");
            return 0;
        }

        printf("%d ", curr);

        count++;

        if (count > 10) 
        {
            printf("\n");
            count = 0;
        }

        fflush(stdout); // To display output in real-time
        usleep(200000); // Wait for 200 ms
    }

    printf("\n\nFibonacci sequence generation successful!\n");
    printf("Total terms generated: %d\n", input);

    return 0;
}