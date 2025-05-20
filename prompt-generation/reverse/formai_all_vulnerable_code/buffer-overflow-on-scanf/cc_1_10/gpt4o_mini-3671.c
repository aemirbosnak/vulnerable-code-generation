//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

unsigned short calculate_checksum(const char *data) {
    unsigned long sum = 0;
    size_t length = strlen(data);
    
    for (size_t i = 0; i < length; i++) {
        sum += data[i]; // add current character to the sum
        if (sum > 65535) { // if sum exceeds 16 bits
            sum -= 65536; // wrap around
        }
    }
    
    // Return the one's complement of the sum
    return (unsigned short)(~sum);
}

void display_menu() {
    printf("===================================\n");
    printf("         CHECKSUM CALCULATOR      \n");
    printf("===================================\n");
    printf("1. Calculate Checksum\n");
    printf("2. Exit\n");
    printf("Choose an option: ");
}

int main() {
    char input[MAX_INPUT_SIZE];
    unsigned short checksum;

    while (1) {
        display_menu();
        
        int choice;
        scanf("%d", &choice);

        // Handle choices
        if (choice == 1) {
            printf("Enter the data (max %d characters): ", MAX_INPUT_SIZE - 1);
            getchar(); // consume newline from previous input
            fgets(input, MAX_INPUT_SIZE, stdin);
            // Remove trailing newline
            input[strcspn(input, "\n")] = 0;

            checksum = calculate_checksum(input);
            printf("The checksum of \"%s\" is: 0x%04X\n", input, checksum);
        } else if (choice == 2) {
            printf("Exiting the program. Goodbye!\n");
            break;
        } else {
            printf("Invalid choice! Please try again.\n");
        }

        printf("\n"); // empty line for better output separation
    }

    return 0;
}