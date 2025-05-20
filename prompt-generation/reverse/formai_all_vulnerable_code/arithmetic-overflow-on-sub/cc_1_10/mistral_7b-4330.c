//MISTRAL-7B DATASET v1.0 Category: Warehouse Management System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_ITEMS 50
#define ITEM_SIZE 20
#define INVENTORY_FILE "inventory.dat"

struct Item {
    char name[ITEM_SIZE];
    int stock;
};

void loadInventory(struct Item inventory[]) {
    int fd;
    struct Item temp;

    fd = open(INVENTORY_FILE, O_RDONLY);

    if (fd == -1) {
        printf("Error: Could not open inventory file.\n");
        exit(1);
    }

    for (int i = 0; i < MAX_ITEMS && read(fd, &temp, sizeof(temp)) > 0; i++) {
        strcpy(inventory[i].name, temp.name);
        inventory[i].stock = temp.stock;
    }

    close(fd);
}

void saveInventory(struct Item inventory[]) {
    int fd;

    fd = open(INVENTORY_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1) {
        printf("Error: Could not open inventory file.\n");
        exit(1);
    }

    for (int i = 0; i < MAX_ITEMS; i++) {
        write(fd, &inventory[i], sizeof(inventory[i]));
    }

    close(fd);
}

int main() {
    struct Item inventory[MAX_ITEMS];
    char command[10];
    int index;

    loadInventory(inventory);

    printf("Welcome to the Post-Apocalyptic Warehouse Management System!\n");
    printf("Available Items:\n");

    for (int i = 0; i < MAX_ITEMS && inventory[i].stock > 0; i++) {
        printf("%d. %s\n", i+1, inventory[i].name);
    }

    while (1) {
        printf("\nEnter command (add <num> <item> or take <num> <item>): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            scanf("%d %s", &index, command+3);
            index--;

            if (index >= 0 && index < MAX_ITEMS && inventory[index].stock > 0) {
                int qty;
                scanf("%d", &qty);

                if (qty > inventory[index].stock) {
                    printf("Error: Not enough stock.\n");
                } else {
                    inventory[index].stock -= qty;
                    printf("Item taken.\n");
                }
            } else {
                printf("Error: Invalid item number.\n");
            }
        } else if (strcmp(command, "take") == 0) {
            scanf("%d %s", &index, command+4);
            index--;

            if (index >= 0 && index < MAX_ITEMS) {
                if (inventory[index].stock > 0) {
                    inventory[index].stock--;
                    printf("Item taken.\n");
                } else {
                    printf("Error: Item not in stock.\n");
                }
            } else {
                printf("Error: Invalid item number.\n");
            }
        } else {
            printf("Error: Invalid command.\n");
        }

        saveInventory(inventory);
    }

    return 0;
}