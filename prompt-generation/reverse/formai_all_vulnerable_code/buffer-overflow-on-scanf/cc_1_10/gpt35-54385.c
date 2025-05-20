//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    const int MAX_SIZE = 10000;
    char message[MAX_SIZE];
    int length;
    int i, j, k, p, q;
    int arr1[MAX_SIZE], arr2[MAX_SIZE];
    int b, m, seed;
    int watermarkLength, watermark[MAX_SIZE];

    /* Get the message from user */
    printf("Enter the message: ");
    fgets(message, MAX_SIZE, stdin);
    length = strlen(message);

    /* Prompt the user to enter seed value */
    printf("Enter a seed value: ");
    scanf("%d", &seed);

    /* Generate arr1 of prime numbers using the sieve of Eratosthenes algorithm */
    memset(arr1, 1, MAX_SIZE*sizeof(int));
    arr1[0] = 0;
    arr1[1] = 0;
    for(i = 2; i*i <= MAX_SIZE; i++){
        if(arr1[i] == 1){
            for(j = i*i; j <= MAX_SIZE; j += i){
                arr1[j] = 0;
            }
        }
    }

    /* Generate arr2 of random numbers using linear congruential method */
    m = 1 << 16; /* Modulus */
    b = seed; /* Constant */
    arr2[0] = (seed*3) % m; /* First random number */
    for(k = 1; k < length; k++){
        arr2[k] = (b*arr2[k-1]) % m;
    }

    /* Generate watermark array */
    watermarkLength = length/8;
    for(p = 0; p < watermarkLength; p++){
        watermark[p] = 0;
        for(q = 0; q < 8; q++){
            watermark[p] += ((arr1[8*p+q]*arr2[8*p+q]) % 256) << (7 - q);
        }
    }

    /* Add watermark to message */
    for(i = 0; i < length; i++){
        message[i] ^= watermark[i%watermarkLength];
    }

    /* Print the watermarked message */
    printf("Watermarked message: %s", message);

    return 0;
}