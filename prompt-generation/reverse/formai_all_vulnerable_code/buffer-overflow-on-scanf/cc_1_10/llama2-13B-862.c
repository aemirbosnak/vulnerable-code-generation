//LLAMA2-13B DATASET v1.0 Category: Pattern printing ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRING_LENGTH 100
#define MAX_NUMBER_OF_STARS 10

// Function to print a star pattern
void print_star_pattern(int num_stars) {
    for (int i = 0; i < num_stars; i++) {
        printf("*");
    }
    printf("\n");
}

// Function to print a string with stars
void print_string_with_stars(char *str, int num_stars) {
    for (int i = 0; i < strlen(str); i++) {
        if (i % 2 == 0) {
            printf("*%c", str[i]);
        } else {
            printf("%c*", str[i]);
        }
    }
    printf("\n");
}

int main() {
    // Get the number of stars and the string to print
    int num_stars = get_user_input("Enter the number of stars: ");
    char str[MAX_STRING_LENGTH];
    get_user_input("Enter the string to print: ", str);

    // Print the star pattern
    print_star_pattern(num_stars);

    // Print the string with stars
    print_string_with_stars(str, num_stars);

    return 0;
}

// Function to get user input
int get_user_input(char *prompt) {
    int input;
    printf("%s", prompt);
    scanf("%d", &input);
    return input;
}