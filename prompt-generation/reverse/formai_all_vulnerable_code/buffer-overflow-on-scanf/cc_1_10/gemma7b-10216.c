//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: accurate
#include <stdio.h>
#include <string.h>

int main()
{
    char name[20];
    char number[10];
    int i;

    // Create a phone book
    FILE *phoneBook = fopen("phoneBook.txt", "w");

    // Get the user's name and number
    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your number: ");
    scanf("%s", number);

    // Write the user's information to the phone book
    fprintf(phoneBook, "%s, %s\n", name, number);

    // Close the phone book
    fclose(phoneBook);

    // Open the phone book
    phoneBook = fopen("phoneBook.txt", "r");

    // Search for the user's name
    printf("Enter the name of the person you want to find: ");
    scanf("%s", name);

    // Iterate over the phone book to find the user's information
    i = 0;
    while (fscanf(phoneBook, "%s, %s\n", name, number) != EOF)
    {
        // Check if the user's name is the same as the name in the phone book
        if (strcmp(name, name) == 0)
        {
            // Print the user's information
            printf("Name: %s\n", name);
            printf("Number: %s\n", number);
        }
        i++;
    }

    // Close the phone book
    fclose(phoneBook);

    return 0;
}