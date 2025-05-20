//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: mathematical
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    // Read the input string
    char *s = malloc(100000);
    scanf("%s", s);

    // Calculate the length of the string
    int n = strlen(s);

    // Create a frequency table
    int *f = malloc(256);
    for (int i = 0; i < 256; i++)
        f[i] = 0;

    for (int i = 0; i < n; i++)
        f[s[i]]++;

    // Calculate the entropy of the string, using a one-byte character encoding
    double entropy = 0;
    for (int i = 0; i < 256; i++)
        if (f[i] > 0)
            entropy += f[i] * log2(f[i]);

    entropy /= n;

    // Calculate the optimal code length for each character
    double *l = malloc(256);
    for (int i = 0; i < 256; i++)
    {
        if (f[i] == 0)
            l[i] = 0;
        else
            l[i] = -log2(f[i] / n);
    }

    // Calculate the compressed string length
    double compressed_length = 0;
    for (int i = 0; i < n; i++)
        compressed_length += l[s[i]];

    // Print the results
    printf("Original string length: %d\n", n);
    printf("Entropy: %f\n", entropy);
    printf("Compressed string length: %f\n", compressed_length);

    // Free the allocated memory
    free(s);
    free(f);
    free(l);

    return 0;
}