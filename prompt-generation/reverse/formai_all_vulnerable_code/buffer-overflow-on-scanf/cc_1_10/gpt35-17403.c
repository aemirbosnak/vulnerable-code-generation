//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CV {
    char name[50];
    char email[50];
    char phone[15];
    char address[100];
    char skills[200];
} CV;

void parse_resume(char *filename, CV *cv) {
    // Open file
    FILE *f = fopen(filename, "r");
    if (!f) {
        printf("File not found!\n");
        exit(1);
    }
    
    // Read file line by line
    char line[200];
    int count = 0;
    while (fgets(line, 200, f)) {
        count++;
        // Parse name
        if (count == 1) {
            strcpy(cv->name, line);
            cv->name[strlen(line)-1] = '\0';
        }
        // Parse email
        if (strstr(line, "@")) {
            strcpy(cv->email, line);
            cv->email[strlen(line)-1] = '\0';
        }
        // Parse phone
        if (strstr(line, "Phone")) {
            strcpy(cv->phone, line+6);
            cv->phone[strlen(line)-8] = '\0';
        }
        // Parse address
        if (strstr(line, "Address")) {
            strcpy(cv->address, line+9);
            cv->address[strlen(line)-11] = '\0';
        }
        // Parse skills
        if (strstr(line, "Skills")) {
            fgets(line, 200, f);
            strcpy(cv->skills, line);
            cv->skills[strlen(line)-1] = '\0';
        }
    }
    
    // Close file
    fclose(f);
}

int main() {
    char filename[50];
    printf("Enter the filename of the resume: ");
    scanf("%s", filename);
    
    CV cv;
    parse_resume(filename, &cv);
    
    // Print CV
    printf("Name: %s\n", cv.name);
    printf("Email: %s\n", cv.email);
    printf("Phone: %s\n", cv.phone);
    printf("Address: %s\n", cv.address);
    printf("Skills: %s\n", cv.skills);
    
    return 0;
}