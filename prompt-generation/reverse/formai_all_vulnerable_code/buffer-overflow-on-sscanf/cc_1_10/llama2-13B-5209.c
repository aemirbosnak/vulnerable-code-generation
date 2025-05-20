//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 25
#define MAX_GUESTS 10

// Structure to store guest information
typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_NAME_LENGTH];
    int age;
    int arrived;
} guest_t;

// Function to read guest information from file
void read_guests(FILE *file, guest_t *guests) {
    int i = 0;
    char line[1024];

    while (fgets(line, 1024, file)) {
        // Skip empty lines and comments
        if (strlen(line) == 0 || line[0] == '#') {
            continue;
        }

        // Parse name, email, age, and arrived information
        sscanf(line, "%s %s %d %d", guests[i].name, guests[i].email, &guests[i].age, &guests[i].arrived);

        // Increment index and check for end of file
        i++;
        if (feof(file)) {
            break;
        }
    }
}

// Function to print guest information in a thoughtful style
void print_guests(guest_t *guests, int num_guests) {
    int i = 0;

    printf("Welcome, dear guests!\n");

    while (i < num_guests) {
        printf("Our lovely guest %s, aged %d, has arrived!\n", guests[i].name, guests[i].age);

        // Print a personalized message based on the guest's age
        if (guests[i].age >= 18 && guests[i].age <= 24) {
            printf("We hope you enjoy your time here and take advantage of our special deals for young adults!");
        } else if (guests[i].age >= 25 && guests[i].age <= 34) {
            printf("We're so glad you're here! Don't forget to try our signature cocktails and desserts!");
        } else if (guests[i].age >= 35 && guests[i].age <= 49) {
            printf("Welcome, esteemed guest! We hope you have a relaxing and rejuvenating time with us.");
        } else {
            printf("We're honored to have you here! Enjoy your stay and let us know if you need anything.");
        }

        // Increment index and check for end of array
        i++;
    }

    printf("\nThank you for joining us! We hope you have a wonderful time.\n");
}

int main() {
    // Open guest file
    FILE *file = fopen("guests.txt", "r");

    // Check for file error
    if (file == NULL) {
        perror("Error opening guests.txt");
        return 1;
    }

    // Read guest information from file
    guest_t guests[MAX_GUESTS];
    read_guests(file, guests);

    // Print guest information in a thoughtful style
    print_guests(guests, MAX_GUESTS);

    // Close file
    fclose(file);

    return 0;
}