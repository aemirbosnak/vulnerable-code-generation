//FormAI DATASET v1.0 Category: Data validation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int main() {
    char name[50];
    int age;
    float height;

    // Validate name input
    bool valid_name = false;
    while (!valid_name) {
        printf("Enter your name (letters only): ");
        fgets(name, sizeof(name), stdin);

        // Check if input contains non-alphabetic characters
        bool only_letters = true;
        for (int i = 0; name[i] != '\0'; i++) {
            if (!isalpha(name[i])) {
                only_letters = false;
                break;
            }
        }

        if (only_letters) {
            valid_name = true;
        } else {
            printf("Invalid input! Name must contain letters only.\n");
        }
    }

    // Validate age input
    bool valid_age = false;
    while (!valid_age) {
        printf("Enter your age: ");
        if (scanf("%d", &age) == 1 && age >= 0 && age <= 120) {
            valid_age = true;
        } else {
            printf("Invalid input! Age must be a positive integer between 0 and 120.\n");

            // Clear buffer to avoid infinite loop
            while (getchar() != '\n') {}
        }
    }

    // Validate height input
    bool valid_height = false;
    while (!valid_height) {
        printf("Enter your height (in meters): ");
        if (scanf("%f", &height) == 1 && height > 0 && height <= 3) {
            valid_height = true;
        } else {
            printf("Invalid input! Height must be a positive float between 0 and 3 meters.\n");

            // Clear buffer to avoid infinite loop
            while (getchar() != '\n') {}
        }
    }

    // Print validated inputs
    printf("\nName: %s", name);
    printf("Age: %d\n", age);
    printf("Height: %.2f meters\n", height);

    return 0;
}