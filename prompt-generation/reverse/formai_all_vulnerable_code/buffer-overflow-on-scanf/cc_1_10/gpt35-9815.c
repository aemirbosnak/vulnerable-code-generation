//FormAI DATASET v1.0 Category: Hotel Management System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct guest_info {
    char name[50];
    int room_num;
    int days_stayed;
    float total_bill;
};

int main() {
    struct guest_info guest;
    FILE *fptr;
    char filename[20];
    float room_cost, total_cost;
    int choice;

    printf("Welcome to C Hotel Management System\n");

    printf("Enter guest name: ");
    fgets(guest.name, sizeof(guest.name), stdin);
    printf("Enter room number: ");
    scanf("%d", &guest.room_num);
    printf("Enter number of days stayed: ");
    scanf("%d", &guest.days_stayed);

    printf("\nSelect room type:\n");
    printf("1. Single Room\n");
    printf("2. Double Room\n");
    printf("3. Suite Room\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            room_cost = 50.50;
            break;
        case 2:
            room_cost = 75.75;
            break;
        case 3:
            room_cost = 100.00;
            break;
        default:
            printf("Invalid choice!\n");
            return 0;
    }

    total_cost = guest.days_stayed * room_cost;
    guest.total_bill = total_cost;

    printf("\n--------------------\n");
    printf("Guest name: %s", guest.name);
    printf("Room number: %d\n", guest.room_num);
    printf("Days stayed: %d\n", guest.days_stayed);
    printf("Total bill: $%.2f\n", guest.total_bill);
    printf("----------------------\n");

    printf("Do you want to save the data to a file? (Y/N) ");
    char save_choice = getchar();

    if(save_choice == 'Y' || save_choice == 'y') {
        printf("Enter file name: ");
        fgets(filename, sizeof(filename), stdin);
        filename[strcspn(filename, "\n")] = 0; // remove newline character
        fptr = fopen(filename, "w");

        fprintf(fptr, "Guest name: %s", guest.name);
        fprintf(fptr, "Room number: %d\n", guest.room_num);
        fprintf(fptr, "Days stayed: %d\n", guest.days_stayed);
        fprintf(fptr, "Total bill: $%.2f\n", guest.total_bill);

        printf("Data saved successfully to file.\n");
        fclose(fptr);
    } else {
        printf("Thank you for using C Hotel Management System.\n");
    }

    return 0;
}