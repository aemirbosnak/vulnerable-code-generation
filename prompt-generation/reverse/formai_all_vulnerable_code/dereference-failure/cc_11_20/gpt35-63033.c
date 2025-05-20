//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // User input for resume
    printf("Please enter your resume: ");
    char* resume = (char *)malloc(1000 * sizeof(char));
    fgets(resume, 1000, stdin);

    // Parsing resume for relevant information
    char* name = (char *)malloc(100 * sizeof(char));
    char* email = (char *)malloc(100 * sizeof(char));
    char* phone = (char *)malloc(20 * sizeof(char));
    char* experience = (char *)malloc(500 * sizeof(char));
    char* education = (char *)malloc(500 * sizeof(char));

    // Extracting name from resume
    char* temp_name = strstr(resume, "Name:");
    if (temp_name != NULL)
    {
        temp_name += 5;
        char* end_name = strstr(temp_name, "\n");
        int len_name = end_name - temp_name;
        strncpy(name, temp_name, len_name);
        name[len_name] = '\0';
    }

    // Extracting email from resume
    char* temp_email = strstr(resume, "Email:");
    if (temp_email != NULL)
    {
        temp_email += 6;
        char* end_email = strstr(temp_email, "\n");
        int len_email = end_email - temp_email;
        strncpy(email, temp_email, len_email);
        email[len_email] = '\0';
    }

    // Extracting phone number from resume
    char* temp_phone = strstr(resume, "Phone:");
    if (temp_phone != NULL)
    {
        temp_phone += 6;
        char* end_phone = strstr(temp_phone, "\n");
        int len_phone = end_phone - temp_phone;
        strncpy(phone, temp_phone, len_phone);
        phone[len_phone] = '\0';
    }

    // Extracting experience from resume
    char* temp_experience = strstr(resume, "Experience:");
    if (temp_experience != NULL)
    {
        temp_experience += 11;
        char* end_experience = strstr(temp_experience, "\n\n");
        int len_experience = end_experience - temp_experience;
        strncpy(experience, temp_experience, len_experience);
        experience[len_experience] = '\0';
    }

    // Extracting education from resume
    char* temp_education = strstr(resume, "Education:");
    if (temp_education != NULL)
    {
        temp_education += 10;
        char* end_education = strstr(temp_education, "\n\n");
        int len_education = end_education - temp_education;
        strncpy(education, temp_education, len_education);
        education[len_education] = '\0';
    }
    
    // Printing the extracted data
    printf("\n");

    if (strlen(name) > 0)
        printf("Name: %s\n", name);
    else
        printf("Name not found in resume.\n");

    if (strlen(email) > 0)
        printf("Email: %s\n", email);
    else
        printf("Email not found in resume.\n");

    if (strlen(phone) > 0)
        printf("Phone: %s\n", phone);
    else
        printf("Phone number not found in resume.\n");

    if (strlen(experience) > 0)
        printf("Experience: %s\n", experience);
    else
        printf("Experience not found in resume.\n");

    if (strlen(education) > 0)
        printf("Education: %s\n", education);
    else
        printf("Education not found in resume.\n");

    // Freeing memory
    free(resume);
    free(name);
    free(email);
    free(phone);
    free(experience);
    free(education);

    return 0;
}