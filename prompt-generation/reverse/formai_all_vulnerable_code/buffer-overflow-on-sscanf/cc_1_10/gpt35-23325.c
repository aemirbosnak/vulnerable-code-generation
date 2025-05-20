//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define structs to hold information about resumes
typedef struct {
    char* name;
    char* email;
    char* phone;
} ContactInfo;

typedef struct {
    int start_year;
    int end_year;
    char* company;
    char* position;
} WorkExperience;

typedef struct {
    char* school_name;
    int graduation_year;
    char* degree;
    char* major;
} Education;

// Define a function to parse resumes and create a struct for each one
void parse_resume(char* filename) {
    FILE* f = fopen(filename, "r");
    if (!f) {
        printf("Error: unable to open file %s\n", filename);
        return;
    }

    // Initialize structs to hold information about resume
    ContactInfo contact = { NULL, NULL, NULL };
    WorkExperience work[10] = { 0 };
    Education education[10] = { 0 };

    // Parse the file line by line
    char line[256];
    while (fgets(line, sizeof(line), f)) {
        char header[32], value[224];
        int num_fields = sscanf(line, "%s %224[^\n]", header, value);
        if (num_fields != 2) {
            continue; // Ignore any lines that don't have a header and a value
        }

        // Parse the header and the value
        if (strcmp(header, "Name:") == 0) {
            contact.name = strdup(value);
        } else if (strcmp(header, "Email:") == 0) {
            contact.email = strdup(value);
        } else if (strcmp(header, "Phone:") == 0) {
            contact.phone = strdup(value);
        } else if (strcmp(header, "Work Experience:") == 0) {
            // Parse the start year, end year, company, and position
            int start_year, end_year;
            char company[128], position[128];
            int num_fields = sscanf(value, "%d - %d, %127[^,], %127[^\n]", &start_year, &end_year, company, position);
            if (num_fields == 4) {
                // Add this work experience to the array
                int i;
                for (i = 0; i < 10 && work[i].start_year != 0; i++);
                work[i].start_year = start_year;
                work[i].end_year = end_year;
                work[i].company = strdup(company);
                work[i].position = strdup(position);
            }
        } else if (strcmp(header, "Education:") == 0) {
            // Parse the school name, graduation year, degree, and major
            char school_name[128], degree[128], major[128];
            int graduation_year;
            int num_fields = sscanf(value, "%127[^,], %127[^,], %d, %127[^\n]", school_name, degree, &graduation_year, major);
            if (num_fields == 4) {
                // Add this education to the array
                int i;
                for (i = 0; i < 10 && education[i].school_name != NULL; i++);
                education[i].school_name = strdup(school_name);
                education[i].graduation_year = graduation_year;
                education[i].degree = strdup(degree);
                education[i].major = strdup(major);
            }

        }
    }

    // Close the file
    fclose(f);

    // Print out the parsed information for this resume
    printf("Name: %s\n", contact.name);
    printf("Email: %s\n", contact.email);
    printf("Phone: %s\n", contact.phone);
    printf("Work Experience:\n");
    int i;
    for (i = 0; i < 10 && work[i].start_year != 0; i++) {
        printf("%d - %d: %s, %s\n", work[i].start_year, work[i].end_year, work[i].company, work[i].position);
    }
    printf("Education:\n");
    for (i = 0; i < 10 && education[i].school_name != NULL; i++) {
        printf("%s\n", education[i].school_name);
        printf("%s, %s\n", education[i].degree, education[i].major);
        printf("Graduated in %d\n", education[i].graduation_year);
    }
    printf("\n");
}

int main() {
    parse_resume("resume1.txt");
    parse_resume("resume2.txt");
    parse_resume("resume3.txt");
    return 0;
}