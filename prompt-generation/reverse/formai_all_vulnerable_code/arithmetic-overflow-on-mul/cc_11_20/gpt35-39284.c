//FormAI DATASET v1.0 Category: Educational ; Style: shape shifting
#include <stdio.h>

int main() {
    printf("Welcome to the shape-shifter program!\n");
    printf("Enter a number 0-9 to choose a shape: ");

    int choice;
    scanf("%d", &choice);

    if(choice == 0) {
        printf("You've chosen a square!\n");
        int side_length;
        printf("Enter the length of the sides: ");
        scanf("%d", &side_length);
        for(int i = 0; i < side_length; i++) {
            for(int j = 0; j < side_length; j++) {
                printf("* ");
            }
            printf("\n");
        }
    } else if(choice == 1) {
        printf("You've chosen a triangle!\n");
        int height;
        printf("Enter the height of the triangle: ");
        scanf("%d", &height);
        for(int i = 0; i < height; i++) {
            for(int j = 0; j <= i; j++) {
                printf("* ");
            }
            printf("\n");
        }
    } else if(choice == 2) {
        printf("You've chosen a circle!\n");
        int radius;
        printf("Enter the radius of the circle: ");
        scanf("%d", &radius);
        double pi = 3.14159;
        for(int i = -radius; i <= radius; i++) {
            for(int j = -radius; j <= radius; j++) {
                if(i*i + j*j <= radius*radius) {
                    printf("* ");
                } else {
                    printf("  ");
                }
            }
            printf("\n");
        }
    } else {
        printf("Invalid choice, please try again.\n");
    }

    return 0;
}