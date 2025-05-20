//FormAI DATASET v1.0 Category: Pattern printing ; Style: configurable
#include <stdio.h>

int main() {
    int height, width;
    printf("Enter height: ");
    scanf("%d", &height);
    printf("Enter width: ");
    scanf("%d", &width);

    int pattern_type;
    printf("Choose pattern type (1 to 3):\n");
    printf("1. X pattern\n");
    printf("2. Diamond pattern\n");
    printf("3. Right-angled triangle pattern\n");
    scanf("%d", &pattern_type);

    switch(pattern_type) {
        case 1:
            printf("X Pattern:\n");
            for(int row=1; row<=height; row++) {
                for(int col=1; col<=width; col++) {
                    if(row == col || col == (width-row+1))
                        printf("*");
                    else
                        printf(" ");
                }
                printf("\n");
            }
            break;

        case 2:
            printf("Diamond Pattern:\n");
            for(int row=1; row<=height; row++) {
                for(int col=1; col<=width; col++) {
                    if(row+col == (height/2)+2 || row+col == (height/2)+width || 
                       row-col == height/2 || col-row == height/2)
                        printf("*");
                    else
                        printf(" ");
                }
                printf("\n");
            }
            break;

        case 3:
            printf("Right-angled Triangle Pattern:\n");
            for(int row=1; row<=height; row++) {
                for(int col=1; col<=row; col++)
                    printf("*");
                printf("\n");
            }
            break;

        default:
            printf("Invalid choice.\n");
    }
    return 0;
}