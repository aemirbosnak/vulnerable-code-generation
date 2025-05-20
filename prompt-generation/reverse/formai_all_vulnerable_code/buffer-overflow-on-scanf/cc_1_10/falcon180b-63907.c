//Falcon-180B DATASET v1.0 Category: Educational ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

// Function to display menu options
void display_menu(void) {
    printf("Menu:\n");
    printf("1. Option 1\n");
    printf("2. Option 2\n");
    printf("3. Option 3\n");
    printf("4. Exit\n");
}

// Function to perform option 1
void option1(void) {
    printf("Performing option 1...\n");
}

// Function to perform option 2
void option2(void) {
    printf("Performing option 2...\n");
}

// Function to perform option 3
void option3(void) {
    printf("Performing option 3...\n");
}

// Main function
int main(void) {
    int choice;

    do {
        // Display menu options
        display_menu();

        // Get user choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform selected option
        switch (choice) {
        case 1:
            option1();
            break;
        case 2:
            option2();
            break;
        case 3:
            option3();
            break;
        case 4:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }

    } while (choice!= 4);

    return 0;
}