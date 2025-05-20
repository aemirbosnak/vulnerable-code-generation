//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: automated
#include <stdio.h>
#include <string.h>

int main()
{
    char name[20], phone[20];
    int i, n, found = 0;

    // Create an array of structures to store phone book data
    struct phoneBook
    {
        char name[20];
        char phone[20];
    } phoneBookArray[100];

    // Get the number of entries in the phone book
    printf("Enter the number of entries in the phone book: ");
    scanf("%d", &n);

    // Populate the phone book array
    for (i = 0; i < n; i++)
    {
        printf("Enter the name of the person: ");
        scanf("%s", phoneBookArray[i].name);

        printf("Enter the phone number of the person: ");
        scanf("%s", phoneBookArray[i].phone);
    }

    // Search for a name in the phone book
    printf("Enter the name of the person you want to find: ");
    scanf("%s", name);

    // Iterate over the phone book array to find the name
    for (i = 0; i < n; i++)
    {
        if (strcmp(name, phoneBookArray[i].name) == 0)
        {
            found = 1;
            printf("The phone number of the person is: %s", phoneBookArray[i].phone);
        }
    }

    // If the name was not found, print an error message
    if (!found)
    {
        printf("The name was not found.");
    }

    return 0;
}