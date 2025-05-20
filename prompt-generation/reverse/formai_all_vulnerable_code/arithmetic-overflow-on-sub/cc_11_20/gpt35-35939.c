//FormAI DATASET v1.0 Category: Pattern printing ; Style: configurable
#include <stdio.h>

int main() {
    int length, width, height, pattern;
    
    printf("Enter the length of the pattern: ");
    scanf("%d", &length);
    
    printf("Enter the width of the pattern: ");
    scanf("%d", &width);
    
    printf("Enter the height of the pattern: ");
    scanf("%d", &height);
    
    printf("Enter the pattern (1-4):\n");
    printf("1. X Pattern\n");
    printf("2. Right Angle Triangle Pattern\n");
    printf("3. Pyramid Pattern\n");
    printf("4. Diamond Pattern\n");
    
    scanf("%d", &pattern);
    
    switch(pattern) {
        case 1:
            for(int i=1; i<=length; i++) {
                for(int j=1; j<=width; j++) {
                    if(i==j || i+j==width+1) {
                        printf("*");
                    } else {
                        printf(" ");
                    }
                }
                printf("\n");
            }
            break;
        case 2:
            for(int i=1; i<=height; i++) {
                for(int j=1; j<=i; j++) {
                    printf("*");
                }
                printf("\n");
            }
            break;
        case 3:
            for(int i=1; i<=height; i++) {
                for(int j=1; j<=height-i; j++) {
                    printf(" ");
                }
                for(int k=1; k<=2*i-1; k++) {
                    printf("*");
                }
                printf("\n");
            }
            break;
        case 4:
            for(int i=1; i<=height; i++) {
                for(int j=1; j<=height-i; j++) {
                    printf(" ");
                }
                for(int k=1; k<=2*i-1; k++) {
                    printf("*");
                }
                printf("\n");
            }
            for(int i=height-1; i>=1; i--) {
                for(int j=1; j<=height-i; j++) {
                    printf(" ");
                }
                for(int k=1; k<=2*i-1; k++) {
                    printf("*");
                }
                printf("\n");
            }
            break;
        default:
            printf("Invalid Pattern Number!");
    }
    
    return 0;
}