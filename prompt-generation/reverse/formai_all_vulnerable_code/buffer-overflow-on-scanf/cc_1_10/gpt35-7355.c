//FormAI DATASET v1.0 Category: Hotel Management System ; Style: detailed
#include<stdio.h>
#include<string.h>

void booking();
void checkin();
void checkout();
void viewall();

struct guest
{
    int roomno;
    char name[20];
    char address[50];
    char phone[12];
    int days;
    int rent;
}g;

FILE *fp, *fp1, *fp2;

int main()
{
    int choice, pin;

    printf("Enter PIN: ");
    scanf("%d", &pin);

    if(pin == 1234)
    {
        while(1)
        {
            printf("\n---- Welcome to C Hotel Management System ----\n");
            printf("\n1. Booking\n2. Check-in\n3. Check-out\n4. View all bookings\n5. Exit\n");
            printf("\nEnter your choice: ");
            scanf("%d", &choice);

            switch(choice)
            {
                case 1:
                    booking();
                    break;
                case 2:
                    checkin();
                    break;
                case 3:
                    checkout();
                    break;
                case 4:
                    viewall();
                    break;
                case 5:
                    printf("\nThank you for using the system!\n");
                    return 0;
                default:
                    printf("\nInvalid choice, please try again.\n");
            }
        }
    }
    else
    {
        printf("\nIncorrect PIN entered. System exiting.\n");
    }

    return 0;
}

void booking()
{
    int roomno, size;
    printf("\nEnter room no: ");
    scanf("%d", &roomno);

    fp = fopen("bookings.txt", "r");

    while(fscanf(fp, "%d %s %s %s %d %d", &g.roomno, g.name, g.address, g.phone, &g.days, &g.rent)!=EOF)
    {
        if(g.roomno == roomno)
        {
            printf("\nRoom already booked.\n");
            fclose(fp);
            return;
        }
    }

    fclose(fp);

    printf("\nEnter name: ");
    scanf("%s", g.name);
    printf("\nEnter address: ");
    scanf("%s", g.address);
    printf("\nEnter phone number: ");
    scanf("%s", g.phone);
    printf("\nEnter number of days to stay: ");
    scanf("%d", &g.days);
    printf("\nEnter room rent per day: ");
    scanf("%d", &g.rent);

    fp1 = fopen("bookings.txt", "a");
    fprintf(fp1, "\n%d %s %s %s %d %d", roomno, g.name, g.address, g.phone, g.days, g.rent);
    fclose(fp1);

    printf("\nBooking done successfully!\n");

    fp2 = fopen("rooms.txt", "r+");
    fseek(fp2, (roomno-1)*4, SEEK_SET);
    size = fwrite(&roomno, sizeof(int), 1, fp2);
    fclose(fp2);
}

void checkin()
{
    int roomno, size;
    printf("\nEnter room no: ");
    scanf("%d", &roomno);

    fp = fopen("bookings.txt", "r");

    while(fscanf(fp, "%d %s %s %s %d %d", &g.roomno, g.name, g.address, g.phone, &g.days, &g.rent)!=EOF)
    {
        if(g.roomno == roomno)
        {
            printf("\nGuest name: %s\nRoom no: %d\nAddress: %s\nPhone number: %s\nDays stayed: %d\nRoom rent: %d\n", g.name, g.roomno, g.address, g.phone, g.days, g.rent);
            fclose(fp);

            fp = fopen("rooms.txt", "r+");
            fseek(fp, (roomno-1)*4, SEEK_SET);
            size = fwrite(&roomno, sizeof(int), 1, fp);
            fclose(fp);

            printf("\nCheck-in done successfully!\n");
            return;
        }
    }

    printf("\nRoom not booked.\n");

    fclose(fp);
}

void checkout()
{
    int roomno, size;
    printf("\nEnter room no: ");
    scanf("%d", &roomno);

    fp = fopen("bookings.txt", "r");

    while(fscanf(fp, "%d %s %s %s %d %d", &g.roomno, g.name, g.address, g.phone, &g.days, &g.rent)!=EOF)
    {
        if(g.roomno == roomno)
        {
            printf("\nGuest name: %s\nRoom no: %d\nAddress: %s\nPhone number: %s\nDays stayed: %d\nRoom rent: %d\n", g.name, g.roomno, g.address, g.phone, g.days, g.rent);
            fclose(fp);

            fp1 = fopen("temp.txt", "w");

            fp = fopen("bookings.txt", "r");

            while(fscanf(fp, "%d %s %s %s %d %d", &g.roomno, g.name, g.address, g.phone, &g.days, &g.rent)!=EOF)
            {
                if(g.roomno != roomno)
                {
                    fprintf(fp1, "\n%d %s %s %s %d %d", g.roomno, g.name, g.address, g.phone, g.days, g.rent);
                }
            }

            fclose(fp);
            fclose(fp1);

            fp = fopen("bookings.txt", "w");
            fp1 = fopen("temp.txt", "r");

            while(fscanf(fp1, "%d %s %s %s %d %d", &g.roomno, g.name, g.address, g.phone, &g.days, &g.rent)!=EOF)
            {
                fprintf(fp, "\n%d %s %s %s %d %d", g.roomno, g.name, g.address, g.phone, g.days, g.rent);
            }

            fclose(fp);
            fclose(fp1);

            fp2 = fopen("rooms.txt", "r+");
            fseek(fp2, (roomno-1)*4, SEEK_SET);
            size = fwrite(&roomno, sizeof(int), 1, fp2);
            fclose(fp2);

            printf("\nCheck-out done successfully!\n");
            return;
        }
    }

    printf("\nRoom not booked.\n");

    fclose(fp);
}

void viewall()
{
    fp = fopen("bookings.txt", "r");

    printf("\nRoom no\tName\tAddress\tPhone no\tDays stayed\tRent per day\n");

    while(fscanf(fp, "%d %s %s %s %d %d", &g.roomno, g.name, g.address, g.phone, &g.days, &g.rent)!=EOF)
    {
        printf("%d\t%s\t%s\t%s\t%d\t\t%d\n", g.roomno, g.name, g.address, g.phone, g.days, g.rent);
    }

    fclose(fp);
}