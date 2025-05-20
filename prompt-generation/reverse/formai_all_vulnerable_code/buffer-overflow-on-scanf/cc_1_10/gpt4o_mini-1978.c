//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256

unsigned int calculate_checksum(const char *data) {
    unsigned int checksum = 0;
    for (size_t i = 0; i < strlen(data); i++) {
        checksum += (unsigned char)data[i];
    }
    return checksum;
}

void to_binary(unsigned int num, char *binary, size_t size) {
    binary[size - 1] = '\0'; // Null-terminate the string
    
    for (size_t i = 0; i < size - 1; i++) {
        binary[size - 2 - i] = (num & (1 << i)) ? '1' : '0';
    }
}

void display_menu() {
    printf("Checksum Calculator Menu:\n");
    printf("1. Calculate Checksum\n");
    printf("2. Exit\n");
    printf("Please select an option: ");
}

int main() {
    char input[MAX_LENGTH];
    unsigned int checksum;
    char binary_representation[33]; // 32 bits + null terminator
    int choice;
    
    while (1) {
        display_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter string (max %d characters): ", MAX_LENGTH - 1);
                scanf(" %[^\n]", input); // Read string with spaces
                
                checksum = calculate_checksum(input);
                printf("Checksum calculated: %u\n", checksum);
                
                to_binary(checksum, binary_representation, sizeof(binary_representation));
                printf("Binary Representation: %s\n", binary_representation);
                break;

            case 2:
                printf("Exiting program. Goodbye!\n");
                exit(0);
                
            default:
                printf("Invalid choice, please try again.\n");
        }
        
        printf("\n");
    }
    
    return 0;
}