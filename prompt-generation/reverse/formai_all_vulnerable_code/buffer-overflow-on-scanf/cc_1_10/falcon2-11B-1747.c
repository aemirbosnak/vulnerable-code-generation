//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    float salary;
} Employee;

typedef struct {
    char name[50];
    int room_no;
    int price;
} Room;

typedef struct {
    char name[50];
    int check_in_date;
    int check_out_date;
} Guest;

typedef struct {
    int hotel_id;
    char name[50];
    int year_built;
    int room_capacity;
} Hotel;

int main() {
    Hotel hotel;
    printf("Enter hotel name: ");
    scanf("%s", hotel.name);
    printf("Enter year built: ");
    scanf("%d", &hotel.year_built);
    printf("Enter room capacity: ");
    scanf("%d", &hotel.room_capacity);

    Room rooms[hotel.room_capacity];
    int room_no;
    for(room_no = 0; room_no < hotel.room_capacity; room_no++) {
        printf("Enter room details: \n");
        printf("Room number: ");
        scanf("%d", &rooms[room_no].room_no);
        printf("Room price: ");
        scanf("%d", &rooms[room_no].price);
    }

    Employee employees[10];
    int emp_no;
    for(emp_no = 0; emp_no < 10; emp_no++) {
        printf("Enter employee details: \n");
        printf("Employee name: ");
        scanf("%s", employees[emp_no].name);
        printf("Employee age: ");
        scanf("%d", &employees[emp_no].age);
        printf("Employee salary: ");
        scanf("%f", &employees[emp_no].salary);
    }

    Guest guests[100];
    int guest_no;
    for(guest_no = 0; guest_no < 100; guest_no++) {
        printf("Enter guest details: \n");
        printf("Guest name: ");
        scanf("%s", guests[guest_no].name);
        printf("Guest check-in date: ");
        scanf("%d", &guests[guest_no].check_in_date);
        printf("Guest check-out date: ");
        scanf("%d", &guests[guest_no].check_out_date);
    }

    printf("Hotel details: \n");
    printf("Hotel name: %s \n", hotel.name);
    printf("Year built: %d \n", hotel.year_built);
    printf("Room capacity: %d \n", hotel.room_capacity);

    printf("Room details: \n");
    for(room_no = 0; room_no < hotel.room_capacity; room_no++) {
        printf("Room number: %d \n", rooms[room_no].room_no);
        printf("Room price: %d \n", rooms[room_no].price);
    }

    printf("Employee details: \n");
    for(emp_no = 0; emp_no < 10; emp_no++) {
        printf("Employee name: %s \n", employees[emp_no].name);
        printf("Employee age: %d \n", employees[emp_no].age);
        printf("Employee salary: %f \n", employees[emp_no].salary);
    }

    printf("Guest details: \n");
    for(guest_no = 0; guest_no < 100; guest_no++) {
        printf("Guest name: %s \n", guests[guest_no].name);
        printf("Guest check-in date: %d \n", guests[guest_no].check_in_date);
        printf("Guest check-out date: %d \n", guests[guest_no].check_out_date);
    }

    return 0;
}