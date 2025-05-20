//FormAI DATASET v1.0 Category: Pattern printing ; Style: modular
#include <stdio.h>

// Function to print the upper triangle of the C pattern
void printUpper(int size) {
    for(int i=0;i<size;i++) {
        for(int j=0;j<size;j++) {
            if(i==0 || j==0)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

// Function to print the middle part of the C pattern
void printMiddle(int size) {
    for(int i=0;i<size;i++) {
        printf("*\n");
    }
}

// Function to print the lower triangle of the C pattern
void printLower(int size) {
    for(int i=0;i<size;i++) {
        for(int j=0;j<size;j++) {
            if(i==(size-1) || j==0)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

// Function to print the entire C pattern
void printC(int size) {
    printUpper(size);
    printMiddle(size);
    printLower(size);
}

// Main function to test the C pattern printing program
int main() {
    int size;
    printf("Enter size of C pattern (minimum 3): ");
    scanf("%d",&size);
    if(size<3) {
        printf("Size should be at least 3.\n");
        return 0;
    }
    printf("Printing C pattern of size %d:\n",size);
    printC(size);
    return 0;
}