//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

// Function to generate a prime number
int is_prime(int num)
{
    int i;
    for(i = 2; i < num; i++)
    {
        if(num % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    char message[MAX_SIZE];
    int i, j, k;
    int prime_num = 0;
    int prime_index = 0;
    int watermark[MAX_SIZE];

    printf("Please enter a message to be watermarked: ");
    scanf("%[^\n]s", message);

    // Generate a prime number for each character in the message
    for(i = 0; i < strlen(message); i++)
    {
        // Find the next prime number
        while(!is_prime(prime_num))
            prime_num++;

        // Assign the prime number to the watermark array
        watermark[i] = prime_num;
        prime_index++;
        prime_num++;
    }

    // Print the message and its corresponding watermark
    printf("\n-------------------\n");
    printf("MESSAGE | WATERMARK\n");
    printf("-------------------\n");
    for(i = 0; i < strlen(message); i++)
    {
        printf("%c       | %d\n", message[i], watermark[i]);
    }

    return 0;
}