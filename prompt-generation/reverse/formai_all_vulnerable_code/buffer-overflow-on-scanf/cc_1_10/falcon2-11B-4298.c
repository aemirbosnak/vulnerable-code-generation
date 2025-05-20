//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: relaxed
#include <stdio.h>

struct Hotel{
    char name[50];
    int rooms;
    float price;
};

int main() {
    struct Hotel hotel1;
    printf("Enter hotel name: ");
    scanf("%s", hotel1.name);
    printf("Enter number of rooms: ");
    scanf("%d", &hotel1.rooms);
    printf("Enter price per room: ");
    scanf("%f", &hotel1.price);

    struct Hotel hotel2;
    printf("Enter hotel name: ");
    scanf("%s", hotel2.name);
    printf("Enter number of rooms: ");
    scanf("%d", &hotel2.rooms);
    printf("Enter price per room: ");
    scanf("%f", &hotel2.price);

    struct Hotel hotel3;
    printf("Enter hotel name: ");
    scanf("%s", hotel3.name);
    printf("Enter number of rooms: ");
    scanf("%d", &hotel3.rooms);
    printf("Enter price per room: ");
    scanf("%f", &hotel3.price);

    struct Hotel hotel4;
    printf("Enter hotel name: ");
    scanf("%s", hotel4.name);
    printf("Enter number of rooms: ");
    scanf("%d", &hotel4.rooms);
    printf("Enter price per room: ");
    scanf("%f", &hotel4.price);

    struct Hotel hotel5;
    printf("Enter hotel name: ");
    scanf("%s", hotel5.name);
    printf("Enter number of rooms: ");
    scanf("%d", &hotel5.rooms);
    printf("Enter price per room: ");
    scanf("%f", &hotel5.price);

    printf("Hotel 1: %s, %d rooms, %.2f per room\n", hotel1.name, hotel1.rooms, hotel1.price);
    printf("Hotel 2: %s, %d rooms, %.2f per room\n", hotel2.name, hotel2.rooms, hotel2.price);
    printf("Hotel 3: %s, %d rooms, %.2f per room\n", hotel3.name, hotel3.rooms, hotel3.price);
    printf("Hotel 4: %s, %d rooms, %.2f per room\n", hotel4.name, hotel4.rooms, hotel4.price);
    printf("Hotel 5: %s, %d rooms, %.2f per room\n", hotel5.name, hotel5.rooms, hotel5.price);

    return 0;
}