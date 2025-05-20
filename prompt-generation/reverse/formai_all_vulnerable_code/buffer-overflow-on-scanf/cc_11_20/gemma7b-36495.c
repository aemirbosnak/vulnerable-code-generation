//Gemma-7B DATASET v1.0 Category: Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

int main() {
    int x, y, z;
    printf("Enter the values of x, y, and z:");
    scanf("%d %d %d", &x, &y, &z);

    switch (x) {
        case 1:
            switch (y) {
                case 2:
                    switch (z) {
                        case 3:
                            printf("The value of x, y, and z is: %d, %d, %d", x, y, z);
                            break;
                        case 4:
                            printf("The value of x, y, and z is: %d, %d, %d", x, y, z);
                            break;
                        default:
                            printf("Invalid values");
                            break;
                    }
                    break;
                case 3:
                    switch (z) {
                        case 4:
                            printf("The value of x, y, and z is: %d, %d, %d", x, y, z);
                            break;
                        case 5:
                            printf("The value of x, y, and z is: %d, %d, %d", x, y, z);
                            break;
                        default:
                            printf("Invalid values");
                            break;
                    }
                    break;
                default:
                    printf("Invalid values");
                    break;
            }
            break;
        case 2:
            switch (y) {
                case 3:
                    switch (z) {
                        case 4:
                            printf("The value of x, y, and z is: %d, %d, %d", x, y, z);
                            break;
                        case 5:
                            printf("The value of x, y, and z is: %d, %d, %d", x, y, z);
                            break;
                        default:
                            printf("Invalid values");
                            break;
                    }
                    break;
                case 4:
                    switch (z) {
                        case 5:
                            printf("The value of x, y, and z is: %d, %d, %d", x, y, z);
                            break;
                        case 6:
                            printf("The value of x, y, and z is: %d, %d, %d", x, y, z);
                            break;
                        default:
                            printf("Invalid values");
                            break;
                    }
                    break;
                default:
                    printf("Invalid values");
                    break;
            }
            break;
        default:
            printf("Invalid values");
            break;
    }

    return 0;
}