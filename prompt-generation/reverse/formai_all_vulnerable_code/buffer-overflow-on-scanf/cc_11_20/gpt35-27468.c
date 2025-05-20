//FormAI DATASET v1.0 Category: Hotel Management System ; Style: authentic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//define structure of the hotel
struct hotel{
    char name[50];
    int rating;
    int capacity;
    int price;
};

int main(){
    //declare variables to be used in program
    int choice, i, j, count=0, found=0;
    char searchName[50];
    struct hotel hotels[20];

    while(choice != 5){
        //print menu for user
        printf("Welcome to the Hotel Management System! Please choose from the following options:\n");
        printf("1. Add a new hotel.\n");
        printf("2. Search for a hotel by name.\n");
        printf("3. Display all hotels.\n");
        printf("4. Update hotel information.\n");
        printf("5. Exit program.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        //switch statement to handle different user choices
        switch(choice){
            case 1:
                //prompt user to enter information about new hotel
                printf("Enter the name of the hotel: ");
                scanf("%s", hotels[count].name);
                printf("Enter the hotel rating (1-5): ");
                scanf("%d", &hotels[count].rating);
                printf("Enter the hotel capacity: ");
                scanf("%d", &hotels[count].capacity);
                printf("Enter the hotel price per night: ");
                scanf("%d", &hotels[count].price);
                count++;
                break;

            case 2:
                //prompt user to enter name of hotel to search for
                printf("Enter the name of the hotel to search for: ");
                scanf("%s", searchName);
                found = 0;
                //loop through the hotel array to find matching hotel
                for(i=0; i<count; i++){
                    if(strcmp(hotels[i].name, searchName) == 0){
                        printf("Name: %s\nRating: %d\nCapacity: %d\nPrice per night: %d\n", hotels[i].name, hotels[i].rating, hotels[i].capacity, hotels[i].price);
                        found = 1;
                    }
                }
                if(found == 0){
                    printf("No hotel with that name was found.\n");
                }
                break;

            case 3:
                //loop through the hotel array to display each hotel's information
                for(i=0; i<count; i++){
                    printf("Name: %s\nRating: %d\nCapacity: %d\nPrice per night: %d\n", hotels[i].name, hotels[i].rating, hotels[i].capacity, hotels[i].price);
                }
                break;

            case 4:
                //prompt user to enter name of hotel to update
                printf("Enter the name of the hotel to update: ");
                scanf("%s", searchName);
                found = 0;
                //loop through hotel array to find matching hotel to update
                for(i=0; i<count; i++){
                    if(strcmp(hotels[i].name, searchName) == 0){
                        found = 1;
                        //prompt user to enter new information about the hotel
                        printf("Enter the new rating for the hotel: ");
                        scanf("%d", &hotels[i].rating);
                        printf("Enter the new capacity for the hotel: ");
                        scanf("%d", &hotels[i].capacity);
                        printf("Enter the new price per night for the hotel: ");
                        scanf("%d", &hotels[i].price);
                    }
                }
                if(found == 0){
                    printf("No hotel with that name was found.\n");
                }
                break;

            case 5:
                //exit the program
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}