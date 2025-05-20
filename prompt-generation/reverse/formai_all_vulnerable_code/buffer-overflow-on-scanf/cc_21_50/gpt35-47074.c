//FormAI DATASET v1.0 Category: Hotel Management System ; Style: Cryptic
#include <stdio.h>
#include <string.h>

struct room{
    char number[4];
    char type[10];
    char availability[3];
    float price;
};

void main(){
    int choice, i, count=0, found=0, no_of_rooms=0;
    char num[4];

    struct room rooms[20];

    while(1){
        printf("\n~~~ MAIN MENU ~~~\n");
        printf("1. Add a Room\n");
        printf("2. Display All Rooms\n");
        printf("3. Search a Room\n");
        printf("4. Update Room Details\n");
        printf("5. Delete a Room\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                if(count<20){
                    printf("\nRoom Number: ");
                    scanf("%s", &rooms[count].number);
                    printf("Room Type: ");
                    scanf("%s", &rooms[count].type);
                    printf("Availability (Yes/No): ");
                    scanf("%s", &rooms[count].availability);
                    printf("Price per Night: $");
                    scanf("%f", &rooms[count].price);
                    count++;
                    printf("\nRoom added successfully!\n");
                } else {
                    printf("\nCannot add more rooms!\n");
                }
                break;
            case 2:
                if(count==0){
                    printf("\nNo rooms in database!\n");
                } else {
                    printf("\nRoom Number\tRoom Type\tAvailability\tPrice per Night\n");
                    for(i=0; i<count; i++){
                        printf("%s\t\t%s\t\t%s \t\t$%.2f\n", rooms[i].number, rooms[i].type, rooms[i].availability, rooms[i].price);
                    }
                }
                break;
            case 3:
                found=0;
                if(count==0){
                    printf("\nNo rooms in database!\n");
                } else {
                    printf("\nEnter the room number to be searched: ");
                    scanf("%s", &num);
                    for(i=0; i<count; i++){
                        if(strcmp(num,rooms[i].number)==0){
                            found=1;
                            printf("\nRoom Found!\n");
                            printf("\nRoom Number\tRoom Type\tAvailability\tPrice per Night\n");
                            printf("%s\t\t%s\t\t%s\t\t$%.2f\n", rooms[i].number, rooms[i].type, rooms[i].availability, rooms[i].price);
                            break;
                        }
                    }
                    if(found==0){
                        printf("\nRoom not found!\n");
                    }
                }
                break;
            case 4:
                found=0;
                if(count==0){
                    printf("\nNo rooms in database!\n");
                } else {
                    printf("\nEnter the room number to be updated: ");
                    scanf("%s", &num);
                    for(i=0; i<count; i++){
                        if(strcmp(num,rooms[i].number)==0){
                            found=1;
                            printf("\nRoom Found!\n");
                            printf("\nEnter new room type: ");
                            scanf("%s", &rooms[i].type);
                            printf("Enter new availability (Yes/No): ");
                            scanf("%s", &rooms[i].availability);
                            printf("Enter new price per Night: $");
                            scanf("%f", &rooms[i].price);
                            printf("\nRoom updated successfully!\n");
                            break;
                        }
                    }
                    if(found==0){
                        printf("\nRoom not found!\n");
                    }
                }
                break;
            case 5:
                found=0;
                if(count==0){
                    printf("\nNo rooms in database!\n");
                } else {
                    printf("\nEnter the room number to be deleted: ");
                    scanf("%s", &num);
                    for(i=0; i<count; i++){
                        if(strcmp(num,rooms[i].number)==0){
                            found=1;
                            printf("\nRoom Found!\n");
                            for(int j=i; j<count-1; j++){
                                strcpy(rooms[j].number,rooms[j+1].number);
                                strcpy(rooms[j].type,rooms[j+1].type);
                                strcpy(rooms[j].availability,rooms[j+1].availability);
                                rooms[j].price=rooms[j+1].price;
                            }
                            count--;
                            printf("\nRoom deleted successfully!\n");
                            break;
                        }
                    }
                    if(found==0){
                        printf("\nRoom not found!\n");
                    }
                }
                break;
            case 6:
                printf("\nExiting Program!\n");
                return;
        }
    }
}