//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: puzzling
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 1000000 //Maximum size of input string

//Function to calculate the checksum
unsigned short calculateChecksum(char* input) {
    unsigned short sum = 0;
    int i;

    for (i = 0; i < strlen(input); i++) {
        sum += tolower(input[i]);
    }

    return sum;
}

//Function to reverse a string
void reverseString(char* str, int size) {
    int i, j;
    char temp;

    for (i = 0, j = size - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

//Function to print the checksum
void printChecksum(unsigned short checksum) {
    printf("Checksum: %04X\n", checksum);
}

int main() {
    char input[MAX_SIZE];
    int size;

    printf("Enter a string: ");
    fgets(input, MAX_SIZE, stdin);

    size = strlen(input);

    //Remove newline character
    input[size - 1] = '\0';

    //Reverse the string
    reverseString(input, size);

    //Calculate the checksum
    unsigned short checksum = calculateChecksum(input);

    //Print the checksum
    printChecksum(checksum);

    return 0;
}