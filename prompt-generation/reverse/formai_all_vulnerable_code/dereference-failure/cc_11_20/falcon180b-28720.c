//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM 1000000
#define MAX_BITS 50000

int main() {
    int num, i, j, bit, count = 0;
    char *key;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    printf("Enter a key (a string of 1's and 0's): ");
    scanf("%s", key);

    int key_size = strlen(key);

    //Check if key is valid
    for(i = 0; i < key_size; i++) {
        if(key[i]!= '0' && key[i]!= '1') {
            printf("Invalid key!\n");
            exit(0);
        }
    }

    int *exponent = (int *)malloc(MAX_NUM * sizeof(int));
    int *result = (int *)malloc(MAX_BITS * sizeof(int));

    //Calculate the exponent
    for(i = 0; i < MAX_NUM; i++) {
        if(i == num) {
            exponent[i] = 0;
        } else {
            exponent[i] = 1;
        }
    }

    //Calculate the result
    for(i = 0; i < MAX_BITS; i++) {
        for(j = 0; j < key_size; j++) {
            if(key[j] == '1') {
                result[i] += exponent[i % num];
            }
        }
        if(result[i] > 1) {
            result[i] = 1;
        } else if(result[i] < 0) {
            result[i] = 0;
        }
    }

    //Print the result
    printf("Encrypted number: ");
    for(i = 0; i < MAX_BITS; i++) {
        if(result[i] == 1) {
            printf("1");
        } else {
            printf("0");
        }
    }

    free(exponent);
    free(result);

    return 0;
}