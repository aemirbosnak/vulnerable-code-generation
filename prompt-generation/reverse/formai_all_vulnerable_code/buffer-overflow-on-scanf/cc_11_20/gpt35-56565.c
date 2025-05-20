//FormAI DATASET v1.0 Category: Phone Book ; Style: lively
#include <stdio.h>
#include <string.h>

struct phonebook_entry {
    char name[50];
    char phone_number[20];
};

int main()
{
    struct phonebook_entry phonebook[20];
    int count = 0;

    printf("Welcome to My Phone Book!\n");

    while(1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add new entry\n");
        printf("2. Display all entries\n");
        printf("3. Search for an entry\n");
        printf("4. Edit an entry\n");
        printf("5. Delete an entry\n");
        printf("6. Exit\n");

        int choice;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                printf("\nEnter name: ");
                scanf("%s", phonebook[count].name);
                printf("Enter phone number: ");
                scanf("%s", phonebook[count].phone_number);
                printf("Entry added successfully!\n");
                count++;
                break;
            }
            case 2: {
                printf("\nAll entries:\n");
                printf("Name\t\tPhone number\n");
                for(int i=0;i<count;i++) {
                    printf("%s\t\t%s\n", phonebook[i].name, phonebook[i].phone_number);
                }
                break;
            }
            case 3: {
                char search_name[50];
                printf("\nEnter name to search: ");
                scanf("%s", search_name);
                int found = 0;
                for(int i=0;i<count;i++) {
                    if(strcmp(phonebook[i].name, search_name) == 0) {
                        printf("%s: %s\n", phonebook[i].name, phonebook[i].phone_number);
                        found = 1;
                        break;
                    }
                }
                if(!found) {
                    printf("No entry found\n");
                }
                break;
            }
            case 4: {
                char search_name[50];
                printf("\nEnter name of the entry to edit: ");
                scanf("%s", search_name);
                int found = 0;
                for(int i=0;i<count;i++) {
                    if(strcmp(phonebook[i].name, search_name) == 0) {
                        printf("Enter new phone number: ");
                        scanf("%s", phonebook[i].phone_number);
                        printf("Entry edited successfully!\n");
                        found = 1;
                        break;
                    }
                }
                if(!found) {
                    printf("No entry found\n");
                }
                break;
            }
            case 5: {
                char search_name[50];
                printf("\nEnter name of the entry to delete: ");
                scanf("%s", search_name);
                int found = 0;
                for(int i=0;i<count;i++) {
                    if(strcmp(phonebook[i].name, search_name) == 0) {
                        for(int j=i;j<count-1;j++) {
                            strcpy(phonebook[j].name, phonebook[j+1].name);
                            strcpy(phonebook[j].phone_number, phonebook[j+1].phone_number);
                        }
                        count--;
                        printf("Entry deleted successfully!\n");
                        found = 1;
                        break;
                    }
                }
                if(!found) {
                    printf("No entry found\n");
                }
                break;
            }
            case 6: {
                printf("\nGoodbye!\n");
                return 0;
            }
            default: {
                printf("\nInvalid choice, try again.\n");
                break;
            }
        }
    }
}