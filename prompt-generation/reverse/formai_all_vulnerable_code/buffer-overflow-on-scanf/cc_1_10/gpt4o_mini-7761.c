//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

void display_menu() {
    printf("Welcome to the Simple Checksum Calculator!\n");
    printf("===========================================\n");
    printf("1. Calculate Checksum\n");
    printf("2. Exit\n");
    printf("Choose an option (1 or 2): ");
}

unsigned long calculate_checksum(FILE *file) {
    unsigned long checksum = 0;
    char buffer[MAX_BUFFER_SIZE];
    
    while (fread(buffer, sizeof(char), MAX_BUFFER_SIZE, file)) {
        for (int i = 0; i < MAX_BUFFER_SIZE; i++) {
            checksum += (unsigned char)buffer[i];
        }
    }

    return checksum;
}

void calculate_and_display_checksum() {
    char filename[256];
    printf("Enter the name of the file to calculate the checksum: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return;
    }

    unsigned long checksum = calculate_checksum(file);
    fclose(file);
    
    printf("Checksum of file \"%s\" is: %lu\n", filename, checksum);
}

int main() {
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                calculate_and_display_checksum();
                break;
            case 2:
                printf("Thank you for using the Checksum Calculator! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    }

    return 0;
}