//FormAI DATASET v1.0 Category: Phone Book ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PhoneBookEntry
{
    char name[50];
    char number[20];
};

int main()
{
    int capacity = 5; // initial capacity
    int size = 0; // number of entries currently in the phone book
    struct PhoneBookEntry *phoneBook = malloc(capacity * sizeof(struct PhoneBookEntry)); // allocate memory for phone book
    
    printf("Welcome to My Phone Book!\n");
    
    while(1) // keep the program running until user chooses to exit
    {
        printf("What would you like to do?\n");
        printf("1. Add an entry\n");
        printf("2. Search for an entry\n");
        printf("3. Print all entries\n");
        printf("4. Exit\n");
        printf("Choice: ");
        
        int choice;
        scanf("%d", &choice);
        
        if(choice == 1) // add an entry
        {
            if(size == capacity) // if phone book is at capacity, double its size
            {
                capacity *= 2;
                phoneBook = realloc(phoneBook, capacity * sizeof(struct PhoneBookEntry));
            }
            
            printf("Enter name: ");
            scanf("%s", phoneBook[size].name);
            printf("Enter number: ");
            scanf("%s", phoneBook[size].number);
            size++;
            
            printf("Entry added successfully!\n");
        }
        else if(choice == 2) // search for an entry
        {
            printf("Enter name or number to search for: ");
            char query[50];
            scanf("%s", query);
            
            int found = 0;
            
            for(int i = 0; i < size; i++)
            {
                if(strcmp(query, phoneBook[i].name) == 0 || strcmp(query, phoneBook[i].number) == 0)
                {
                    printf("%s: %s\n", phoneBook[i].name, phoneBook[i].number);
                    found = 1;
                }
            }
            
            if(!found)
            {
                printf("No matching entry found.\n");
            }
        }
        else if(choice == 3) // print all entries
        {
            for(int i = 0; i < size; i++)
            {
                printf("%s: %s\n", phoneBook[i].name, phoneBook[i].number);
            }
        }
        else if(choice == 4) // exit
        {
            printf("Goodbye!\n");
            free(phoneBook);
            return 0;
        }
        else // invalid input
        {
            printf("Invalid input. Please try again.\n");
        }
    }
}