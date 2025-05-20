//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: safe
/*
 * Resume Parsing System Example Program
 * Author: [Your Name]
 * Date: [Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to split a string by a delimiter */
char **split(char *str, char delimiter)
{
    int count = 0;
    char **result = NULL;
    char *token = strtok(str, delimiter);

    while (token!= NULL)
    {
        result = realloc(result, sizeof(char *) * ++count);
        result[count - 1] = token;
        token = strtok(NULL, delimiter);
    }

    return result;
}

/* Function to parse a resume */
void parse_resume(FILE *resume)
{
    char line[512];
    char **sections = NULL;

    /* Read the first line to determine the name of the applicant */
    fgets(line, sizeof(line), resume);
    printf("Applicant Name: %s\n", line);

    /* Split the rest of the resume into sections */
    while (fgets(line, sizeof(line), resume)!= NULL)
    {
        sections = split(line, ':');
        if (sections!= NULL && sections[0]!= NULL)
        {
            printf("Section: %s\n", sections[0]);
            printf("Content:\n%s\n", sections[1]);
        }
        free(sections);
    }
}

int main()
{
    FILE *resume;
    char filename[64];

    /* Get the filename of the resume from the user */
    printf("Enter the filename of the resume: ");
    scanf("%s", filename);

    /* Open the resume file for reading */
    resume = fopen(filename, "r");
    if (resume == NULL)
    {
        printf("Error: Could not open resume file.\n");
        return 1;
    }

    /* Parse the resume */
    parse_resume(resume);

    /* Close the resume file */
    fclose(resume);

    return 0;
}