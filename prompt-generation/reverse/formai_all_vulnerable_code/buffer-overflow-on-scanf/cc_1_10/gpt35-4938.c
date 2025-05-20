//FormAI DATASET v1.0 Category: Binary Converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

int main()
{

    printf("My dear Romeo, let me show thee\n");
    printf("The magic of binary numbers in glee\n");

    int num;
    printf("Enter any decimal number my heart\n");
    scanf("%d", &num);

    printf("Oh my undying love, behold yonder\n");
    printf("The binary representation, marvel at its wonder\n");

    int binary[100];
    int index = 0;
    while (num > 0) {
        binary[index] = num % 2;
        num = num / 2;
        index++;
    }

    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }

    printf("\nNow Juliet, let me teach you a code so true\n");
    printf("A code that will make the conversion easy for you\n");

    printf("Enter any binary number, my fair maiden\n");

    char bin[100];
    scanf("%s", bin);
    int decimal = 0;

    for (int i = 0; bin[i] != '\0'; i++) {
        if (bin[i] == '1') {
            decimal = decimal * 2 + 1;
        } else if (bin[i] == '0') {
            decimal = decimal * 2;
        }
    }

    printf("My sweet Juliet, the decimal equivalent of this number\n");
    printf("Is %d, a number that will forever slumber\n", decimal);

    printf("Thus concludes our lesson of binary conversion\n");
    printf("May our love forever be in binary conjunction\n");

    return 0;
}