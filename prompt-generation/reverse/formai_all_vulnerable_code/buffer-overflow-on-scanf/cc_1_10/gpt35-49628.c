//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 1000

struct item {
    int id;
    char name[50];
    int quantity;
};

struct warehouse {
    int id;
    char location[50];
    struct item items[MAX_ITEMS];
    int num_items;
};

struct user {
    int id;
    char username[50];
    char password[50];
    int is_admin;
};

struct warehouse warehouses[MAX_ITEMS];
int num_warehouses = 0;

struct user users[MAX_ITEMS];
int num_users = 0;

int current_user_id = -1;

void print_menu() {
    printf("1. Add warehouse\n");
    printf("2. View warehouse\n");
    printf("3. Add item to warehouse\n");
    printf("4. Remove item from warehouse\n");
    printf("5. Logout\n");
    printf("6. Quit\n");
}

void add_warehouse() {
    printf("Enter the warehouse ID: ");
    scanf("%d", &warehouses[num_warehouses].id);
    printf("Enter the warehouse location: ");
    scanf("%s", warehouses[num_warehouses].location);
    warehouses[num_warehouses].num_items = 0;
    num_warehouses++;
}

void print_warehouses() {
    printf("Warehouse List:\n");
    for (int i = 0; i < num_warehouses; i++) {
        printf("%d. %s\n", warehouses[i].id, warehouses[i].location);
    }
}

void view_warehouse(int warehouse_id) {
    for (int i = 0; i < num_warehouses; i++) {
        if (warehouses[i].id == warehouse_id) {
            printf("Warehouse ID: %d\n", warehouse_id);
            printf("Warehouse Location: %s\n", warehouses[i].location);
            printf("Item List:\n");
            for (int j = 0; j < warehouses[i].num_items; j++) {
                printf("%d. %s, Quantity: %d\n", warehouses[i].items[j].id, warehouses[i].items[j].name, warehouses[i].items[j].quantity);
            }
            return;
        }
    }
    printf("Warehouse not found!\n");
}

void add_item(int warehouse_id) {
    for (int i = 0; i < num_warehouses; i++) {
        if (warehouses[i].id == warehouse_id) {
            if (warehouses[i].num_items == MAX_ITEMS) {
                printf("Warehouse is full!\n");
                return;
            }
            printf("Enter the item ID: ");
            scanf("%d", &warehouses[i].items[warehouses[i].num_items].id);
            printf("Enter the item name: ");
            scanf("%s", warehouses[i].items[warehouses[i].num_items].name);
            printf("Enter the item quantity: ");
            scanf("%d", &warehouses[i].items[warehouses[i].num_items].quantity);
            warehouses[i].num_items++;
            return;
        }
    }
    printf("Warehouse not found!\n");
}

void remove_item(int warehouse_id, int item_id) {
    for (int i = 0; i < num_warehouses; i++) {
        if (warehouses[i].id == warehouse_id) {
            for (int j = 0; j < warehouses[i].num_items; j++) {
                if (warehouses[i].items[j].id == item_id) {
                    for (int k = j + 1; k < warehouses[i].num_items; k++) {
                        warehouses[i].items[k - 1] = warehouses[i].items[k];
                    }
                    warehouses[i].num_items--;
                    return;
                }
            }
            printf("Item not found!\n");
            return;
        }
    }
    printf("Warehouse not found!\n");
}

void login() {
    char username[50];
    char password[50];
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            current_user_id = users[i].id;
            printf("Welcome %s!\n", username);
            return;
        }
    }
    printf("Invalid username or password!\n");
}

void logout() {
    current_user_id = -1;
    printf("Logged out!\n");
}

void add_user() {
    printf("Enter the username: ");
    scanf("%s", users[num_users].username);
    printf("Enter the password: ");
    scanf("%s", users[num_users].password);
    printf("Is this user an admin?\n");
    printf("1. Yes\n");
    printf("2. No\n");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        users[num_users].is_admin = 1;
    } else {
        users[num_users].is_admin = 0;
    }
    users[num_users].id = num_users;
    num_users++;
}

int main() {
    while (1) {
        if (current_user_id == -1) {
            printf("Please log in!\n");
            login();
        } else {
            if (users[current_user_id].is_admin) {
                printf("Admin Menu:\n");
                print_menu();
                int choice;
                scanf("%d", &choice);
                switch (choice) {
                    case 1: add_warehouse(); break;
                    case 2: print_warehouses(); break;
                    case 3: {
                        int warehouse_id;
                        printf("Enter the warehouse ID: ");
                        scanf("%d", &warehouse_id);
                        add_item(warehouse_id);
                        break;
                    }
                    case 4: {
                        int warehouse_id;
                        int item_id;
                        printf("Enter the warehouse ID: ");
                        scanf("%d", &warehouse_id);
                        printf("Enter the item ID: ");
                        scanf("%d", &item_id);
                        remove_item(warehouse_id, item_id);
                        break;
                    }
                    case 5: logout(); break;
                    case 6: exit(0);
                }
            } else {
                printf("User Menu:\n");
                print_menu();
                int choice;
                scanf("%d", &choice);
                switch (choice) {
                    case 2: {
                        int warehouse_id;
                        printf("Enter the warehouse ID: ");
                        scanf("%d", &warehouse_id);
                        view_warehouse(warehouse_id);
                        break;
                    }
                    case 5: logout(); break;
                    case 6: exit(0);
                }
            }
        }
    }
    return 0;
}