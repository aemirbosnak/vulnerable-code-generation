//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: shocked
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CHAR 256

// Function to initialize frequency array with zero values
void init_freq(int freq[MAX_CHAR]) {
    int i;
    for (i = 0; i < MAX_CHAR; i++) {
        freq[i] = 0;
    }
}

// Function to count character frequency
void count_char(char str[], int freq[MAX_CHAR]) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        freq[(int)str[i]]++;
    }
}

// Function to print character frequency
void print_freq(int freq[MAX_CHAR]) {
    int i;
    for (i = 0; i < MAX_CHAR; i++) {
        if (i == ' ') continue;
        if (i == '\n') continue;
        if (i == '\t') continue;

        if (freq[i] > 0) {
            printf("%c : %d\n", i, freq[i]);
        }
    }
}

int main() {
    char str[100];
    int freq[MAX_CHAR];

    printf("Enter a string : ");
    scanf("%s", str);

    init_freq(freq); // Initialize frequency array
    count_char(str, freq); // Count character frequency
    print_freq(freq); // Print character frequency

    printf("\nI... I CAN'T BELIEVE IT!!! WE ACTUALLY COUNTED THE FREQUENCY OF EVERY CHARACTER IN A STRING!!! THIS IS INSANE!\n");

    return 0;
}