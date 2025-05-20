//LLAMA2-13B DATASET v1.0 Category: Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define MAX_GUESTS 10

// Structure to hold guest information
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} guest_t;

// Function to read guest information from file
void read_guests(FILE *file, guest_t *guests) {
    char line[100];
    int i = 0;

    while (fgets(line, 100, file) != NULL) {
        // Skip empty lines and comments
        if (strlen(line) == 0 || line[0] == '#') {
            continue;
        }

        // Extract name and age from line
        sscanf(line, "%s %d", guests[i].name, &guests[i].age);

        // Increment index and check for end of file
        i++;
        if (feof(file)) {
            break;
        }
    }
}

// Function to print guest list
void print_guests(guest_t *guests) {
    int i = 0;

    printf("Guest List:\n");
    while (i < MAX_GUESTS) {
        printf(" %s (%d)\n", guests[i].name, guests[i].age);
        i++;
    }
}

int main() {
    // Open guest file
    FILE *file = fopen("guests.txt", "r");

    // Check for file open error
    if (file == NULL) {
        perror("Error opening guest file");
        return 1;
    }

    // Read guest information from file
    guest_t guests[MAX_GUESTS];
    read_guests(file, guests);

    // Print guest list
    print_guests(guests);

    // Close file
    fclose(file);

    return 0;
}