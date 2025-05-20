//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Function to check if a given number is prime or not
int isPrime(int n)
{
    if (n <= 1)
        return 0;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return 0;
    }

    return 1;
}

// Function to embed a watermark into a given integer array
void embedWatermark(int *array, int size)
{
    // Find the first prime number greater than the array size
    int watermark = size + 1;
    while (!isPrime(watermark))
        watermark++;

    // Set the last element of the array to be the watermark
    array[size - 1] = watermark;
}

// Function to extract a watermark from a given integer array
int extractWatermark(int *array, int size)
{
    // Extract the watermark from the last element of the array
    int watermark = array[size - 1];

    // Check if the watermark is a prime number
    if (!isPrime(watermark))
    {
        printf("Watermark not found!\n");
        return -1;
    }

    return watermark - 1;
}

int main()
{
    int array[100];
    int size;

    // Read the input array size from the user
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Read the input array elements from the user
    printf("Enter the array elements: ");
    for (int i = 0; i < size; i++)
        scanf("%d", &array[i]);

    // Embed the watermark into the input array
    embedWatermark(array, size);

    printf("Watermark embedded successfully!\n");

    // Extract the watermark from the input array
    int watermark = extractWatermark(array, size);

    if (watermark != -1)
        printf("Extracted watermark: %d\n", watermark);

    return 0;
}