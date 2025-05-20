//FormAI DATASET v1.0 Category: Digital signal processing ; Style: decentralized
#include <stdio.h>
#define SIZE 1024

int main(void)
{
    int input[SIZE], output[SIZE];
    int i, j, k;
    int N, M;
    int input_sum, output_sum;

    printf("Enter the value of N: ");
    scanf("%d", &N);

    printf("Enter the value of M: ");
    scanf("%d", &M);

    printf("Enter the input signal: \n");

    for(i=0; i<N; i++)
    {
        scanf("%d", &input[i]);
    }

    for(i=0; i<N-M; i++)
    {
        output[i] = 0;

        for(j=0; j<M; j++)
        {
            output[i] += input[i+j];
        }

        output[i] /= M;
    }

    printf("\n");

    printf("Input signal: ");
    for(i=0; i<N; i++)
    {
        printf("%d ", input[i]);
    }

    printf("\n");

    printf("Output signal: ");
    for(i=0; i<N-M; i++)
    {
        printf("%d ", output[i]);
    }

    printf("\n");

    input_sum = 0;
    for(i=0; i<N; i++)
    {
        input_sum += input[i];
    }

    output_sum = 0;
    for(i=0; i<N-M; i++)
    {
        output_sum += output[i];
    }

    printf("\n");

    printf("Input signal average: %d\n", input_sum / N);
    printf("Output signal average: %d\n", output_sum / (N-M));

    printf("\n");

    printf("Difference between input and output average: %d\n", (input_sum / N) - (output_sum / (N-M)));

    return 0;
}