//FormAI DATASET v1.0 Category: Database Indexing System ; Style: peaceful
// Header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Indexing
struct phonebook
{
    char name[20];
    char phone[15];
};

// Function to create Index
int createIndex(FILE *fp, char *index, int size)
{
    fseek(fp, 0, SEEK_SET);

    struct phonebook pb;
    char temp[20];
    int count = 0;

    // Read each record from main file and store the offset of each record
    while(fread(&pb, sizeof(struct phonebook), 1, fp) == 1)
    {
        strcpy(temp, pb.name);

        // Write the offset and name into index file
        fwrite(&count, sizeof(int), 1, index);
        fwrite(temp, sizeof(char), size, index);
        count++;
    }
    printf("Index Created Successfully!\n");

    return count;
}

// Function to search for a record using Index
void searchIndex(FILE *fp, FILE *index, char *name, int size, int count)
{
    int lower = 0, upper = count - 1, mid, flag = 0, offset;

    // Binary Search through the Index file
    while(lower <= upper)
    {
        mid = (lower + upper) / 2;
        fseek(index, mid*(sizeof(int)+size), SEEK_SET);

        fread(&offset, sizeof(int), 1, index);

        char temp[20];
        fread(temp, sizeof(char), size, index);
        temp[size] = '\0';

        if(strncmp(temp, name, size) == 0)   // Compare the name with the current index entry
        {
            flag = 1;
            fseek(fp, offset*sizeof(struct phonebook), SEEK_SET);

            struct phonebook pb;
            fread(&pb, sizeof(struct phonebook), 1, fp);

            printf("Name: %s\nPhone: %s\n", pb.name, pb.phone);
            break;
        }
        else if(strncmp(temp, name, size) < 0)
            lower = mid + 1;
        else
            upper = mid - 1;
    }

    if(flag == 0)
        printf("Record not found!\n");
}

int main()
{
    // Open Main database file
    FILE *fp = fopen("phonebook.txt", "r");

    if(fp == NULL)
    {
        printf("Error opening main file!\n");
        exit(1);
    }

    // Open Index file for writing
    FILE *index = fopen("index.txt", "w");

    if(index == NULL)
    {
        printf("Error opening index file!\n");
        exit(1);
    }

    int count = createIndex(fp, index, 20);

    char name[20];

    printf("Enter the name to search: ");
    scanf("%s", name);

    searchIndex(fp, index, name, 20, count);

    // Close the files
    fclose(fp);
    fclose(index);

    return 0;
}