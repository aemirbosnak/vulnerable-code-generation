//LLAMA2-13B DATASET v1.0 Category: Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SURPRISED 1

int main() {
    int i, j, k, l;
    char str[100];

    // Initialize variables
    for (i = 0; i < 100; i++) {
        str[i] = 'a';
    }

    // Generate a random number
    srand(time(NULL));
    l = rand() % 10;

    // Print a surprise message
    printf("WOW! You just won a prize! The random number is: %d\n", l);

    // Check if the number is less than 5
    if (l < 5) {
        // Print a special message
        printf("Congratulations! You won a surprise gift! You can choose from:\n");

        // Generate a list of gifts
        for (i = 0; i < 10; i++) {
            // Generate a random gift name
            sprintf(str + i * 2, "Gift %d: %s", i + 1,
                                         (i % 2) ? "A magic bean" : "A unicorn horn");
        }

        // Print the list of gifts
        printf("%s\n", str);

        // Ask the user to choose a gift
        printf("Please enter the number of the gift you want: ");
        scanf("%d", &j);

        // Print the chosen gift
        printf("You chose gift %d: %s\n", j + 1, str + j * 2);
    } else {
        // Print a consolation message
        printf("Don't worry, you can always try again! Better luck next time!");
    }

    return SURPRISED;
}