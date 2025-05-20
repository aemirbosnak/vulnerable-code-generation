//FormAI DATASET v1.0 Category: Database Indexing System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

struct person {
    char name[50];
    int age;
    long phone;
};

struct index {
    char name[50];
    int offset;
};

void insindex(struct index*, struct person, int*);
void printperson(struct person);
void printindex(struct index);

int main()
{
    int n = 5;
    struct person people[n];
    struct index index[n];
    int size = sizeof(struct person);
    int offset = 0;
    int indexsize = sizeof(struct index);
    int indexcount = 0;
    FILE *file;

    for(int i = 0; i < n; i++)
    {
        printf("Enter name: ");
        scanf("%s", &people[i].name);
        printf("Enter age: ");
        scanf("%d", &people[i].age);
        printf("Enter phone number: ");
        scanf("%ld", &people[i].phone);

        insindex(index, people[i], &indexcount);

        file = fopen("people.db", "ab");
        fwrite(&people[i], size, 1, file);
        offset = ftell(file) - size;
        fclose(file);
        index[indexcount - 1].offset = offset;
    }

    printf("\nPeople:\n");
    for(int i = 0; i < n; i++)
    {
        printperson(people[i]);
    }

    printf("\nIndex:\n");
    for(int i = 0; i < indexcount; i++)
    {
        printindex(index[i]);
    }

    return 0;
}

void insindex(struct index *index, struct person p, int *count)
{
    if(*count == 0)
    {
        sprintf((*index).name, "%s", p.name);
        *count += 1;
        return;
    }
    for(int i = 0; i < *count; i++)
    {
        if(strcmp(p.name, (*index).name) == -1)
        {
            for(int j = *count; j >= i; j--)
            {
                index[j + 1] = index[j];
            }
            sprintf((*index).name, "%s", p.name);
            (*index).offset = -1;
            *count += 1;
            return;
        }
        if(strcmp(p.name, (*index).name) == 0)
        {
            return;
        }
    }
    sprintf((*index).name, "%s", p.name);
    (*index).offset = -1;
    *count += 1;
    return;
}

void printperson(struct person p)
{
    printf("Name: %s\nAge: %d\nPhone: %ld\n", p.name, p.age, p.phone);
}

void printindex(struct index i)
{
    printf("Name: %s\nOffset: %d\n", i.name, i.offset);
}