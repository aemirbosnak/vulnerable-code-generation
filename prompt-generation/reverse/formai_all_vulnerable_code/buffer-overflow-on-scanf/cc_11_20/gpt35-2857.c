//FormAI DATASET v1.0 Category: Hotel Management System ; Style: futuristic
#include <stdio.h>
#include <string.h>

struct guest {
    char name[20];
    char room_number[5];
    int room_price;
};

int main() {
    struct guest guest_db[5];
    int num_guests = 0;
    int total_revenue = 0;

    while (1) {
        printf("Welcome to C Hotel Management System\n");
        printf("1. Check-in a guest\n");
        printf("2. Check-out a guest\n");
        printf("3. View guest database\n");
        printf("4. View total revenue\n");
        printf("5. Exit\n");

        int user_choice = 0;
        printf("Please enter your choice: ");
        scanf("%d", &user_choice);

        switch (user_choice) {
            case 1: {
                if (num_guests == 5) {
                    printf("Sorry, the hotel is currently full.\n");
                    break;
                }

                struct guest new_guest;
                printf("Please enter guest name: ");
                scanf("%s", &new_guest.name);
                printf("Please enter room number: ");
                scanf("%s", &new_guest.room_number);
                printf("Please enter room price: ");
                scanf("%d", &new_guest.room_price);

                guest_db[num_guests] = new_guest;
                num_guests++;
                printf("Guest has been checked in.\n");
                break;
            }
            case 2: {
                char room_number[5];
                printf("Please enter room number: ");
                scanf("%s", &room_number);

                int guest_index = -1;
                for (int i = 0; i < num_guests; i++) {
                    if (strcmp(guest_db[i].room_number, room_number) == 0) {
                        guest_index = i;
                        break;
                    }
                }

                if (guest_index == -1) {
                    printf("Sorry, no guest found with that room number.\n");
                    break;
                }

                int bill_amount = guest_db[guest_index].room_price;

                printf("Guest %s has been checked out. Total bill amount: %d\n", guest_db[guest_index].name, bill_amount);

                total_revenue += bill_amount;

                for (int i = guest_index; i < num_guests - 1; i++) {
                    guest_db[i] = guest_db[i+1];
                }

                num_guests--;
                break;
            }
            case 3: {
                printf("Guest Database:\n");
                printf("Name\t\tRoom Number\tRoom Price\n");
                for (int i = 0; i < num_guests; i++) {
                    printf("%s\t\t%s\t\t%d\n", guest_db[i].name, guest_db[i].room_number, guest_db[i].room_price);
                }
                break;
            }
            case 4: {
                printf("Total revenue: %d\n", total_revenue);
                break;
            }
            case 5: {
                printf("Exiting...\n");
                return 0;
            }
            default: {
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }
    }
}