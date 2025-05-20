//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 500

// Data structure to store the relevant information from a resume
typedef struct resume {
    char name[50];
    char email[50];
    char phone[20];
    char education[100];
    char skills[500];
} Resume;

// Function to extract relevant information from a resume
void extractResumeInfo(char* resumeData, Resume* res) {

    int i = 0, j = 0, k = 0, l = 0, m = 0;
    char currentLine[MAX_LINE_LENGTH];

    while (resumeData[i] != '\0') {

        // Check if the current character is a new line character
        if (resumeData[i] == '\n') {

            // Check if the current line contains relevant information
            if (strstr(currentLine, "Name:") != NULL) {
                sscanf(currentLine + 5, "%s", res->name);
            }
            else if (strstr(currentLine, "Email:") != NULL) {
                sscanf(currentLine + 6, "%s", res->email);
            }
            else if (strstr(currentLine, "Phone:") != NULL) {
                sscanf(currentLine + 6, "%s", res->phone);
            }
            else if (strstr(currentLine, "Education:") != NULL) {
                sscanf(currentLine + 10, "%[^\n]", res->education);
            }
            else if (strstr(currentLine, "Skills:") != NULL) {
                sscanf(currentLine + 7, "%[^\n]", res->skills);
            }

            // Reset the current line buffer
            j = 0;
            k = 0;
            l = 0;
            m = 0;
            currentLine[j] = '\0';

        }
        else {

            // Check if the current character is a printable character
            if (isprint(resumeData[i])) {

                // Add the current character to the current line buffer
                if (j < MAX_LINE_LENGTH - 1) {
                    currentLine[j++] = resumeData[i];
                }

                // Check for overflow in education or skills buffer
                if (l < 100 && k > 9) {
                    res->education[l++] = resumeData[i];
                }
                else if (m < 500 && k > 6) {
                    res->skills[m++] = resumeData[i];
                }

                // Increment the character counter
                k++;
            }
        }

        // Increment the character pointer
        i++;
    }
}

int main() {

    // Sample resume data
    char* resumeData =
        "Name: John Doe\n"
        "Email: john.doe@email.com\n"
        "Phone: 123-456-7890\n"
        "Education: Bachelor of Science in Computer Science, XYZ University, 2008-2012\n"
        "Skills: C, C++, Java, Python, SQL, HTML, CSS\n";

    // Initialize an instance of the Resume struct
    Resume myResume;

    // Extract relevant information from the resume
    extractResumeInfo(resumeData, &myResume);

    // Print out the extracted information
    printf("Name: %s\n", myResume.name);
    printf("Email: %s\n", myResume.email);
    printf("Phone: %s\n", myResume.phone);
    printf("Education: %s\n", myResume.education);
    printf("Skills: %s\n", myResume.skills);

    return 0;
}