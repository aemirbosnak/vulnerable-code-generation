//FormAI DATASET v1.0 Category: Pattern printing ; Style: relaxed
#include <stdio.h>

int main() {
    int rows, i, j, spaces;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    spaces = rows - 1;

    for (i = 1; i <= rows; i++) {
        
        //Left Half
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        
        //Spaces
        for (j = 1; j <= spaces; j++) {
            printf(" ");
        }
        
        //Right Half
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        
        spaces--;
        printf("\n");
    }
    
    spaces = 1;
    
    for (i = rows; i >= 1; i--) {
        
        //Left Half
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        
        //Spaces
        for (j = 1; j <= spaces; j++) {
            printf(" ");
        }
        
        //Right Half
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        
        spaces++;
        printf("\n");
    }

    return 0;
}