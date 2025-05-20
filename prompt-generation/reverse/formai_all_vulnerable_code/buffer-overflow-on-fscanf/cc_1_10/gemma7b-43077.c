//Gemma-7B DATASET v1.0 Category: Data mining ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 100

void main()
{
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    char str[MAX], str1[MAX], str2[MAX], str3[MAX];
    float f, g, h, avg, sum, total, min, max;
    FILE *fp;

    fp = fopen("data.txt", "r");
    fscanf(fp, "%s", str);
    fclose(fp);

    // Convert str to uppercase
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 32;
        }
    }

    // Split str into words
    char *word = strtok(str, " ");

    // Count the number of words
    int numWords = 0;
    while (word)
    {
        numWords++;
        word = strtok(NULL, " ");
    }

    // Calculate the average word length
    avg = 0.0;
    word = strtok(str, " ");
    while (word)
    {
        int length = strlen(word);
        avg += (float)length;
        word = strtok(NULL, " ");
    }

    // Find the minimum word length
    min = MAX;
    word = strtok(str, " ");
    while (word)
    {
        int length = strlen(word);
        if (length < min)
        {
            min = (float)length;
        }
        word = strtok(NULL, " ");
    }

    // Find the maximum word length
    max = 0.0;
    word = strtok(str, " ");
    while (word)
    {
        int length = strlen(word);
        if (length > max)
        {
            max = (float)length;
        }
        word = strtok(NULL, " ");
    }

    // Print the results
    printf("Number of words: %d\n", numWords);
    printf("Average word length: %.2f\n", avg);
    printf("Minimum word length: %.2f\n", min);
    printf("Maximum word length: %.2f\n", max);
}