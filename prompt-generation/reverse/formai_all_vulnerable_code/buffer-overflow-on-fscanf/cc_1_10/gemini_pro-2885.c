//GEMINI-pro DATASET v1.0 Category: File handling ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the bunker's capacity
#define BUNKER_CAPACITY 10

// Define the survivor struct
typedef struct survivor {
    char name[32];
    int age;
    int health;
    int skills[5];
} survivor;

// Create an array of survivors
survivor survivors[BUNKER_CAPACITY];

// Load the survivors from a file
void load_survivors(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Read the number of survivors from the file
    int num_survivors;
    fscanf(file, "%d", &num_survivors);

    // Read the survivors from the file
    for (int i = 0; i < num_survivors; i++) {
        fscanf(file, "%s %d %d", survivors[i].name, &survivors[i].age, &survivors[i].health);
        
        // Read the survivor's skills from the file
        for (int j = 0; j < 5; j++) {
            fscanf(file, "%d", &survivors[i].skills[j]);
        }
    }

    // Close the file
    fclose(file);
}

// Save the survivors to a file
void save_survivors(char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Write the number of survivors to the file
    int num_survivors = sizeof(survivors) / sizeof(survivor);
    fprintf(file, "%d\n", num_survivors);

    // Write the survivors to the file
    for (int i = 0; i < num_survivors; i++) {
        fprintf(file, "%s %d %d", survivors[i].name, survivors[i].age, survivors[i].health);

        // Write the survivor's skills to the file
        for (int j = 0; j < 5; j++) {
            fprintf(file, " %d", survivors[i].skills[j]);
        }

        fprintf(file, "\n");
    }

    // Close the file
    fclose(file);
}

// Print the survivors to the console
void print_survivors() {
    for (int i = 0; i < sizeof(survivors) / sizeof(survivor); i++) {
        printf("%s (%d years old, health: %d)\n", survivors[i].name, survivors[i].age, survivors[i].health);
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    // Load the survivors from the file
    load_survivors(argv[1]);

    // Print the survivors to the console
    print_survivors();

    // Save the survivors to the file
    save_survivors(argv[1]);

    return 0;
}