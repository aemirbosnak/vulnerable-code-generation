//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: mathematical
#include <stdio.h>
#include <string.h>

int main() {
    char resume[1000];
    char name[50], email[50], phone[15], education[100], skills[100];
    int experience;

    printf("Enter your resume:\n");
    gets(resume);

    // Parse name
    int start = 0, end;
    while (resume[start] == ' ') start++;
    end = start;
    while (resume[end] != ' ') end++;
    strncpy(name, resume + start, end - start);
    name[end - start] = '\0';

    // Parse email
    start = end + 1;
    end = start;
    while (resume[end] != ' ' && resume[end] != '\0') end++;
    strncpy(email, resume + start, end - start);
    email[end - start] = '\0';

    // Parse phone number
    start = end + 1;
    end = start;
    while (resume[end] != ' ' && resume[end] != '\0') end++;
    strncpy(phone, resume + start, end - start);
    phone[end - start] = '\0';

    // Parse education
    start = end + 1;
    end = start;
    while (resume[end] != ',' && resume[end] != '\0') end++;
    strncpy(education, resume + start, end - start);
    education[end - start] = '\0';

    // Parse skills
    start = end + 1;
    end = start;
    while (resume[end] != ',' && resume[end] != '\0') end++;
    strncpy(skills, resume + start, end - start);
    skills[end - start] = '\0';

    // Parse experience
    start = end + 1;
    end = start;
    while (resume[end] != ' ' && resume[end] != '\0') end++;
    char experience_string[end - start + 1];
    strncpy(experience_string, resume + start, end - start);
    experience_string[end - start] = '\0';
    sscanf(experience_string, "%d", &experience);

    // Print parsed information
    printf("Name: %s\n", name);
    printf("Email: %s\n", email);
    printf("Phone: %s\n", phone);
    printf("Education: %s\n", education);
    printf("Skills: %s\n", skills);
    printf("Experience: %d years\n", experience);

    return 0;
}