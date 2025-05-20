//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 25

typedef struct PhoneBookEntry
{
    char name[MAX_NAME_LENGTH];
    int phone_number;
} PhoneBookEntry;

int main()
{
    PhoneBookEntry entries[] =
    {
        {"Johnny Bravo", 555-123-4567},
        {"Jane Doe", 555-456-2123},
        {"Mr. T", 555-321-9841},
        {"Catra", 555-612-0432},
        {"Optimus Prime", 555-731-6249}
    };

    int num_entries = sizeof(entries) / sizeof(PhoneBookEntry);

    // Print the phone book entries
    for (int i = 0; i < num_entries; i++)
    {
        printf("%s: %d\n", entries[i].name, entries[i].phone_number);
    }

    // Search for a phone number
    char search_name[MAX_NAME_LENGTH];
    printf("Enter a name: ");
    scanf("%s", search_name);

    int found = 0;
    for (int i = 0; i < num_entries; i++)
    {
        if (strcmp(entries[i].name, search_name) == 0)
        {
            found = 1;
            printf("%s: %d\n", entries[i].name, entries[i].phone_number);
        }
    }

    if (!found)
    {
        printf("No entry found for that name.\n");
    }

    return 0;
}