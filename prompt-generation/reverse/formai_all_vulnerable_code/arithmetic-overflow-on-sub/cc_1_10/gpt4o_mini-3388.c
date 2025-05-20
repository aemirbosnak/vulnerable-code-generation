//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

// Function to simulate file download
double simulate_download(size_t file_size) {
    // Simulating time taken to download a file
    usleep(file_size * 100); // Sleep for file_size * 100 microseconds to simulate download speed
    return file_size; // returning size for simplicity
}

// Function to display the retro user interface
void display_intro() {
    printf("\n");
    printf("=====================================\n");
    printf("      Retro Internet Speed Test      \n");
    printf("         By Your Name (2023)        \n");
    printf("=====================================\n");
    printf("This program will simulate checking your internet speed by downloading a small file.\n");
    printf("Let's see how fast your connection is!\n");
    printf("=====================================\n");
}

// Function to calculate speed in Mbps
double calculate_speed(size_t file_size, double time_taken) {
    return (file_size * 8) / (time_taken * 1000000); // Convert bytes to bits, and the result to Mbps
}

// Function to execute speed test
void speed_test() {
    const size_t file_size = 1024 * 1024; // 1 MB file
    printf("Preparing to download a file of size %zu bytes...\n", file_size);

    clock_t start_time = clock(); // Start timer
    simulate_download(file_size);
    clock_t end_time = clock(); // End timer

    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC; // Calculate time taken
    double speed = calculate_speed(file_size, time_taken); // Calculate speed

    printf("Download complete!\n");
    printf("Time taken: %.2f seconds\n", time_taken);
    printf("Estimated Speed: %.2f Mbps\n", speed);
}

int main() {
    char choice;

    display_intro();
    
    while (1) {
        printf("Do you want to perform an internet speed test? (y/n): ");
        choice = getchar();
        while(getchar() != '\n'); // Clear the input buffer
        
        if (choice == 'y' || choice == 'Y') {
            speed_test();
        } else if (choice == 'n' || choice == 'N') {
            printf("Thank you for using the Retro Internet Speed Test. Goodbye!\n");
            break;
        } else {
            printf("Invalid input! Please enter 'y' or 'n'.\n");
        }
    }

    return 0;
}