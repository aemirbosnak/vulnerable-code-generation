//FormAI DATASET v1.0 Category: Phone Book ; Style: sophisticated
#include<stdio.h>
#include<string.h>

struct Person 
{
    char name[50];
    char phone[20];
};

void add_person(struct Person p[], int *count)
{
    printf("\nEnter name and phone number: ");
    scanf("%s %s", p[*count].name, p[*count].phone);
    *count += 1;
}

void search_person(struct Person p[], int count, char query[])
{
    int found = 0;
    for(int i = 0; i < count; i++)
    {
        if(strstr(p[i].name, query) != NULL || strstr(p[i].phone, query) != NULL)
        {
            printf("\n%s  %s", p[i].name, p[i].phone);
            found = 1;
        }
    }
    if(!found)
    {
        printf("\nNo results found!");
    }
}

int main()
{
    struct Person phone_book[100];
    int count = 0, option;
    char query[50];
    do
    {
        printf("\n\nPhone Book\n");
        printf("1. Add a person\n");
        printf("2. Search for a person\n");
        printf("3. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1: add_person(phone_book, &count);
                    break;

            case 2: printf("\nEnter a name or phone number to search: ");
                    scanf("%s", query);
                    search_person(phone_book, count, query);
                    break;

            case 3: printf("\nThank you for using the phone book!\n");
                    break;

            default: printf("\nInvalid option, please try again!");
                     break;
        }
    } while(option != 3);

    return 0;
}