//FormAI DATASET v1.0 Category: Phone Book ; Style: random
#include<stdio.h>
#include<string.h>

// Structure which stores the data in a phone book entry
struct phonebook_entry {
    char name[100];
    long int number;
};

int main() {
    int i, n, choice, flag = 0;
    long int number_to_search;

    printf("Welcome to the C Phone Book Program! \n");

    printf("Enter the number of phonebook entries: ");
    scanf("%d", &n);

    // Declaring an array of structures to store the phone book data
    struct phonebook_entry phonebook[n];

    // Taking user input to populate the phone book
    for(i = 0; i < n; i++) {
        printf("\nEnter the name for entry %d: ", i+1);
        scanf("%s", phonebook[i].name);

        printf("Enter the phone number for entry %d: ", i+1);
        scanf("%li", &phonebook[i].number);
    }

    // Menu driven program for various operations on the phone book
    while(1) {
        printf("\nMain Menu:\n");
        printf("1. Display all entries\n");
        printf("2. Search by phone number\n");
        printf("3. Add a new entry\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: 
                // Displaying all entries in the phone book
                printf("\nPHONE BOOK ENTRIES:\n");
                for(i = 0; i < n; i++) {
                    printf("%d. %s\t %li\n", i+1, phonebook[i].name, phonebook[i].number);
                }
                break;

            case 2: 
                // Searching for an entry by phone number
                flag = 0;            
                printf("\nEnter the phone number to search: ");
                scanf("%li", &number_to_search);
                for(i = 0; i < n; i++){
                    if(phonebook[i].number == number_to_search){
                        printf("\n%s is stored in the phone book with phone number %li\n", phonebook[i].name, phonebook[i].number);
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0){
                    printf("\nSorry, the phone number you entered is not stored in the phone book.\n");
                }
                break;

            case 3: 
                // Adding a new entry in the phone book
                printf("\nADD NEW ENTRY:\n");
                n++;
                printf("Enter the name for new entry: ");
                scanf("%s", phonebook[n-1].name);

                printf("Enter the phone number for new entry: ");
                scanf("%li", &phonebook[n-1].number);
                printf("\nNew entry added!\n");
                break;

            case 4:
                // Exiting the program
                printf("\nThank you for using the phone book program!\n\n");
                return 0;

            default:
                // Handling invalid user choices
                printf("\nInvalid choice, please enter a valid choice.\n");
                break;
        }
    }
    return 0;
}