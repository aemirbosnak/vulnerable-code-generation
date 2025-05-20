//Falcon2-11B DATASET v1.0 Category: Periodic Table Quiz ; Style: accurate
#include <stdio.h>

int main() {
    // Initialize variables
    int element, element_index, score;
    char element_name[10];

    // Print the title
    printf("Periodic Table Quiz\n");

    // Get the element name from the user
    printf("Enter an element symbol: ");
    scanf("%c", &element);

    // Check if the element is valid
    if (element >= 'A' && element <= 'Z') {
        // Get the element index from the user
        printf("Enter the element index (1-118): ");
        scanf("%d", &element_index);

        // Check if the element index is valid
        if (element_index >= 1 && element_index <= 118) {
            // Get the element name from the periodic table
            switch (element_index) {
                case 1:
                    // Hydrogen
                    sprintf(element_name, "H");
                    break;
                case 2:
                    // Helium
                    sprintf(element_name, "He");
                    break;
                case 3:
                    // Lithium
                    sprintf(element_name, "Li");
                    break;
                case 4:
                    // Beryllium
                    sprintf(element_name, "Be");
                    break;
                // Add cases for other elements...
                default:
                    // Invalid element index
                    printf("Invalid element index.\n");
                    return 1;
            }

            // Display the element name
            printf("Element %c is at index %d.\n", element, element_index);

            // Get the user's score
            printf("Enter your score (1-10): ");
            scanf("%d", &score);

            // Check if the score is valid
            if (score >= 1 && score <= 10) {
                // Display the result
                if (element_index == score) {
                    printf("Correct!\n");
                } else {
                    printf("Incorrect.\n");
                }
            } else {
                // Invalid score
                printf("Invalid score.\n");
            }
        } else {
            // Invalid element index
            printf("Invalid element index.\n");
        }
    } else {
        // Invalid element symbol
        printf("Invalid element symbol.\n");
    }

    // End the program
    return 0;
}