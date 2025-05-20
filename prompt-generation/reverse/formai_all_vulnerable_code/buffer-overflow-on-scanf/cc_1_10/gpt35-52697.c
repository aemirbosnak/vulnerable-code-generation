//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MED 50   // maximum number of medicines that can be stored
#define MED_NAME_LEN 30 // maximum length of medicine name

// structure for medicine details
struct medicine {
    char name[MED_NAME_LEN];
    float price;
    int quantity;
    char expiry_date[11]; // format: dd-mm-yyyy
};

// function prototypes
void add_medicine(struct medicine meds[], int *count);
void display_medicines(struct medicine meds[], int count);
void search_medicines(struct medicine meds[], int count);
void remove_medicine(struct medicine meds[], int *count);

int main()
{
    struct medicine meds[MAX_MED];
    int count = 0, choice;

    printf("Welcome to the Medical Store Management System!\n");

    do {
        // display menu options
        printf("\nMenu:\n");
        printf("1. Add new medicine\n");
        printf("2. Display all medicines\n");
        printf("3. Search medicines\n");
        printf("4. Remove medicine\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: // add medicine
                add_medicine(meds, &count);
                break;
            case 2: // display all medicines
                display_medicines(meds, count);
                break;
            case 3: // search medicines
                search_medicines(meds, count);
                break;
            case 4: // remove medicine
                remove_medicine(meds, &count);
                break;
            case 5: // exit
                printf("Thank you for using the Medical Store Management System!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 5);

    return 0;
}

void add_medicine(struct medicine meds[], int *count)
{
    // check if maximum medicines have been stored
    if (*count == MAX_MED) {
        printf("Sorry, maximum number of medicines have been stored.\n");
        return;
    }

    printf("\nAdd New Medicine:\n");

    // get medicine details from user
    printf("Name: ");
    getchar(); // flush out newline character from previous input
    fgets(meds[*count].name, MED_NAME_LEN, stdin);
    meds[*count].name[strcspn(meds[*count].name, "\n")] = '\0'; // remove trailing newline
    printf("Price: ");
    scanf("%f", &meds[*count].price);
    printf("Quantity: ");
    scanf("%d", &meds[*count].quantity);
    printf("Expiry Date (dd-mm-yyyy): ");
    getchar(); // flush out newline character from previous input
    fgets(meds[*count].expiry_date, 11, stdin);
    meds[*count].expiry_date[strcspn(meds[*count].expiry_date, "\n")] = '\0'; // remove trailing newline

    // increment medicine counter
    (*count)++;

    printf("Medicine added successfully!\n");
}

void display_medicines(struct medicine meds[], int count)
{
    // check if any medicines have been stored
    if (count == 0) {
        printf("No medicines found.\n");
        return;
    }

    printf("\nAll Medicines:\n");

    // display all medicines
    for (int i = 0; i < count; i++) {
        printf("\nMedicine %d:\n", i+1);
        printf("Name: %s\n", meds[i].name);
        printf("Price: %.2f\n", meds[i].price);
        printf("Quantity: %d\n", meds[i].quantity);
        printf("Expiry Date: %s\n", meds[i].expiry_date);
    }
}

void search_medicines(struct medicine meds[], int count)
{
    // check if any medicines have been stored
    if (count == 0) {
        printf("No medicines found.\n");
        return;
    }

    char search_name[MED_NAME_LEN];
    int found = 0;

    // get medicine name to search for
    printf("\nEnter name of medicine to search for: ");
    getchar(); // flush out newline character from previous input
    fgets(search_name, MED_NAME_LEN, stdin);
    search_name[strcspn(search_name, "\n")] = '\0'; // remove trailing newline

    // search for medicine
    for (int i = 0; i < count; i++) {
        if (strcmp(meds[i].name, search_name) == 0) {
            printf("\nMedicine %d:\n", i+1);
            printf("Name: %s\n", meds[i].name);
            printf("Price: %.2f\n", meds[i].price);
            printf("Quantity: %d\n", meds[i].quantity);
            printf("Expiry Date: %s\n", meds[i].expiry_date);
            found = 1;
        }
    }

    if (!found) {
        printf("Medicine not found.\n");
    }
}

void remove_medicine(struct medicine meds[], int *count)
{
    // check if any medicines have been stored
    if (*count == 0) {
        printf("No medicines found.\n");
        return;
    }

    char remove_name[MED_NAME_LEN];
    int found = 0, remove_index;

    // get medicine name to remove
    printf("\nEnter name of medicine to remove: ");
    getchar(); // flush out newline character from previous input
    fgets(remove_name, MED_NAME_LEN, stdin);
    remove_name[strcspn(remove_name, "\n")] = '\0'; // remove trailing newline

    // search for medicine
    for (int i = 0; i < *count; i++) {
        if (strcmp(meds[i].name, remove_name) == 0) {
            remove_index = i;
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Medicine not found.\n");
        return;
    }

    // remove medicine and shift other medicines to fill gap
    for (int i = remove_index; i < *count-1; i++) {
        strcpy(meds[i].name, meds[i+1].name);
        meds[i].price = meds[i+1].price;
        meds[i].quantity = meds[i+1].quantity;
        strcpy(meds[i].expiry_date, meds[i+1].expiry_date);
    }

    // decrement medicine counter
    (*count)--;

    printf("Medicine removed successfully!\n");
}