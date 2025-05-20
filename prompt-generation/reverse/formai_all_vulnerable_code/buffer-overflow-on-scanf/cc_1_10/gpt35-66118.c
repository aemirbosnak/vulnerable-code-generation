//FormAI DATASET v1.0 Category: Pattern printing ; Style: automated
#include <stdio.h>

int main() {
    int n, i, j, space1=0, space2=0;
    printf("Enter the size of pattern: ");
    scanf("%d", &n);

    // First half of the pattern
    for(i=1; i<=n; ++i) {
        // Print spaces
        for(j=1; j<=space1; ++j) {
            printf(" ");
        }
        // Print stars
        for(j=1; j<=(2*i-1); ++j) {
            printf("*");
        }
        // Move to the next line
        printf("\n");
        // Increase the number of spaces for next line
        ++space1;
    }

    // Upper half of the second half of the pattern
    space1 -= 2;
    for(i=(n/2)+1; i<=n; ++i) {
        // Print spaces
        for(j=1; j<=space1; ++j) {
            printf(" ");
        }
        // Print stars
        for(j=1; j<=(2*i-1); ++j) {
            printf("*");
        }
        // Move to the next line
        printf("\n");
        // Decrease the number of spaces for next line
        --space1;
        // Increase the number of spaces for the second half of the pattern 
        if(space2==0) {
            space2 = 2;
            space1 -= space2;
        } else {
            ++space2;
            space1 -= space2;
        }
    }

    return 0;
}