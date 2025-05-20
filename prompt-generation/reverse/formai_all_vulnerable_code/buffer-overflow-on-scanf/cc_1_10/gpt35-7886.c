//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STOCK 1000 // maximum stock of medicines available
#define MAX_LENGTH 20 // maximum length of medicine name

// structure to hold information of a medicine
struct Medicine {
    int id; // unique identifier for the medicine
    char name[MAX_LENGTH]; // name of the medicine
    float price; // price of the medicine
    int stock; // current stock of the medicine
};

struct Medicine medicines[MAX_STOCK]; // array of medicines
int num_medicines = 0; // current number of medicines available

// function to add a medicine to the system
void add_medicine()
{
    if(num_medicines == MAX_STOCK) {
        printf("Error: Maximum stock reached.\n");
        return;
    }

    struct Medicine med;

    // get input for the medicine
    printf("Enter medicine name: ");
    scanf("%s", med.name);
    printf("Enter medicine price: ");
    scanf("%f", &med.price);
    printf("Enter medicine stock: ");
    scanf("%d", &med.stock);

    // generate unique id for the medicine
    med.id = num_medicines + 1;

    // add the medicine to the array
    medicines[num_medicines] = med;
    num_medicines++;

    printf("Medicine added successfully.\n\n");
}

// function to display the list of medicines
void display_medicines()
{
    printf("ID\tName\t\tPrice\tStock\n");

    for(int i=0; i<num_medicines; i++) {
        printf("%d\t%-10s\t%.2f\t%d\n", medicines[i].id, medicines[i].name, medicines[i].price, medicines[i].stock);
    }

    printf("\n");
}

// function to search for a medicine by name
void search_medicine()
{
    char name[MAX_LENGTH];
    printf("Enter medicine name: ");
    scanf("%s", name);

    int found = 0;

    for(int i=0; i<num_medicines; i++) {
        if(strcmp(medicines[i].name, name) == 0) {
            found = 1;
            printf("Medicine found:\n");
            printf("ID: %d\nName: %s\nPrice: %.2f\nStock: %d\n\n", medicines[i].id, medicines[i].name, medicines[i].price, medicines[i].stock);
        }
    }

    if(!found) {
        printf("Medicine not found.\n\n");
    }
}

// function to update the stock of a medicine
void update_stock()
{
    int id;
    int stock;

    printf("Enter medicine ID: ");
    scanf("%d", &id);

    int found = 0;

    for(int i=0; i<num_medicines; i++) {
        if(medicines[i].id == id) {
            found = 1;
            printf("Enter new stock: ");
            scanf("%d", &stock);

            medicines[i].stock = stock;

            printf("Stock updated.\n\n");
        }
    }

    if(!found) {
        printf("Medicine not found.\n\n");
    }
}

int main()
{
    int choice;

    while(1) {
        // display menu
        printf("1. Add Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Search Medicine\n");
        printf("4. Update Stock\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_medicine();
                break;
            case 2:
                display_medicines();
                break;
            case 3:
                search_medicine();
                break;
            case 4:
                update_stock();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n\n");
        }
    }

    return 0;
}