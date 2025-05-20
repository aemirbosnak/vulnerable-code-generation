//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 255
#define MAX_EXPERIENCE_LENGTH 512

typedef struct Resume
{
    char name[MAX_NAME_LENGTH];
    char experience[MAX_EXPERIENCE_LENGTH];
    struct Resume* next;
} Resume;

int main()
{
    Resume* head = NULL;

    // Parse resume data from a text file
    FILE* file = fopen("resume.txt", "r");
    if (file)
    {
        char name[MAX_NAME_LENGTH];
        char experience[MAX_EXPERIENCE_LENGTH];

        // Read name and experience from the file
        fscanf(file, "%s", name);
        fscanf(file, "%[^\n]%*c", experience);

        // Create a new resume node
        Resume* new_node = (Resume*)malloc(sizeof(Resume));
        strcpy(new_node->name, name);
        strcpy(new_node->experience, experience);
        new_node->next = NULL;

        // Insert the new node into the head of the list
        if (head)
        {
            new_node->next = head;
        }
        head = new_node;
    }

    // Print the resume data
    for (Resume* current = head; current; current = current->next)
    {
        printf("Name: %s\n", current->name);
        printf("Experience: %s\n", current->experience);
    }

    return 0;
}