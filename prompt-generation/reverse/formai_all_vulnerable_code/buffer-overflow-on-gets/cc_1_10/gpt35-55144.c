//FormAI DATASET v1.0 Category: Compression algorithms ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100

int main()
{
    char input[SIZE], output[SIZE], original[SIZE];
    int count = 1, index = 0, i, j, n;

    printf("Enter the string: ");
    gets(input);
    n = strlen(input);

    //Performing Run-Length Encoding

    for(i = 0; i < n; i++) {
        if(input[i] == input[i+1]) {
            count++;
        }
        else {
            output[index] = count + '0'; //Converting integer to character
            output[index+1] = input[i];
            index += 2;
            count = 1;
        }
    }

    output[index] = '\0'; //Adding null character at the end


    printf("\nOriginal String: %s", input);
    printf("\nEncoded String: %s", output);


    //Performing Run-Length Decoding

    count = 0;
    index = 0;
    n = strlen(output);

    for(i = 0; i < n; i++) {
        if(i % 2 == 0) {
            count = output[i] - '0'; //Converting character to integer
        }
        else {
            while(count) {
                original[index] = output[i];
                count--;
                index++;
            }
        }
    }

    original[index] = '\0'; //Adding null character at the end

    printf("\nDecoded String: %s", original);


    return 0;
}