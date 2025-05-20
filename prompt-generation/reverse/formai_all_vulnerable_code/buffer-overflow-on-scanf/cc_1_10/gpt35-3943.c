//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: medieval
#include <stdio.h>
#include <string.h>

//Function to remove vowels from a string
void removeVowels(char *str) {
    int i = 0, j = 0;

    while (str[i] != '\0') {
        if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u' &&
            str[i] != 'A' && str[i] != 'E' && str[i] != 'I' && str[i] != 'O' && str[i] != 'U') {
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0';
}

int main()
{
    char name[50];
    char skills[200];
    char experience[200];
    char education[200];

    printf("Welcome to the Medieval Resume Parsing System!\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    removeVowels(name);
    printf("Greetings, %s, we will now parse your resume!\n\n", name);
    
    //Ask for skills
    printf("What are your skills? (separate each skill with a comma): ");
    scanf(" %[^\n]s", skills);

    //Loop through skills and print them out
    printf("\nYour skills:\n");
    char* skill = strtok(skills, ",");
    while (skill != NULL) {
        removeVowels(skill);
        printf("- %s\n", skill);
        skill = strtok(NULL, ",");
    }

    //Ask for experience
    printf("\nWhat experience do you have? (separate each experience with a comma): ");
    scanf(" %[^\n]s", experience);

    //Loop through experience and print them out
    printf("\nYour experience:\n");
    char* exp = strtok(experience, ",");
    while (exp != NULL) {
        removeVowels(exp);
        printf("- %s\n", exp);
        exp = strtok(NULL, ",");
    }

    //Ask for education
    printf("\nWhat education do you have? (separate each education with a comma): ");
    scanf(" %[^\n]s", education);

    //Loop through education and print them out
    printf("\nYour education:\n");
    char* edu = strtok(education, ",");
    while (edu != NULL) {
        removeVowels(edu);
        printf("- %s\n", edu);
        edu = strtok(NULL, ",");
    }

    printf("\nThank you for using the Medieval Resume Parsing System!\n");

    return 0;
}