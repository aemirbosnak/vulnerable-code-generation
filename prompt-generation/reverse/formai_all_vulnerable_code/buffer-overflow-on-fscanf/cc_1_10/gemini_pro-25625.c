//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of suspects
#define MAX_SUSPECTS 10

// Define the structure of a suspect
typedef struct {
    char name[50];
    int age;
    char gender[10];
    char occupation[50];
    char motive[50];
    char alibi[50];
} suspect_t;

// Define the array of suspects
suspect_t suspects[MAX_SUSPECTS];

// Define the function to read the suspects from a file
void read_suspects(char *filename) {
    FILE *fp;
    int i;

    // Open the file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Read the suspects from the file
    for (i = 0; i < MAX_SUSPECTS; i++) {
        fscanf(fp, "%s %d %s %s %s %s", suspects[i].name, &suspects[i].age, suspects[i].gender, suspects[i].occupation, suspects[i].motive, suspects[i].alibi);
    }

    // Close the file
    fclose(fp);
}

// Define the function to print the suspects
void print_suspects() {
    int i;

    // Print the suspects
    for (i = 0; i < MAX_SUSPECTS; i++) {
        printf("%s, %d, %s, %s, %s, %s\n", suspects[i].name, suspects[i].age, suspects[i].gender, suspects[i].occupation, suspects[i].motive, suspects[i].alibi);
    }
}

// Define the function to find the most likely suspect
suspect_t find_most_likely_suspect() {
    int i;
    suspect_t most_likely_suspect;

    // Initialize the most likely suspect
    most_likely_suspect.name[0] = '\0';
    most_likely_suspect.age = 0;
    most_likely_suspect.gender[0] = '\0';
    most_likely_suspect.occupation[0] = '\0';
    most_likely_suspect.motive[0] = '\0';
    most_likely_suspect.alibi[0] = '\0';

    // Find the suspect with the most likely motive
    for (i = 0; i < MAX_SUSPECTS; i++) {
        if (strcmp(suspects[i].motive, "Revenge") == 0) {
            most_likely_suspect = suspects[i];
            break;
        }
    }

    // Find the suspect with the most likely alibi
    for (i = 0; i < MAX_SUSPECTS; i++) {
        if (strcmp(suspects[i].alibi, "None") == 0) {
            most_likely_suspect = suspects[i];
            break;
        }
    }

    // Return the most likely suspect
    return most_likely_suspect;
}

int main() {
    // Read the suspects from the file
    read_suspects("suspects.txt");

    // Print the suspects
    print_suspects();

    // Find the most likely suspect
    suspect_t most_likely_suspect = find_most_likely_suspect();

    // Print the most likely suspect
    printf("The most likely suspect is %s.\n", most_likely_suspect.name);

    return 0;
}