//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMBERS 100
#define FILE_NAME "numbers.txt"

// Function to calculate checksum
unsigned long calculate_checksum(int numbers[], int count) {
    unsigned long checksum = 0;
    for (int i = 0; i < count; i++) {
        checksum += numbers[i];
    }
    return checksum;
}

// Function to read numbers from the file
int read_numbers_from_file(const char *filename, int numbers[]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open file!");
        return -1;
    }
    
    int count = 0;
    while (fscanf(file, "%d", &numbers[count]) != EOF && count < MAX_NUMBERS) {
        count++;
    }
    
    fclose(file);
    return count;
}

// Function to display the numbers
void display_numbers(int numbers[], int count) {
    printf("Here are the numbers we will be calculating the checksum for:\n");
    for (int i = 0; i < count; i++) {
        printf("Number %d: %d\n", i + 1, numbers[i]);
    }
}

// Main function to execute the program
int main() {
    int numbers[MAX_NUMBERS];
    memset(numbers, 0, sizeof(numbers));

    printf("🚀 Welcome to the Exciting C Checksum Calculator! 🚀\n");

    int count = read_numbers_from_file(FILE_NAME, numbers);
    if (count < 0) {
        return EXIT_FAILURE;
    }

    if (count == 0) {
        printf("😲 Oops! No numbers found in the file. Please add numbers to %s.\n", FILE_NAME);
        return EXIT_FAILURE;
    }

    display_numbers(numbers, count);

    unsigned long checksum = calculate_checksum(numbers, count);
    printf("💡 The calculated checksum of the provided numbers is: %lu\n", checksum);

    printf("🎉 Thank you for using the C Checksum Calculator! 🎉\n");
    return EXIT_SUCCESS;
}