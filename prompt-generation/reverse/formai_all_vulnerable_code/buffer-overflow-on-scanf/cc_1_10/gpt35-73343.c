//FormAI DATASET v1.0 Category: Phone Book ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct phoneBookStruct
{
    char name[MAX];
    char phoneNumber[MAX];
} phoneBook;

phoneBook phoneBookList[MAX];
int entryCount = 0;

void addEntry()
{
    if (entryCount == MAX)
    {
        printf("Phone book is full. Unable to add new entry.\n");
        return;
    }

    printf("Enter name (max %d characters):\n", MAX);
    fflush(stdin);
    fgets(phoneBookList[entryCount].name, MAX, stdin);

    printf("Enter phone number (max %d characters):\n", MAX);
    fflush(stdin);
    fgets(phoneBookList[entryCount].phoneNumber, MAX, stdin);

    entryCount++;
}

void searchByName()
{
    char nameToSearch[MAX];
    printf("Enter name to search (max %d characters):\n", MAX);
    fflush(stdin);
    fgets(nameToSearch, MAX, stdin);

    for (int i = 0; i < entryCount; i++)
    {
        if (strcmp(phoneBookList[i].name, nameToSearch) == 0)
        {
            printf("Match found: %s - %s", phoneBookList[i].name, phoneBookList[i].phoneNumber);
            return;
        }
    }

    printf("No match found for %s.\n", nameToSearch);
}

void printPhoneBook()
{
    for (int i = 0; i < entryCount; i++)
    {
        printf("%s - %s", phoneBookList[i].name, phoneBookList[i].phoneNumber);
    }
}

int main()
{
    int choice;

    do
    {
        printf("Phone Book Menu\n");
        printf("1. Add new entry\n");
        printf("2. Search by name\n");
        printf("3. Print phone book\n");
        printf("4. Exit\n");
        printf("Enter choice:\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addEntry();
            break;
        case 2:
            searchByName();
            break;
        case 3:
            printPhoneBook();
            break;
        case 4:
            printf("Exiting phone book...\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    } while (1);

    return 0;
}