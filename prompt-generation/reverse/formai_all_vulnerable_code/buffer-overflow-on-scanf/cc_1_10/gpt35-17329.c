//FormAI DATASET v1.0 Category: Hotel Management System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct guest {
    char name[20];
    char address[50];
    char phone[12];
    int room_number;
    int num_of_nights;
    float rate;
};

void print_guest(struct guest *g) {
    printf("Name: %s\n", g->name);
    printf("Address: %s\n", g->address);
    printf("Phone: %s\n", g->phone);
    printf("Room Number: %d\n", g->room_number);
    printf("Number of Nights: %d\n", g->num_of_nights);
    printf("Rate: $%.2f\n", g->rate);
    printf("Total Bill: $%.2f\n", g->num_of_nights * g->rate);
    printf("============================\n");
}

int main(void) {
    int num_of_guests = 0;
    struct guest *guest_list = NULL;
    char choice;
    int i;

    do {
        printf("Welcome to the C Hotel Management System.\n");
        printf("1. Add Guest\n");
        printf("2. Print Guest List\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        fflush(stdout);
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                num_of_guests++;
                if (guest_list == NULL) {
                    guest_list = (struct guest*) malloc(sizeof(struct guest));
                } else {
                    guest_list = (struct guest*) realloc(guest_list, (num_of_guests) * sizeof(struct guest));
                }

                printf("Enter guest name: ");
                fflush(stdout);
                scanf("%s", guest_list[num_of_guests-1].name);

                printf("Enter guest address: ");
                fflush(stdout);
                scanf("%s", guest_list[num_of_guests-1].address);

                printf("Enter guest phone: ");
                fflush(stdout);
                scanf("%s", guest_list[num_of_guests-1].phone);

                printf("Enter guest room number: ");
                fflush(stdout);
                scanf("%d", &guest_list[num_of_guests-1].room_number);

                printf("Enter number of nights: ");
                fflush(stdout);
                scanf("%d", &guest_list[num_of_guests-1].num_of_nights);

                printf("Enter rate per night: ");
                fflush(stdout);
                scanf("%f", &guest_list[num_of_guests-1].rate);

                printf("Guest added successfully.\n");
                printf("============================\n");

                break;
            case '2':
                for (i = 0; i < num_of_guests; i++) {
                    print_guest(&guest_list[i]);
                }
                break;
            case '3':
                printf("Thank you for using the C Hotel Management System.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != '3');

    return 0;
}