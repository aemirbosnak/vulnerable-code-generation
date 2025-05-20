//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// Function prototypes
uint32_t calculate_checksum(const char *data, size_t length);
void display_checksum(uint32_t checksum);
void user_input_handler();
void file_input_handler();
char* get_input_file_name();

int main() {
    // Cosmic declaration of the variable to hold user’s choices 
    int choice;
    
    printf("Welcome to the Mind-Bending C Checksum Calculator!\n");
    printf("Choose your source of data:\n");
    printf("1. Input from Console\n");
    printf("2. Input from File\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    // Galactic decision-making based on user choice
    switch (choice) {
        case 1:
            user_input_handler();
            break;
        case 2:
            file_input_handler();
            break;
        default:
            printf("Invalid choice! Exiting...\n");
            return 1;
    }
    
    return 0;
}

// Function to handle user input from the console
void user_input_handler() {
    // Announcing the next step in this infinite loop of data collection
    printf("Enter the data for checksum calculation (end with EOF):\n");
    
    // Dynamic memory allocation for user data
    size_t bufsize = 1024;
    char *data = (char *)malloc(bufsize * sizeof(char));
    if (!data) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    size_t length = 0;
    // Reading data until EOF (Ctrl+D)
    while (getline(&data, &bufsize, stdin) != -1) {
        length += strlen(data);
    }

    // Calculating the checksum 
    uint32_t checksum = calculate_checksum(data, length);
    display_checksum(checksum);
    
    // Freeing the allocated memory
    free(data);
}

// Function to handle file input 
void file_input_handler() {
    // Prompting for file name
    char *filename = get_input_file_name();
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file: %s\n", filename);
        free(filename);
        return;
    }

    // Reading data from file
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    char *data = (char *)malloc(file_size + 1);
    if (!data) {
        fprintf(stderr, "Memory allocation failed!\n");
        fclose(file);
        free(filename);
        exit(EXIT_FAILURE);
    }
    
    fread(data, 1, file_size, file);
    data[file_size] = '\0'; // Null-terminate

    // Calculating checksum 
    uint32_t checksum = calculate_checksum(data, file_size);
    display_checksum(checksum);

    // Cleanup 
    fclose(file);
    free(filename);
    free(data);
}

// Function to read input file name
char* get_input_file_name() {
    char *filename = (char *)malloc(256 * sizeof(char));
    if (!filename) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    printf("Enter the name of the file: ");
    scanf("%s", filename);
    return filename;
}

// Function to calculate the checksum
uint32_t calculate_checksum(const char *data, size_t length) {
    // Implementation of a simple checksum algorithm (sum of bytes)
    uint32_t checksum = 0;
    for (size_t i = 0; i < length; i++) {
        checksum += (uint8_t)data[i]; // Cast to uint8_t to get byte value
    }
    return checksum;
}

// Function to display the calculated checksum
void display_checksum(uint32_t checksum) {
    printf("The calculated checksum is: 0x%08X\n", checksum);
}