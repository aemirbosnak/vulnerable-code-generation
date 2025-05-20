//LLAMA2-13B DATASET v1.0 Category: Educational ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to print a rainbow
void print_rainbow(void) {
    int i, j, k;
    for (i = 0; i < 7; i++) {
        for (j = 0; j < 6; j++) {
            for (k = 0; k < 3; k++) {
                printf("%c", (i == j) && (j == k) ? '*' : ' ');
            }
            printf("\n");
        }
        printf("\n");
    }
}

// Function to print a pyramid of asterisks
void print_pyramid(int n) {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            printf("%c", (i == j) ? '*' : ' ');
        }
        printf("\n");
    }
}

int main() {
    int choice;
    printf("Welcome to the C Programming Adventure!\n");
    printf("Choose an option (1 for rainbow, 2 for pyramid, or 3 to exit): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            print_rainbow();
            break;
        case 2:
            print_pyramid(5);
            break;
        case 3:
            printf("Goodbye! %c", 0xA9); // Secret message for the keen-eyed observer
            exit(0);
            break;
        default:
            printf("Invalid input. Please try again.\n");
            break;
    }

    return 0;
}