//FormAI DATASET v1.0 Category: Password management ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item {
    char website[50];
    char username[50];
    char password[50];
};

void add_item(struct item *list, int num_items) {
    printf("Website: ");
    scanf("%s", list[num_items].website);
    printf("Username: ");
    scanf("%s", list[num_items].username);
    printf("Password: ");
    scanf("%s", list[num_items].password);
    printf("Item added!\n");
}

void display_items(struct item *list, int num_items) {
    if (num_items == 0) {
        printf("No items to display.\n");
    } else {
        printf("Website\t\tUsername\t\tPassword\n");
        printf("---------------------------------------------\n");
        for (int i = 0; i < num_items; i++) {
            printf("%s\t\t%s\t\t%s\n", list[i].website, list[i].username, list[i].password);
        }
    }
}

void delete_item(struct item *list, int num_items) {
    char website[50];
    printf("Enter the website of the item you wish to delete: ");
    scanf("%s", website);
    for (int i = 0; i < num_items; i++) {
        if (strcmp(list[i].website, website) == 0) {
            for (int j = i; j < num_items - 1; j++) {
                list[j] = list[j+1];
            }
            printf("Item deleted!\n");
            return;
        }
    }
    printf("Item not found.\n");
}

void save_items(struct item *list, int num_items) {
    FILE *fp;
    fp = fopen("passwords.txt", "w");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
    } else {
        for (int i = 0; i < num_items; i++) {
            fprintf(fp, "%s %s %s\n", list[i].website, list[i].username, list[i].password);
        }
        printf("Items saved to file.\n");
        fclose(fp);
    }
}

void load_items(struct item *list, int *num_items) {
    FILE *fp;
    fp = fopen("passwords.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
    } else {
        int i = *num_items; // Start at next available index in list
        while (fscanf(fp, "%s %s %s", list[i].website, list[i].username, list[i].password) == 3) {
            i++;
        }
        *num_items = i; // Update number of items in list
        printf("Items loaded from file.\n");
        fclose(fp);
    }
}

int main() {
    struct item list[100]; // Initialize list with maximum capacity of 100 items
    int num_items = 0; // Initialize number of items to 0

    int choice;
    do {
        printf("\n1. Add item\n2. Display items\n3. Delete item\n4. Save items to file\n5. Load items from file\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item(list, num_items);
                num_items++;
                break;
            case 2:
                display_items(list, num_items);
                break;
            case 3:
                delete_item(list, num_items);
                num_items--;
                break;
            case 4:
                save_items(list, num_items);
                break;
            case 5:
                load_items(list, &num_items);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}