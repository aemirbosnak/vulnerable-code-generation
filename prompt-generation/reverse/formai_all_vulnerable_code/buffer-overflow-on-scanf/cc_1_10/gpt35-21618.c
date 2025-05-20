//FormAI DATASET v1.0 Category: Pattern printing ; Style: futuristic
#include <stdio.h>

int main() {
    int size;
    printf("Enter the size of C Pattern (must be atleast 5): ");
    scanf("%d", &size);

    // Check if the size is valid
    if(size<5) {
        printf("Invalid size, size must be atleast 5.\n");
        return 0;
    }

    // Print top horizontal line of C
    for(int i=0; i< size; i++) {
        printf("*");
    }
    printf("\n");

    // Print vertical line of C
    for(int i=0; i<size-2; i++) {
        printf("*\n");
    }

    // Print bottom horizontal line of C
    for(int i=0; i< size; i++) {
        printf("*");
    }

    printf("\n\n");

    // Print futuristic C Pattern

    printf(" ***********\n");  // Top horizontal line

    for(int i = 1; i <= (size-2)/2; i++){
        printf(" *\n");  // First Vertical Line
    }

    for(int i = 0; i < (size-2)/2; i++){
        printf(" *");  // Top Half of "C"
    }
    printf("\n");

    for(int i = 0; i < (size-2)/2; i++){
        printf(" *\n");  // Bottom Half of "C"
    }

    printf(" ***********\n");  // Bottom Horizontal Line

    return 0;
}