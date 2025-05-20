//FormAI DATASET v1.0 Category: Hotel Management System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for guest information
struct Guest {
    char name[50];
    int age;
    long long int phone;
    char address[100];
    char room_type[20];
    int room_number;
    int days;
    float cost;
};

// Define struct for room information
struct Room {
    int number;
    char type[20];
    float cost_per_day;
    int is_available;
};

// Function prototypes
void print_menu();
int add_guest(struct Guest *guests_list, struct Room *rooms_list);
void print_guest_info(struct Guest guest);
int search_guest(struct Guest *guests_list);
void update_guest(struct Guest *guest);
int check_out(struct Guest *guest, struct Room *rooms_list);

int main() {
    // Initialize room list
    struct Room rooms_list[10] = {
        {101, "Single", 50.0, 1},
        {102, "Single", 50.0, 1},
        {103, "Double", 75.0, 1},
        {104, "Double", 75.0, 1},
        {105, "Suite", 100.0, 1},
        {106, "Suite", 100.0, 1},
        {201, "Single", 50.0, 1},
        {202, "Single", 50.0, 1},
        {203, "Double", 75.0, 1},
        {204, "Double", 75.0, 1},
    };

    // Initialize guest list
    struct Guest guests_list[10];

    // Initialize menu choice variable
    int choice;

    do {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_guest(guests_list, rooms_list);
                break;
            case 2:
                search_guest(guests_list);
                break;
            case 3:
                printf("Enter guest name: ");
                char name[50];
                scanf("%s", name);
                for(int i=0; i<10; i++) {
                    if(strcmp(guests_list[i].name, name) == 0) {
                        update_guest(&guests_list[i]);
                    }
                }
                break;
            case 4:
                printf("Enter guest name: ");
                char guest_name[50];
                scanf("%s", guest_name);

                for(int i=0; i<10; i++) {
                    if(strcmp(guests_list[i].name, guest_name) == 0) {
                        check_out(&guests_list[i], rooms_list);
                    }
                }
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(choice != 5);

    return 0;
}

void print_menu() {
    printf("\nMain Menu\n");
    printf("1. Add a guest\n");
    printf("2. Search for a guest\n");
    printf("3. Update guest information\n");
    printf("4. Check-out a guest\n");
    printf("5. Quit\n");
}

int add_guest(struct Guest *guests_list, struct Room *rooms_list) {
    // Find an available room
    int room_number = 0;
    for(int i=0; i<10; i++) {
        if(rooms_list[i].is_available == 1) {
            room_number = rooms_list[i].number;
            rooms_list[i].is_available = 0;
            break;
        }
    }

    if(room_number == 0) {
        printf("Sorry, no rooms available.\n");
        return -1;
    }

    // Get guest information
    struct Guest new_guest;
    printf("Enter guest name: ");
    scanf("%s", new_guest.name);
    printf("Enter guest age: ");
    scanf("%d", &new_guest.age);
    printf("Enter guest phone number: ");
    scanf("%lld", &new_guest.phone);
    printf("Enter guest address: ");
    scanf("%s", new_guest.address);
    printf("Enter room type (Single, Double, Suite): ");
    scanf("%s", new_guest.room_type);
    new_guest.room_number = room_number;
    printf("Enter number of days staying: ");
    scanf("%d", &new_guest.days);

    // Calculate cost of stay
    for(int i=0; i<10; i++) {
        if(strcmp(rooms_list[i].type, new_guest.room_type) == 0) {
            new_guest.cost = new_guest.days * rooms_list[i].cost_per_day;
        }
    }

    // Add guest to guest list
    for(int i=0; i<10; i++) {
        if(guests_list[i].name[0] == '\0') {
            guests_list[i] = new_guest;
            printf("Guest %s assigned room %d.\n", new_guest.name, new_guest.room_number);
            return 0;
        }
    }

    printf("No room available. Guest %s cannot be accommodated.\n", new_guest.name);
    return -1;
}

void print_guest_info(struct Guest guest) {
    printf("Name: %s\n", guest.name);
    printf("Age: %d\n", guest.age);
    printf("Phone: %lld\n", guest.phone);
    printf("Address: %s\n", guest.address);
    printf("Room type: %s\n", guest.room_type);
    printf("Room number: %d\n", guest.room_number);
    printf("Days stayed: %d\n", guest.days);
    printf("Total cost: $%.2f\n\n", guest.cost);
}

int search_guest(struct Guest *guests_list) {
    printf("Enter guest name: ");
    char name[50];
    scanf("%s", name);

    for(int i=0; i<10; i++) {
        if(strcmp(guests_list[i].name, name) == 0) {
            print_guest_info(guests_list[i]);
            return i;
        }
    }

    printf("Guest not found.\n");
    return -1;
}

void update_guest(struct Guest *guest) {
    int choice;

    do {
        printf("\nWhat would you like to update?\n");
        printf("1. Name\n");
        printf("2. Age\n");
        printf("3. Phone\n");
        printf("4. Address\n");
        printf("5. Room type\n");
        printf("6. Days stayed\n");
        printf("7. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter new name: ");
                scanf("%s", guest->name);
                break;
            case 2:
                printf("Enter new age: ");
                scanf("%d", &guest->age);
                break;
            case 3:
                printf("Enter new phone number: ");
                scanf("%lld", &guest->phone);
                break;
            case 4:
                printf("Enter new address: ");
                scanf("%s", guest->address);
                break;
            case 5:
                printf("Enter new room type (Single, Double, Suite): ");
                scanf("%s", guest->room_type);
                break;
            case 6:
                printf("Enter new number of days staying: ");
                scanf("%d", &guest->days);
                guest->cost = 0.0; // Recalculate cost with new number of days
                break;
            case 7:
                printf("Returning to main menu.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(choice != 7);
}

int check_out(struct Guest *guest, struct Room *rooms_list) {
    // Release room
    for(int i=0; i<10; i++) {
        if(rooms_list[i].number == guest->room_number) {
            rooms_list[i].is_available = 1;
            break;
        }
    }

    print_guest_info(*guest); // Print final bill info
    guest->name[0] = '\0'; // Remove guest from guest list
    printf("Guest checked-out.\n");
}