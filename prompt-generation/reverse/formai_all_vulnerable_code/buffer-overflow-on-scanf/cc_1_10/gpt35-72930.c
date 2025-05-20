//FormAI DATASET v1.0 Category: Binary Converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the Binary Converter!\n");

    char input[10];
    int decimal, i=0;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    while (decimal > 0) {
        input[i] = decimal % 2 + '0';
        decimal = decimal / 2;
        i++;
    }

    printf("The binary representation of your number is: ");

    if (i == 0) {
        printf("0");
    }
    else {
        for (int j = i - 1; j >= 0; j--) {
            printf("%c", input[j]);
        }
    }

    printf("\n");

    printf("Now let's convert it back to decimal... but wait, do you want to add some spice to it?\n");
    printf("Enter y for yes or n for no: ");

    char spice;
    scanf(" %c", &spice);

    if (spice == 'y') {
        printf("Great! Let's add a little bit of randomness to the result...\n");
        int random_num = rand() % 10;
        printf("Your original binary number was %s, but now it's %d%d%d%d%d!\n", input, 
            (input[4]+random_num)%2,(input[3]+random_num)%2,(input[2]+random_num)%2,
            (input[1]+random_num)%2,(input[0]+random_num)%2);
    }
    else if (spice == 'n') {
        printf("Okay, let's convert it back normally...\n");
        int sum = 0;
        int base = 1;
        for (int j = i - 1; j >= 0; j--) {
            sum += (input[j] - '0') * base;
            base = base * 2;
        }
        printf("Your decimal number is: %d\n", sum);
    }
    else {
        printf("I'm sorry, I didn't understand that. Let's try again later.\n");
    }

    return 0;
}