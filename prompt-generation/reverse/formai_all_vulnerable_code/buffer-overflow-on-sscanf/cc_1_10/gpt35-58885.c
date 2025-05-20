//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: secure
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_STRING_LENGTH 1000 // Maximum length of a string

// Defining a structure for Storing Resume Data
typedef struct Resume {
    char name[MAX_STRING_LENGTH];
    char email[MAX_STRING_LENGTH];
    char phone[MAX_STRING_LENGTH];
    char address[MAX_STRING_LENGTH];
    char education[MAX_STRING_LENGTH];
    char experience[MAX_STRING_LENGTH];
} ResumeInfo;

// Function to parse the Resume Data
ResumeInfo parseResume(char* resumeData) {

    ResumeInfo resume; // Initializing a ResumeInfo variable
    
    // Extracting the Name from the ResumeData
    char* name = strstr(resumeData, "Name:");
    if(name) {
        sscanf(name + 5, "%s", resume.name);
    }

    // Extracting the Email from the ResumeData
    char* email = strstr(resumeData, "Email:");
    if(email) {
        sscanf(email + 6, "%s", resume.email);
    }

    // Extracting the Phone Number from the ResumeData
    char* phone = strstr(resumeData, "Phone:");
    if(phone) {
        sscanf(phone + 6, "%s", resume.phone);
    }

    // Extracting the Address from the ResumeData
    char* address = strstr(resumeData, "Address:");
    if(address) {
        sscanf(address + 8, "%s", resume.address);
    }

    // Extracting the Education from the ResumeData
    char* education = strstr(resumeData, "Education:");
    if(education) {
        sscanf(education + 10, "%s", resume.education);
    }

    // Extracting the Experience from the ResumeData
    char* experience = strstr(resumeData, "Experience:");
    if(experience) {
        sscanf(experience + 11, "%s", resume.experience);
    }

    return resume;
}

// Function to securely read a line
void readLine(char* string, size_t max) {
    if (fgets(string, max, stdin) == NULL) {
        string[0] = '\0';
    } else {
        string[strcspn(string, "\n")] = '\0';
    }
}

// Main Function
int main() {

    char resumeData[MAX_STRING_LENGTH]; // Initializing a character array for storing Resume Data
    printf("Enter the Resume Data: ");
    readLine(resumeData, MAX_STRING_LENGTH); // Reading the Resume Data from the user
    ResumeInfo resume = parseResume(resumeData); // Parsing the Resume Data

    // Displaying the results
    printf("\nName: %s\nEmail: %s\nPhone: %s\nAddress: %s\nEducation: %s\nExperience: %s\n",
            resume.name, resume.email, resume.phone, resume.address, resume.education, resume.experience);

    return 0;
}