//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: all-encompassing
// A unique C Digital Watermarking example program

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Define the maximum size of the message
#define MAX_SIZE 1000

// Define the watermark
#define WATERMARK "digitalwatermark"

// Function to check if the message has already been watermarked
// Returns 1 if the message has already been watermarked, else 0
int isWatermarked(char *message) {
    if (strstr(message, WATERMARK) != NULL) {
        return 1;
    }
    return 0;
}

// Function to add the watermark to the message
void addWatermark(char *message) {
    strcat(message, WATERMARK);
}

// Function to remove the watermark from the message
void removeWatermark(char *message) {
    char *watermark = strstr(message, WATERMARK);
    if (watermark != NULL) {
        *watermark = '\0';
    }
}

int main() {
    char message[MAX_SIZE];
    int choice;

    printf("Welcome to Digital Watermarking example program!\n");
    
    // Loop until the user chooses to quit
    while(1) {
        printf("\nPlease select an option:\n");
        printf("1. Add watermark to message\n");
        printf("2. Remove watermark from message\n");
        printf("3. Check if message has been watermarked\n");
        printf("4. Quit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        // Handle invalid choices
        if (choice < 1 || choice > 4) {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        // Handle the user's choice
        switch(choice) {
            case 1:
                printf("Enter message to add watermark to: ");
                getchar(); // consume newline character
                fgets(message, MAX_SIZE, stdin);
                if (isWatermarked(message)) {
                    printf("Message has already been watermarked.\n");
                } else {
                    addWatermark(message);
                    printf("Watermark added to message: %s\n", message);
                }
                break;
            case 2:
                printf("Enter message to remove watermark from: ");
                getchar(); // consume newline character
                fgets(message, MAX_SIZE, stdin);
                if (isWatermarked(message)) {
                    removeWatermark(message);
                    printf("Watermark removed from message: %s\n", message);
                } else {
                    printf("Message has not been watermarked.\n");
                }
                break;
            case 3:
                printf("Enter message to check for watermark: ");
                getchar(); // consume newline character
                fgets(message, MAX_SIZE, stdin);
                if (isWatermarked(message)) {
                    printf("Message has been watermarked.\n");
                } else {
                    printf("Message has not been watermarked.\n");
                }
                break;
            case 4:
                printf("Thank you for using Digital Watermarking example program!\n");
                exit(0);
        }
    }

    return 0;
}