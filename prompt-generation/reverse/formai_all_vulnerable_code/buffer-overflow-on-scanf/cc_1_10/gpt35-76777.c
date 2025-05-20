//FormAI DATASET v1.0 Category: Pattern printing ; Style: modular
#include <stdio.h>
#include <stdlib.h>

/* Function to print the top part of the C */
void print_top_c(int length) {
    for(int i = 0; i < length; i++) {
        printf("*");
    }
    printf("\n");
    for(int i = 0; i < (length/2); i++) {
        printf("*\n");
    }
}

/* Function to print the middle part of the C */
void print_middle_c(int length, int width) {
    for(int i = 0; i < (width-2); i++) {
        printf("*");
        for(int j = 0; j < (length-2); j++) {
            printf(" ");
        }
        printf("*\n");
    }
}

/* Function to print the bottom part of the C */
void print_bottom_c(int length) {
    for(int i = 0; i < (length/2); i++) {
        printf("*\n");
    }
    for(int i = 0; i < length; i++) {
        printf("*");
    }
    printf("\n");
}

/* Main function to print the C */
int main() {
    int length, width;

    printf("Enter length of C: ");
    scanf("%d", &length);
    printf("Enter width of C: ");
    scanf("%d", &width);

    /* Print top part of C */
    print_top_c(length);

    /* Print middle part of C */
    print_middle_c(length, width);

    /* Print bottom part of C */
    print_bottom_c(length);

    return 0;
}