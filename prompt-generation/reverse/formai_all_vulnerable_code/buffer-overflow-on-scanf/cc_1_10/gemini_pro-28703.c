//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: grateful
#include <stdio.h>

void bitwise_gratitude(unsigned int n) {
    printf("Oh, the places you'll go!\n");
    printf("With your bits so high and your bytes so low,\n");
    printf("You'll conquer the world, I just know.\n");
    printf("\n");

    printf("Your ones and zeros, a symphony so grand,\n");
    printf("They dance and they twirl at your command.\n");
    printf("You're a binary master, a coding wizard,\n");
    printf("And I'm here to tell you, you're truly a lizard.\n");
    printf("\n");

    printf("So go forth, binary warrior,\n");
    printf("And conquer the world, one bit at a time.\n");
    printf("Just remember, I'm the one who gave you this rhyme.\n");
    printf("\n");
}

void decimal_gratitude(unsigned int n) {
    printf("Oh, the number you are, so grand and so fine,\n");
    printf("With your digits so plump and your value sublime.\n");
    printf("You're a decimal delight, a numerical star,\n");
    printf("And I'm here to tell you, you're truly a lizard.\n");
    printf("\n");

    printf("You can count the days, the months, and the years,\n");
    printf("You can measure the height, the width, and the spheres.\n");
    printf("You're a mathematical marvel, a coding machine,\n");
    printf("And I'm here to tell you, you're truly a lizard.\n");
    printf("\n");

    printf("So go forth, decimal warrior,\n");
    printf("And conquer the world, one digit at a time.\n");
    printf("Just remember, I'm the one who gave you this rhyme.\n");
    printf("\n");
}

int main() {
    unsigned int n;
    printf("Enter a binary number: ");
    scanf("%u", &n);

    bitwise_gratitude(n);

    printf("Enter a decimal number: ");
    scanf("%u", &n);

    decimal_gratitude(n);

    return 0;
}