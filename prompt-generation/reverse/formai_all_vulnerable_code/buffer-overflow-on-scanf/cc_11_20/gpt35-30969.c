//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine //creating a structure for storing medicine information
{
    char name[100];
    int quantity;
    float price;
};

int main()
{
    struct medicine list[20]; //creating a list of medicines
    int choice, n=0, i;
    char search[100];

    while(1) //loop for displaying menu 
    {
        printf("\nWelcome to Medical Store Management System\n");
        printf("1. Add Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Search Medicine\n");
        printf("4. Delete Medicine\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: //adding medicine 
                printf("Enter name of medicine: ");
                fflush(stdin); //clearing buffer
                gets(list[n].name); 
                printf("Enter quantity of medicine: ");
                scanf("%d", &list[n].quantity);
                printf("Enter price of medicine: ");
                scanf("%f", &list[n].price);
                n++; //incrementing the counter after adding a medicine
                break;

            case 2: //displaying all medicines
                printf("List of medicines:\n");
                printf("S.no. Name          Quantity     Price\n");
                printf("----------------------------------------------------\n");

                for(i=0; i<n; i++)
                {
                    printf("%-5d %-13s %-12d %.2f\n", i+1, list[i].name, list[i].quantity, list[i].price); //displaying medicine details
                }
                break;

            case 3: //searching for a medicine
                printf("Enter name of medicine to be searched: ");
                fflush(stdin);
                gets(search);

                for(i=0; i<n; i++)
                {
                    if(strcmp(list[i].name, search) == 0) //comparing the user input with the medicine name
                    {
                        printf("Medicine found!\n");
                        printf("Name: %s\n", list[i].name);
                        printf("Quantity: %d\n", list[i].quantity);
                        printf("Price: %.2f\n", list[i].price);
                        break;
                    }
                }
                if(i == n) //checking if the medicine was not found
                {
                    printf("Medicine not found!\n");
                }
                break;

            case 4: //deleting a medicine
                printf("Enter name of medicine to be deleted: ");
                fflush(stdin);
                gets(search);

                for(i=0; i<n; i++)
                {
                    if(strcmp(list[i].name, search) == 0) //comparing the user input with the medicine name
                    {
                        n--; //decrementing the counter
                        list[i] = list[n]; //shifting the last element to the position of deleted element
                        printf("Medicine deleted!\n");
                        break;
                    }
                }
                if(i == n) //checking if the medicine was not found
                {
                    printf("Medicine not found!\n");
                }
                break;

            case 5: //exiting the program
                exit(0);

            default: //handling invalid user input
                printf("Invalid choice! Try again.\n");
                break;
        }
    }

    return 0;
}