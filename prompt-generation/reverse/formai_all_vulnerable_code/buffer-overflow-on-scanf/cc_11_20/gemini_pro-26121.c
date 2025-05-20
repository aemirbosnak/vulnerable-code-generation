//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char title[50];
    int age;
    int salary;
} employee;

typedef struct {
    int room_number;
    char room_type[50];
    int num_beds;
    int price;
} room;

typedef struct {
    int reservation_id;
    char guest_name[50];
    int room_number;
    char check_in_date[50];
    char check_out_date[50];
} reservation;

employee employees[] = {
    {"John Smith", "Manager", 45, 1000},
    {"Jane Doe", "Front Desk Clerk", 25, 500},
    {"Bob Smith", "Maintenance", 30, 600}
};

room rooms[] = {
    {101, "Standard", 2, 100},
    {102, "Deluxe", 2, 150},
    {103, "Suite", 4, 200}
};

reservation reservations[] = {
    {1000, "John Doe", 101, "2023-01-01", "2023-01-03"},
    {1001, "Jane Smith", 102, "2023-01-05", "2023-01-07"}
};

int main() {
    int choice;

    do {
        printf("Welcome to the Medieval Hotel Management System!\n");
        printf("1. List employees\n");
        printf("2. List rooms\n");
        printf("3. List reservations\n");
        printf("4. Add a new employee\n");
        printf("5. Add a new room\n");
        printf("6. Add a new reservation\n");
        printf("7. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Employees:\n");
                for (int i = 0; i < sizeof(employees) / sizeof(employees[0]); i++) {
                    printf("%s, %s, %d, %d\n", employees[i].name, employees[i].title, employees[i].age, employees[i].salary);
                }
                break;
            case 2:
                printf("Rooms:\n");
                for (int i = 0; i < sizeof(rooms) / sizeof(rooms[0]); i++) {
                    printf("%d, %s, %d, %d\n", rooms[i].room_number, rooms[i].room_type, rooms[i].num_beds, rooms[i].price);
                }
                break;
            case 3:
                printf("Reservations:\n");
                for (int i = 0; i < sizeof(reservations) / sizeof(reservations[0]); i++) {
                    printf("%d, %s, %d, %s, %s\n", reservations[i].reservation_id, reservations[i].guest_name, reservations[i].room_number, reservations[i].check_in_date, reservations[i].check_out_date);
                }
                break;
            case 4:
                printf("Enter the employee's name: ");
                scanf("%s", &employees[sizeof(employees) / sizeof(employees[0])].name);
                printf("Enter the employee's title: ");
                scanf("%s", &employees[sizeof(employees) / sizeof(employees[0])].title);
                printf("Enter the employee's age: ");
                scanf("%d", &employees[sizeof(employees) / sizeof(employees[0])].age);
                printf("Enter the employee's salary: ");
                scanf("%d", &employees[sizeof(employees) / sizeof(employees[0])].salary);
                break;
            case 5:
                printf("Enter the room number: ");
                scanf("%d", &rooms[sizeof(rooms) / sizeof(rooms[0])].room_number);
                printf("Enter the room type: ");
                scanf("%s", &rooms[sizeof(rooms) / sizeof(rooms[0])].room_type);
                printf("Enter the number of beds: ");
                scanf("%d", &rooms[sizeof(rooms) / sizeof(rooms[0])].num_beds);
                printf("Enter the room price: ");
                scanf("%d", &rooms[sizeof(rooms) / sizeof(rooms[0])].price);
                break;
            case 6:
                printf("Enter the reservation ID: ");
                scanf("%d", &reservations[sizeof(reservations) / sizeof(reservations[0])].reservation_id);
                printf("Enter the guest name: ");
                scanf("%s", &reservations[sizeof(reservations) / sizeof(reservations[0])].guest_name);
                printf("Enter the room number: ");
                scanf("%d", &reservations[sizeof(reservations) / sizeof(reservations[0])].room_number);
                printf("Enter the check-in date: ");
                scanf("%s", &reservations[sizeof(reservations) / sizeof(reservations[0])].check_in_date);
                printf("Enter the check-out date: ");
                scanf("%s", &reservations[sizeof(reservations) / sizeof(reservations[0])].check_out_date);
                break;
        }
    } while (choice != 7);

    return 0;
}