//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_INPUT 100
#define MAX_NUMBER 1000000

// Define a struct to represent a "work of art"
typedef struct {
    int num;      // The number of the artwork
    char name[50]; // The name of the artwork
    float price;   // The price of the artwork
} artwork_t;

// Define an array to store the artworks
artwork_t artworks[MAX_INPUT];

// Function to read input from the user and add it to the array
void read_input(void) {
    int i;
    for (i = 0; i < MAX_INPUT; i++) {
        printf("Enter a number (0-99): ");
        scanf("%d", &artworks[i].num);
        printf("Enter a name for the artwork (up to 50 characters): ");
        fgets(artworks[i].name, 50, stdin);
        printf("Enter the price of the artwork: ");
        scanf("%.2f", &artworks[i].price);
    }
}

// Function to calculate the total value of the artworks
float total_value(void) {
    int i;
    float total = 0;
    for (i = 0; i < MAX_INPUT; i++) {
        total += artworks[i].price;
    }
    return total;
}

// Function to display the artworks and their values
void display_artworks(void) {
    int i;
    for (i = 0; i < MAX_INPUT; i++) {
        printf("%d. %s - %.2f\n", artworks[i].num, artworks[i].name, artworks[i].price);
    }
}

int main(void) {
    int choice;

    // Prompt the user to enter the number of artworks they want to create
    printf("Welcome to the Art Gallery!\n");
    printf("How many artworks would you like to create? (0-100): ");
    scanf("%d", &choice);

    // Create the artworks based on the user's input
    for (int i = 0; i < choice; i++) {
        read_input();
    }

    // Calculate the total value of the artworks
    float total = total_value();

    // Display the artworks and their values
    display_artworks();

    // Ask the user if they want to calculate the total value again
    printf("Would you like to calculate the total value again? (y/n): ");
    char response;
    scanf(" %c", &response);

    if (response == 'y') {
        total_value();
    }

    return 0;
}