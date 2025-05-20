//LLAMA2-13B DATASET v1.0 Category: Pattern printing ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define PRINT_LINE(x) printf("%s\n", x)
#define PRINT_SPACE(x) printf("%*s", (x), " ")
#define PRINT_NEW_LINE() printf("\n")

int main() {
    int i, j;
    char name[50];
    int age;
    float height, weight;

    // Ask for user input
    PRINT_SPACE(20);
    printf("Please enter your name: ");
    scanf("%49s", name);
    PRINT_SPACE(10);
    printf("What is your age: ");
    scanf("%d", &age);
    PRINT_SPACE(10);
    printf("Please enter your height: ");
    scanf("%f", &height);
    PRINT_SPACE(10);
    printf("Please enter your weight: ");
    scanf("%f", &weight);

    // Print a calm greeting
    PRINT_LINE("Hello there, ");
    PRINT_SPACE(10);
    PRINT_LINE(name);
    PRINT_SPACE(10);
    PRINT_LINE("! Welcome to this little program I made for you.");
    PRINT_NEW_LINE();

    // Print some math problems
    PRINT_LINE("Here's a little math problem for you:");
    PRINT_NEW_LINE();
    PRINT_LINE("If you have 5 apples and you give 2 to your friend, how many do you have left?");
    PRINT_NEW_LINE();
    PRINT_LINE("Answer: ");
    PRINT_SPACE(10);
    scanf("%d", &i);
    PRINT_SPACE(10);
    if (i == 3) {
        PRINT_LINE("Correct! You have 3 apples left.");
    } else {
        PRINT_LINE("Oops, that's not correct. The answer is 3.");
    }
    PRINT_NEW_LINE();

    // Print some more math problems
    PRINT_LINE("Here's another math problem for you:");
    PRINT_NEW_LINE();
    PRINT_LINE("If you have 10 pencils and you give 3 to your brother, how many do you have left?");
    PRINT_NEW_LINE();
    PRINT_LINE("Answer: ");
    PRINT_SPACE(10);
    scanf("%d", &i);
    PRINT_SPACE(10);
    if (i == 7) {
        PRINT_LINE("Correct! You have 7 pencils left.");
    } else {
        PRINT_LINE("Oops, that's not correct. The answer is 7.");
    }
    PRINT_NEW_LINE();

    // Print a final message
    PRINT_LINE("Well, that's all for now. ");
    PRINT_SPACE(10);
    PRINT_LINE("I hope you enjoyed this little program. ");
    PRINT_SPACE(10);
    PRINT_LINE("Bye for now!");
    PRINT_NEW_LINE();

    return 0;
}