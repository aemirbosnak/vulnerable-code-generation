//FormAI DATASET v1.0 Category: Pattern printing ; Style: artistic
#include <stdio.h>

void printPattern(int n);

int main() {
    int n;
    
    printf("Enter the number of rows for the pattern: ");
    scanf("%d", &n);
    
    // Check if the number is odd or not, if not then subtract 1 from it
    if(n % 2 == 0) {
        n--;
    }
    
    printPattern(n);
    
    return 0;
}

void printPattern(int n) {
    int mid = n / 2;
    
    // Printing the first half of the pattern
    for(int i = 0; i <= mid; i++) {
        // Printing the spaces before the *
        for(int j = mid - i; j >= 0; j--) {
            printf(" ");
        }
        
        // Printing the *
        for(int j = 0; j < 2*i+1; j++) {
            printf("*");
        }
        
        printf("\n");
    }
    
    // Printing the second half of the pattern
    for(int i = mid+1; i < n; i++) {
        // Printing the spaces before the *
        for(int j = 0; j <= i - mid - 1; j++) {
            printf(" ");
        }
        
        // Printing the *
        for(int j = 0; j < 2*(n-i)-1; j++) {
            printf("*");
        }
        
        printf("\n");
    }
}