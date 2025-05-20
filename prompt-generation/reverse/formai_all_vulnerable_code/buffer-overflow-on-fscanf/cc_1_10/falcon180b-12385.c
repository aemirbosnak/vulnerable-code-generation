//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum length of fields
#define MAX_NAME_LENGTH 100
#define MAX_ADDRESS_LENGTH 200
#define MAX_PHONE_LENGTH 20

// Define structure for resume data
typedef struct {
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Resume;

// Function to read resume data from file
Resume read_resume(FILE* file) {
    Resume resume;

    // Read name
    fscanf(file, "Name: %[^\n]", resume.name);

    // Read address
    fscanf(file, "Address: %[^\n]", resume.address);

    // Read phone number
    fscanf(file, "Phone: %[^\n]", resume.phone);

    return resume;
}

// Function to write resume data to file
void write_resume(FILE* file, Resume resume) {
    // Write name
    fprintf(file, "Name: %s\n", resume.name);

    // Write address
    fprintf(file, "Address: %s\n", resume.address);

    // Write phone number
    fprintf(file, "Phone: %s\n", resume.phone);
}

// Function to parse resume data
void parse_resume(Resume resume) {
    printf("Name: %s\n", resume.name);
    printf("Address: %s\n", resume.address);
    printf("Phone: %s\n", resume.phone);
}

int main() {
    // Open input file
    FILE* input_file = fopen("input.txt", "r");

    // Check if input file is valid
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    // Read resume data from input file
    Resume resume = read_resume(input_file);

    // Close input file
    fclose(input_file);

    // Parse resume data
    parse_resume(resume);

    // Open output file
    FILE* output_file = fopen("output.txt", "w");

    // Check if output file is valid
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        return 1;
    }

    // Write resume data to output file
    write_resume(output_file, resume);

    // Close output file
    fclose(output_file);

    return 0;
}