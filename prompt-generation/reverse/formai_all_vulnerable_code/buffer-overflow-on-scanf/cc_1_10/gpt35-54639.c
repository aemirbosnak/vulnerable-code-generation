//FormAI DATASET v1.0 Category: Hotel Management System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* A structure to hold all the details of a guest */
typedef struct {
    char name[50];
    int age;
    char address[100];
    char phone[20];
    int room_number;
    int days_stayed;
    double payment;
} GuestInfo;

/* A function to get input for guest registration */
void register_guest(GuestInfo *guest) {
    printf("Enter name: ");
    scanf("%[^\n]%*c", guest->name);
    printf("Enter age: ");
    scanf("%d", &guest->age);
    printf("Enter address: ");
    scanf("%[^\n]%*c", guest->address);
    printf("Enter phone: ");
    scanf("%[^\n]%*c", guest->phone);
    printf("Enter room number: ");
    scanf("%d", &guest->room_number);
    printf("Enter days stayed: ");
    scanf("%d", &guest->days_stayed);
    guest->payment = 100.0 * guest->days_stayed;
    printf("Registration Successful.\n");
}

/* A function to display all guest details */
void display_all_guests(GuestInfo *guest_list, int num_guests) {
    printf("Guest Details:\n");
    printf("Name\tAge\tAddress\t\t\tPhone\t\tRoom\tDays\tPayment\n");
    for (int i = 0; i < num_guests; i++) {
        printf("%s\t%d\t%-20s\t%s\t\t%d\t%d\t%.2lf\n", guest_list[i].name, guest_list[i].age, guest_list[i].address, guest_list[i].phone, guest_list[i].room_number, guest_list[i].days_stayed, guest_list[i].payment);
    }
}

/* A function to search for guest details */
void search_guest(GuestInfo *guest_list, int num_guests, char *name) {
    for (int i = 0; i < num_guests; i++) {
        if (strcmp(guest_list[i].name, name) == 0) {
            printf("Guest %s Found.\n", guest_list[i].name);
            printf("Name\tAge\tAddress\t\t\tPhone\t\tRoom\tDays\tPayment\n");
            printf("%s\t%d\t%-20s\t%s\t\t%d\t%d\t%.2lf\n", guest_list[i].name, guest_list[i].age, guest_list[i].address, guest_list[i].phone, guest_list[i].room_number, guest_list[i].days_stayed, guest_list[i].payment);
            return;
        }
    }
    printf("Guest Not Found.\n");
}

/* A function to delete a guest */
void delete_guest(GuestInfo *guest_list, int *num_guests, char *name) {
    for (int i = 0; i < *num_guests; i++) {
        if (strcmp(guest_list[i].name, name) == 0) {
            for (int j = i+1; j < *num_guests; j++) {
                guest_list[j-1] = guest_list[j];
            }
            (*num_guests)--;
            printf("Guest %s Deleted Successfully.\n", name);
            return;
        }
    }
    printf("Guest Not Found.\n");
}

/* The main function */
int main() {
    int choice, num_guests = 0;
    GuestInfo guest_list[20];
    char name[50];

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Register Guest\n");
        printf("2. Display All Guests\n");
        printf("3. Search Guest\n");
        printf("4. Delete Guest\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                register_guest(&guest_list[num_guests]);
                num_guests++;
                break;
            case 2:
                display_all_guests(guest_list, num_guests);
                break;
            case 3:
                printf("Enter Guest Name: ");
                scanf("%[^\n]%*c", name);
                search_guest(guest_list, num_guests, name);
                break;
            case 4:
                printf("Enter Guest Name: ");
                scanf("%[^\n]%*c", name);
                delete_guest(guest_list, &num_guests, name);
                break;
            case 5:
                printf("Exiting Program...\n");
                exit(0);
            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}