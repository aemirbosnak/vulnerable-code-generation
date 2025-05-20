//FormAI DATASET v1.0 Category: Phone Book ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Defining a Structure to hold phone book entry
struct PhoneBookEntry {
    char name[100];
    char phone_number[20];
};

int main() {
    int choice,flag=1;
    int count=0;
    struct PhoneBookEntry phonebook[100];

    // Welcome Message
    printf("Welcome to the C Phone Book! \n");

    // Infinite loop until user chooses to exit
    while(flag == 1) {
        printf("Please select an option from the menu: \n");
        printf("1. Add Phone Book Entry \n");
        printf("2. Search Phone Book \n");
        printf("3. Print Complete Phone Book \n");
        printf("4. Exit Phone Book \n");

        // Read user input
        scanf("%d",&choice);

        // Switch case to handle different user choices
        switch(choice) {
            case 1:
                printf("Enter Name: ");
                scanf("%s",phonebook[count].name);
                printf("Enter Phone Number: ");
                scanf("%s",phonebook[count].phone_number);
                printf("Phone book entry created successfully! \n\n");
                count++;
                break;
            case 2:
                printf("Enter the Name you want to search: ");
                char searchName[100];
                scanf("%s",searchName);
                int flag=0;
                for(int i=0; i<count; i++) {
                    if(strcmp(phonebook[i].name, searchName) == 0) {
                        printf("Name: %s\t Phone Number: %s\n\n", phonebook[i].name, phonebook[i].phone_number);
                        flag=1;
                    }
                }
                if(flag == 0) {
                    printf("No phone book entry found with the given name! \n\n");
                }
                break;
            case 3:
                printf("Complete Phone Book: \n");
                for(int i=0; i<count; i++) {
                    printf("Name: %s\t Phone Number: %s\n", phonebook[i].name, phonebook[i].phone_number);
                }
                printf("\n");
                break;
            case 4:
                printf("Exiting...Thanks for using C Phone Book! \n");
                flag=0;
                break;
            default:
                printf("Invalid Input! Please choose a valid option from the menu. \n\n");
        }
    }

    return 0;
}