//FormAI DATASET v1.0 Category: Mailing list manager ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char menu_choice;
    printf("Welcome to the mailing list manager!\n");

    // Dynamically allocate the mailing list
    char **mail_list;
    int mail_count = 0;
    mail_list = (char **)malloc(1 * sizeof(char *));
    mail_list[0] = (char *)malloc(255 * sizeof(char));

    do
    {
        // Display menu
        printf("\n");
        printf("Select an action:\n");
        printf("a. Add email address\n");
        printf("b. View mailing list\n");
        printf("c. Remove email address\n");
        printf("d. Quit\n");

        // Get user's selection
        printf("Your selection: ");
        scanf(" %c", &menu_choice);

        switch (menu_choice)
        {
            case 'a':   // Add email address
            {
                // Get the email address from the user
                printf("Enter the email address: ");
                char new_mail[255];
                scanf(" %s", new_mail);

                // Check if the email address already exists in the mailing list
                int already_exists = 0;
                for (int i = 0; i < mail_count; i++)
                {
                    if (strcmp(mail_list[i], new_mail) == 0)
                    {
                        already_exists = 1;
                        printf("The email address already exists in the mailing list.\n");
                        break;
                    }
                }

                // Add the email address to the mailing list if it doesn't already exist
                if (!already_exists)
                {
                    strcpy(mail_list[mail_count], new_mail);
                    mail_count++;
                    mail_list = (char **)realloc(mail_list, (mail_count + 1) * sizeof(char *));
                    mail_list[mail_count] = (char *)malloc(255 * sizeof(char));
                    printf("The email address has been added to the mailing list.\n");
                }

                break;
            }

            case 'b':   // View mailing list
            {
                printf("Mailing list:\n");
                for (int i = 0; i < mail_count; i++)
                {
                    printf("%s\n", mail_list[i]);
                }

                break;
            }

            case 'c':   // Remove email address
            {
                // Get the email address to remove from the user
                printf("Enter the email address to remove: ");
                char email_to_remove[255];
                scanf(" %s", email_to_remove);

                // Search for the email address in the mailing list
                int found_index = -1;
                for (int i = 0; i < mail_count; i++)
                {
                    if (strcmp(mail_list[i], email_to_remove) == 0)
                    {
                        found_index = i;
                        break;
                    }
                }

                // Remove the email address from the mailing list if it was found
                if (found_index != -1)
                {
                    // Shift the remaining email addresses forward in the mailing list
                    for (int i = found_index; i < mail_count - 1; i++)
                    {
                        strcpy(mail_list[i], mail_list[i + 1]);
                    }

                    // Decrement the mail count and resize the mailing list
                    mail_count--;
                    mail_list = (char **)realloc(mail_list, (mail_count + 1) * sizeof(char *));
                    mail_list[mail_count] = (char *)malloc(255 * sizeof(char));
                    printf("The email address has been removed from the mailing list.\n");
                }
                else
                {
                    printf("The email address was not found in the mailing list.\n");
                }

                break;
            }

            case 'd':   // Quit
            {
                printf("Goodbye!\n");
                break;
            }

            default:
            {
                printf("Invalid selection. Please try again.\n");
                break;
            }
        }

    } while (menu_choice != 'd');

    // Free the memory used by the mailing list
    for (int i = 0; i < mail_count; i++)
    {
        free(mail_list[i]);
    }
    free(mail_list);

    return 0;
}