//FormAI DATASET v1.0 Category: Pattern printing ; Style: immersive
#include <stdio.h>

int main() {
    int height, i, j, k, l, m, space, extra_space, num;

    printf("Welcome to the immersive C pattern printing program! \n");

    printf("How high do you want your pyramid to be (integers only)? \n");
    scanf("%d", &height);

    printf("How wide do you want your base to be (must be odd and greater than or equal to 3)? \n");
    scanf("%d", &num);

    if(num % 2 == 0 || num < 3) {
        printf("Sorry, invalid base width. You must enter an odd number greater than or equal to 3. \n");
        return 0;
    }

    space = height - 1;

    for(i = 1; i <= height; i++) {
        for(j = 1; j <= space; j++) {
            printf(" ");
        }
        space--;

        for(k = 1; k <= i; k++) {
            printf("* ");
        }

        printf("\n");
    }

    extra_space = (num - height) / 2;

    for(l = 1; l <= extra_space; l++) {
        for(m = 1; m <= num; m++) {
            printf(" ");
        }

        printf("\n");
    }

    if(num > height) {
        for(i = 1; i <= height; i++) {
            for(j = 1; j <= extra_space; j++) {
                printf(" ");
            }

            for(k = 1; k <= num - 2 * extra_space; k++) {
                printf("*");
            }

            printf("\n");
        }
    }

    printf("Thanks for using our program! Press any key to exit. \n");

    return 0;
}