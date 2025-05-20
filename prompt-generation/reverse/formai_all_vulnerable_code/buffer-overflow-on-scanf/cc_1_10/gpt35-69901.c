//FormAI DATASET v1.0 Category: Hotel Management System ; Style: realistic
#include<stdio.h>
#include<stdlib.h>

struct guest {
    char name[50];
    int room_number;
    int phone_number;
    int days_stay;
    float room_charge;
};

int main() {

    struct guest g[100];
    int i, j, n;
    float total_revenue = 0.0;

    printf("Enter the number of guests: ");
    scanf("%d", &n);

    // Taking input from user
    for(i=0; i<n; i++) {
        printf("\nEnter details of Guest %d\n", i+1);
        printf("Name: ");
        scanf("%s", g[i].name);
        printf("Room Number: ");
        scanf("%d", &g[i].room_number);
        printf("Phone Number: ");
        scanf("%d", &g[i].phone_number);
        printf("Days Stay: ");
        scanf("%d", &g[i].days_stay);
        printf("Room Charge per Day: ");
        scanf("%f", &g[i].room_charge);
    }

    // Displaying guest details and calculating revenue
    printf("\nGuest Details\n");
    printf("Name\tRoom No.\tPhone No.\tDays Stayed\tCharge per Day\tTotal Charge\n");
    for(i=0; i<n; i++) {
        float total_charge = g[i].days_stay * g[i].room_charge;

        printf("%s\t%d\t\t%d\t\t%d\t\t%.2f\t\t%.2f\n", g[i].name, g[i].room_number, g[i].phone_number, g[i].days_stay, g[i].room_charge, total_charge);

        total_revenue += total_charge; // Add to total revenue
    }

    // Displaying total revenue
    printf("\nTotal Revenue: %.2f", total_revenue);

    return 0;
}