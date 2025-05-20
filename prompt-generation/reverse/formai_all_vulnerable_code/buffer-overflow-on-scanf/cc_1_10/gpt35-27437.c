//FormAI DATASET v1.0 Category: Pattern printing ; Style: Dennis Ritchie
#include <stdio.h>

/* Function to print pattern */
void printPattern(int rows){

    int mid = (rows / 2);
    
    // Loop for upper part
    for (int i = 0; i < mid; i++){
        for (int j = i; j < mid; j++){
            printf("* ");
        }
        for (int k = 0; k < ((i*2)+1); k++){
            printf("  ");
        }
        for (int j = i; j < mid; j++){
            printf("* ");
        }
        printf("\n");
    }
    
    // Loop for mid row
    for (int i = 0; i < (mid*2)+1; i++) {
        printf("* ");
    }
    printf("\n");
    
    // Loop for bottom part
    for (int i = mid-1; i >= 0; i--){
        for (int j = i; j < mid; j++){
            printf("* ");
        }
        for (int k = 0; k < ((i*2)+1); k++){
            printf("  ");
        }
        for (int j = i; j < mid; j++){
            printf("* ");
        }
        printf("\n");
    }
}

int main() {

    int rows;
    
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    
    printPattern(rows);
    
    return 0;
}