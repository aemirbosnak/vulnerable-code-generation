//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold resume information
typedef struct resume {
    char name[50];
    char email[50];
    char phone[20];
    char education[100];
    char experience[500];
    // ... additional fields as needed
} Resume;

int main() {
    char resumeText[1000]; // Assume the resume is no longer than 1000 characters
    printf("Please enter the resume text:\n");
    scanf("%[^\n]", resumeText); // Read the entire line of text, stopping at the newline character
    
    // Split the text into individual words
    char *word;
    char *delimiter = " ,.-\n"; // Assume words are separated by space, comma, hyphen, period, or newline
    word = strtok(resumeText, delimiter);
    
    // Create a new resume object
    Resume *newResume = (Resume *) malloc(sizeof(Resume));
    strcpy(newResume->name, ""); // Initialize the name field
    strcpy(newResume->email, ""); // Initialize the email field
    strcpy(newResume->phone, ""); // Initialize the phone field
    strcpy(newResume->education, ""); // Initialize the education field
    strcpy(newResume->experience, ""); // Initialize the experience field
    
    // Loop through each word in the resume text
    while (word != NULL) {
        // Check if the word is a name
        if (strlen(word) > 3 && word[0] >= 'A' && word[0] <= 'Z') {
            strcat(newResume->name, word);
            strcat(newResume->name, " ");
        }
        
        // Check if the word is an email address
        if (strstr(word, "@") != NULL) {
            strcpy(newResume->email, word);
        }
        
        // Check if the word is a phone number
        if (strlen(word) == 10 && word[0] >= '0' && word[0] <= '9') {
            strcpy(newResume->phone, word);
        }
        
        // Check if the word is an educational institution
        if (strlen(word) > 5 && (strcmp(word, "college") == 0 || strcmp(word, "university") == 0)) {
            strcat(newResume->education, word);
            strcat(newResume->education, " ");
        }
        
        // Check if the word is a job title or company name
        if (strlen(word) > 2 && (strstr(word, "engineer") != NULL || strstr(word, "developer") != NULL || strstr(word, "manager") != NULL)) {
            strcat(newResume->experience, word);
            strcat(newResume->experience, " ");
        }
        
        word = strtok(NULL, delimiter);
    }
    
    // Print out the parsed resume fields
    printf("Name: %s\n", newResume->name);
    printf("Email: %s\n", newResume->email);
    printf("Phone: %s\n", newResume->phone);
    printf("Education: %s\n", newResume->education);
    printf("Experience: %s\n", newResume->experience);
    
    free(newResume); // Free the memory allocated for the resume object
    
    return 0;
}