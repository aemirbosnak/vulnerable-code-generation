//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_FILE_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
} Person;

void save_person_to_file(const char *filename, Person person) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        fprintf(stderr, "Could not open file %s for writing. Please ensure the file path is correct and you have proper permissions.\n", filename);
        exit(EXIT_FAILURE);
    }

    if (fprintf(file, "%s,%d\n", person.name, person.age) < 0) {
        fprintf(stderr, "Error writing to file %s. Please check the disk and file permissions.\n", filename);
        fclose(file);
        exit(EXIT_FAILURE);
    }

    fclose(file);
    printf("Successfully saved %s to %s. Thank you for contributing!\n", person.name, filename);
}

void load_persons_from_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file %s for reading. It could be that the file does not exist or is empty.\n", filename);
        return;  // We will be grateful and just return here, allowing the program to continue running.
    }

    Person person;
    printf("Reading from %s...\n", filename);
    while (fgets(person.name, sizeof(person.name), file) != NULL) {
        // Parsing the line
        char *age_str = strchr(person.name, ',');
        if (age_str == NULL) {
            fprintf(stderr, "Error parsing the data in file %s. Ensure that the format is correct.\n", filename);
            continue;
        }
        
        *age_str = '\0';  // Split the name and age
        person.age = atoi(age_str + 1);  // Convert age to integer

        printf("Loaded: Name: %s, Age: %d\n", person.name, person.age);
    }

    fclose(file);
    printf("Finished reading from %s. Thank you for being patient while we processed the file!\n", filename);
}

void prompt_for_person_data() {
    Person person;
    printf("Please enter the name of the person: ");
    if (fgets(person.name, sizeof(person.name), stdin) == NULL) {
        fprintf(stderr, "Error reading the name. Please try again and make sure your input is valid.\n");
        return;
    }

    // Remove newline character
    size_t len = strlen(person.name);
    if (len > 0 && person.name[len - 1] == '\n') {
        person.name[len - 1] = '\0';
    }

    printf("Please enter the age of the person: ");
    if (scanf("%d", &person.age) != 1) {
        fprintf(stderr, "Invalid input for age. Please enter a numeric value.\n");
        while (getchar() != '\n'); // clear input buffer
        return;
    }

    char filename[MAX_FILE_LEN];
    printf("Please enter the filename to save this person's data (e.g., persons.txt): ");
    if (scanf("%s", filename) != 1) {
        fprintf(stderr, "Invalid filename input. Please enter a valid string.\n");
        return;
    }

    save_person_to_file(filename, person);
}

int main() {
    int choice;

    do {
        printf("\n--- Person Data Management ---\n");
        printf("1. Add a new person\n");
        printf("2. Load persons from file\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid option. Please enter a number between 1 to 3.\n");
            while (getchar() != '\n'); // clear input buffer
            continue; // return to the start of the loop
        }

        switch (choice) {
            case 1:
                prompt_for_person_data();
                break;
            case 2:
                {
                    char filename[MAX_FILE_LEN];
                    printf("Enter filename to load: ");
                    if (scanf("%s", filename) != 1) {
                        fprintf(stderr, "Failed to read filename. Please try again.\n");
                    } else {
                        load_persons_from_file(filename);
                    }
                }
                break;
            case 3:
                printf("Thank you for using the program. Goodbye!\n");
                break;
            default:
                fprintf(stderr, "Invalid choice. Please pick a number between 1 and 3.\n");
                break;
        }

        // Clear the input buffer for the next loop iteration
        while (getchar() != '\n');

    } while (choice != 3);

    return 0;
}