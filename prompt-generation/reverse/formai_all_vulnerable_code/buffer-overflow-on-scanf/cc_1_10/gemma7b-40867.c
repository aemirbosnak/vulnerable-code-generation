//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insert_record(char **records, int *size)
{
    *size++;
    records = realloc(records, (*size) * sizeof(char *));
    records[*size - 1] = malloc(20);
    printf("Enter details:");
    scanf("%s", records[*size - 1]);
}

void search_record(char **records, int size)
{
    int i;
    char search_term[20];
    printf("Enter search term:");
    scanf("%s", search_term);

    for (i = 0; i < size; i++)
    {
        if (strcmp(records[i], search_term) == 0)
        {
            printf("Record details:");
            printf("%s\n", records[i]);
        }
    }
}

int main()
{
    char **records = NULL;
    int size = 0;

    while (1)
    {
        printf("Enter 1 to insert, 2 to search, or 3 to exit:");
        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insert_record(&records, &size);
                break;
            case 2:
                search_record(records, size);
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}