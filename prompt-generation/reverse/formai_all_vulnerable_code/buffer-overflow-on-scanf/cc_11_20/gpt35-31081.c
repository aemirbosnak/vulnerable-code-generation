//FormAI DATASET v1.0 Category: Phone Book ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Function to display the menu */
void display_menu()
{
    printf("\n-- Phone Book --\n");
    printf("1. Display Contacts\n");
    printf("2. Add Contact\n");
    printf("3. Search Contact\n");
    printf("4. Modify Contact\n");
    printf("5. Delete Contact\n");
    printf("6. Exit\n");
    printf("\nEnter your choice: ");
}

/* Structure to store the contact details */
struct contact
{
    char name[50];
    char phone[15];
    char email[50];
};

int main()
{
    struct contact phonebook[100];
    int choice;
    int count = 0;

    do
    {
        display_menu();
        scanf("%d", &choice);
        getchar(); // To clear the '\n' character from input buffer

        switch(choice)
        {
            /* Display all the contacts */
            case 1:
            {
                if(count == 0)
                {
                    printf("No contacts found!\n");
                }
                else
                {
                    printf("\n-- Contacts --\n");
                    printf("%-30s %-15s %-30s\n", "Name", "Phone", "Email");
                    printf("------------------------------------------------------------------\n");
                    for(int i=0; i<count; i++)
                    {
                        printf("%-30s %-15s %-30s\n", phonebook[i].name, phonebook[i].phone, phonebook[i].email);
                    }
                }
                break;
            }

            /* Add a new contact */
            case 2:
            {
                printf("\n-- Add Contact --\n");
                printf("Enter the name: ");
                fgets(phonebook[count].name, 50, stdin);
                printf("Enter the phone number: ");
                fgets(phonebook[count].phone, 15, stdin);
                printf("Enter the email address: ");
                fgets(phonebook[count].email, 50, stdin);
                count++;
                printf("Contact added successfully!\n");
                break;
            }

            /* Search for a contact */
            case 3:
            {
                char search_term[50];
                int found = 0;
                printf("\n-- Search Contact --\n");
                printf("Enter a search term: ");
                fgets(search_term, 50, stdin);
                printf("%-30s %-15s %-30s\n", "Name", "Phone", "Email");
                printf("------------------------------------------------------------------\n");
                for(int i=0; i<count; i++)
                {
                    if(strstr(phonebook[i].name, search_term) || strstr(phonebook[i].phone, search_term) || strstr(phonebook[i].email, search_term))
                    {
                        printf("%-30s %-15s %-30s\n", phonebook[i].name, phonebook[i].phone, phonebook[i].email);
                        found = 1;
                    }
                }
                if(!found)
                {
                    printf("No contacts found!\n");
                }
                break;
            }

            /* Modify a contact */
            case 4:
            {
                char search_term[50];
                int found = 0;
                int index;
                printf("\n-- Modify Contact --\n");
                printf("Enter a search term: ");
                fgets(search_term, 50, stdin);
                for(int i=0; i<count; i++)
                {
                    if(strstr(phonebook[i].name, search_term) || strstr(phonebook[i].phone, search_term) || strstr(phonebook[i].email, search_term))
                    {
                        printf("%-30s %-15s %-30s\n", "Name", "Phone", "Email");
                        printf("------------------------------------------------------------------\n");
                        printf("%-30s %-15s %-30s\n", phonebook[i].name, phonebook[i].phone, phonebook[i].email);
                        found = 1;
                        index = i;
                        break;
                    }
                }
                if(!found)
                {
                    printf("No contacts found!\n");
                }
                else
                {
                    printf("\nEnter the new details below:\n");
                    printf("Enter the name: ");
                    fgets(phonebook[index].name, 50, stdin);
                    printf("Enter the phone number: ");
                    fgets(phonebook[index].phone, 15, stdin);
                    printf("Enter the email address: ");
                    fgets(phonebook[index].email, 50, stdin);
                    printf("Contact modified successfully!\n");
                }
                break;
            }

            /* Delete a contact */
            case 5:
            {
                char search_term[50];
                int found = 0;
                int index;
                printf("\n-- Delete Contact --\n");
                printf("Enter a search term: ");
                fgets(search_term, 50, stdin);
                for(int i=0; i<count; i++)
                {
                    if(strstr(phonebook[i].name, search_term) || strstr(phonebook[i].phone, search_term) || strstr(phonebook[i].email, search_term))
                    {
                        printf("%-30s %-15s %-30s\n", "Name", "Phone", "Email");
                        printf("------------------------------------------------------------------\n");
                        printf("%-30s %-15s %-30s\n", phonebook[i].name, phonebook[i].phone, phonebook[i].email);
                        found = 1;
                        index = i;
                        break;
                    }
                }
                if(!found)
                {
                    printf("No contacts found!\n");
                }
                else
                {
                    for(int i=index; i<count-1; i++)
                    {
                        strcpy(phonebook[i].name, phonebook[i+1].name);
                        strcpy(phonebook[i].phone, phonebook[i+1].phone);
                        strcpy(phonebook[i].email, phonebook[i+1].email);
                    }
                    count--;
                    printf("Contact deleted successfully!\n");
                }
                break;
            }

            /* Exit the program */
            case 6:
            {
                printf("\nExiting...");
                exit(0);
            }

            /* Default case for invalid input */
            default:
            {
                printf("\nInvalid choice! Please try again.\n");
            }
        }

    }while(choice != 6);

    return 0;
}