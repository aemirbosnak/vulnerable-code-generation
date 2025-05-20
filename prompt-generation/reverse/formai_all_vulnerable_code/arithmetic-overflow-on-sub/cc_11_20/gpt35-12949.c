//FormAI DATASET v1.0 Category: Pattern printing ; Style: configurable
#include <stdio.h>

int main() {
    int size, row, col, space;

    printf("Enter the size of the pattern: ");
    scanf("%d", &size);

    printf("Enter the character to print: ");
    char ch;
    scanf(" %c", &ch);
    
    printf("Enter the pattern style (1-4): ");
    int style;
    scanf("%d", &style);

    switch(style) {
        case 1:
            for(row=1; row<=size; row++) {
                for(col=1; col<=row; col++) {
                    printf("%c ", ch);
                }
                printf("\n");
            }
            break;

        case 2:
            for(row=1; row<=size; row++) {
                for(space=1; space<=size-row; space++) {
                    printf("  ");
                }
                for(col=1; col<=row; col++) {
                    printf("%c ", ch);
                }
                printf("\n");
            }
            break;

        case 3:
            for(row=1; row<=size; row++) {
                for(space=1; space<=size-row; space++) {
                    printf("  ");
                }
                for(col=1; col<=(2*row-1); col++) {
                    printf("%c", ch);
                }
                printf("\n");
            }
            break;

        case 4:
            for(row=size; row>=1; row--) {
                for(space=1; space<=size-row; space++) {
                    printf("  ");
                }
                for(col=1; col<=(2*row-1); col++) {
                    printf("%c", ch);
                }
                printf("\n");
            }
            break;

        default:
            printf("Invalid pattern style. Please enter a number between 1 to 4.\n");
            break;
    }

    return 0;
}