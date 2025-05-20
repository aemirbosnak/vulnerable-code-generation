//FormAI DATASET v1.0 Category: Hotel Management System ; Style: optimized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct hotel{
    int room_no;
    char guest_name[30];
    int guest_nic;
    char check_in_date[15];
    char check_out_date[15];
    int room_rate;
    int total_days;
    int total_bill;
};

void add_new_record(struct hotel rooms[], int n){
    int i;
    printf("Enter the details for room %d:\n", n+1);
    printf("Room number: ");
    scanf("%d", &rooms[n].room_no);
    printf("Guest name: ");
    fflush(stdin);
    gets(rooms[n].guest_name);
    printf("Guest NIC: ");
    scanf("%d", &rooms[n].guest_nic);
    printf("Check-in date (dd/mm/yyyy): ");
    fflush(stdin);
    gets(rooms[n].check_in_date);
    printf("Check-out date (dd/mm/yyyy): ");
    fflush(stdin);
    gets(rooms[n].check_out_date);
    printf("Room rate: ");
    scanf("%d", &rooms[n].room_rate);
    printf("Total days stayed: ");
    scanf("%d", &rooms[n].total_days);
    rooms[n].total_bill = rooms[n].room_rate * rooms[n].total_days;
    printf("\nRecord added successfully!\n\n");
}

void view_all_records(struct hotel rooms[], int n){
    int i=0;
    if(n==0){
        printf("No records found!\n\n");
    }
    else{
        printf("All records:\n\n");
        printf("Room No\tGuest Name\tGuest NIC\tCheck-in Date\tCheck-out Date\tRoom Rate\tTotal Days\tTotal Bill\n");
        for(i=0; i<n; i++){
            printf("%d\t%s\t%d\t%s\t%s\t%d\t%d\t%d\n", rooms[i].room_no, rooms[i].guest_name, rooms[i].guest_nic, rooms[i].check_in_date, rooms[i].check_out_date, rooms[i].room_rate, rooms[i].total_days, rooms[i].total_bill);
        }
        printf("\n");
    }
}

void search_record(struct hotel rooms[], int n){
    int i, search_room_no;
    printf("Enter the room number to search for: ");
    scanf("%d", &search_room_no);
    printf("\n");
    for(i=0; i<n; i++){
        if(rooms[i].room_no==search_room_no){
            printf("Room No\tGuest Name\tGuest NIC\tCheck-in Date\tCheck-out Date\tRoom Rate\tTotal Days\tTotal Bill\n");
            printf("%d\t%s\t%d\t%s\t%s\t%d\t%d\t%d\n\n", rooms[i].room_no, rooms[i].guest_name, rooms[i].guest_nic, rooms[i].check_in_date, rooms[i].check_out_date, rooms[i].room_rate, rooms[i].total_days, rooms[i].total_bill);
            break;
        }
        if(i==n-1){
            printf("No record found for room number %d.\n\n", search_room_no);
        }
    }
}

void edit_record(struct hotel rooms[], int n){
    int i, edit_room_no;
    printf("Enter the room number to edit: ");
    scanf("%d", &edit_room_no);
    for(i=0; i<n; i++){
        if(rooms[i].room_no==edit_room_no){
            printf("Enter the new details for room %d:\n", edit_room_no);
            printf("Room number: ");
            scanf("%d", &rooms[i].room_no);
            printf("Guest name: ");
            fflush(stdin);
            gets(rooms[i].guest_name);
            printf("Guest NIC: ");
            scanf("%d", &rooms[i].guest_nic);
            printf("Check-in date (dd/mm/yyyy): ");
            fflush(stdin);
            gets(rooms[i].check_in_date);
            printf("Check-out date (dd/mm/yyyy): ");
            fflush(stdin);
            gets(rooms[i].check_out_date);
            printf("Room rate: ");
            scanf("%d", &rooms[i].room_rate);
            printf("Total days stayed: ");
            scanf("%d", &rooms[i].total_days);
            rooms[i].total_bill = rooms[i].room_rate * rooms[i].total_days;
            printf("\nRecord updated successfully!\n\n");
            break;
        }
        if(i==n-1){
            printf("No record found for room number %d.\n\n", edit_room_no);
        }
    }
}

void delete_record(struct hotel rooms[], int n){
    int i, delete_room_no;
    printf("Enter the room number to delete: ");
    scanf("%d", &delete_room_no);
    for(i=0; i<n; i++){
        if(rooms[i].room_no==delete_room_no){
            rooms[i] = rooms[n-1];
            printf("Record deleted successfully!\n\n");
            break;
        }
        if(i==n-1){
            printf("No record found for room number %d.\n\n", delete_room_no);
        }
    }
}

int main(){
    int option, num_records=0, i;
    struct hotel rooms[50];
    printf("Welcome to Hotel Management System!\n\n");
    while(1){
        printf("1. Add new record\n");
        printf("2. View all records\n");
        printf("3. Search record\n");
        printf("4. Edit record\n");
        printf("5. Delete record\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        printf("\n");
        switch(option){
            case 1:
                if(num_records==50){
                    printf("Error: Maximum number of records reached.\n\n");
                }
                else{
                    add_new_record(rooms, num_records);
                    num_records++;
                }
                break;
            case 2:
                view_all_records(rooms, num_records);
                break;
            case 3:
                search_record(rooms, num_records);
                break;
            case 4:
                edit_record(rooms, num_records);
                break;
            case 5:
                delete_record(rooms, num_records);
                num_records--;
                break;
            case 6:
                printf("Thank you for using Hotel Management System!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n\n");
                break;
        }
    }
    return 0;
}