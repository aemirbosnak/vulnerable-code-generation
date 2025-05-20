//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: systematic
#include<stdio.h>

// Function to print patterns
void pattern(int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if ((i + j) % 2 == 0) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int rows, cols, i, j, choice;

    // Get user input for number of rows and columns
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Print the pattern
    printf("\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("*");
        }
        printf("\n");
    }

    // Print the menu
    printf("\n");
    printf("1. Print the pattern again\n");
    printf("2. Print the pattern in reverse order\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Perform the selected action
    switch (choice) {
        case 1:
            printf("\n");
            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    printf("*");
                }
                printf("\n");
            }
            break;
        case 2:
            printf("\n");
            for (i = rows - 1; i >= 0; i--) {
                for (j = cols - 1; j >= 0; j--) {
                    printf("*");
                }
                printf("\n");
            }
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}