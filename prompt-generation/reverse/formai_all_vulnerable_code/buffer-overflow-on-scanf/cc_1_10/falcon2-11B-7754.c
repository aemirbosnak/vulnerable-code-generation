//Falcon2-11B DATASET v1.0 Category: Resume Parsing System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int parseResume(char* filename, char* name, char* email, char* phone, char* address, char* degree, char* major, char* minor, char* gpa) {
    // open the file
    FILE* fp = fopen(filename, "r");

    // check if file exists
    if (fp == NULL) {
        printf("File not found\n");
        return 1;
    }

    // read each line of the file
    char line[100];
    while (fgets(line, sizeof(line), fp)) {
        // check if line starts with "name:"
        if (strcmp(line, "name:") == 0) {
            // extract name from line
            sscanf(line + 5, "%s", name);
        }

        // check if line starts with "email:"
        else if (strcmp(line, "email:") == 0) {
            // extract email from line
            sscanf(line + 6, "%s", email);
        }

        // check if line starts with "phone:"
        else if (strcmp(line, "phone:") == 0) {
            // extract phone number from line
            sscanf(line + 6, "%s", phone);
        }

        // check if line starts with "address:"
        else if (strcmp(line, "address:") == 0) {
            // extract address from line
            sscanf(line + 9, "%s", address);
        }

        // check if line starts with "degree:"
        else if (strcmp(line, "degree:") == 0) {
            // extract degree from line
            sscanf(line + 7, "%s", degree);
        }

        // check if line starts with "major:"
        else if (strcmp(line, "major:") == 0) {
            // extract major from line
            sscanf(line + 7, "%s", major);
        }

        // check if line starts with "minor:"
        else if (strcmp(line, "minor:") == 0) {
            // extract minor from line
            sscanf(line + 8, "%s", minor);
        }

        // check if line starts with "gpa:"
        else if (strcmp(line, "gpa:") == 0) {
            // extract gpa from line
            sscanf(line + 5, "%s", gpa);
        }
    }

    // close the file
    fclose(fp);

    return 0;
}

int main() {
    char filename[100];
    char name[100];
    char email[100];
    char phone[100];
    char address[100];
    char degree[100];
    char major[100];
    char minor[100];
    char gpa[100];

    printf("Enter file name: ");
    scanf("%s", filename);

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter email: ");
    scanf("%s", email);

    printf("Enter phone number: ");
    scanf("%s", phone);

    printf("Enter address: ");
    scanf("%s", address);

    printf("Enter degree: ");
    scanf("%s", degree);

    printf("Enter major: ");
    scanf("%s", major);

    printf("Enter minor: ");
    scanf("%s", minor);

    printf("Enter gpa: ");
    scanf("%s", gpa);

    if (parseResume(filename, name, email, phone, address, degree, major, minor, gpa)) {
        printf("Parsing failed\n");
    } else {
        printf("Parsing successful\n");
    }

    return EXIT_SUCCESS;
}