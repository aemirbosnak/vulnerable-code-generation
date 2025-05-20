//FormAI DATASET v1.0 Category: Hotel Management System ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct hotel {
    char roomNo[10];
    char name[20];
    char contact[15];
    int days;
    int rate;
}g;

void checkIn() {
    struct hotel g;
    printf("\nEnter Room Number: ");
    fflush(stdin);
    gets(g.roomNo);
    
    printf("\nEnter Name: ");
    fflush(stdin);
    gets(g.name);
    
    printf("\nEnter Contact Number: ");
    fflush(stdin);
    gets(g.contact);
    
    printf("\nEnter Number of Days: ");
    scanf("%d", &g.days);
    
    printf("\nEnter Rate per Day: ");
    scanf("%d", &g.rate);

    FILE *fp;
    fp = fopen("hotelManagement.dat", "ab");
    if(fp == NULL) {
        printf("File cannot be opened!");
        exit(1);
    }
    fwrite(&g, sizeof(g), 1, fp);
    fclose(fp);
}

void display() {
    struct hotel g;
    FILE *fp;
    fp = fopen("hotelManagement.dat", "rb");
    if(fp == NULL) {
        printf("\nFile cannot be opened!");
        exit(1);
    }
    printf("\nRoom No.\tName\tContact No.\tDays\tRate\tAmount");
    printf("\n---------------------------------------------------------------------");
    while(fread(&g, sizeof(g), 1, fp)) {
        printf("\n%s\t\t%s\t%s\t%d\t%d\t%d", g.roomNo, g.name, g.contact, g.days, g.rate, g.days*g.rate);
    }
    fclose(fp);
}

void checkOut() {
    struct hotel g;
    int flag = 0;
    char room[10];
    printf("\nEnter Room Number to checkout: ");
    fflush(stdin);
    gets(room);

    FILE *fp, *newfp;
    fp = fopen("hotelManagement.dat", "rb");
    if(fp == NULL) {
        printf("\nFile cannot be opened!");
        exit(1);
    }
    newfp = fopen("temp.dat", "wb");
    if(newfp == NULL) {
        printf("\nFile cannot be opened!");
        exit(1);
    }
    while(fread(&g, sizeof(g), 1, fp)) {
        if(strcmp(g.roomNo, room) != 0) {
            fwrite(&g, sizeof(g), 1, newfp);
        } else {
            flag = 1;
            printf("\nRoom No.\tName\tContact No.\tDays\tRate\tAmount");
            printf("\n---------------------------------------------------------------------");
            printf("\n%s\t\t%s\t%s\t%d\t%d\t%d", g.roomNo, g.name, g.contact, g.days, g.rate, g.days*g.rate);
        }
    }
    if(flag == 0) {
        printf("\nRoom Number not found!");
    }
    fclose(fp);
    fclose(newfp);

    remove("hotelManagement.dat");
    rename("temp.dat", "hotelManagement.dat");
    printf("\nCheckout Successful!");
}

int main() {
    int choice;
    printf("\n\t\t~~~~~~~~~ HOTEL MANAGEMENT SYSTEM ~~~~~~~~~\n");
    while(1) {
        printf("\n1. Check In");
        printf("\n2. Display All Records");
        printf("\n3. Check Out");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                checkIn();
                break;
            case 2:
                display();
                break;
            case 3:
                checkOut();
                break;
            case 4:
                printf("\nThank you for using our hotel management system!");
                exit(0);
            default:
                printf("\nInvalid Choice!");
        }
    }
    return 0;
}