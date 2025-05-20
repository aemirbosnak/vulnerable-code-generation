//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Generate a random sequence of 0's and 1's
void generate_random_sequence(int *seq, int n)
{
    for(int i=0;i<n;i++)
    {
        seq[i] = rand()%2;
    }
}

// Calculate the Hamming distance between two sequences
int hamming_distance(int *seq1, int *seq2, int n)
{
    int d = 0;
    for(int i=0;i<n;i++)
    {
        if(seq1[i]!=seq2[i])
        {
            d++;
        }
    }
    return d;
}

int main()
{
    // Code for Digital Watermarking

    char message[100];
    int watermark[100], N;
    printf("Enter a message to watermark: ");
    scanf("%[^\n]s", message);

    printf("Enter length of watermark: ");
    scanf("%d", &N);

    // Generate random watermark sequence
    srand(time(NULL));
    generate_random_sequence(watermark, N);

    // Embed watermark in message
    for(int i=0;i<N;i++)
    {
        message[i] = (message[i] & ~1) | watermark[i];
    }

    printf("Original message: %s\n", message);

    // Attack on watermarked message

    char attack[100];
    printf("Enter an attacked message: ");
    scanf(" %[^\n]s", attack);

    // Calculate Hamming Distance between the two messages
    int d = hamming_distance(message, attack, N);
    if(d<=5)
    {
        printf("Watermark detected!\n");
    }
    else
    {
        printf("Watermark not detected.\n");
    }

    return 0;
}