//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 255
#define MAX_EXPERIENCE_LEN 512

typedef struct Resume
{
    char name[MAX_NAME_LEN];
    char experience[MAX_EXPERIENCE_LEN];
    struct Resume* next;
} Resume;

void parse_resume(char* filename)
{
    FILE* file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }

    Resume* head = NULL;
    Resume* current = NULL;

    char name[MAX_NAME_LEN];
    char experience[MAX_EXPERIENCE_LEN];

    while (!feof(file))
    {
        fscanf(file, "%s", name);
        fscanf(file, "%[^\n]%*c", experience);

        if (current == NULL)
        {
            current = malloc(sizeof(Resume));
            head = current;
        }
        else
        {
            current->next = malloc(sizeof(Resume));
            current = current->next;
        }

        strcpy(current->name, name);
        strcpy(current->experience, experience);
    }

    fclose(file);

    current = head;
    while (current)
    {
        printf("Name: %s\n", current->name);
        printf("Experience: %s\n", current->experience);
        printf("\n");
        current = current->next;
    }
}

int main()
{
    parse_resume("resume.txt");
    return 0;
}