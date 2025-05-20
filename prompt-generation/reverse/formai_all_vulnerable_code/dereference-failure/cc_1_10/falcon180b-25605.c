//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Struct to hold resume data
typedef struct {
    char name[50];
    char address[100];
    char phone[15];
    char email[50];
    char education[100];
    char experience[200];
} Resume;

// Function to read input file and store data in resume struct
void read_input_file(Resume* resume, FILE* input_file) {
    char line[100];
    char* token;
    int i = 0;

    // Read name
    fgets(line, sizeof(line), input_file);
    token = strtok(line, ",");
    strcpy(resume->name, token);

    // Read address
    fgets(line, sizeof(line), input_file);
    strcpy(resume->address, line);

    // Read phone number
    fgets(line, sizeof(line), input_file);
    token = strtok(line, ",");
    strcpy(resume->phone, token);

    // Read email
    fgets(line, sizeof(line), input_file);
    strcpy(resume->email, line);

    // Read education
    fgets(line, sizeof(line), input_file);
    strcpy(resume->education, line);

    // Read experience
    fgets(line, sizeof(line), input_file);
    strcpy(resume->experience, line);
}

// Function to write parsed data to output file
void write_output_file(Resume* resume, FILE* output_file) {
    fprintf(output_file, "Name: %s\n", resume->name);
    fprintf(output_file, "Address: %s\n", resume->address);
    fprintf(output_file, "Phone: %s\n", resume->phone);
    fprintf(output_file, "Email: %s\n", resume->email);
    fprintf(output_file, "Education: %s\n", resume->education);
    fprintf(output_file, "Experience: %s\n", resume->experience);
}

// Function to parse resume data and write to output file
void parse_resume(Resume* resume, FILE* input_file, FILE* output_file) {
    read_input_file(resume, input_file);
    write_output_file(resume, output_file);
}

int main() {
    Resume resume;
    FILE* input_file = fopen("input.txt", "r");
    FILE* output_file = fopen("output.txt", "w");

    if (input_file == NULL || output_file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    parse_resume(&resume, input_file, output_file);

    fclose(input_file);
    fclose(output_file);

    return 0;
}