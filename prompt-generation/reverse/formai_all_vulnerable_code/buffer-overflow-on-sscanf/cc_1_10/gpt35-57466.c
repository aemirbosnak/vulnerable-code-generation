//FormAI DATASET v1.0 Category: Color Code Converter ; Style: surrealist
#include<stdio.h>

void main(){

    printf("Welcome to the Surreal Color Code Converter!\n");

    printf("Enter your RGB color code in the format \"R,G,B\":\n");

    char input[10];
    fgets(input, 10, stdin);

    int r, g, b;

    sscanf(input, "%d,%d,%d", &r, &g, &b);

    printf("Your color code is %d,%d,%d\n", r, g, b);

    printf("Converting to surrealist color code...\n");

    int surreal_r = (r * 69) % 256;
    int surreal_g = (g + 420) % 256;
    int surreal_b = (b - 666) % 256;

    printf("Your surrealist color code is %d,%d,%d\n", surreal_r, surreal_g, surreal_b);

    printf("Would you like to see your surrealist color? (y/n)\n");

    char answer;
    scanf("%c", &answer);

    if (answer == 'y') {

        printf("Hold on tight, things are about to get weird...\n");
        printf("...\n");
        printf("...\n");
        printf("Your surrealist color is... ");

        for(int i = 0; i < surreal_r; i++){
            printf("\u2588");
        }

        printf("\n");

        for(int i = 0; i < surreal_g; i++){
            printf("\u2588");
        }

        printf("\n");

        for(int i = 0; i < surreal_b; i++){
            printf("\u2588");
        }

        printf("\n");

    } else {

        printf("Suit yourself. Thanks for using the Surreal Color Code Converter!\n");

    }

}