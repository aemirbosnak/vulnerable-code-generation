//Falcon2-11B DATASET v1.0 Category: Warehouse Management System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 100
#define MAX_USERS 100
#define MAX_QUANTITY 1000

typedef struct {
    int id;
    char name[20];
    int quantity[MAX_ITEMS];
} User;

typedef struct {
    char item[20];
    int quantity;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    User users[MAX_USERS];
} Warehouse;

int main() {
    Warehouse warehouse;
    int i, j, k, l;

    srand(time(NULL));

    for (i = 0; i < MAX_ITEMS; i++) {
        warehouse.items[i].item[0] = 'A' + rand() % 26;
        warehouse.items[i].item[1] = 'B' + rand() % 26;
        warehouse.items[i].item[2] = 'C' + rand() % 26;
        warehouse.items[i].item[3] = 'D' + rand() % 26;
        warehouse.items[i].item[4] = 'E' + rand() % 26;
        warehouse.items[i].item[5] = 'F' + rand() % 26;
        warehouse.items[i].item[6] = 'G' + rand() % 26;
        warehouse.items[i].item[7] = 'H' + rand() % 26;
        warehouse.items[i].item[8] = 'I' + rand() % 26;
        warehouse.items[i].item[9] = 'J' + rand() % 26;
        warehouse.items[i].item[10] = 'K' + rand() % 26;
        warehouse.items[i].item[11] = 'L' + rand() % 26;
        warehouse.items[i].item[12] = 'M' + rand() % 26;
        warehouse.items[i].item[13] = 'N' + rand() % 26;
        warehouse.items[i].item[14] = 'O' + rand() % 26;
        warehouse.items[i].item[15] = 'P' + rand() % 26;
        warehouse.items[i].item[16] = 'Q' + rand() % 26;
        warehouse.items[i].item[17] = 'R' + rand() % 26;
        warehouse.items[i].item[18] = 'S' + rand() % 26;
        warehouse.items[i].item[19] = 'T' + rand() % 26;
        warehouse.items[i].item[20] = 'U' + rand() % 26;
        warehouse.items[i].item[21] = 'V' + rand() % 26;
        warehouse.items[i].item[22] = 'W' + rand() % 26;
        warehouse.items[i].item[23] = 'X' + rand() % 26;
        warehouse.items[i].item[24] = 'Y' + rand() % 26;
        warehouse.items[i].item[25] = 'Z' + rand() % 26;
        warehouse.items[i].quantity = rand() % MAX_QUANTITY;
    }

    for (i = 0; i < MAX_USERS; i++) {
        warehouse.users[i].id = i + 1;
        strcpy(warehouse.users[i].name, "User " + (i + 1));
    }

    for (i = 0; i < MAX_ITEMS; i++) {
        printf("Item %c has quantity %d.\n", warehouse.items[i].item, warehouse.items[i].quantity);
    }

    for (i = 0; i < MAX_USERS; i++) {
        printf("User %d's name is %s.\n", warehouse.users[i].id, warehouse.users[i].name);
    }

    return 0;
}