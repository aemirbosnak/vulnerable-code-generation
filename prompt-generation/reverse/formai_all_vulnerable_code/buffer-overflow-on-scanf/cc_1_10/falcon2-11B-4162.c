//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: imaginative
#include<stdio.h>
#include<string.h>

struct guest
{
    char name[20];
    int room_no;
    int check_in_date;
    int check_out_date;
};

void add_guest(struct guest g)
{
    printf("Enter name of the guest: ");
    scanf("%s", g.name);
    printf("Enter room number: ");
    scanf("%d", &g.room_no);
    printf("Enter check-in date: ");
    scanf("%d", &g.check_in_date);
    printf("Enter check-out date: ");
    scanf("%d", &g.check_out_date);

    printf("\nGuest added successfully!\n");
}

void check_in(struct guest g)
{
    printf("\nGuest is checked in!\n");
}

void check_out(struct guest g)
{
    printf("\nGuest is checked out!\n");
}

void view_guests()
{
    struct guest g;
    int i = 0;
    printf("\nGuest list:\n");

    while(i < 10)
    {
        printf("Guest %d: %s\n", i+1, g.name);
        i++;
    }
}

int main()
{
    struct guest g;
    int choice, room_no, check_in_date, check_out_date;

    do
    {
        printf("\n1. Add new guest\n2. Check-in a guest\n3. Check-out a guest\n4. View guest list\n5. Exit\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                add_guest(g);
                break;
            case 2:
                room_no = g.room_no;
                check_in_date = g.check_in_date;
                check_out_date = g.check_out_date;
                printf("\nEnter room number: ");
                scanf("%d", &room_no);
                printf("Enter check-in date: ");
                scanf("%d", &check_in_date);
                printf("Enter check-out date: ");
                scanf("%d", &check_out_date);
                check_in(g);
                break;
            case 3:
                room_no = g.room_no;
                check_in_date = g.check_in_date;
                check_out_date = g.check_out_date;
                printf("\nEnter room number: ");
                scanf("%d", &room_no);
                printf("Enter check-in date: ");
                scanf("%d", &check_in_date);
                printf("Enter check-out date: ");
                scanf("%d", &check_out_date);
                check_out(g);
                break;
            case 4:
                view_guests();
                break;
            case 5:
                return 0;
            default:
                printf("\nInvalid choice!\n");
        }
    } while(choice!= 5);

    return 0;
}