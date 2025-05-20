//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: systematic
#include <stdio.h>
#include <string.h>

// Define a structure to store phone numbers
typedef struct PhoneNumber
{
    char name[50];
    char number[20];
} PhoneNumber;

// Create an array of phone numbers
PhoneNumber phoneNumbers[] =
{
    {"John Doe", "555-123-4567"},
    {"Jane Doe", "555-234-5678"},
    {"Bill Smith", "555-345-6789"},
    {"Mary Johnson", "555-456-7890"},
    {"Bob Anderson", "555-567-8901"}
};

// Function to search for a phone number
int searchPhoneNumber(char *name)
{
    for (int i = 0; i < 5; i++)
    {
        if (strcmp(name, phoneNumbers[i].name) == 0)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    char name[50];

    // Get the name of the person to search for
    printf("Enter the name of the person you want to find:");
    scanf("%s", name);

    // Search for the phone number
    int index = searchPhoneNumber(name);

    // If the person was found, display their phone number
    if (index != -1)
    {
        printf("Phone number: %s\n", phoneNumbers[index].number);
    }
    else
    {
        printf("No such person was found.\n");
    }

    return 0;
}