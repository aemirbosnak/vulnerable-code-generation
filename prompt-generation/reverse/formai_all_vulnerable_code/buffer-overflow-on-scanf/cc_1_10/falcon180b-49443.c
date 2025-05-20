//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void) {
    char input[100];
    char output[100];
    int i = 0;
    int j = 0;
    int choice;
    int dec = 0;
    int hex = 0;
    int bin = 0;

    printf("Welcome to the Color Code Converter!\n");
    printf("Please choose a color code:\n");
    printf("1. Decimal\n");
    printf("2. Hexadecimal\n");
    printf("3. Binary\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter a decimal number:\n");
            scanf("%s", input);
            dec = atoi(input);
            sprintf(output, "#%06X", dec);
            printf("The hexadecimal representation is: %s\n", output);
            break;
        case 2:
            printf("Enter a hexadecimal number:\n");
            scanf("%s", input);
            hex = atoi(input);
            sprintf(output, "%d", hex);
            printf("The decimal representation is: %s\n", output);
            break;
        case 3:
            printf("Enter a binary number:\n");
            scanf("%s", input);
            bin = atoi(input);
            sprintf(output, "%d", bin);
            printf("The decimal representation is: %s\n", output);
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}