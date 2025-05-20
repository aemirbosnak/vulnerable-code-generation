//FormAI DATASET v1.0 Category: Phone Book ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct phonebook {
    char name[20];
    char number[12];
};

int main()
{
    int n=0, i, j, k, choice;
    char search[20];
    printf("Enter the number of phonebook entries you want to make: ");
    scanf("%d", &n);
    fflush(stdin);

    struct phonebook *book = (struct phonebook*)malloc(n*sizeof(struct phonebook));

    if(book == NULL)
    {
        printf("Memory allocation unsuccessful. \n");
        return 1;
    }

    printf("\nEnter the name and number of %d contacts\n", n);
    for(i=0; i<n; i++)
    {
        printf("\nEnter the name of contact %d: ", i+1);
        scanf("%s", book[i].name);
        fflush(stdin);

        printf("\nEnter the phone number of contact %d: ", i+1);
        scanf("%s", book[i].number);
        fflush(stdin);
    }

    printf("\n\nPhonebook created successfully!\n");

    do {
        printf("\n\n1) Search by name\n2) List all contacts\n3) Exit\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                printf("\nEnter the name you want to search for: ");
                scanf("%s", search);
                fflush(stdin);

                for(i=0; i<n; i++)
                {
                    if(strcmp(search, book[i].name)==0)
                    {
                        printf("\n\nContact found!\n");
                        printf("Name: %s\nPhone Number: %s\n", book[i].name, book[i].number);
                        break;
                    }
                    else if (i == n-1)
                    {
                        printf("\nContact not found!\n");
                    }
                }
                break;
            }
            case 2:
            {
                printf("\n\nList of all contacts:\n");
                for(i=0; i<n; i++)
                {
                    printf("Name: %s\nPhone Number: %s\n\n", book[i].name, book[i].number);
                }
                break;
            }
            case 3:
            {
                printf("\n\nProgram terminated.\n");
                break;
            }
            default:
            {
                printf("\n\nPlease enter a valid choice.\n");
                break;
            }
        }

    }while(choice!=3);

    free(book);
    return 0;
}