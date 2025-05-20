//FormAI DATASET v1.0 Category: Educational ; Style: shape shifting
#include <stdio.h>

int main() {

    printf("Welcome to the shape-shifting program!\n");
    printf("Enter a number corresponding to a shape:\n");
    printf("1. Triangle\n2. Square\n3. Circle\n4. Hexagon\n");
    
    int choice;
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            printf("\nEnter the height of the triangle: ");
            int height;
            scanf("%d", &height);
            for(int i=1; i<=height; i++) {
                for(int j=1; j<=i; j++) {
                    printf("*");
                }
                printf("\n");
            }
            break;
            
        case 2:
            printf("\nEnter the length of the side of the square: ");
            int length;
            scanf("%d", &length);
            for(int i=1; i<=length; i++) {
                for(int j=1; j<=length; j++) {
                    printf("*");
                }
                printf("\n");
            }
            break;
            
        case 3:
            printf("\nEnter the radius of the circle: ");
            int radius;
            scanf("%d", &radius);
            for(int i=-radius; i<=radius; i++) {
                for(int j=-radius; j<=radius; j++) {
                    if(i*i+j*j<=radius*radius) {
                        printf("*");
                    }
                    else {
                        printf(" ");
                    }
                }
                printf("\n");
            }
            break;
            
        case 4:
            printf("\nEnter the side length of the hexagon: ");
            int side_length;
            scanf("%d", &side_length);
            for(int i=1; i<=2*side_length; i++) {
                int spaces = abs(side_length-i);
                for(int j=1; j<=spaces; j++) {
                    printf(" ");
                }
                if(i<=side_length) {
                    for(int j=1; j<=side_length+i-1; j++) {
                        printf("*");
                    }
                }
                else {
                    for(int j=1; j<=3*side_length-i-1; j++) {
                        printf("*");
                    }
                }
                
                printf("\n");
            }
            break;
        
        default:
            printf("Invalid choice!\n");
            break;
    }
    
    return 0;
}