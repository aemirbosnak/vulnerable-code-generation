//FormAI DATASET v1.0 Category: Hotel Management System ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure to store the details of the guest
struct guest{
    char name[50];
    int room_no;
    int nights;
    float rate;
    float total;
};

// Function to display the menu
void menu(){
    printf("Welcome to C Hotel Management System\n\n");
    printf("1. Add Guest Details\n");
    printf("2. Modify Guest Details\n");
    printf("3. Delete Guest Details\n");
    printf("4. Calculate Bill\n");
    printf("5. Display Guest Details\n");
    printf("6. Exit\n");
}

int main(){
    int choice, i, flag=0, n=0, room_no;

    struct guest g[100];

    do{
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                // Add Guest Details
                printf("\nEnter Guest Details:\n");
                printf("Name: ");
                scanf("%s", g[n].name);
                printf("Room number: ");
                scanf("%d", &g[n].room_no);
                printf("Number of nights staying: ");
                scanf("%d", &g[n].nights);
                printf("Rate per night of the room: ");
                scanf("%f", &g[n].rate);
                flag = 1;
                n++;
                break;


            case 2:
                // Modify Guest Details
                printf("Enter room number: ");
                scanf("%d", &room_no);
                for(i=0; i<n; i++){
                    if(g[i].room_no == room_no){
                        printf("Enter new rate per night of the room: ");
                        scanf("%f", &g[i].rate);
                        flag = 1;
                    }
                }
                break;

            case 3:
                // Delete Guest Details
                printf("Enter room number: ");
                scanf("%d", &room_no);
                for(i=0; i<n; i++){
                    if(g[i].room_no == room_no){
                        strcpy(g[i].name, "");
                        g[i].nights = 0;
                        g[i].rate= 0;
                        flag = 1;
                    }
                }
                break;

            case 4:
                // Calculate Bill
                printf("Enter room number: ");
                scanf("%d", &room_no);
                for(i=0; i<n; i++){
                    if(g[i].room_no == room_no){
                        g[i].total = g[i].nights * g[i].rate;
                        printf("Total Bill: %.2f\n", g[i].total);
                        flag = 1;
                    }
                }
                break;

            case 5:
                // Display Guest Details
                printf("Guest Details:\n");
                for(i=0; i<n; i++){
                    if(strcmp(g[i].name, "") != 0){
                        printf("Name: %s\n", g[i].name);
                        printf("Room number: %d\n", g[i].room_no);
                        printf("Number of nights staying: %d\n", g[i].nights);
                        printf("Rate per night of the room: %.2f\n", g[i].rate);
                        printf("Total Bill: %.2f\n\n", g[i].total);
                        flag = 1;
                    }
                }
                break;

            case 6:
                // Exit
                printf("Thank you for using C Hotel Management System!");
                exit(0);
                break;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }

    }while(choice != 6);

    return 0;
}