//Falcon2-11B DATASET v1.0 Category: Medical Store Management System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char file_name[50];
    printf("Enter the file name: ");
    scanf("%s", file_name);

    FILE *fp;
    fp = fopen(file_name, "r");

    if (fp == NULL) {
        printf("Invalid file path!\n");
        exit(0);
    }

    int num_items;
    fscanf(fp, "%d", &num_items);

    int items[num_items];
    for (int i = 0; i < num_items; i++) {
        fscanf(fp, "%d", &items[i]);
    }

    fclose(fp);

    int num_items_to_add;
    printf("Enter the number of items to add: ");
    scanf("%d", &num_items_to_add);

    int new_items[num_items_to_add];
    for (int i = 0; i < num_items_to_add; i++) {
        printf("Enter the item: ");
        scanf("%d", &new_items[i]);
    }

    items[num_items] = new_items[0];
    for (int i = 1; i < num_items_to_add; i++) {
        items[num_items + i] = new_items[i];
    }

    int num_items_to_remove;
    printf("Enter the number of items to remove: ");
    scanf("%d", &num_items_to_remove);

    for (int i = num_items; i < num_items + num_items_to_remove; i++) {
        printf("%d ", items[i]);
    }

    printf("\n");

    int item_to_remove;
    printf("Enter the item to remove: ");
    scanf("%d", &item_to_remove);

    for (int i = num_items; i < num_items + num_items_to_remove; i++) {
        if (items[i] == item_to_remove) {
            for (int j = i; j < num_items + num_items_to_remove; j++) {
                items[j] = items[j + 1];
            }

            num_items -= 1;
            break;
        }
    }

    printf("The items in the store are: ");
    for (int i = 0; i < num_items; i++) {
        printf("%d ", items[i]);
    }

    printf("\n");

    return 0;
}