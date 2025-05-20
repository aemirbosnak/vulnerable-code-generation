//FormAI DATASET v1.0 Category: Hotel Management System ; Style: Claude Shannon
/* C Hotel Management System */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct guest {
    char name[50];
    int room_no;
    int check_in_day;
    int check_out_day;
    int room_price;
};

void add_guest(struct guest *guest_list, int *guest_count) {
    printf("\nEnter guest name: ");
    scanf("%s", guest_list[*guest_count].name);
    printf("Enter room number: ");
    scanf("%d", &guest_list[*guest_count].room_no);
    printf("Enter check-in day (1 = Monday, 2 = Tuesday, etc.): ");
    scanf("%d", &guest_list[*guest_count].check_in_day);
    printf("Enter check-out day (1 = Monday, 2 = Tuesday, etc.): ");
    scanf("%d", &guest_list[*guest_count].check_out_day);
    printf("Enter room price: ");
    scanf("%d", &guest_list[*guest_count].room_price);
    (*guest_count)++;
}

void print_guest(struct guest guest) {
    printf("\nGuest Name: %s", guest.name);
    printf("\nRoom Number: %d", guest.room_no);
    printf("\nCheck-in Day: %d", guest.check_in_day);
    printf("\nCheck-out Day: %d", guest.check_out_day);
    printf("\nRoom Price: %d", guest.room_price);
}

void print_all_guests(struct guest *guest_list, int guest_count) {
    int i;
    for (i = 0; i < guest_count; i++) {
        printf("\nGuest %d:", i + 1);
        print_guest(guest_list[i]);
    }
}

void delete_guest(struct guest *guest_list, int *guest_count, int index) {
    int i;
    for (i = index; i < *guest_count - 1; i++) {
        guest_list[i] = guest_list[i + 1];
    }
    (*guest_count)--;
}

int main() {
    struct guest guest_list[50];
    int guest_count = 0;
    int choice, i, guest_index, total_price;

    do {
        printf("\n\n Welcome to the Claude Shannon Hotel Management System!");
        printf("\n 1. Add guest");
        printf("\n 2. View all guests");
        printf("\n 3. Delete guest");
        printf("\n 4. Calculate total price for all guests");
        printf("\n 5. Exit");
        printf("\n\n Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_guest(guest_list, &guest_count);
                break;
            case 2:
                print_all_guests(guest_list, guest_count);
                break;
            case 3:
                printf("\nEnter guest index to be deleted: ");
                scanf("%d", &guest_index);
                delete_guest(guest_list, &guest_count, guest_index - 1);
                break;
            case 4:
                total_price = 0;
                for (i = 0; i < guest_count; i++) {
                    total_price += guest_list[i].room_price;
                }
                printf("\nTotal price for all guests: %d", total_price);
                break;
            case 5:
                printf("\n\nThank you for using the Claude Shannon Hotel Management System!");
                break;
            default:
                printf("\n Invalid choice. Please try again.");
        }
    } while(choice != 5);

    return 0;
}