//FormAI DATASET v1.0 Category: Hotel Management System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//structure to store guest details
struct guest{
    char name[50];
    int room_num;
    int days_stayed;
    int total_cost;
};

//function to display guest details
void displayGuestDetails(struct guest g){
    printf("\nGuest Name: %s\n", g.name);
    printf("Room Number: %d\n", g.room_num);
    printf("Number of Days Stayed: %d\n", g.days_stayed);
    printf("Total Cost: Rs. %d\n", g.total_cost);
}

//function to calculate room charge
int calculateRoomCharge(int room_type, int days){
    int rate_per_day;
    if(room_type == 1){
        rate_per_day = 1000;
    }
    else if(room_type == 2){
        rate_per_day = 1500;
    }
    else{
        rate_per_day = 2000;
    }
    return rate_per_day*days;
}

int main()
{
    int choice, room_count[3] = {0, 0, 0}; //to count available rooms
    
    while(1){
        printf("\nWelcome to C Hotel Management System\n");
        printf("1. Check-in\n");
        printf("2. Display Guest Details\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:{
                struct guest g;
                printf("\nEnter Guest Name: ");
                getchar();
                fgets(g.name, sizeof(g.name), stdin);
                strtok(g.name, "\n");
                printf("Enter Room Number (1-50): ");
                scanf("%d", &g.room_num);
                if(g.room_num<1 || g.room_num>50){
                    printf("Invalid Room Number\n");
                    break;
                }
                printf("Enter Number of Days Stayed: ");
                scanf("%d", &g.days_stayed);
                printf("Select Room Type:\n1. Standard (Rs. 1000/day)\n2. Deluxe (Rs. 1500/day)\n3. Suite (Rs. 2000/day)\nEnter the number corresponding to the Room type: ");
                int room_type;
                scanf("%d", &room_type);
                if(room_type<1 || room_type>3){
                    printf("Invalid Choice\n");
                    break;
                }
                g.total_cost = calculateRoomCharge(room_type, g.days_stayed);
                printf("Total Cost: Rs. %d\n", g.total_cost);
                room_count[room_type-1]++; //incrementing room count for booked room type
                displayGuestDetails(g);
                break;
            }
            case 2:{
                int room_num;
                printf("\nEnter Room Number: ");
                scanf("%d", &room_num);
                if(room_num<1 || room_num>50){
                    printf("Invalid Room Number\n");
                    break;
                }
                int room_type;
                if(room_num<=10){
                    room_type = 1;
                }
                else if(room_num<=30){
                    room_type = 2;
                }
                else{
                    room_type = 3;
                }
                if(room_count[room_type-1] == 0){ //if no room of given type is booked
                    printf("No Guest in Room Number %d\n", room_num);
                    break;
                }
                else{
                    FILE *fp;
                    fp = fopen("guest.txt", "r"); //reading guest details from file
                    struct guest g;
                    while(fread(&g, sizeof(g), 1, fp)){
                        if(g.room_num == room_num){
                            displayGuestDetails(g);
                            break;
                        }
                    }
                    fclose(fp);
                }
                break;
            }
            case 3:{
                printf("\nThank you for using C Hotel Management System\n");
                exit(0);
            }
            default:{
                printf("\nInvalid Choice\n");
            }
        }
    }
    return 0;
}