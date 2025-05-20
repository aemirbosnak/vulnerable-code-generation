//FormAI DATASET v1.0 Category: Pattern printing ; Style: high level of detail
#include<stdio.h>

// Function to print the C Pattern
void printCPattern(int n){
    int row, col;

    // Upper horizontal line
    for(row=0; row<1; row++){
        for(col=0; col<n; col++){
            printf("*");
        }
    }
    printf("\n");

    // First vertical line
    for(row=0; row<n/2; row++){
        for(col=0; col<1; col++){
            printf("*");
        }
        printf("\n");
    }

    // Center horizontal line
    for(row=0; row<1; row++){
        for(col=0; col<n; col++){
            printf("*");
        }
    }
    printf("\n");

    // Second vertical line
    for(row=0; row<n/2; row++){
        for(col=0; col<1; col++){
            printf("*");
        }
        printf("\n");
    }

    // Lower horizontal line
    for(row=0; row<1; row++){
        for(col=0; col<n; col++){
            printf("*");
        }
    }
}

int main(){
    int n;
    printf("Please enter a positive odd integer greater than or equal to 3 to print the C Pattern: ");
    scanf("%d",&n);

    // Check if number is valid
    if(n%2==0 || n<3){
        printf("Invalid input!");
        return 0;
    }

    // Call function to print C pattern
    printCPattern(n);

    return 0;
}