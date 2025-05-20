//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>

struct guest{
    int id;
    char name[20];
    int age;
    int room_no;
};

int main()
{
    struct guest guest_info[10];

    printf("Welcome to the Imaginary Hotel Management System!\n");

    //Creating guest records
    printf("Enter the guest ID:\n");
    scanf("%d",&guest_info[0].id);
    printf("Enter the guest name:\n");
    scanf("%s",guest_info[0].name);
    printf("Enter the guest age:\n");
    scanf("%d",&guest_info[0].age);
    printf("Enter the guest room number:\n");
    scanf("%d",&guest_info[0].room_no);

    printf("\nGuest 1 details:\n");
    printf("ID: %d\n",guest_info[0].id);
    printf("Name: %s\n",guest_info[0].name);
    printf("Age: %d\n",guest_info[0].age);
    printf("Room No: %d\n",guest_info[0].room_no);

    printf("\n");

    //Creating guest records
    printf("Enter the guest ID:\n");
    scanf("%d",&guest_info[1].id);
    printf("Enter the guest name:\n");
    scanf("%s",guest_info[1].name);
    printf("Enter the guest age:\n");
    scanf("%d",&guest_info[1].age);
    printf("Enter the guest room number:\n");
    scanf("%d",&guest_info[1].room_no);

    printf("\nGuest 2 details:\n");
    printf("ID: %d\n",guest_info[1].id);
    printf("Name: %s\n",guest_info[1].name);
    printf("Age: %d\n",guest_info[1].age);
    printf("Room No: %d\n",guest_info[1].room_no);

    printf("\n");

    //Creating guest records
    printf("Enter the guest ID:\n");
    scanf("%d",&guest_info[2].id);
    printf("Enter the guest name:\n");
    scanf("%s",guest_info[2].name);
    printf("Enter the guest age:\n");
    scanf("%d",&guest_info[2].age);
    printf("Enter the guest room number:\n");
    scanf("%d",&guest_info[2].room_no);

    printf("\nGuest 3 details:\n");
    printf("ID: %d\n",guest_info[2].id);
    printf("Name: %s\n",guest_info[2].name);
    printf("Age: %d\n",guest_info[2].age);
    printf("Room No: %d\n",guest_info[2].room_no);

    printf("\n");

    //Creating guest records
    printf("Enter the guest ID:\n");
    scanf("%d",&guest_info[3].id);
    printf("Enter the guest name:\n");
    scanf("%s",guest_info[3].name);
    printf("Enter the guest age:\n");
    scanf("%d",&guest_info[3].age);
    printf("Enter the guest room number:\n");
    scanf("%d",&guest_info[3].room_no);

    printf("\nGuest 4 details:\n");
    printf("ID: %d\n",guest_info[3].id);
    printf("Name: %s\n",guest_info[3].name);
    printf("Age: %d\n",guest_info[3].age);
    printf("Room No: %d\n",guest_info[3].room_no);

    printf("\n");

    //Creating guest records
    printf("Enter the guest ID:\n");
    scanf("%d",&guest_info[4].id);
    printf("Enter the guest name:\n");
    scanf("%s",guest_info[4].name);
    printf("Enter the guest age:\n");
    scanf("%d",&guest_info[4].age);
    printf("Enter the guest room number:\n");
    scanf("%d",&guest_info[4].room_no);

    printf("\nGuest 5 details:\n");
    printf("ID: %d\n",guest_info[4].id);
    printf("Name: %s\n",guest_info[4].name);
    printf("Age: %d\n",guest_info[4].age);
    printf("Room No: %d\n",guest_info[4].room_no);

    printf("\n");

    //Creating guest records
    printf("Enter the guest ID:\n");
    scanf("%d",&guest_info[5].id);
    printf("Enter the guest name:\n");
    scanf("%s",guest_info[5].name);
    printf("Enter the guest age:\n");
    scanf("%d",&guest_info[5].age);
    printf("Enter the guest room number:\n");
    scanf("%d",&guest_info[5].room_no);

    printf("\nGuest 6 details:\n");
    printf("ID: %d\n",guest_info[5].id);
    printf("Name: %s\n",guest_info[5].name);
    printf("Age: %d\n",guest_info[5].age);
    printf("Room No: %d\n",guest_info[5].room_no);

    printf("\n");

    //Creating guest records
    printf("Enter the guest ID:\n");
    scanf("%d",&guest_info[6].id);
    printf("Enter the guest name:\n");
    scanf("%s",guest_info[6].name);
    printf("Enter the guest age:\n");
    scanf("%d",&guest_info[6].age);
    printf("Enter the guest room number:\n");
    scanf("%d",&guest_info[6].room_no);

    printf("\nGuest 7 details:\n");
    printf("ID: %d\n",guest_info[6].id);
    printf("Name: %s\n",guest_info[6].name);
    printf("Age: %d\n",guest_info[6].age);
    printf("Room No: %d\n",guest_info[6].room_no);

    printf("\n");

    //Creating guest records
    printf("Enter the guest ID:\n");
    scanf("%d",&guest_info[7].id);
    printf("Enter the guest name:\n");
    scanf("%s",guest_info[7].name);
    printf("Enter the guest age:\n");
    scanf("%d",&guest_info[7].age);
    printf("Enter the guest room number:\n");
    scanf("%d",&guest_info[7].room_no);

    printf("\nGuest 8 details:\n");
    printf("ID: %d\n",guest_info[7].id);
    printf("Name: %s\n",guest_info[7].name);
    printf("Age: %d\n",guest_info[7].age);
    printf("Room No: %d\n",guest_info[7].room_no);

    printf("\n");

    //Creating guest records
    printf("Enter the guest ID:\n");
    scanf("%d",&guest_info[8].id);
    printf("Enter the guest name:\n");
    scanf("%s",guest_info[8].name);
    printf("Enter the guest age:\n");
    scanf("%d",&guest_info[8].age);
    printf("Enter the guest room number:\n");
    scanf("%d",&guest_info[8].room_no);

    printf("\nGuest 9 details:\n");
    printf("ID: %d\n",guest_info[8].id);
    printf("Name: %s\n",guest_info[8].name);
    printf("Age: %d\n",guest_info[8].age);
    printf("Room No: %d\n",guest_info[8].room_no);

    printf("\n");

    //Displaying all guest details
    printf("All Guest Details:\n");
    for(int i=0;i<9;i++){
        printf("ID: %d\n",guest_info[i].id);
        printf("Name: %s\n",guest_info[i].name);
        printf("Age: %d\n",guest_info[i].age);
        printf("Room No: %d\n",guest_info[i].room_no);
    }

    return 0;
}