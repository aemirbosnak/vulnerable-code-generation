//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold parsed resume data
struct Resume {
    char name[50];
    char email[50];
    char phone[15];
    char skills[500];
};

// Parse resume function, takes file path and returns parsed resume struct
struct Resume parse_resume(const char* file_path) {
    // Open file for reading
    FILE* file = fopen(file_path, "r");
    if (!file) {
        printf("Error reading file\n");
        exit(EXIT_FAILURE);
    }
    
    // Allocate memory for parsed resume struct
    struct Resume resume;
    memset(&resume, 0, sizeof(struct Resume));
    
    // Parse each line of file
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        // Find name using regex
        // In this example, we simply check if line contains "Name:"
        if (strstr(line, "Name:")) {
            sscanf(line, "Name: %[^\n]s", resume.name);
        }
        
        // Find email using regex
        // In this example, we simply check if line contains "@"
        if (strstr(line, "@")) {
            sscanf(line, "%s", resume.email);
        }
        
        // Find phone using regex
        // In this example, we simply check if line contains "Phone:"
        if (strstr(line, "Phone:")) {
            sscanf(line, "Phone: %[^\n]s", resume.phone);
        }
        
        // Find skills using regex
        // In this example, we simply check if line contains "Skills:"
        if (strstr(line, "Skills:")) {
            sscanf(line, "Skills: %[^\n]s", resume.skills);
        }
    }
    
    // Close file and return parsed resume struct
    fclose(file);
    return resume;
}

int main() {
    // Call parse_resume function with file path
    struct Resume resume = parse_resume("resume.txt");
    
    // Print parsed resume data
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Skills: %s\n", resume.skills);
    
    return 0;
}