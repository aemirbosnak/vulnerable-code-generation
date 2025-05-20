//Falcon-180B DATASET v1.0 Category: Hotel Management System ; Style: energetic
#include<stdio.h>
#include<string.h>

#define MAX 100

struct guest {
    char name[50];
    char address[100];
    int room_no;
    int days_stay;
    int bill;
};

void add_guest(struct guest *g, int n) {
    printf("\nEnter the details of the guest:\n");
    printf("Name: ");
    scanf("%s", g[n].name);
    printf("Address: ");
    scanf("%s", g[n].address);
    printf("Room No.: ");
    scanf("%d", &g[n].room_no);
    printf("Number of days stay: ");
    scanf("%d", &g[n].days_stay);
}

void display_guest(struct guest *g, int n) {
    printf("\nGuest Details:\n");
    printf("Name: %s\n", g[n].name);
    printf("Address: %s\n", g[n].address);
    printf("Room No.: %d\n", g[n].room_no);
    printf("Number of days stay: %d\n", g[n].days_stay);
}

void calculate_bill(struct guest *g, int n) {
    g[n].bill = g[n].days_stay * 500; // Assuming $500 per day
    printf("\nTotal Bill: $%d\n", g[n].bill);
}

void main() {
    struct guest g[MAX];
    int n, choice;

    printf("\nWelcome to the Hotel Management System!\n");
    printf("Enter the number of guests: ");
    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        add_guest(g, i);
    }

    while(1) {
        printf("\nChoose an option:\n");
        printf("1. Display Guest Details\n");
        printf("2. Calculate Bill\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter the guest number: ");
                scanf("%d", &n);
                display_guest(g, n);
                break;

            case 2:
                printf("\nEnter the guest number: ");
                scanf("%d", &n);
                calculate_bill(g, n);
                break;

            case 3:
                printf("\nThank you for using the Hotel Management System!\n");
                exit(0);

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
}