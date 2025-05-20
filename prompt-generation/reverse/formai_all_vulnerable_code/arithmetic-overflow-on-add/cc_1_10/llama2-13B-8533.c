//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define PRINT_WITH_ASCII_ART 1

int main() {
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);

    // Retro-style welcome message
    printf("Welcome to my groovy program! \n");
    printf("It's a far out trip, man! \n");
    printf("Get ready to enter a world of pure imagination...\n");
    printf("Yeah, it's gonna be a gas! \n");

    // Retro-style menu
    printf("What would you like to do, my friend?\n");
    printf("1. Play some groovy tunes with my rad synthesizer\n");
    printf("2. Check out the far-out graphics on my bitchin' graphics card\n");
    printf("3. Test my skills with a trippy little math problem\n");
    printf("4. Take a break and grab a cup of coffee (or a Coca-Cola)\n");

    int choice;
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    // Retro-style math problem
    if (choice == 3) {
        int num1, num2, sum;

        printf("Here's the math problem, dude: \n");
        printf("I have two groovy numbers, man: ");
        scanf("%d%d", &num1, &num2);
        printf("Now, add them together and tell me the result: ");
        sum = num1 + num2;
        printf("The answer is %d, man! \n", sum);

        // Retro-style result checker
        if (sum > 100) {
            printf("Whoa, that's one far-out answer, man! \n");
        } else if (sum < 0) {
            printf("Whoa, that's one trippy answer, man! \n");
        } else {
            printf("Groovy, you got it right, man! \n");
        }
    }

    // Retro-style ending
    printf("It's been real, man! \n");
    printf("Peace out, and remember: keep on groovin'! \n");
    return 0;
}