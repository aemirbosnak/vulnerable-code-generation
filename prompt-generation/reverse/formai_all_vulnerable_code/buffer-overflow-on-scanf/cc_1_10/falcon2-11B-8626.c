//Falcon2-11B DATASET v1.0 Category: Haunted House Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    char age[100];
} Person;

typedef struct {
    char room_name[100];
    int number_of_people;
} Room;

void create_person(Person *person) {
    printf("Enter person name: ");
    scanf("%s", person->name);

    printf("Enter person age: ");
    scanf("%s", person->age);
}

void create_room(Room *room) {
    printf("Enter room name: ");
    scanf("%s", room->room_name);

    printf("Enter number of people in room: ");
    scanf("%d", &room->number_of_people);
}

void print_person(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %s\n", person->age);
}

void print_room(Room *room) {
    printf("Room Name: %s\n", room->room_name);
    printf("Number of People: %d\n", room->number_of_people);
}

int main() {
    Room room1;
    Room room2;

    create_room(&room1);
    create_room(&room2);

    printf("Room 1: %s (Number of People: %d)\n", room1.room_name, room1.number_of_people);
    printf("Room 2: %s (Number of People: %d)\n", room2.room_name, room2.number_of_people);

    return 0;
}