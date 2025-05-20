//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// C Alien Language Translator

int main()
{
    char input[100], output[100], temp[100];
    int i, j, k, len, flag;

    printf("Welcome to the C Alien Language Translator\n");
    printf("==========================================\n");
    printf("Please enter a word in the C Alien Language:\n");

    // Read the user input
    scanf("%s", input);

    // Check if the input is valid
    if (strlen(input) % 2 != 0) {
        printf("Sorry, the input is not valid!\n");
        exit(0);
    }

    // Copy the input into the temp array
    strcpy(temp, input);

    // Reverse the second half of the input
    len = strlen(input);
    for (i = len/2, j = len-1; i < len; i++, j--) {
        temp[i] = input[j];
    }

    // Check if the input is a palindrome
    flag = 1;
    for (i = 0; i < len/2; i++) {
        if (input[i] != temp[i]) {
            flag = 0;
            break;
        }
    }

    // Translate the input into the output
    if (flag == 1) {
        for (i = 0; i < len/2; i++) {
            j = i*2;
            k = j+1;
            output[i] = input[k];
            output[len/2+i] = input[j];
        }
        output[len] = '\0';
    } else {
        for (i = 0; i < len; i++) {
            output[i] = input[len-i-1];
        }
        output[len] = '\0';
    }

    // Print the output
    printf("The translated word in the C Alien Language is:\n");
    printf("%s\n", output);

    return 0;
}