//FormAI DATASET v1.0 Category: File handling ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("\nThank you for using my file handling program!\n");
    printf("Please enter the path to the file you would like to read: \n");

    char file_path[100];

    scanf("%s", file_path);

    FILE *file_ptr = fopen(file_path, "r");

    if (file_ptr == NULL)
    {
        printf("\nOops! The file path you entered was invalid.\n");
        printf("Please run the program again and enter a valid file path.\n");
        return 1;
    }

    printf("\nThe contents of the file are:\n");

    char current_char;

    while ((current_char = fgetc(file_ptr)) != EOF)
    {
        printf("%c", current_char);
    }

    printf("\nThank you for reading the file!\n");

    fclose(file_ptr);

    printf("\nWould you like to create a new file? (y/n)\n");

    char response;

    scanf("%s", &response);

    if (response == 'y')
    {
        FILE *new_file_ptr = fopen("new_file.txt", "w");

        if (new_file_ptr == NULL)
        {
            printf("\nOops! There was an error creating the new file.\n");
            printf("Please run the program again and try again.\n");
            return 1;
        }

        printf("\nPlease enter the contents of the new file:\n");

        char new_file_contents[1000];

        scanf(" %[^\n]%*c", new_file_contents);

        fputs(new_file_contents, new_file_ptr);

        printf("\nThank you for creating the new file!\n");

        fclose(new_file_ptr);
    }

    printf("\nHave a great day!\n");

    return 0;
}