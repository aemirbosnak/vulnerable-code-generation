//FormAI DATASET v1.0 Category: Text processing ; Style: Donald Knuth
/*
 * Text processing program using Knuth's algorithm
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum input length
#define MAX_LEN 100

// Define maximum number of characters in the alphabet
#define MAX_ALPHA_SIZE 26 

// Define alphabet structure
struct alphabet {
    char letter;
    int count;
};

// Define function to sort alphabet by count
void sort_alphabet(struct alphabet *a, int n) {
    int i, j;
    struct alphabet temp;

    for (i = 0; i < n; i++) {
        for (j = i+1; j < n; j++) {
            if (a[j].count > a[i].count) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

// Define function to print alphabet
void print_alphabet(struct alphabet *a, int n) {
    int i;
    printf("Alphabet:\n");
    for (i = 0; i < n; i++) {
        printf("%c: %d\n", a[i].letter, a[i].count);
    }
}

int main() {
    char input[MAX_LEN];
    int len, i, j, count;
    struct alphabet alpha[MAX_ALPHA_SIZE];

    // Get input from user
    printf("Enter text to analyze: ");
    fgets(input, MAX_LEN, stdin);
    
    // Remove newline character from input
    len = strlen(input);
    if (input[len-1] == '\n') {
        input[len-1] = '\0';
    }
    
    // Initialize alphabet counts
    for (i = 0; i < MAX_ALPHA_SIZE; i++) {
        alpha[i].letter = 'a' + i;
        alpha[i].count = 0;
    }
    
    // Count occurrences of each letter in input
    for (i = 0; i < len; i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            alpha[input[i]-'a'].count++;
        }
    }
    
    // Sort alphabet by count
    sort_alphabet(alpha, MAX_ALPHA_SIZE);
    
    // Print alphabet
    print_alphabet(alpha, MAX_ALPHA_SIZE);

    return 0;
}