//FormAI DATASET v1.0 Category: File handling ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    // Ask user for a file name
    char filename[50];
    printf("Enter the name of a file: ");
    scanf("%s", filename);

    // Open the file and check for errors
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s.", filename);
        exit(1);
    }

    // Get the file size and allocate memory for its contents
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    rewind(file);
    char *contents = malloc(size + 1);

    // Read the file into the contents buffer and add a null terminator
    fread(contents, 1, size, file);
    contents[size] = '\0';

    // Check if the file is a puzzle
    if (strstr(contents, "PUZZLE") != NULL) {
        printf("Congratulations, you found the puzzle!\n");
    } else {
        printf("Sorry, this file is not a puzzle.\n");
    }

    // Encode the puzzle solution
    char solution[] = "GUVF VF N CRGGL.\n";
    char encoded[size + 1];
    for (int i = 0; i < size; i++) {
        if (contents[i] >= 'A' && contents[i] <= 'Z') {
            encoded[i] = ((contents[i] - 'A' + 13) % 26) + 'A';
        } else if (contents[i] >= 'a' && contents[i] <= 'z') {
            encoded[i] = ((contents[i] - 'a' + 13) % 26) + 'a';
        } else {
            encoded[i] = contents[i];
        }
    }
    encoded[size] = '\0';

    // Write the encoded puzzle solution into a new file
    FILE *new_file = fopen("puzzle_solution.txt", "w");
    if (new_file == NULL) {
        printf("Could not create puzzle_solution.txt.");
        exit(1);
    }
    fprintf(new_file, "%s", encoded);
    fclose(new_file);

    // Free memory and close file
    free(contents);
    fclose(file);

    return 0;
}