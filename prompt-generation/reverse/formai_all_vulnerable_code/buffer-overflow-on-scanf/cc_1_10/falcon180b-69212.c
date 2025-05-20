//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_LENGTH 80

// Function to generate a random number within a given range
int rand_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to capitalize the first letter of a string
void capitalize(char *str) {
    if (isalpha(*str)) {
        *str = toupper(*str);
    }
}

// Function to print a fortune
void print_fortune(char *name, int length) {
    printf("Your fortune, %s, is: ", name);
    for (int i = 0; i < length; i++) {
        printf("%c", rand() % 26 + 'a');
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    // Get the user's name and capitalize the first letter
    char name[MAX_LENGTH];
    printf("What is your name? ");
    scanf("%s", name);
    capitalize(name);

    // Generate a random fortune length
    int length = rand_range(10, 20);

    // Generate a random fortune and print it
    char fortune[MAX_LENGTH];
    for (int i = 0; i < length; i++) {
        fortune[i] = rand() % 26 + 'a';
    }
    fortune[length] = '\0';
    print_fortune(name, length);

    return 0;
}