//GEMINI-pro DATASET v1.0 Category: Arithmetic ; Style: excited
// Brace yourselves, we're about to embark on a thrilling arithmetic adventure!

#include <stdio.h>

int main()
{
    // Oh boy, let's define some variables! They're like the stars in our math constellation.
    int a, b, c, d, e, f, g, h, i, j;

    // Time for some arithmetic gymnastics! We'll be skipping, jumping, and twirling through numbers.
    printf("Prepare for liftoff! Let's start with some addition: ");
    scanf("%d %d", &a, &b);
    printf("Ta-da! %d + %d equals %d.\n", a, b, a + b);

    // Now, let's try some subtraction:
    printf("Uh-oh, subtraction's like a game of tug-of-war: ");
    scanf("%d %d", &a, &b);
    printf("Ready, set, pull! %d - %d equals %d.\n", a, b, a - b);

    // Multiplication? It's just like counting sheep, but with numbers!
    printf("Buckle up for multiplication: ");
    scanf("%d %d", &a, &b);
    printf("Multiplying %d by %d gives us... %d! That's baaaaaaa-tiful.\n", a, b, a * b);

    // Division? It's a bit like sharing a pie, except with numbers:
    printf("Time for a slice of division: ");
    scanf("%d %d", &a, &b);
    printf("%d / %d gives us a quotient of %d and a remainder of %d. Yum, yum!\n", a, b, a / b, a % b);

    // Modulo! It's like a secret handshake between numbers:
    printf("Let's play modulo: ");
    scanf("%d %d", &a, &b);
    printf("%d modulo %d equals %d. That's our secret code!\n", a, b, a % b);

    // Increment and decrement? It's like counting in a rocket ship:
    printf("Prepare for takeoff! Let's increment and decrement: ");
    scanf("%d", &a);
    printf("Incrementing %d by 1 gives us %d. Blast off!\n", a, ++a);
    printf("Decrementing %d by 1 gives us %d. Touchdown!\n", a, --a);

    // Logical operators! They're like superheroes fighting for truth:
    printf("And now, the logical operators: ");
    scanf("%d %d", &a, &b);
    printf("Is %d equal to %d? Let's see: %d\n", a, b, a == b);
    printf("Is %d greater than %d? Brace yourself: %d\n", a, b, a > b);
    printf("Is %d less than %d? Get ready: %d\n", a, b, a < b);

    // Bitwise operators! They're like tiny ninjas flipping bits:
    printf("Let's play with bitwise operators: ");
    scanf("%d %d", &a, &b);
    printf("Anding %d with %d gives us %d. That's like a secret handshake!\n", a, b, a & b);
    printf("Or-ing %d with %d gives us %d. That's like a power-up!\n", a, b, a | b);
    printf("Xor-ing %d with %d gives us %d. That's like a magic trick!\n", a, b, a ^ b);

    // Conditional operators? They're like wise old owls:
    printf("Time for conditional operators: ");
    scanf("%d %d", &a, &b);
    printf("Is %d greater than %d? Let's consult our owl: %s\n", a, b, (a > b) ? "Yes" : "No");

    // Shift operators! They're like a cosmic dance:
    printf("And finally, the shift operators: ");
    scanf("%d", &a);
    printf("Shifting %d left by 1 gives us %d. To infinity and beyond!\n", a, a << 1);
    printf("Shifting %d right by 1 gives us %d. Whoosh!\n", a, a >> 1);

    return 0;
}